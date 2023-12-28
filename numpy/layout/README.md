# Memory layout of the Numpy matrices
{:.no_toc}

<nav markdown="1" class="toc-class">
* TOC
{:toc}
</nav>

## The goal

More information about the Numpy matrices and the memory structure behind it. 

Questions to [David Rotermund](mailto:davrot@uni-bremen.de)



## [Memory layouts​ (row-major vs column-major)](https://en.wikipedia.org/wiki/Row-_and_column-major_order)

C order (or row-major)

> In row-major order, the last dimension is contiguous, so that the memory-offset of this element is given by:

$$ n_{d}+N_{d}\cdot (n_{d-1}+N_{d-1}\cdot (n_{d-2}+N_{d-2}\cdot (\cdots +N_{2}n_{1})\cdots )))=\sum _{k=1}^{d}\left(\prod _{\ell =k+1}^{d}N_{\ell }\right)n_{k} $$


Fortran (or column-major)

> In column-major order, the first dimension is contiguous, so that the memory-offset of this element is given by:

$$ n_{1}+N_{1}\cdot (n_{2}+N_{2}\cdot (n_{3}+N_{3}\cdot (\cdots +N_{d-1}n_{d})\cdots )))=\sum _{k=1}^{d}\left(\prod _{\ell =1}^{k-1}N_{\ell }\right)n_{k} $$


![Row_and_column_major_order.svg](Row_and_column_major_order.svg)

[Illustration of difference between row- and column-major ordering](https://en.wikipedia.org/wiki/Row-_and_column-major_order#/media/File:Row_and_column_major_order.svg) (by CMG Lee. CC BY-SA 4.0)


## [numpy.ndarray.flags](https://numpy.org/doc/stable/reference/generated/numpy.ndarray.flags.html)

```python
ndarray.flags
```

> Information about the memory layout of the array.


Attributes:

|||
|---|---|
|C_CONTIGUOUS (C)|The data is in a single, C-style contiguous segment.|
|F_CONTIGUOUS (F)|The data is in a single, Fortran-style contiguous segment.|
|OWNDATA (O)|The array owns the memory it uses or borrows it from another object.|
|WRITEABLE (W)| The data area can be written to. Setting this to False locks the data, making it read-only. A view (slice, etc.) inherits WRITEABLE from its base array at creation time, but a view of a writeable array may be subsequently locked while the base array remains writeable. (The opposite is not true, in that a view of a locked array may not be made writeable. However, currently, locking a base object does not lock any views that already reference it, so under that circumstance it is possible to alter the contents of a locked array via a previously created writeable view onto it.) Attempting to change a non-writeable array raises a RuntimeError exception.|
|ALIGNED (A)|The data and all elements are aligned appropriately for the hardware.|
|WRITEBACKIFCOPY (X)|This array is a copy of some other array. The C-API function PyArray_ResolveWritebackIfCopy must be called before deallocating to the base array will be updated with the contents of this array.|
|FNC|F_CONTIGUOUS and not C_CONTIGUOUS.|
|FORC|F_CONTIGUOUS or C_CONTIGUOUS (one-segment test).|
|BEHAVED (B)|ALIGNED and WRITEABLE.|
|CARRAY (CA)|BEHAVED and C_CONTIGUOUS.|
|FARRAY (FA)|BEHAVED and F_CONTIGUOUS and not C_CONTIGUOUS.|


### 1d

```python
import numpy as np

a = np.zeros((1, 2))
print(a.flags)
```

Output

```python
  C_CONTIGUOUS : True
  F_CONTIGUOUS : True
  OWNDATA : True
  WRITEABLE : True
  ALIGNED : True
  WRITEBACKIFCOPY : False
```

### 2d

```python
import numpy as np

a = np.zeros((2, 2))
print(a.flags)
```

Output

```python
  C_CONTIGUOUS : True
  F_CONTIGUOUS : False
  OWNDATA : True
  WRITEABLE : True
  ALIGNED : True
  WRITEBACKIFCOPY : False
```

## C - contigousness

There are situations when you need a C_CONTIGUOUS matrix. Examples are PyBind11 and numba.  

```python
import numpy as np

a = np.arange(1, 10)

print(a.flags["C_CONTIGUOUS"])  # -> True

print(a[::1].flags["C_CONTIGUOUS"])  # -> True
print(a[::2].flags["C_CONTIGUOUS"])  # -> False

print(a[::2].copy().flags["C_CONTIGUOUS"])  # -> True
```

**You may want to make a copy of B for PyBind11 and numba or...**

## [numpy.ascontiguousarray](https://numpy.org/doc/stable/reference/generated/numpy.ascontiguousarray.html)

```python
numpy.ascontiguousarray(a, dtype=None, *, like=None)
```

> Return a contiguous array (ndim >= 1) in memory (C order).

```python
import numpy as np

a = np.arange(1, 10)

print(a.flags["C_CONTIGUOUS"])  # -> True
print(a[::2].flags["C_CONTIGUOUS"])  # -> False
print(np.ascontiguousarray(a[::2]).flags["C_CONTIGUOUS"])  # -> True
```


