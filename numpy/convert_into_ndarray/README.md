# Convert other data into numpy arrays e.g. asarray
{:.no_toc}

<nav markdown="1" class="toc-class">
* TOC
{:toc}
</nav>

## The goal



Questions to [David Rotermund](mailto:davrot@uni-bremen.de)


## [numpy.asarray](https://numpy.org/doc/stable/reference/generated/numpy.asarray.html)

```python
numpy.asarray(a, dtype=None, order=None, *, like=None)
```

The importance of **asarray**:

> Convert the input to an array.

```python
import numpy as np


a_list = [[1, 2], [3, 4]]
a_np = np.asarray(a_list)

w = np.asarray(1)

print(w.sum())  # -> 1
print(a_np.sum())  # -> 10
print(a_np > 2)

print(1.sum()) # SyntaxError: invalid decimal literal
print(a_list.sum())  # AttributeError: 'list' object has no attribute 'sum'
print(a_list > 2) # TypeError: '>' not supported between instances of 'list' and 'int'
```

Output:

```python
[[False False]
 [ True  True]]
```

## [numpy.fromiter](https://numpy.org/doc/stable/reference/generated/numpy.fromiter.html)

{: .topic-optional}
This is an optional topic!

```python
numpy.fromiter(iter, dtype, count=-1, *, like=None)
```

> Create a new 1-dimensional array from an iterable object.

## [numpy.fromfunction](https://numpy.org/doc/stable/reference/generated/numpy.fromfunction.html)

{: .topic-optional}
This is an optional topic!

```python
numpy.fromfunction(function, shape, *, dtype=<class 'float'>, like=None, **kwargs)[source]
```

> Construct an array by executing a function over each coordinate.
> 
> The resulting array therefore has a value fn(x, y, z) at coordinate (x, y, z).



## [numpy.array](https://numpy.org/doc/stable/reference/generated/numpy.array.html)

{: .topic-optional}
This is an optional topic!

Don't confuse **asarray** with **array**. **array** can be used to put a numpy structure around data. **asarray** converts the data into a numpy array. (As far as I understand...). Thus normally you don't need to touch **array**. 

```python
numpy.array(object, dtype=None, *, copy=True, order='K', subok=False, ndmin=0, like=None)
```

> Create an array.

