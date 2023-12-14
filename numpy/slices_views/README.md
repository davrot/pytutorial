# Slices and views
{:.no_toc}

<nav markdown="1" class="toc-class">
* TOC
{:toc}
</nav>

## The goal

Sometimes we want to use or see only a part of the matrix. This can be done via slices and views

Questions to [David Rotermund](mailto:davrot@uni-bremen.de)

## 1-d slices 

We assume N as the number of elements and 1d:​

* A valid index starts at **0** and runs until N-1​
* [start:stop:step] ​
    start = 1, stop=N, step=1 ​-> this results in the sequence​ 1,2,3,...,(N-1)​
* [start:stop:1] can be shortened to [start:stop]​
* [0:stop] can be shortened to [:stop]​
* [start:N] can be shortened to [start:]​
* B = A[:] or B = A[...] gives you a view of A. B has the same shape and size of A. ​

```python
import numpy as np

a = np.arange(0, 10)
print(a[1:10:1])  # -> [1 2 3 4 5 6 7 8 9]
print(a[3:7:2])  # -> [3 5]
print(a[3:6])  # -> [3 4 5]
print(a[:6])  # -> [0 1 2 3 4 5]
print(a[5:])  # -> [5 6 7 8 9]
print(a[:])  # -> [0 1 2 3 4 5 6 7 8 9]
print(a[...])  # -> [0 1 2 3 4 5 6 7 8 9]
print(a[:9999])  # -> [0 1 2 3 4 5 6 7 8 9]
print(a[9999:])  # ->[]
```

* Negative values for start and stop are understood as N-\|start\| and N-\|stop\|
* N-1 is the last valid index. ​
* Thus A[-1] gives us the last element of A.​

Extracting a value based on a negative index: 

```python
import numpy as np

a = np.arange(0, 10)
print(a[-1])  # -> 9
print(a[-2])  # -> 8
print(a[-9])  # -> 1
print(a[-10])  # -> 0
print(a[-11])  # IndexError: index -11 is out of bounds for axis 0 with size 10
```

Extracting a slice based on a negative stop point: 

```python
import numpy as np

a = np.arange(0, 10)
print(a)  # -> [0 1 2 3 4 5 6 7 8 9]
print(a[:-1])  # -> [0 1 2 3 4 5 6 7 8]
print(a[:-5])  # -> [0 1 2 3 4]
print(a[:-8])  # -> [0 1]
print(a[:-11])  # -> []
print(a[:-12])  # -> []
print(a[:-999])  # -> []
```

Extracting a slice based on a negative start point: 

```python
import numpy as np

a = np.arange(0, 10)
print(a)  # -> [0 1 2 3 4 5 6 7 8 9]
print(a[-3:-1])  # -> [7 8]
print(a[-1:-8])  # -> []
print(a[-9999:])  # -> [0 1 2 3 4 5 6 7 8 9]
```

Negative step sizes:
```python
import numpy as np

a = np.arange(0, 10)
print(a)  # -> [0 1 2 3 4 5 6 7 8 9]
print(a[::-1])  # -> [9 8 7 6 5 4 3 2 1 0]
print(a[4:-2:-1]) # -> []
print(a[-1:5:-1]) # -> [9 8 7 6]
```

### [... (Ellipsis)](https://docs.python.org/dev/library/constants.html#Ellipsis)

> The same as the ellipsis literal “...”. Special value used mostly in conjunction with extended slicing syntax for user-defined container data types. Ellipsis is the sole instance of the types.EllipsisType type.

```python
import numpy as np

a = np.empty((2, 3, 4, 5, 6, 7, 8))
print(a.shape)  # -> (2, 3, 4, 5, 6, 7, 8)
print(a[..., 1:2].shape)  # -> (2, 3, 4, 5, 6, 7, 1)
print(a[:, :, 1:2, ...].shape)  # -> (2, 3, 1, 5, 6, 7, 8)
print(a[0, ...].shape)  # -> (3, 4, 5, 6, 7, 8)
print(a[0, ..., 0].shape)  # -> (3, 4, 5, 6, 7)
```

## Views

What does **view** mean? It means that two objects share the same memory. 

```python
import numpy as np

a = np.zeros((2, 3))
b=a
print(a)
print()
b[0,0] = 1

print(a)
```

Output

```python
[[0. 0. 0.]
 [0. 0. 0.]]

[[1. 0. 0.]
 [0. 0. 0.]]
```

a and b are not independent. If I change b this changes automatically a too. **It is of high importance to understand when a view is created.** Otherwise you will get totally wrong results.  

Operations which are known to create views are: 
* Slicing
* Reshaping
* ndarray.view()
* Transposition


* Using [start:stop:step] for slicing out segments results in a view. b = a[:-1]
* A simple assignment keeps a view as a view.​ e.g. b = a
* A mathematical operation on a view **may** create a new real ndarray. ​

### [numpy.may_share_memory](https://numpy.org/doc/stable/reference/generated/numpy.may_share_memory.html)

```python
numpy.may_share_memory(a, b, /, max_work=None)
```

> Determine if two arrays might share memory
>
> A return of True does not necessarily mean that the two arrays share any element. It just means that they might.
>
> Only the memory bounds of a and b are checked by default.

A simple example: 

```python
import numpy as np

a = np.zeros((2, 3))

b=a
print(np.may_share_memory(a,b)) # -> True  
```

```python
import numpy as np

a = np.zeros((2, 3))
b = a[1:2, 2:3]
print(np.may_share_memory(a, b))  # -> True

b = a[:, 2:3]
print(np.may_share_memory(a, b))  # -> True

b = a[:, ::2]
print(np.may_share_memory(a, b))  # -> True

b = a[0, :]
print(np.may_share_memory(a, b))  # -> True

b = a[0, 0]
print(np.may_share_memory(a, b))  # -> False
```

The a[0,0] does not create a view, because this creates an interger instead of a np.ndarray. And this kind of type conversion requires the creation of a new object. 

```python
import numpy as np

a = np.zeros((2, 3))
b = a.T
print(np.may_share_memory(a, b))  # -> True
```

Math operations normally create new objects: 

```python
import numpy as np

a = np.zeros((2, 3))
b = a**2
print(np.may_share_memory(a, b))  # -> False

b = np.exp(a)
print(np.may_share_memory(a, b))  # -> False

b = a+1
print(np.may_share_memory(a, b))  # -> False
```

## [numpy.copy](https://numpy.org/doc/stable/reference/generated/numpy.copy.html)

Using [copy()](https://numpy.org/doc/stable/reference/generated/numpy.copy.html) ensures that you continue to with *no* view. 

```python
numpy.copy(a, order='K', subok=False)
```
> Return an array copy of the given object.

```python
import numpy as np

a = np.zeros((2, 3))
b = a.copy()

print(np.may_share_memory(a, b))  # -> False

b = a[1:2, 2:3].copy()
print(np.may_share_memory(a, b))  # -> False
```

## dtype casting ([numpy.ndarray.astype](https://numpy.org/doc/stable/reference/generated/numpy.ndarray.astype.html))

dtype casting destroys / prevent views. However, don’t cast to the original dtype. Use copy() instead!

```python
ndarray.astype(dtype, order='K', casting='unsafe', subok=True, copy=True)
```

> Copy of the array, cast to a specified type.

```python
import numpy as np

a = np.zeros((2, 3))

b = a.astype(dtype=np.float32)
print(np.may_share_memory(a, b))  # -> False

b = a.astype(dtype=np.float64)
print(np.may_share_memory(a, b))  # -> False

b = a.astype(dtype=a.dtype)
print(np.may_share_memory(a, b))  # -> False
```
