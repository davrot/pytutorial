# The fast and furious way
{:.no_toc}

<nav markdown="1" class="toc-class">
* TOC
{:toc}
</nav>

## Top

Let us assume that you know what you are doing. And also let us assume that you notices how extremely slow the "correct" way of communication between Python and C++ is. Well the following section is for you...

Questions to [David Rotermund](mailto:davrot@uni-bremen.de)

## Design corner stone

It is the job of Python (Numpy or PyTorch) to provide the tensors from which we read and in which we write. In the cpp domain, we will use this matrices as the interface to Python. We are not allowed to change the sizes of these tensors. We are only allowed to change the content of the tensors. In addition we need to make sure that the matrices are in C_CONTIGUOUS shape. 

Don't forget that C Contiguous is just a complicated way of saying Row-major order memory layout [Row- and column-major order](https://en.wikipedia.org/wiki/Row-_and_column-major_order).

$$M[a,b,c,d] = M[\eta_a \cdot a + \eta_b \cdot  b + \eta_c \cdot  c + d]$$

with

$$\eta_c = n_d$$

$$\eta_b = \eta_c \cdot n_c$$

$$\eta_a = \eta_b \cdot n_b$$

## On the Python side

### PyTorch (CPU)

```python
import torch

a = torch.zeros((10, 10, 10, 10))

assert a.is_contiguous()
assert a.is_cuda is False

assert a.ndim == 4

# Now I extract the pointer to the data memory of the ndarray
input_pointer = a.data_ptr()

# Also I need the shape information for the C++ program.
input_dim_0: int = a.shape[0]
input_dim_1: int = a.shape[1]
input_dim_2: int = a.shape[2]
input_dim_3: int = a.shape[3]
```

### PyTorch (GPU)

```python
import torch

a = torch.zeros((10, 10, 10, 10), device=torch.device("cuda:0"))

assert a.is_contiguous()
assert a.is_cuda

assert a.ndim == 4

# Now I extract the pointer to the data memory of the ndarray
input_pointer = a.data_ptr()

# Also I need the shape information for the C++ program.
input_dim_0: int = a.shape[0]
input_dim_1: int = a.shape[1]
input_dim_2: int = a.shape[2]
input_dim_3: int = a.shape[3]
```

### Numpy

```python
import numpy as np

a = np.zeros((10, 10, 10, 10))

assert a.flags["C_CONTIGUOUS"]


assert a.ndim == 4

# Now I extract the pointer to the data memory of the ndarray
input_pointer, _ = a.__array_interface__["data"]

# Also I need the shape information for the C++ program.
input_dim_0: int = a.shape[0]
input_dim_1: int = a.shape[1]
input_dim_2: int = a.shape[2]
input_dim_3: int = a.shape[3]
```

## On the C++ side

Your C++ method needs to accept these arguments

```cpp
int64_t input_pointer_addr, 
int64_t input_dim_0,
int64_t input_dim_1, 
int64_t input_dim_2, 
int64_t input_dim_3,
```

Inside your C++ method you convert the address into a pointer. **BE WARNED:** Make absolutely sure that the dtype of the np.ndarray is correctly reflected in the pointer type

* dtype=np.float32 --> float
* dtype=np.float64 --> double
* dtype=np.uint64 --> uint64
* ...

  
**If you fuck this up then this will end in tears!**

```cpp
float *input_pointer = (float *)input_pointer_addr;

// Input
assert((input_pointer != nullptr));
assert((input_dim_0 > 0));
assert((input_dim_1 > 0));
assert((input_dim_2 > 0));
assert((input_dim_3 > 0));
```

## GPU

### .env File
```Makefile
PYBIN=~/P3.11/bin/
CC=/usr/lib64/ccache/clang++
NVCC=/usr/local/cuda-12/bin/nvcc -allow-unsupported-compiler 

PARAMETERS_O_CPU = -O3 -std=c++14 -fPIC -Wall -fopenmp=libomp
PARAMETERS_Linker_CPU = -shared -lm -lomp -lstdc++ -Wall

PARAMETERS_O_GPU= -O3 -std=c++14 -ccbin=$(CC) \
    -Xcompiler "-fPIC -Wall -fopenmp=libomp"   
PARAMETERS_Linker_GPU=-Xcompiler "-shared -lm -lomp -lstdc++ -Wall"

O_DIRS = o/
```

### Makefile

```Makefile
include .env
export

name = HDynamicCNN
type = GPU

PYPOSTFIX := $(shell $(PYBIN)python3-config --extension-suffix)
PYBIND11INCLUDE := $(shell $(PYBIN)python3 -m pybind11 --includes)
PARAMETERS_O = $(PARAMETERS_O_GPU) $(PYBIND11INCLUDE) 
PARAMETERS_Linker = $(PARAMETERS_Linker_GPU)

so_file = Py$(name)$(type)$(PYPOSTFIX)
pyi_file = Py$(name)$(type).pyi
all: $(so_file)

$(O_DIRS)$(name)$(type).o: $(name)$(type).h $(name)$(type).cu
	mkdir -p $(O_DIRS) 
	$(NVCC) $(PARAMETERS_O) -c $(name)$(type).cu -o $(O_DIRS)$(name)$(type).o

$(O_DIRS)Py$(name)$(type).o: $(name)$(type).h Py$(name)$(type).cpp 
	mkdir -p $(O_DIRS)
	$(NVCC) $(PARAMETERS_O) -c Py$(name)$(type).cpp -o $(O_DIRS)Py$(name)$(type).o

$(so_file): $(O_DIRS)$(name)$(type).o $(O_DIRS)Py$(name)$(type).o
	$(NVCC) $(PARAMETERS_Linker) -o $(so_file) $(O_DIRS)$(name)$(type).o $(O_DIRS)Py$(name)$(type).o


#######################
clean:
	rm -rf $(O_DIRS)
	rm -f $(so_file)
	rm -f $(pyi_file)
```

### .cu File

#### CuBlas

You want to use [cublas](https://docs.nvidia.com/cuda/cublas/index.html) if possible. 

### Create and free memory

```cpp
    cudaError_t status;
    float* w_memory = nullptr;
    status = cudaMalloc((void**)&w_memory, number_of_elements * sizeof(float));
    assert((status == cudaSuccess));
```

```cpp
    status = cudaFree(w_memory);
    assert((status == cudaSuccess));
```
### Own kernels


**Writing a working Cuda Kernel is easy. However, writing a fast one is really really hard. Beside a good Cuda code, you need a good setting for the parallelization parameters. And those depend on the problem AND the GPU you are using.**

If you really want to make your own GPU kernel, don't forget: 

```cpp
    status = cudaDeviceSynchronize();
    assert((status == cudaSuccess));
```

### Example Kernel: 

```cpp
            kernel_pxy_reciprocal<<<
                dim3(grid_and_thread_settings[ID_KERNEL_PXY_RECIPROCAL][0],
                    grid_and_thread_settings[ID_KERNEL_PXY_RECIPROCAL][1],
                    grid_and_thread_settings[ID_KERNEL_PXY_RECIPROCAL][2]),
                dim3(grid_and_thread_settings[ID_KERNEL_PXY_RECIPROCAL][3],
                    grid_and_thread_settings[ID_KERNEL_PXY_RECIPROCAL][4],
                    grid_and_thread_settings[ID_KERNEL_PXY_RECIPROCAL][5])>>>(
                        epsilon_scale_memory,
                        grid_and_thread_settings[ID_KERNEL_PXY_RECIPROCAL][6]);
```

```cpp
    occupancy_kernel_pxy_reciprocal(
        dim_x, dim_y, number_of_pattern, h_dim,
        grid_and_thread_settings[ID_KERNEL_PXY_RECIPROCAL], display_debug);
```


#### kernel_pxy_reciprocal.h

```cpp
#ifndef KERNEL_PXY_RECIPROCAL
#define KERNEL_PXY_RECIPROCAL
#include <vector>
__global__ void kernel_pxy_reciprocal(float* __restrict__ pxy_memory,
                                      size_t max_idx);

void occupancy_kernel_pxy_reciprocal(size_t dim_x, size_t dim_y,
                                     size_t number_of_pattern, size_t h_dim,
                                     std::vector<size_t>& output,
                                     bool display_debug);

#endif /* KERNEL_PXY_RECIPROCAL */
```

#### kernel_pxy_reciprocal.cu

```cpp
#include <cassert>
#include <iostream>

#include "kernel_helper_functions.h"
#include "kernel_pxy_reciprocal.h"

__global__ void kernel_pxy_reciprocal(float* __restrict__ pxy_memory,
                                      size_t max_idx) {
  size_t idx = threadIdx.x + blockIdx.x * blockDim.x;

  if (idx < max_idx) {
    pxy_memory[idx] = 1.0 / pxy_memory[idx];
  }
};

void occupancy_kernel_pxy_reciprocal(size_t dim_x, size_t dim_y,
                                     size_t number_of_pattern, size_t h_dim,
                                     std::vector<size_t>& output,
                                     bool display_debug) {
  size_t max_threadable_tasks;
  cudaError_t status;

  int min_grid_size;
  int thread_block_size;
  int grid_size;

  max_threadable_tasks = number_of_pattern * dim_x * dim_y;

  status = cudaOccupancyMaxPotentialBlockSize(
      &min_grid_size, &thread_block_size, (void*)kernel_pxy_reciprocal, 0,
      max_threadable_tasks);
  assert((status == cudaSuccess));

  grid_size =
      (max_threadable_tasks + thread_block_size - 1) / thread_block_size;

  output.resize(7);
  output[0] = grid_size;
  output[1] = 1;
  output[2] = 1;
  output[3] = thread_block_size;
  output[4] = 1;
  output[5] = 1;
  output[6] = max_threadable_tasks;

  if (display_debug == true) {
    std::cout << "kernel_pxy_reciprocal:" << std::endl;
    kernel_debug_plot(output, display_debug);
  }
};
```

#### kernel_helper_functions.h

```cpp
#ifndef KERNEL_HELPER_FUNCTIONS
#define KERNEL_HELPER_FUNCTIONS
#include <vector>

void kernel_debug_plot(std::vector<size_t> output, bool display_debug);

#endif /* KERNEL_HELPER_FUNCTIONS */
```

#### kernel_helper_functions.cu 

```cpp
#include <iostream>

#include "kernel_helper_functions.h"

void kernel_debug_plot(std::vector<size_t> output, bool display_debug) {
  if (display_debug == true) {
    std::cout << "grid x: " << output[0] << std::endl;
    std::cout << "grid y: " << output[1] << std::endl;
    std::cout << "grid z: " << output[2] << std::endl;
    std::cout << "thread block x: " << output[3] << std::endl;
    std::cout << "thread block y: " << output[4] << std::endl;
    std::cout << "thread block z: " << output[5] << std::endl;
    std::cout << "max_idx: " << output[6] << std::endl << std::endl;
  }

  return;
};
```
