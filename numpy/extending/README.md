# Extending an existing matrix
{:.no_toc}

<nav markdown="1" class="toc-class">
* TOC
{:toc}
</nav>

## The goal



Questions to [David Rotermund](mailto:davrot@uni-bremen.de)

## [numpy.tile](https://numpy.org/doc/stable/reference/generated/numpy.tile.html)

```python
numpy.tile(A, reps)
```

> Construct an array by repeating A the number of times given by reps.
> 
> If reps has length d, the result will have dimension of max(d, A.ndim).
> 
> If A.ndim < d, A is promoted to be d-dimensional by prepending new axes. So a shape (3,) array is promoted to (1, 3) for 2-D replication, or shape (1, 1, 3) for 3-D replication. If this is not the desired behavior, promote A to d-dimensions manually before calling this function.
> 
> If A.ndim > d, reps is promoted to A.ndim by pre-pending 1’s to it. Thus for an A of shape (2, 3, 4, 5), a reps of (2, 2) is treated as (1, 1, 2, 2).
> 
> Note : Although tile may be used for broadcasting, it is strongly recommended to use numpy’s broadcasting operations and functions.

**Very very important!!!​ First use numpy.newaxis​ to create the required additional axis and then use tile.**

Adding a new dimension:

```python
import numpy as np

a = np.arange(1, 5)

print(a)  # -> [1 2 3 4]
print(a.shape)  # -> (4,)

b = a[np.newaxis, :]
print(b.shape)  # -> (1, 4)
print(np.may_share_memory(a, b))  # -> True (View)

c = np.tile(a, (1, 1))
print(c.shape)  # -> (1, 4)
print(np.may_share_memory(a, c))  # -> False (Copy)
```

Examples:

```python
import numpy as np

a = np.arange(1, 5)[np.newaxis, :]

print(a)  # -> [[1 2 3 4]]
print(a.shape)  # -> (1, 4)

c = np.tile(a, (1, 1))
print(c)  # -> [[1 2 3 4]]
print(c.shape)  # -> (1, 4)

c = np.tile(a, (4, 1))
print(c)
print(c.shape)  # -> (4, 4)

c = np.tile(a, (1, 4))
print(c)  # -> [[1 2 3 4 1 2 3 4 1 2 3 4 1 2 3 4]]
print(c.shape)  # -> (1, 16)
```

Output: 

```python
[[1 2 3 4]
 [1 2 3 4]
 [1 2 3 4]
 [1 2 3 4]]
```

Be very careful if you haven’t newaxis-ed...​

```python
import numpy as np

a = np.arange(1, 5)

print(a)  # -> [1 2 3 4]
print(a.shape)  # -> (4,)

c = np.tile(a, (4))
print(c)  # -> [1 2 3 4 1 2 3 4 1 2 3 4 1 2 3 4]
print(c.shape)  # -> (16,)

c = np.tile(a, (1, 4))
print(c)  # -> [[1 2 3 4 1 2 3 4 1 2 3 4 1 2 3 4]]
print(c.shape)  # -> (1, 16)

c = np.tile(a, (4, 1))
print(c)
print(c.shape)  # -> (4, 4)
print()

c = np.tile(a, (4, 1, 1))
print(c) 
print(c.shape)  # -> (4, 1, 4)
print()

c = np.tile(a, (1, 4, 1))
print(c) 
print(c.shape)  # -> (1, 4, 4)
print()

c = np.tile(a, (1, 1, 4))
print(c)  # -> [[[1 2 3 4 1 2 3 4 1 2 3 4 1 2 3 4]]]
print(c.shape)  # -> (1, 1, 16)
```

Output:

```python
[[1 2 3 4]
 [1 2 3 4]
 [1 2 3 4]
 [1 2 3 4]]

[[[1 2 3 4]]

 [[1 2 3 4]]

 [[1 2 3 4]]

 [[1 2 3 4]]]

[[[1 2 3 4]
  [1 2 3 4]
  [1 2 3 4]
  [1 2 3 4]]]
```
