# Resize: Compensation for bad planning?
{:.no_toc}

<nav markdown="1" class="toc-class">
* TOC
{:toc}
</nav>

## Top

Questions to [David Rotermund](mailto:davrot@uni-bremen.de)

**Try to avoid using this function!** Do better planning. 


Resize does its work on the linear memory segment.
* If it is resized to a bigger array, the beginning of the original memory segment is copied into the new end segment.
* If it is resized to a smaller array, the memory segment is shrunken by cutting of the end.

## [numpy.resize](https://numpy.org/doc/stable/reference/generated/numpy.resize.html)

```python
numpy.resize(a, new_shape)
```

> Return a new array with the specified shape.
> 
> If the new array is larger than the original array, then the new array is filled with repeated copies of a. Note that this behavior is different from a.resize(new_shape) which fills with zeros instead of repeated copies of a.

```python
import numpy as np

a = np.arange(1, 10).reshape((3, 3))
print(a)
print()
b = np.resize(a, (2, 3))
print(b)
print()
b = np.resize(a, (3, 1))
print(b)
print()
b = np.resize(a, (5, 5))
print(b)
```

Output:

```python
[[1 2 3]
 [4 5 6]
 [7 8 9]]

[[1 2 3]
 [4 5 6]]

[[1]
 [2]
 [3]]

[[1 2 3 4 5]
 [6 7 8 9 1]
 [2 3 4 5 6]
 [7 8 9 1 2]
 [3 4 5 6 7]]
```

## This is not [numpy.ndarray.resize](https://numpy.org/doc/stable/reference/generated/numpy.ndarray.resize.html#numpy.ndarray.resize)

```python
ndarray.resize(new_shape, refcheck=True)
```

> Change shape and size of array in-place.

I added a copy because it does not work on views (*ValueError: cannot resize this array: it does not own its data*) , which reshape creates. 

```python
import numpy as np

a = np.arange(1, 10).reshape((3, 3)).copy()
print(a)
print()
a.resize((5, 5))
print(a)
```

Output:

```python
[[1 2 3]
 [4 5 6]
 [7 8 9]]

[[1 2 3 4 5]
 [6 7 8 9 0]
 [0 0 0 0 0]
 [0 0 0 0 0]
 [0 0 0 0 0]]
```

