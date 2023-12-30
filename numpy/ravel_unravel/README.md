# Ravel and UnRavel
{:.no_toc}

<nav markdown="1" class="toc-class">
* TOC
{:toc}
</nav>

## Top

Questions to [David Rotermund](mailto:davrot@uni-bremen.de)

## [numpy.ravel_multi_index](https://numpy.org/doc/stable/reference/generated/numpy.ravel_multi_index.html)

```python
numpy.ravel_multi_index(multi_index, dims, mode='raise', order='C')
```

> Converts a tuple of index arrays into an array of flat indices, applying boundary modes to the multi-index.

```python
import numpy as np

idx = np.ravel_multi_index(([0, 1, 2], [0, 1, 1]), dims=(3, 2))
print(idx)  # -> [0 3 5]

a = np.zeros((3, 2))
a.flat[idx] = 1
print(a)
print()

a = np.zeros((3, 2))
a.flat[idx] = np.arange(1, idx.shape[0] + 1)
print(a)
```

Output:

```python
[[1. 0.]
 [0. 1.]
 [0. 1.]]

[[1. 0.]
 [0. 2.]
 [0. 3.]]
```


## [numpy.unravel_index](https://numpy.org/doc/stable/reference/generated/numpy.unravel_index.html)

```python
numpy.unravel_index(indices, shape, order='C')
```

> Converts a flat index or array of flat indices into a tuple of coordinate arrays.




