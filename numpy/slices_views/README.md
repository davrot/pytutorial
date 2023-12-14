# Slices and views
{:.no_toc}

<nav markdown="1" class="toc-class">
* TOC
{:toc}
</nav>

## The goal

Sometimes we want to use or see only a part of the matrix. This can be done via slices and views

Questions to [David Rotermund](mailto:davrot@uni-bremen.de)

## Reminder 

We assume N as the number of elements and 1d:​

* A valid index starts at **0** and runs until N-1​
* [start:stop:step] ​
    start = 1, stop=N, step=1 ​-> this results in the sequence​ 1,2,3,...,(N-1)​
* [start:stop:1] can be shortened to [start:stop]​
* [0:stop] can be shortened to [:stop]​
* [start:N] can be shortened to [start:]​
* B = A[:] or B = A[...] gives you a view of A. B has the same shape and size of A. ​

```python
import numpy as np

a = np.arange(0, 10)
print(a[1:10:1])  # -> [1 2 3 4 5 6 7 8 9]
print(a[3:7:2])  # -> [3 5]
print(a[3:6])  # -> [3 4 5]
print(a[:6])  # -> [0 1 2 3 4 5]
print(a[5:])  # -> [5 6 7 8 9]
print(a[:])  # -> [0 1 2 3 4 5 6 7 8 9]
print(a[...])  # -> [0 1 2 3 4 5 6 7 8 9]
```
