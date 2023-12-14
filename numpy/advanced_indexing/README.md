# Advanced Indexing
{:.no_toc}

<nav markdown="1" class="toc-class">
* TOC
{:toc}
</nav>

## The goal

Beside slicing there is something called advanced indexing 

Questions to [David Rotermund](mailto:davrot@uni-bremen.de)

## Boolean Array​

We can use Boolean arrays for more complicate indexing: 

```python
import numpy as np

a = np.arange(1,10).reshape(3,3)
b = np.zeros_like(a)

b[a.sum(axis=1) > 6, :] = 1

print(a)
print()
print(b)
```

Output:

```python
[[1 2 3]
 [4 5 6]
 [7 8 9]]

[[0 0 0]
 [1 1 1]
 [1 1 1]]
```

Behind the curtains more or less this happens:​

```python
import numpy as np

a = np.arange(1, 10).reshape(3, 3)
b = np.zeros_like(a)

temp_0 = a.sum(axis=1)
temp_1 = temp_0 > 6
temp_2 = np.nonzero(temp_1)
b[temp_2] = 1

print(temp_0)
print()
print(temp_1)
print()
print(temp_2)
print()
print(b)
```

Output:

```python
[ 6 15 24]

[False  True  True]

(array([1, 2]),)

[[0 0 0]
 [1 1 1]
 [1 1 1]]
```

