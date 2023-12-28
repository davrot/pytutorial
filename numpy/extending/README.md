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

**You might want to first use numpy.newaxis​ to create the required additional axis and then use tile.**

Adding a new dimension makes a copy:

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

### Don’t confuse tile() with repeat()!​

```python
numpy.repeat(a, repeats, axis=None)[source]
```

> Repeat each element of an array after themselves

```python
import numpy as np

a = np.arange(1, 5)
print(a)  # -> [1 2 3 4]
print(a.shape)  # -> (4,)

b = np.repeat(a, (4))
print(b)  # -> [1 1 1 1 2 2 2 2 3 3 3 3 4 4 4 4]
print(b.shape)  # -> (16,)
```

## [numpy.pad](https://numpy.org/doc/stable/reference/generated/numpy.pad.html)

```python
numpy.pad(array, pad_width, mode='constant', **kwargs)
```

> Pad an array.

> **pad_width** : {sequence, array_like, int}
> 
> Number of values padded to the edges of each axis. ((before_1, after_1), ... (before_N, after_N)) unique pad widths for each axis. (before, after) or ((before, after),) yields same before and after pad for each axis. (pad,) or int is a shortcut for before = after = pad width for all axes.

> **constant_values** : sequence or scalar, optional
> 
> Used in ‘constant’. The values to set the padded values for each axis.
> 
> ((before_1, after_1), ... (before_N, after_N)) unique pad constants for each axis.
> 
> (before, after) or ((before, after),) yields same before and after constants for each axis.
> 
> (constant,) or constant is a shortcut for before = after = constant for all axes.
> 
> Default is 0.

```python
import numpy as np

a = np.arange(1, 5)
print(a)  # -> [1 2 3 4]
print(a.shape)  # -> (4,)


print(np.pad(a, 2))  # -> [0 0 1 2 3 4 0 0]
print(np.pad(a, [2, 3]))  # -> [0 0 1 2 3 4 0 0 0]
print(np.pad(a, [2, 3], constant_values=-1))  # -> [-1 -1  1  2  3  4 -1 -1 -1]
```

```python
import numpy as np

a = np.arange(1, 5).reshape((1, 4))
print(a)  # -> [[1 2 3 4]]
print(a.shape)  # -> (1, 4)


print(np.pad(a, [[2, 3], [1, 1]]))
```

Output:
```python
[[0 0 0 0 0 0]
 [0 0 0 0 0 0]
 [0 1 2 3 4 0]
 [0 0 0 0 0 0]
 [0 0 0 0 0 0]
 [0 0 0 0 0 0]]
```

### Pad can do more complex padding patterns than just pad with constant values!

> **mode** : str or function, optional
> 
> One of the following string values or a user supplied function.

|||
|---|---|
|‘constant’ (default)|Pads with a constant value.|
|‘edge’|Pads with the edge values of array.|
|‘linear_ramp’|Pads with the linear ramp between end_value and the array edge value.|
|‘maximum’|Pads with the maximum value of all or part of the vector along each axis.|
|‘mean’|Pads with the mean value of all or part of the vector along each axis.|
|‘median’|Pads with the median value of all or part of the vector along each axis.|
|‘minimum’|Pads with the minimum value of all or part of the vector along each axis.|
|‘reflect’|Pads with the reflection of the vector mirrored on the first and last values of the vector along each axis.|
|‘symmetric’|Pads with the reflection of the vector mirrored along the edge of the array.|
|‘wrap’|Pads with the wrap of the vector along the axis. The first values are used to pad the end and the end values are used to pad the beginning.|
|‘empty’|Pads with undefined values.|
|<function>|Padding function, see Notes.|
