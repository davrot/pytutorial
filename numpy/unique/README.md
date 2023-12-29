# Unique
{:.no_toc}

<nav markdown="1" class="toc-class">
* TOC
{:toc}
</nav>

## The goal


Questions to [David Rotermund](mailto:davrot@uni-bremen.de)


## [numpy.unique](https://numpy.org/doc/stable/reference/generated/numpy.unique.html)

```python
numpy.unique(ar, return_index=False, return_inverse=False, return_counts=False, axis=None, *, equal_nan=True)
```

> Find the unique elements of an array.
> 
> Returns the sorted unique elements of an array. There are three optional outputs in addition to the unique elements:
> * the indices of the input array that give the unique values
> * the indices of the unique array that reconstruct the input array
> * the number of times each unique value comes up in the input array

**unique can be used on multi-dimensional arrays. However, the results are strange since empty places need to be filled for shaping the results into one common matrix.**

```python
import numpy as np


a = np.arange(10, 21)
print(a)  # -> [10 11 12 13 14 15 16 17 18 19 20]
idx = np.r_[0:5, 3:8]
print(idx)  # -> [0 1 2 3 4 3 4 5 6 7]
print(a[idx])  # -> [10 11 12 13 14 13 14 15 16 17]

print(np.unique(idx))  # -> [0 1 2 3 4 5 6 7]
print(np.unique(a[idx]))  # -> [10 11 12 13 14 15 16 17]
```

## There are more return arguments available 

```python
import numpy as np


a = np.r_[0:5, 3:8]
print(a)  # -> [0 1 2 3 4 3 4 5 6 7]

values, unique_index = np.unique(a, return_index=True)
_, unique_inverse = np.unique(a, return_inverse=True)
_, unique_counts = np.unique(a, return_counts=True)

print(values)  # -> [0 1 2 3 4 5 6 7]
print(unique_index)  # -> [0 1 2 3 4 7 8 9]
print(unique_inverse)  # -> [0 1 2 3 4 3 4 5 6 7]
print(unique_counts)  # -> [1 1 1 2 2 1 1 1]
```
