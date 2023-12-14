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

## Views

### [... (Ellipsis)](https://docs.python.org/dev/library/constants.html#Ellipsis)

> The same as the ellipsis literal “...”. Special value used mostly in conjunction with extended slicing syntax for user-defined container data types. Ellipsis is the sole instance of the types.EllipsisType type.

 
