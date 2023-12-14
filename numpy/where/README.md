# Where
{:.no_toc}

<nav markdown="1" class="toc-class">
* TOC
{:toc}
</nav>

## The goal

**where** allows to modifiy or combine matricies based on a given condition. 

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

We are using where is this mode: 

```python
idx = numpy.where(condition)
```

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

## Using conditions

```python
numpy.where(condition, x, y)
```

## Identity

In this example nothing happens because independent of the condition the value from **a** is used: 

```python
import numpy as np

a = np.arange(0, 15).reshape((5, 3))

a = np.where(a > 7, a, a)
print(a)
```

Output:

```python
[[ 0  1  2]
 [ 3  4  5]
 [ 6  7  8]
 [ 9 10 11]
 [12 13 14]]
```

## x is a number

```python
import numpy as np

a = np.arange(0, 15).reshape((5, 3))

a = np.where(a > 7, 42, a)
print(a)
```

Output:

```python
[[ 0  1  2]
 [ 3  4  5]
 [ 6  7 42]
 [42 42 42]
 [42 42 42]]
```

## y is a number

```python
import numpy as np

a = np.arange(0, 15).reshape((5, 3))

a = np.where(a > 7, a, 42)
print(a)
```

Output:

```python
[[42 42 42]
 [42 42 42]
 [42 42  8]
 [ 9 10 11]
 [12 13 14]]
```

## x and y are numbers

```python
import numpy as np

a = np.arange(0, 15).reshape((5, 3))

a = np.where(a > 7, 0, 42)
print(a)
```

Output:
```python
[[42 42 42]
 [42 42 42]
 [42 42  0]
 [ 0  0  0]
 [ 0  0  0]]
```

## x and y are matricies

x and y (if both are matricies) need the same size as the conditon has.

```python
import numpy as np

a = np.arange(0, 15).reshape((5, 3))

b = np.arange(15, 30).reshape((5, 3))
c = np.arange(30, 45).reshape((5, 3))

a = np.where(a > 7, b, c)
print(a)
```

Output:

```python
[[30 31 32]
 [33 34 35]
 [36 37 23]
 [24 25 26]
 [27 28 29]]
```
