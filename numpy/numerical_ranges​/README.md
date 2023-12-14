# Making a matrix from numerical ranges
{:.no_toc}

<nav markdown="1" class="toc-class">
* TOC
{:toc}
</nav>

## The goal

Making a matrix from numerical ranges...

Questions to [David Rotermund](mailto:davrot@uni-bremen.de)

## [numpy.arange](https://numpy.org/doc/stable/reference/generated/numpy.arange.html)


```python
numpy.arange([start, ]stop, [step, ]dtype=None, *, like=None)
```

> Return evenly spaced values within a given interval.
> 
> arange can be called with a varying number of positional arguments:
> 
>   **arange(stop)** : Values are generated within the half-open interval [0, stop) (in other words, the interval including start but excluding stop).
>   
>   **arange(start, stop)** : Values are generated within the half-open interval [start, stop).
>   
>   **arange(start, stop, step)** Values are generated within the half-open interval [start, stop), with spacing between values given by step.
>   
>   For integer arguments the function is roughly equivalent to the Python built-in range, but returns an ndarray rather than a range instance.
>
> **When using a non-integer step, such as 0.1, it is often better to use numpy.linspace.**
>
> 

 Examples: 

```python
import numpy as np

print(np.arange(5)) # -> [0 1 2 3 4]
print(np.arange(0, 5)) # -> [0 1 2 3 4]
print(np.arange(2, 5)) # -> [2 3 4]
print(np.arange(0, 5, 2)) # -> [0 2 4]
```

It can be nicely combined with **reshape()**:

```python
import numpy as np
print(np.arange(0, 9).reshape(3, 3))
```

Output:

```python
[[0 1 2]
 [3 4 5]
 [6 7 8]]
```

**Do not use it with non-integer values for step!!!** This can happen and you don't want this to happen: 

```python
import numpy as np

print(np.arange(-3, 0, 0.5, dtype=int)) # -> [-3 -2 -1  0  1  2]
```
