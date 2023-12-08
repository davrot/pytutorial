## Cuda
{:.no_toc}

<nav markdown="1" class="toc-class">
* TOC
{:toc}
</nav>

## The goal

Convince PyTorch and Nvidia's GPUs working together. **I assume you installed the PyTorch and/or TensorFlow version for CUDA. (see Python installation instructions on this site...)**

Questions to [David Rotermund](mailto:davrot@uni-bremen.de)

## Windows / Linux

* Download and install [CUDA driver](https://developer.nvidia.com/cuda-downloads)
* Download and install [cuDNN toolkit](https://developer.nvidia.com/rdp/cudnn-download) (you will need to create an account :-( )

For Linux use a repo if possible. Windows and Linux require that you have install working graphic driver beforehand. At least that is what I believe is a requirement.  

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

## TensorFlow

```python
import tensorflow as tf
```
Expected output (irrelevant nonsense from TensorFlow):

```python
2023-12-08 14:39:08.493465: I tensorflow/core/util/port.cc:113] oneDNN custom operations are on. You may see slightly different numerical results due to floating-point round-off errors from different computation orders. To turn them off, set the environment variable `TF_ENABLE_ONEDNN_OPTS=0`.
2023-12-08 14:39:08.513790: E external/local_xla/xla/stream_executor/cuda/cuda_dnn.cc:9261] Unable to register cuDNN factory: Attempting to register factory for plugin cuDNN when one has already been registered
2023-12-08 14:39:08.513810: E external/local_xla/xla/stream_executor/cuda/cuda_fft.cc:607] Unable to register cuFFT factory: Attempting to register factory for plugin cuFFT when one has already been registered
2023-12-08 14:39:08.514329: E external/local_xla/xla/stream_executor/cuda/cuda_blas.cc:1515] Unable to register cuBLAS factory: Attempting to register factory for plugin cuBLAS when one has already been registered
2023-12-08 14:39:08.517312: I tensorflow/core/platform/cpu_feature_guard.cc:182] This TensorFlow binary is optimized to use available CPU instructions in performance-critical operations.
To enable the following instructions: AVX2 AVX_VNNI FMA, in other operations, rebuild TensorFlow with the appropriate compiler flags.
2023-12-08 14:39:10.432213: W tensorflow/compiler/tf2tensorrt/utils/py_utils.cc:38] TF-TRT Warning: Could not find TensorRT
```

```python
print(tf.config.list_physical_devices('GPU'))
```

Expected output (we care about the last line):

```python
2023-12-08 14:39:19.284332: I external/local_xla/xla/stream_executor/cuda/cuda_executor.cc:901] successful NUMA node read from SysFS had negative value (-1), but there must be at least one NUMA node, so returning NUMA node zero. See more at https://github.com/torvalds/linux/blob/v6.0/Documentation/ABI/testing/sysfs-bus-pci#L344-L355
2023-12-08 14:39:19.308613: I external/local_xla/xla/stream_executor/cuda/cuda_executor.cc:901] successful NUMA node read from SysFS had negative value (-1), but there must be at least one NUMA node, so returning NUMA node zero. See more at https://github.com/torvalds/linux/blob/v6.0/Documentation/ABI/testing/sysfs-bus-pci#L344-L355
2023-12-08 14:39:19.308739: I external/local_xla/xla/stream_executor/cuda/cuda_executor.cc:901] successful NUMA node read from SysFS had negative value (-1), but there must be at least one NUMA node, so returning NUMA node zero. See more at https://github.com/torvalds/linux/blob/v6.0/Documentation/ABI/testing/sysfs-bus-pci#L344-L355
[PhysicalDevice(name='/physical_device:GPU:0', device_type='GPU')]
```
