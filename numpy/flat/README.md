# flat
{:.no_toc}

<nav markdown="1" class="toc-class">
* TOC
{:toc}
</nav>

## Top

Questions to [David Rotermund](mailto:davrot@uni-bremen.de)

## [numpy.ndarray.flat](https://numpy.org/doc/stable/reference/generated/numpy.ndarray.flat.html)

```python
ndarray.flat
```

> A 1-D iterator over the array.
> 
> This is a numpy.flatiter instance, which acts similarly to, but is not a subclass of, Python’s built-in iterator object.

```python
import numpy as np

a = np.arange(0, 12).reshape((4, 3))
c = np.zeros_like(a)

print(a)
print()

for i in range(0, c.size):
    c.flat[i] = a.flat[i] ** 2

print(c)
```

Output:

```python
[[ 0  1  2]
 [ 3  4  5]
 [ 6  7  8]
 [ 9 10 11]]

[[  0   1   4]
 [  9  16  25]
 [ 36  49  64]
 [ 81 100 121]]
```

## Reminder: size vs shape

### [numpy.ndarray.size](https://numpy.org/doc/stable/reference/generated/numpy.ndarray.size.html#numpy-ndarray-size)

```python
ndarray.size
```

> Number of elements in the array.
> 
> Equal to np.prod(a.shape), i.e., the product of the array’s dimensions.

### [ndarray.shape](https://numpy.org/doc/stable/reference/generated/numpy.ndarray.shape.html#numpy-ndarray-shape)

```python
ndarray.shape
```

> Tuple of array dimensions.


