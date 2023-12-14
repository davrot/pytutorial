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


## [numpy.linspace](https://numpy.org/doc/stable/reference/generated/numpy.linspace.html)

```python
numpy.linspace(start, stop, num=50, endpoint=True, retstep=False, dtype=None, axis=0)
```

> Return evenly spaced numbers over a specified interval.
> 
> Returns num evenly spaced samples, calculated over the interval [start, stop].
> 
> The endpoint of the interval can optionally be excluded.

> **start** : array_like
> 
>  The starting value of the sequence.

> **stop** : array_like
> 
>  The end value of the sequence, unless endpoint is set to False. In that case, the sequence consists of all but the last of num + 1 evenly spaced samples, so that stop is excluded. Note that the step size changes when endpoint is False.

> **num** : int, optional
> 
>  Number of samples to generate. Default is 50. Must be non-negative.

> **endpoint** : bool, optional
> 
>  If True, stop is the last sample. Otherwise, it is not included. Default is True.

An example:

```python
import numpy as np

print(np.linspace(0, 1, num=10, endpoint=False))  # -> [0.  0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9]
print(np.arange(0, 10) / 10)  # -> [0.  0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9]
```

Be mindful concerning the endpoint setting (**Notice the ... 8 10]**): 

```python
import numpy as np

print(np.linspace(0, 10, num=10, endpoint=False, dtype=int))  # -> [0 1 2 3 4 5 6 7 8 9]
print(np.linspace(0, 10, num=10, endpoint=True, dtype=int))  # -> [ 0  1  2  3  4  5  6  7  8 10]
```

## [numpy.logspace](https://numpy.org/doc/stable/reference/generated/numpy.logspace.html)

```python
numpy.logspace(start, stop, num=50, endpoint=True, base=10.0, dtype=None, axis=0)
```

> Return numbers spaced evenly on a log scale.
>
> In linear space, the sequence starts at base ** start (base to the power of start) and ends with base ** stop (see endpoint below).

