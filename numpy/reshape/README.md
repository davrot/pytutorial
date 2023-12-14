# Reshape, flatten 
{:.no_toc}

<nav markdown="1" class="toc-class">
* TOC
{:toc}
</nav>

## The goal


Questions to [David Rotermund](mailto:davrot@uni-bremen.de)

## [Reshape](https://numpy.org/doc/stable/reference/generated/numpy.reshape.html)

```python
numpy.reshape(a, newshape, order='C')
```

> Gives a new shape to an array without changing its data.

> **a** : array_like
>   Array to be reshaped.

> **newshape** : int or tuple of ints
>   The new shape should be compatible with the original shape. If an integer, then the result will be a 1-D array of that length. One shape dimension can be -1. In this case, the value is inferred from the length of the array and remaining dimensions.

> **order** : {‘C’, ‘F’, ‘A’}, **optional**
>   Read the elements of a using this index order, and place the elements into the reshaped array using this index order. ‘C’ means to read / write the elements using C-like index order, with the last axis index changing fastest, back to the first axis index changing slowest. ‘F’ means to read / write the elements using Fortran-like index order, with the first index changing fastest, and the last index changing slowest. Note that the ‘C’ and ‘F’ options take no account of the memory layout of the underlying array, and only refer to the order of indexing. ‘A’ means to read / write the elements in Fortran-like index order if a is Fortran contiguous in memory, C-like order otherwise.

Example:

```python
import numpy as np

a = np.arange(0, 15)

b_2d = np.reshape(a, (5, 3))

print(f"View: {np.may_share_memory(a, b_2d)}") # -> View: True
print(b_2d.shape) # -> (5, 3)
print(b_2d)
```

Output: 
```python
[[ 0  1  2]
 [ 3  4  5]
 [ 6  7  8]
 [ 9 10 11]
 [12 13 14]]
```

![image0](image0.png)

**Highest dimension is continuously filled first.**



