# psutil vs os.cpu_count -- How many "CPUs" do I have?
{:.no_toc}

<nav markdown="1" class="toc-class">
* TOC
{:toc}
</nav>

## The goal

How man "CPUs" do I have in this computer? We need this information for multi-processing.

Questions to [David Rotermund](mailto:davrot@uni-bremen.de)


## os.cpu_count

We get the core count inclusive the virtual [hyper threading](https://en.wikipedia.org/wiki/Hyper-threading) cores. But it is included in Python:

 

```python
import os
# If -1 then it looks up the amount of available CPU HT cores
number_of_cpu_processes: int = -1
number_of_cpu_processes_temp = os.cpu_count()

if number_of_cpu_processes < 1:
    if number_of_cpu_processes_temp is None:
        number_of_cpu_processes = 1
    else:
        number_of_cpu_processes = number_of_cpu_processes_temp

print(number_of_cpu_processes) #-> 12 (for my computer)
``` 

## Alternative [psutil](https://github.com/giampaolo/psutil)

```shell
pip install psutil
```

[psutil](https://github.com/giampaolo/psutil): "Cross-platform lib for process and system monitoring in Python"

I can deliver us more than just the CPU count:

* CPU
* Memory
* Disks
* Network
* Sensors
* Other system info
* Process management
* Further process APIs
* Windows services
 
```python
import psutil

number_of_cpu_processes: int = -1
number_of_cpu_processes_no_ht: int = -1
if number_of_cpu_processes == -1:
    number_of_cpu_processes = psutil.cpu_count()
    number_of_cpu_processes_no_ht = psutil.cpu_count(logical=False)

print(number_of_cpu_processes) # -> 12 (for my computer)

print(number_of_cpu_processes_no_ht) # -> 6 (for my computer)
```
