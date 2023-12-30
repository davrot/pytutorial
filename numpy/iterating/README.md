# Iterating over an array
{:.no_toc}

<nav markdown="1" class="toc-class">
* TOC
{:toc}
</nav>

## The goal



Questions to [David Rotermund](mailto:davrot@uni-bremen.de)

{: .topic-optional}
This is an optional topic!



## [numpy.apply_along_axis](https://numpy.org/doc/stable/reference/generated/numpy.apply_along_axis.html)

```python
numpy.apply_along_axis(func1d, axis, arr, *args, **kwargs)
```

> Apply a function to 1-D slices along the given axis.
> 
> Execute func1d(a, *args, **kwargs) where func1d operates on 1-D arrays and a is a 1-D slice of arr along axis.
> 
> This is equivalent to (but faster than) the following use of ndindex and s_, which sets each of ii, jj, and kk to a tuple of indices:

```python
Ni, Nk = a.shape[:axis], a.shape[axis+1:]
for ii in ndindex(Ni):
    for kk in ndindex(Nk):
        f = func1d(arr[ii + s_[:,] + kk])
        Nj = f.shape
        for jj in ndindex(Nj):
            out[ii + jj + kk] = f[jj]
```

> Equivalently, eliminating the inner loop, this can be expressed as:

```python
Ni, Nk = a.shape[:axis], a.shape[axis+1:]
for ii in ndindex(Ni):
    for kk in ndindex(Nk):
        out[ii + s_[...,] + kk] = func1d(arr[ii + s_[:,] + kk])
```

### Example

```python
import numpy as np


def function_1d(input):
    print(f"input shape: {input.shape}, input: {input}")
    return input + input.shape[0]


a = np.arange(1, 13).reshape(3, 4)
print(a)
print(a.shape)  # -> (3, 4)
print()

print("******")
b = np.apply_along_axis(function_1d, axis=0, arr=a)
print("******")
print()

print(b)
print(b.shape)  # -> (3, 4)
print()

print("++++++")
b = np.apply_along_axis(function_1d, axis=1, arr=a)
print("++++++")
print()

print(b)
print(b.shape)  # -> (3, 4)
```

Output:

```python
[[ 1  2  3  4]
 [ 5  6  7  8]
 [ 9 10 11 12]]


******
input shape: (3,), input: [1 5 9]
input shape: (3,), input: [ 2  6 10]
input shape: (3,), input: [ 3  7 11]
input shape: (3,), input: [ 4  8 12]
******

[[ 4  5  6  7]
 [ 8  9 10 11]
 [12 13 14 15]]

++++++
input shape: (4,), input: [1 2 3 4]
input shape: (4,), input: [5 6 7 8]
input shape: (4,), input: [ 9 10 11 12]
++++++

[[ 5  6  7  8]
 [ 9 10 11 12]
 [13 14 15 16]]
```
