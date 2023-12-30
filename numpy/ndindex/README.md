# ndindex
{:.no_toc}

<nav markdown="1" class="toc-class">
* TOC
{:toc}
</nav>

## Top

Questions to [David Rotermund](mailto:davrot@uni-bremen.de)


## [numpy.ndindex](https://numpy.org/doc/stable/reference/generated/numpy.ndindex.html)

```python
class numpy.ndindex(*shape)[source]
```

> An N-dimensional iterator object to index arrays.
> 
> Given the shape of an array, an ndindex instance iterates over the N-dimensional index of the array. At each iteration a tuple of indices is returned, the last dimension is iterated over first.


```python
import numpy as np

for index in np.ndindex((3, 2, 1)):
    print(index)
```

Output:

```python
(0, 0, 0)
(0, 1, 0)
(1, 0, 0)
(1, 1, 0)
(2, 0, 0)
(2, 1, 0)
```
