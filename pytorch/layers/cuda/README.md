## Cuda
{:.no_toc}

<nav markdown="1" class="toc-class">
* TOC
{:toc}
</nav>

## The goal

Convince PyTorch and Nvidia's GPUs working together. **I assume you installed the PyTorch and/or TensorFlow version for CUDA. (see Python installation instructions on thsi site...)**

Questions to [David Rotermund](mailto:davrot@uni-bremen.de)

## Windows

* Download and install [CUDA driver](https://developer.nvidia.com/cuda-downloads)
* Download and install [cuDNN toolkit](https://developer.nvidia.com/rdp/cudnn-download) (you will need to create an account :-( )

## Test the PyTorch

```python
import torch
torch.cuda.is_available()
```

Expected output:

```python
True
```

```python
torch.cuda.is_available()
```

Expected output:

```python
True
```

```python
torch.backends.cuda.is_built()
```

Expected output:

```python
True
```

```python
torch.backends.cudnn.version()
```

Expected output (number depends on the GPU generation and may be different):

```python
8904
```

```python
torch.backends.cudnn.enabled
```

Expected output:

```python
True
```

```python
my_cuda_device = torch.device('cuda:0')
print(torch.cuda.get_device_properties(my_cuda_device))
```

Expected output (values depend on the GPU generation):

```python
_CudaDeviceProperties(name='NVIDIA GeForce RTX 3060', major=8, minor=6, total_memory=12011MB, multi_processor_count=28)
```
