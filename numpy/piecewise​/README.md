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
Instead of values we can use functions (Or you can use lambda functions...​): 

```python
import numpy as np


def function_a(input):
    return input**2


def function_b(input):
    return np.sqrt(input)


a = np.arange(1, 11)
b = np.piecewise(a, [a < 5, a == 0, a > 5], [function_a, 0, function_b])

print(a)  # -> [ 1  2  3  4  5  6  7  8  9 10]
print(b)  # -> [ 1  4  9 16  0  2  2  2  3  3]
```

**However, the results for the sqrt are strange.** Here we see a case where the automatic dtype switch to float64 failed.​ This is why I overzealously mange / define the dtypes.​

```python
import numpy as np


def function_a(input):
    return input**2


def function_b(input):
    return np.sqrt(input)


a = np.arange(1, 11).astype(dtype=np.float32)
b = np.piecewise(a, [a < 5, a == 0, a > 5], [function_a, 0, function_b])

print(a)  # -> [ 1.  2.  3.  4.  5.  6.  7.  8.  9. 10.]
print(b)  # -> [ 1.    4.    9.   16.    0.    2.45  2.65  2.83  3.    3.16]
```





