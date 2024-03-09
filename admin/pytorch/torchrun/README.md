# torchrun for multi-node but single GPU -- checking for network problems 

## Top

Questions to [David Rotermund](mailto:davrot@uni-bremen.de)

This is not a tutorial on how to use DistributedDataParallel.
We use only three of the four elements to use: 
* [distributed.init_process_group](https://pytorch.org/docs/stable/distributed.html#torch.distributed.init_process_group)
* [DistributedDataParallel](https://pytorch.org/docs/stable/generated/torch.nn.parallel.DistributedDataParallel.html#torch.nn.parallel.DistributedDataParallel)
* [DistributedSampler](https://pytorch.org/docs/stable/data.html#torch.utils.data.distributed.DistributedSampler)
* [torch.distributed.destroy_process_group ](https://pytorch.org/tnt/stable/utils/generated/torchtnt.utils.distributed.destroy_process_group.html#torchtnt.utils.distributed.destroy_process_group)

The DistributedSampler is not used in this network test example. It would look something like this: 

```python
sampler = DistributedSampler(dataset) 
loader = DataLoader(dataset, shuffle=False,sampler=sampler)
```

Also you might not want to use [@record](https://pytorch.org/docs/stable/elastic/errors.html#torch.distributed.elastic.multiprocessing.errors.record) during learning. 

Another note:

If you want to test the performance on test data locally (what you probably want to do, even if you don't know yet) 

```python
local_rank = int(os.environ["LOCAL_RANK"])
world_rank = int(os.environ["RANK"])
```

Make sure that local_rank AND world_rank are both == 0.


Which brings me to the point what these numbers (i.e. the lingo behind it) mean:

Identifier of the session on the computer. In the single GPU case, this is always 0. If you have more GPUs (or even CPU threads), this will be different. 

```python
local_rank = int(os.environ["LOCAL_RANK"])
```

The number of nodes (i.e. computers) in the distributed network. In the following I will often use 2, because I used two computers for testing it.   

```python
world_size = int(os.environ["WORLD_SIZE"])
```

The world rank is the identifier if the computer in the distributed network. The master computer is always 0! Do not start another node which is not the master node with 0! Furthermore, don't start to nodes / computers with the same identifie. 
Never ever. It will crash the distributed network. 

```python
world_rank = int(os.environ["RANK"])
```

## torchrun script

The script needs to be started on the computer with the master ip first.

You need to change the master_ip,  master_port and python_file: 

```shell
master_ip="10.10.10.10"
master_port="40001"
python_file="main.py"

ip_check=`ip addr | grep $master_ip | wc -l`

if [[ "$#" -ne 2 ]]
then
    echo "Illegal number of parameters" 
    exit 1  
fi

WORLD_SIZE=$1
WORLD_RANK=$2

echo World Size: $WORLD_SIZE
echo World Rank: $WORLD_RANK

if [[ "$WORLD_SIZE" -le "$WORLD_RANK" ]]
then
    echo "WORLD_RANK needs to bigger then WORLD_SIZE." 
    exit 1  
fi

if [[ $ip_check == "1" ]]
then
    if [[ "$2" -ne 0 ]]
    then
        echo "Master: You need to have the WORLD_RANK of 0." 
        exit 1  
    fi
else
    if [[ "$2" -eq 0 ]]
    then
        echo "Client: You are not allowed to have the WORLD_RANK of 0." 
        exit 1  
    fi
fi

torchrun \
    --nproc_per_node=1 --nnodes=$WORLD_SIZE --node_rank=$WORLD_RANK \
    --master_addr=$master_ip --master_port=$master_port \
    $python_file
```

## Back to the problem at hand

Let's say you ran the following python programm with backend="gloo" for torch.distributed.init_process_group and everything worked. Now you switch to the recommended backend for GPUs: backend="nccl". However you get totally useless error message: 

```shell
  torch.distributed.DistBackendError: NCCL error in: ../torch/csrc/distributed/c10d/ProcessGroupNCCL.cpp:1691, unhandled system error (run with NCCL_DEBUG=INFO for details), NCCL version 2.19.3
  ncclSystemError: System call (e.g. socket, malloc) or external library call failed or device error.
  Last error: 
```  

What happend? 

I don't know what happend in your case but for me it was the following problem: 

nccl uses a peer-to-peer network for data exchange. And it uses a lot of ports. Which port range? This port range: 

```shell
cat /proc/sys/net/ipv4/ip_local_port_range
```  

```shell
32768	60999
```  

You need to configure all your firewalls to allow data exchange between the nodes. Please don't just open the ports and limited them to the IP range of your nodes. 

```python
import os
import torch
from torch.distributed.elastic.multiprocessing.errors import record

local_rank = int(os.environ["LOCAL_RANK"])
world_rank = int(os.environ["RANK"])
world_size = int(os.environ["WORLD_SIZE"])


@record
def main() -> None:
    gpu_identifier: str = f"cuda:{local_rank}"
    assert torch.cuda.device(gpu_identifier)
    device: torch.device = torch.device(gpu_identifier)

    print("init_process_group")
    torch.distributed.init_process_group(
        backend="nccl",
        rank=world_rank,
        world_size=world_size,
    )  # gloo,nccl
    assert torch.distributed.is_initialized()

    print("Sequential")
    model = torch.nn.Sequential()
    model.append(torch.nn.Linear(in_features=100, out_features=10))
    model = model.to(device=device)

    print("DistributedDataParallel")
    ddp_model = torch.nn.parallel.DistributedDataParallel(
        model, device_ids=[local_rank], output_device=local_rank
    )
    print(ddp_model)

    print("destroy_process_group")
    torch.distributed.destroy_process_group()
    print("END")


if __name__ == "__main__":
    assert torch.cuda.is_available()
    assert torch.distributed.is_available()
    assert torch.distributed.is_nccl_available()
    assert torch.distributed.is_torchelastic_launched()

    print(f"world size: {world_size} world rank: {world_rank} local rank: {local_rank}")
    main()

    exit()
```
