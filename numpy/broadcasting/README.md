# [Broadcasting](https://numpy.org/devdocs/user/basics.broadcasting.html)
{:.no_toc}

<nav markdown="1" class="toc-class">
* TOC
{:toc}
</nav>

## The goal

Broadcasting: Automatic adaption of dimensions​

Questions to [David Rotermund](mailto:davrot@uni-bremen.de)

## [General broadcasting rules](https://numpy.org/devdocs/user/basics.broadcasting.html)

> When operating on two arrays, NumPy compares their shapes element-wise. It starts with the trailing (i.e. ***rightmost***) dimension and works its way left. **Two dimensions are compatible when**
> 
> * **they are equal**, or
> * **one of them is 1**.
> 
> If these conditions are not met, a ValueError: operands could not be broadcast together exception is thrown, indicating that the arrays have incompatible shapes.
> 
> **Input arrays do not need to have the same number of dimensions**. **The resulting array will have the same number of dimensions as the input array with the greatest number of dimensions**, where the size of each dimension is the largest size of the corresponding dimension among the input arrays. Note that missing dimensions are assumed to have size one.

![broadcasting_1.png](broadcasting_1.png)

Figure 1 (from [numpy.org](https://numpy.org/devdocs/user/basics.broadcasting.html)) : In the simplest example of broadcasting, the scalar b is stretched to become an array of same shape as a so the shapes are compatible for element-by-element multiplication.

![broadcasting_2.png](broadcasting_2.png)

Figure 2 (from [numpy.org](https://numpy.org/devdocs/user/basics.broadcasting.html)) : A one dimensional array added to a two dimensional array results in broadcasting if number of 1-d array elements matches the number of 2-d array columns.

![broadcasting_3.png](broadcasting_3.png)

Figure 3 (from [numpy.org](https://numpy.org/devdocs/user/basics.broadcasting.html)) : When the trailing dimensions of the arrays are unequal, broadcasting fails because it is impossible to align the values in the rows of the 1st array with the elements of the 2nd arrays for element-by-element addition.

![broadcasting_4.png](broadcasting_4.png)

Figure 4 (from [numpy.org](https://numpy.org/devdocs/user/basics.broadcasting.html)) : In some cases, broadcasting stretches both arrays to form an output array larger than either of the initial arrays.


## [Examples](https://numpy.org/devdocs/user/basics.broadcasting.html#broadcastable-arrays)

Good: 

```python
Image  (3d array): 256 x 256 x 3
Scale  (1d array):             3
Result (3d array): 256 x 256 x 3

A      (4d array):  8 x 1 x 6 x 1
B      (3d array):      7 x 1 x 5
Result (4d array):  8 x 7 x 6 x 5

A      (2d array):  5 x 4
B      (1d array):      1
Result (2d array):  5 x 4

A      (2d array):  5 x 4
B      (1d array):      4
Result (2d array):  5 x 4

A      (3d array):  15 x 3 x 5
B      (3d array):  15 x 1 x 5
Result (3d array):  15 x 3 x 5

A      (3d array):  15 x 3 x 5
B      (2d array):       3 x 5
Result (3d array):  15 x 3 x 5

A      (3d array):  15 x 3 x 5
B      (2d array):       3 x 1
Result (3d array):  15 x 3 x 5
```

Bad:

```python
A      (1d array):  3
B      (1d array):  4 # trailing dimensions do not match

A      (2d array):      2 x 1
B      (3d array):  8 x 4 x 3 # second from last dimensions mismatched
```

## at least

{: .topic-optional}
This is an optional topic!

### [numpy.atleast_1d](https://numpy.org/doc/stable/reference/generated/numpy.atleast_1d.html)

```python
numpy.atleast_1d(*arys)
```

> Convert inputs to arrays with at least one dimension.
> 
> Scalar inputs are converted to 1-dimensional arrays, whilst higher-dimensional inputs are preserved.

### [numpy.atleast_2d](https://numpy.org/doc/stable/reference/generated/numpy.atleast_2d.html)

```python
numpy.atleast_2d(*arys)
```

> View inputs as arrays with at least two dimensions.

### [numpy.atleast_3d](https://numpy.org/doc/stable/reference/generated/numpy.atleast_3d.html)

```python
numpy.atleast_3d(*arys)
```

> View inputs as arrays with at least three dimensions.


### Example

```python
import numpy as np

a = np.atleast_1d(5)
print(a.shape)  # -> (1,)
a = np.atleast_1d(a)
print(a.shape)  # -> (1,)
a = np.atleast_2d(a)
print(a.shape)  # -> (1, 1)
a = np.atleast_2d(a)
print(a.shape)  # -> (1, 1)
a = np.atleast_3d(a)
print(a.shape)  # -> (1, 1, 1)
a = np.atleast_3d(a)
print(a.shape)  # -> (1, 1, 1)

a = np.atleast_1d(np.zeros((2)))
print(a.shape)  # -> (2,)
a = np.atleast_2d(a)
print(a.shape)  # -> (1, 2)
a = np.atleast_3d(a)
print(a.shape)  # -> (1, 2, 1)


a = np.atleast_1d(np.zeros((2, 3)))
print(a.shape)  # -> (2, 3)
a = np.atleast_2d(a)
print(a.shape)  # -> (2, 3)
a = np.atleast_3d(a)
print(a.shape)  # -> (2, 3, 1)
```

## Manual broadcast : [numpy.broadcast_to](https://numpy.org/doc/stable/reference/generated/numpy.broadcast_to.html)

{: .topic-optional}
This is an optional topic!

```python
numpy.broadcast_to(array, shape, subok=False)
```

> Broadcast an array to a new shape.

```python
import numpy as np

a = np.arange(0, 3)

print(a) # -> [0 1 2]
print(a.shape) # -> (3,)

b = np.broadcast_to(a, (3,3))
print(b) 
print(b.shape) # -> (3,3)
```

Output:

```python
[[0 1 2]
 [0 1 2]
 [0 1 2]]
```

## Manual broadcast : [numpy.broadcast_arrays](https://numpy.org/doc/stable/reference/generated/numpy.broadcast_arrays.html)

{: .topic-optional}
This is an optional topic!

```python
numpy.broadcast_arrays(*args, subok=False)
```

> Broadcast any number of arrays against each other.

```python
import numpy as np

a = np.arange(0, 3).reshape(3, 1)
b = np.arange(0, 5).reshape(1, 5)

print(a.shape)  # -> (3, 1)
print(b.shape)  # -> (1, 5)

c, d = np.broadcast_arrays(a, b)
print(c.shape)  # -> (3, 5)
print(d.shape)  # -> (3, 5)

print(c)
print()
print(d)
```

Output:

```python
[[0 0 0 0 0]
 [1 1 1 1 1]
 [2 2 2 2 2]]

[[0 1 2 3 4]
 [0 1 2 3 4]
 [0 1 2 3 4]]
```
