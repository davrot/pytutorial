# Piecewise
{:.no_toc}

<nav markdown="1" class="toc-class">
* TOC
{:toc}
</nav>

## Top

Questions to [David Rotermund](mailto:davrot@uni-bremen.de)

## [numpy.piecewise](https://numpy.org/doc/stable/reference/generated/numpy.piecewise.html)

```python
numpy.piecewise(x, condlist, funclist, *args, **kw)
```

> Evaluate a piecewise-defined function.
> 
> Given a set of conditions and corresponding functions, evaluate each function on the input data wherever its condition is true.

```python
import numpy as np

a = np.arange(1, 11)
b = np.piecewise(a, [a < 5, a == 0, a > 5], [-1, 0, 1])

print(a)  # -> [ 1  2  3  4  5  6  7  8  9 10]
print(b)  # -> [-1 -1 -1 -1  0  1  1  1  1  1]
```


