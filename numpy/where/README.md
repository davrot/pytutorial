# Where
{:.no_toc}

<nav markdown="1" class="toc-class">
* TOC
{:toc}
</nav>

## The goal



Questions to [David Rotermund](mailto:davrot@uni-bremen.de)

## [numpy.where](https://numpy.org/doc/stable/reference/generated/numpy.where.html)

```python
numpy.where(condition, [x, y, ]/)
```
> Return elements chosen from x or y depending on condition.

> **condition** : array_like, bool
>   Where True, yield x, otherwise yield y.

> **x**, **y** : array_like
>  Values from which to choose. x, y and condition need to be broadcastable to some shape.

## Finding indices 

### 2d example

```python
import numpy as np

a = np.arange(0, 15).reshape((5, 3))

print(a)
print()

w = np.where(a > 7)
print(w)
```

Output:

```python
[[ 0  1  2]
 [ 3  4  5]
 [ 6  7  8]
 [ 9 10 11]
 [12 13 14]]

(array([2, 3, 3, 3, 4, 4, 4]), array([2, 0, 1, 2, 0, 1, 2]))
```

### 3d example

```python
import numpy as np

a = np.arange(0, 30).reshape((5, 3, 2))

w = np.where(a > 15)
print(w)
```

Output:

```python
(array([2, 2, 3, 3, 3, 3, 3, 3, 4, 4, 4, 4, 4, 4]), array([2, 2, 0, 0, 1, 1, 2, 2, 0, 0, 1, 1, 2, 2]), array([0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1]))
```

Using the found indices: 

```python
import numpy as np

a = np.arange(0, 30).reshape((5, 3, 2))

idx = np.where(a > 15)
a[idx] = 42
print(a)
```

Output: 

```python
[[[ 0  1]
  [ 2  3]
  [ 4  5]]

 [[ 6  7]
  [ 8  9]
  [10 11]]

 [[12 13]
  [14 15]
  [42 42]]

 [[42 42]
  [42 42]
  [42 42]]

 [[42 42]
  [42 42]
  [42 42]]]
```

```python
import numpy as np

a = np.arange(0, 30).reshape((5, 3, 2))

a[np.where(a > 15)] = 42
print(a)
```
