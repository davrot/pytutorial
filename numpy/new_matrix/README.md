# New matrices 
{:.no_toc}

<nav markdown="1" class="toc-class">
* TOC
{:toc}
</nav>

## The goal

Making a new matrix...

Questions to [David Rotermund](mailto:davrot@uni-bremen.de)

Using **import numpy as np** is the standard. 

## Simple example -- new [np.zeros()](https://numpy.org/doc/stable/reference/generated/numpy.zeros.html)

Define the size of your new matrix with a tuple, e.g.​

```python
M = numpy.zeros((DIM_0, DIM_1, DIM_2, …))​
```

### 1d

```python
import numpy as np

M = np.zeros((2))
print(M)
```

Output:

```python
[0. 0.]
```

### 2d

```python
import numpy as np

M = np.zeros((2, 3))
print(M)
```

Output:

```python
[[0. 0. 0.]
 [0. 0. 0.]]
```

### 3d

```python
import numpy as np

M = np.zeros((2, 3, 4))
print(M)
```

Output:

```python
[[[0. 0. 0. 0.]
  [0. 0. 0. 0.]
  [0. 0. 0. 0.]]

 [[0. 0. 0. 0.]
  [0. 0. 0. 0.]
  [0. 0. 0. 0.]]]
```

## Simple example -- recycle [np.zeros_like()](https://numpy.org/doc/stable/reference/generated/numpy.zeros_like.html)

If you have a matrix with the same size ​you want then you can use zeros_like. This will also copy other properties like the data type.

as a prototype use​

N = numpy.zeros_like(M) ​

```python
import numpy as np

M = np.zeros((2, 3, 4))

N = np.zeros_like(M)
print(N)
```

Output:

```python
[[[0. 0. 0. 0.]
  [0. 0. 0. 0.]
  [0. 0. 0. 0.]]

 [[0. 0. 0. 0.]
  [0. 0. 0. 0.]
  [0. 0. 0. 0.]]]
```

## Remember unpacking

{: .topic-optional}
This is an optional topic!

```python
import numpy as np

d = (3, 4)
M = np.zeros((2, *d))

print(M)
```

## np.empty is not np.zeros

If you are sure that you don’t care about what is inside the matrix in the beginning use​

```python
M = numpy.empty((DIM_0, DIM_1, DIM_2,...))​
```

Empty claims a region in the memory and uses it for a matrix. Zeros goes one step further. It fills the memory with zeros. 

Thus random junk​ (i.e. data that was stored prior at that memory position) with be the content of a matrix if you use empty. However, np.empty() is faster than np.zeros().

```python
​import numpy as np
M = np.empty((10, 4))
print(M)
```

```python
[[1.66706425e-316 0.00000000e+000 6.89933729e-310 6.89933730e-310]
 [6.89933729e-310 6.89933730e-310 6.89933729e-310 6.89933730e-310]
 [6.89933730e-310 6.89933730e-310 6.89933729e-310 6.89933729e-310]
 [6.89933730e-310 6.89933729e-310 6.89933730e-310 6.89933729e-310]
 [6.89933730e-310 4.30513389e-317 4.30321296e-317 6.89933825e-310]
 [4.30389280e-317 6.89933822e-310 4.30366750e-317 6.89933822e-310]
 [4.30311810e-317 4.30480583e-317 4.30462401e-317 4.30336316e-317]
 [6.89933822e-310 4.30386513e-317 4.30358055e-317 4.30571886e-317]
 [4.30568724e-317 4.30659237e-317 6.89933822e-310 6.89933822e-310]
 [6.89933822e-310 6.89933822e-310 4.30289676e-317 6.89920336e-310]]
```
 

## [From shape or value](https://numpy.org/doc/stable/reference/routines.array-creation.html#from-shape-or-value)

|||
|---|---|
|[empty](https://numpy.org/doc/stable/reference/generated/numpy.empty.html#numpy.empty)(shape[, dtype, order, like])|Return a new array of given shape and type, without initializing entries.|
|[empty_like](https://numpy.org/doc/stable/reference/generated/numpy.empty_like.html#numpy.empty_like)(prototype[, dtype, order, subok, ...])|Return a new array with the same shape and type as a given array.|
|[eye](https://numpy.org/doc/stable/reference/generated/numpy.eye.html#numpy.eye)(N[, M, k, dtype, order, like])|Return a 2-D array with ones on the diagonal and zeros elsewhere.|
|[identity](https://numpy.org/doc/stable/reference/generated/numpy.identity.html#numpy.identity)(n[, dtype, like])|Return the identity array.|
|[ones](https://numpy.org/doc/stable/reference/generated/numpy.ones.html#numpy.ones)(shape[, dtype, order, like])|Return a new array of given shape and type, filled with ones.|
|[ones_like](https://numpy.org/doc/stable/reference/generated/numpy.ones_like.html#numpy.ones_like)(a[, dtype, order, subok, shape])|Return an array of ones with the same shape and type as a given array.|
|[zeros](https://numpy.org/doc/stable/reference/generated/numpy.zeros.html#numpy.zeros)(shape[, dtype, order, like])|Return a new array of given shape and type, filled with zeros.|
|[zeros_like](https://numpy.org/doc/stable/reference/generated/numpy.zeros_like.html#numpy.zeros_like)(a[, dtype, order, subok, shape])|Return an array of zeros with the same shape and type as a given array.|
|[full](https://numpy.org/doc/stable/reference/generated/numpy.full.html#numpy.full)(shape, fill_value[, dtype, order, like])|Return a new array of given shape and type, filled with fill_value.|
|[full_like](https://numpy.org/doc/stable/reference/generated/numpy.full_like.html#numpy.full_like)(a, fill_value[, dtype, order, ...])|Return a full array with the same shape and type as a given array.|
