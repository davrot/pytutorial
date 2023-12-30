# trim_zeros
{:.no_toc}

<nav markdown="1" class="toc-class">
* TOC
{:toc}
</nav>

## Top

Questions to [David Rotermund](mailto:davrot@uni-bremen.de)


## [numpy.trim_zeros](https://numpy.org/doc/stable/reference/generated/numpy.trim_zeros.html)

```python
numpy.trim_zeros(filt, trim='fb')
```

> Trim the leading and/or trailing zeros from a 1-D array or sequence.

```python
import numpy as np

a = np.arange(0, 10)
b = np.zeros((5), dtype=np.int64)
c = np.r_[b, a, b]
print(c)  # -> [0 0 0 0 0 0 1 2 3 4 5 6 7 8 9 0 0 0 0 0]

print(np.trim_zeros(c, "b")) # -> [0 0 0 0 0 0 1 2 3 4 5 6 7 8 9]
print(np.trim_zeros(c, "f")) # -> [1 2 3 4 5 6 7 8 9 0 0 0 0 0]
print(np.trim_zeros(c, "fb")) # -> [1 2 3 4 5 6 7 8 9]
```

