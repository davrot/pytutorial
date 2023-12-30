# ndenumerate
{:.no_toc}

<nav markdown="1" class="toc-class">
* TOC
{:toc}
</nav>

## Top

Questions to [David Rotermund](mailto:davrot@uni-bremen.de)


## [numpy.ndenumerate](https://numpy.org/doc/stable/reference/generated/numpy.ndenumerate.html)

```python
class numpy.ndenumerate(arr)
```

> Multidimensional index iterator.
> 
> Return an iterator yielding pairs of array coordinates and values.


```python
import numpy as np

a = np.arange(0, 12).reshape((4, 3))
print(a)
print()

for index, x in np.ndenumerate(a):
    print(index, x)
```

Output:

```python
[[ 0  1  2]
 [ 3  4  5]
 [ 6  7  8]
 [ 9 10 11]]

(0, 0) 0
(0, 1) 1
(0, 2) 2
(1, 0) 3
(1, 1) 4
(1, 2) 5
(2, 0) 6
(2, 1) 7
(2, 2) 8
(3, 0) 9
(3, 1) 10
(3, 2) 11
```
