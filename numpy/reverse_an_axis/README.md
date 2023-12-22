# Reverse an axis
{:.no_toc}

<nav markdown="1" class="toc-class">
* TOC
{:toc}
</nav>

## The goal


Questions to [David Rotermund](mailto:davrot@uni-bremen.de)

## [numpy.flip](https://numpy.org/doc/stable/reference/generated/numpy.flip.html)

```python
numpy.flip(m, axis=None)
```

> Reverse the order of elements in an array along the given axis.
> 
> The shape of the array is preserved, but the elements are reordered.
>
> **m** : array_like
>
> Input array.
> 
> **axis** : None or int or tuple of ints, optional
> 
> Axis or axes along which to flip over. The default, axis=None, will flip over all of the axes of the input array. If axis is negative it counts from the last to the first axis.
> 
> If axis is a tuple of ints, flipping is performed on all of the axes specified in the tuple.
>
> **out** : array_like
> 
> A **view** of m with the entries of axis reversed. Since a view is returned, this operation is done in constant time.

### 1d

```python
import numpy as np

a = np.arange(0, 6)
print(a) # -> [0 1 2 3 4 5]
print()
print(np.flip(a)) # -> [5 4 3 2 1 0]
print()
print(a[::-1]) # -> [5 4 3 2 1 0]
```

### 2d

```python
import numpy as np

a = np.arange(0, 6).reshape((2, 3))
print(a)
print()
print(np.flip(a))
print()
print(np.flip(a, axis=0))
print()
print(np.flip(a, axis=1))
```

Output:

```python
[[0 1 2]
 [3 4 5]]

[[5 4 3]
 [2 1 0]]

[[3 4 5]
 [0 1 2]]

[[2 1 0]
 [5 4 3]]
```

## [numpy.rot90](https://numpy.org/doc/stable/reference/generated/numpy.rot90.html)

```python
numpy.rot90(m, k=1, axes=(0, 1))
```

> Rotate an array by 90 degrees in the plane specified by axes.
> 
> Rotation direction is from the first towards the second axis. This means for a 2D array with the default k and axes, the rotation will be counterclockwise.

```python
import numpy as np

a = np.arange(0, 6).reshape((2, 3))
print(a)
print()
print(np.rot90(a, k=1))
print()
print(np.rot90(a, k=2))
print()
print(np.rot90(a, k=3))
print()
print(np.rot90(a, k=4))
print()
```

Output

```python
[[0 1 2]
 [3 4 5]]

[[2 5]
 [1 4]
 [0 3]]

[[5 4 3]
 [2 1 0]]

[[3 0]
 [4 1]
 [5 2]]

[[0 1 2]
 [3 4 5]]
```
