# Concatenate
{:.no_toc}

<nav markdown="1" class="toc-class">
* TOC
{:toc}
</nav>

## The goal


Questions to [David Rotermund](mailto:davrot@uni-bremen.de)

## [numpy.concatenate]()

```python
numpy.concatenate((a1, a2, ...), axis=0, out=None, dtype=None, casting="same_kind")
```

> Join a sequence of arrays along an existing axis.

```python
import numpy as np

a = np.arange(0, 5)
print(a)  # -> [0 1 2 3 4]
print(a.shape)  # -> (5,)
b = np.arange(0, 8)
print(b)  # -> [0 1 2 3 4 5 6 7]
print(b.shape)  # -> (8,)

c = np.concatenate((a, b))
print(c)  # -> [0 1 2 3 4 0 1 2 3 4 5 6 7]
print(c.shape)  # -> (13,)
print(np.may_share_memory(a, c))  # -> False (Copy)

c = np.concatenate((a, b), axis=0)
print(c)  # -> [0 1 2 3 4 0 1 2 3 4 5 6 7]
print(c.shape)  # -> (13,)
print(np.may_share_memory(a, c))  # -> False (Copy)

c = np.concatenate(
    (a, b), axis=1
)  # AxisError: axis 1 is out of bounds for array of dimension 1
```

concatenate does not add necessary dimensions, you have to do that yourself: 

```python
import numpy as np

a = np.arange(0, 10)
print(a.shape)  # -> (10,)
b = np.arange(0, 10)
print(b.shape)  # -> (10,)

c = np.concatenate((a, b), axis=0)
print(c.shape)  # -> (20,)

c = np.concatenate((a, b), axis=1)  # AxisError: axis 1 is out of bounds for array of dimension 1
```


```python
import numpy as np

a = np.arange(0, 10)[:, np.newaxis]
print(a.shape)  # -> (10,1)
b = np.arange(0, 10)[:, np.newaxis]
print(b.shape)  # -> (10,1)

c = np.concatenate((a, b), axis=0)
print(c.shape)  # -> (20,1)

c = np.concatenate((a, b), axis=1)
print(c)
print(c.shape)  # -> (10,2)
```

Output:

```python
[[0 0]
 [1 1]
 [2 2]
 [3 3]
 [4 4]
 [5 5]
 [6 6]
 [7 7]
 [8 8]
 [9 9]]
```

## [numpy.r_](https://numpy.org/doc/stable/reference/generated/numpy.r_.html)

{: .topic-optional}
This is an optional topic!

```python
numpy.r_ = <numpy.lib.index_tricks.RClass object>
```

> Translates slice objects to concatenation along the first axis.

```python
import numpy as np

a = np.arange(0, 10)
print(a.shape)  # -> (10,)
b = np.arange(0, 10)
print(b.shape)  # -> (10,)

c = np.r_[a, b]
print(c.shape)  # -> (20,)
```


## [numpy.c_](https://numpy.org/doc/stable/reference/generated/numpy.c_.html)

{: .topic-optional}
This is an optional topic!

```python
numpy.c_ = <numpy.lib.index_tricks.CClass object>
```




