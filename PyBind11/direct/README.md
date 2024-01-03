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


