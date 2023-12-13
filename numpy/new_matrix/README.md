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


