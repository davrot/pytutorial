# Advanced Indexing
{:.no_toc}

<nav markdown="1" class="toc-class">
* TOC
{:toc}
</nav>

## The goal

Beside slicing there is something called advanced indexing 

Questions to [David Rotermund](mailto:davrot@uni-bremen.de)

## [Boolean Array​](https://numpy.org/doc/stable/user/basics.indexing.html#boolean-array-indexing)

We can use Boolean arrays for more complicate indexing: 

```python
import numpy as np

a = np.arange(1,10).reshape(3,3)
b = np.zeros_like(a)

b[a.sum(axis=1) > 6, :] = 1

print(a)
print()
print(b)
```

Output:

```python
[[1 2 3]
 [4 5 6]
 [7 8 9]]

[[0 0 0]
 [1 1 1]
 [1 1 1]]
```

Behind the curtains more or less this happens:​

```python
import numpy as np

a = np.arange(1, 10).reshape(3, 3)
b = np.zeros_like(a)

temp_0 = a.sum(axis=1)
temp_1 = temp_0 > 6
temp_2 = np.nonzero(temp_1)
b[temp_2] = 1

print(temp_0)
print()
print(temp_1)
print()
print(temp_2)
print()
print(b)
```

Output:

```python
[ 6 15 24]

[False  True  True]

(array([1, 2]),)

[[0 0 0]
 [1 1 1]
 [1 1 1]]
```

## [Basic indexing](https://numpy.org/doc/stable/user/basics.indexing.html#basics-indexing) vs [Slices](https://numpy.org/doc/stable/user/basics.indexing.html#slicing-and-striding) / Views

If we get put indices in we get a non-view out. This procedure is called indexing: 

```python
import numpy as np

a = np.arange(0, 10)
idx = np.arange(2,5)
b = a[idx]

print(idx) # -> [2 3 4]
print()
print(b) # -> [2 3 4]
print()
print(np.may_share_memory(a,b)) # -> False
```

While this is called slicing:

```python
import numpy as np

a = np.arange(0, 10)
b = a[2:5]

print(b)  # -> [2 3 4]
print()
print(np.may_share_memory(a, b))  # -> True
```

As you can see lies the biggest different in the creation of a view when we use slicing. Indexing creates a new object instead. 

## [Advanced Indexing](https://numpy.org/doc/stable/user/basics.indexing.html#advanced-indexing)

### 1-d indices

In the following we address the matrix **a** accoring **ndarray[[First dim],​ [Second dim]​, [... more dims if your array has them]]​**:

```python
import numpy as np

a = np.arange(0, 9).reshape((3, 3))
print(a)
print()

b = a[[0, 1, 2], [0, 1, 2]]
print(b)
```

Output:

```python
[[0 1 2]
 [3 4 5]
 [6 7 8]]

[0 4 8]
```
Errors are punished via exceptions​ and not silently and creatively circumvented like with slices​:

```python
import numpy as np
a = np.arange(0, 9).reshape((3, 3))
b = a[[0, 1, 3], [0, 1, 2]] # IndexError: index 3 is out of bounds for axis 0 with size 3
```

### n-d indices

Other shapes and repetitions are acceptable too:

```python
import numpy as np

a = np.arange(0, 4).reshape((2, 2))

idx_0 = [[1, 1], [1, 1]]
idx_1 = [[0, 0], [0, 0]]

print(a[idx_0, idx_1])
```

Output:

```python
[[2 2]
 [2 2]]
```

## Advanced slices​

A combination of indexing and slicing can be done but requires some thought. Otherwise it can be confusing like here: 

```python
import numpy as np

a = np.arange(1, 28).reshape(3, 3, 3)
idx = [[1, 1], [1, 1]]

print(a[:, idx, :].shape) # -> (3, 2, 2, 3)
```

You want another example?

```python
import numpy as np

a = np.empty((10, 20, 30, 40, 50))


idx_0 = np.ones((2, 3, 4), dtype=int)
idx_1 = np.ones((2, 3, 4), dtype=int)

print(a[:, idx_0, idx_1].shape)  # -> (10, 2, 3, 4, 40, 50)
print(a[:, idx_0, :, idx_1].shape)  # -> (2, 3, 4, 10, 30, 50)
```
