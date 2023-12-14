# Advanced Indexing
{:.no_toc}

<nav markdown="1" class="toc-class">
* TOC
{:toc}
</nav>

## The goal

Beside slicing there is something called advanced indexing 

Questions to [David Rotermund](mailto:davrot@uni-bremen.de)

## Boolean Array​

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

## Index vs Slices / Views

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

## Advanced Indexing

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
b = a[[0, 1, 3], [0, 1, 2]] # -> IndexError: index 3 is out of bounds for axis 0 with size 3
```
