# The fast and furious way
{:.no_toc}

<nav markdown="1" class="toc-class">
* TOC
{:toc}
</nav>

## Top

Let us assume that you know what you are doing. And also let us assume that you notices how extremely slow the "correct" way of communication between Python and C++ is. Well the following section is for you...

Questions to [David Rotermund](mailto:davrot@uni-bremen.de)



## On the Python side

```python
# If it is a torch tensor then make a "view" to its numpy core
np_input: np.ndarray = input.contiguous().detach().numpy()

# We need to make sure that the numpy ndarray is C_CONTIGUOUS. 
# If not then use numpy.ascontiguousarray() to make it so
assert np_input.flags["C_CONTIGUOUS"] is True

# Input is a 4d ndarray. And I will make sure that this is really the case
assert np_input.ndim == 4

# Now I extract the pointer to the data memory of the ndarray 
np_input_pointer, _ = np_input.__array_interface__["data"]

# Also I need the shape information for the C++ program. 
np_input_dim_0: int = np_input.shape[0]
np_input_dim_1: int = np_input.shape[1]
np_input_dim_2: int = np_input.shape[2]
np_input_dim_3: int = np_input.shape[3]
```

## On the C++ side

Your C++ method needs to accept these arguments

```cpp
int64_t np_input_pointer_addr, 
int64_t np_input_dim_0,
int64_t np_input_dim_1, 
int64_t np_input_dim_2, 
int64_t np_input_dim_3,
```

Inside your C++ method you convert the address into a pointer. **BE WARNED:** Make absolutely sure that the dtype of the np.ndarray is correctly reflected in the pointer type

dtype=np.float32 --> float
dtype=np.float64 --> double
dtype=np.uint64 --> uint64

If you fuck this up then this will end in tears!

```cpp
float *np_input_pointer = (float *)np_input_pointer_addr;

// Input
assert((np_input_pointer != nullptr));
assert((np_input_dim_0 > 0));
assert((np_input_dim_1 > 0));
assert((np_input_dim_2 > 0));
assert((np_input_dim_3 > 0));
```

Don't forget that C Contiguous is just a complicated way of saying Row-major order memory layout [Row- and column-major order](https://en.wikipedia.org/wiki/Row-_and_column-major_order).

$$M[a,b,c,d] = M[\eta_a \cdot a + \eta_b \cdot  b + \eta_c \cdot  c + d]$$

with

$$\eta_c = n_d$$

$$\eta_b = \eta_c \cdot n_c$$

$$\eta_a = \eta_b \cdot n_b$$
