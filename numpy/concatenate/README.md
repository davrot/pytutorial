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
### More r_

```python
import numpy as np

a = np.arange(0, 10)
print(a.shape)  # -> (10,)
b = np.arange(0, 10)
print(b.shape)  # -> (10,)

c = np.r_[a, b]
print(c.shape)  # -> (20,)
c = np.r_["-1", a, b]
print(c.shape)  # -> (20,)
c = np.r_["0, 2", a, b]
print(c.shape)  # -> (2, 10)
c = np.r_["1, 2", a, b]
print(c.shape)  # -> (1, 20)

c = np.r_["0, 1", a, b]
print(c.shape)  # -> (20,)
c = np.r_["0, 2", a, b]
print(c.shape)  # -> (2, 10)
c = np.r_["0, 3", a, b]
print(c.shape)  # -> (2, 1, 10)

c = np.r_["r", a, b]  # r == row
print(c.shape)  # -> (1, 20)
c = np.r_["c", a, b]  # c == column
print(c.shape)  # -> (20, 1)
```

### Producing index arrays​ with r_

```python
import numpy as np

idx = np.r_[2:10, 20:100, 10]
print(idx)
print(idx.shape)  # -> (89,)
```

Output: 

```python
[ 2  3  4  5  6  7  8  9 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35
 36 37 38 39 40 41 42 43 44 45 46 47 48 49 50 51 52 53 54 55 56 57 58 59
 60 61 62 63 64 65 66 67 68 69 70 71 72 73 74 75 76 77 78 79 80 81 82 83
 84 85 86 87 88 89 90 91 92 93 94 95 96 97 98 99 10]
```

**If we use idx for indexing a matrix/ array then we use indexing and not slicing.** 

### Producing index arrays​ with [numpy.s_](https://numpy.org/doc/stable/reference/generated/numpy.s_.html)

```python
numpy.s_ = <numpy.lib.index_tricks.IndexExpression object>
```
> A nicer way to build up index tuples for arrays.

s_ is a simpler alternative to [slice](https://docs.python.org/dev/library/functions.html#slice): 

```python
class slice(stop)
class slice(start, stop, step=None)
```

> Return a slice object representing the set of indices specified by range(start, stop, step). The start and step arguments default to None.
> 
> Slice objects have read-only data attributes start, stop, and step which merely return the argument values (or their default). They have no other explicit functionality; however, they are used by NumPy and other third-party packages.
> 
> Slice objects are also generated when extended indexing syntax is used. For example: a[start:stop:step] or a[start:stop, i]. 

```python
import numpy as np

idx = np.s_[2:10, 20:100, 10]
print(idx) # -> (slice(2, 10, None), slice(20, 100, None), 10)

data = np.zeros((20, 101, 11))
x = data[idx]
print(x.shape) # -> (8, 80)
```


## [numpy.c_](https://numpy.org/doc/stable/reference/generated/numpy.c_.html)

{: .topic-optional}
This is an optional topic!

```python
numpy.c_ = <numpy.lib.index_tricks.CClass object>
```

> Translates slice objects to concatenation along the second axis.
> 
> This is short-hand for np.r_['-1,2,0', index expression], which is useful because of its common occurrence. In particular, arrays will be stacked along their last axis after being upgraded to at least 2-D with 1’s post-pended to the shape (column vectors made out of 1-D arrays).

```python
import numpy as np

a = np.arange(0, 10)
print(a.shape)  # -> (10,)
b = np.arange(0, 10)
print(b.shape)  # -> (10,)

c = np.c_[a, b]
print(c.shape)  # -> (10,2)
```


