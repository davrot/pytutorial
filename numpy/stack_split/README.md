# Stack and Split
{:.no_toc}

<nav markdown="1" class="toc-class">
* TOC
{:toc}
</nav>

## The goal


Questions to [David Rotermund](mailto:davrot@uni-bremen.de)

{: .topic-optional}
This is an optional topic!


## [numpy.column_stack](https://numpy.org/doc/stable/reference/generated/numpy.column_stack.html)

```python
numpy.column_stack(tup)
```

> Stack 1-D arrays as columns into a 2-D array.
> 
> Take a sequence of 1-D arrays and stack them as columns to make a single 2-D array. 2-D arrays are stacked as-is, just like with hstack. 1-D arrays are turned into 2-D columns first.

```python
import numpy as np

a = np.arange(0, 10)
print(a) # -> [0 1 2 3 4 5 6 7 8 9]
print(a.shape)  # -> (10,)

b = np.column_stack((a, a))
print(b)
print(b.shape) # -> (10, 2)
```
Output:

```python
[[0 0]
 [1 1]
 [2 2]
 [3 3]
 [4 4]
 [5 5]
 [6 6]
 [7 7]
 [8 8]
 [9 9]]
```

## [numpy.row_stack](https://numpy.org/doc/stable/reference/generated/numpy.row_stack.html)

```python
numpy.row_stack(tup, *, dtype=None, casting='same_kind')
```

> Stack arrays in sequence vertically (row wise).
> 
> This is equivalent to concatenation along the first axis after 1-D arrays of shape (N,) have been reshaped to (1,N). Rebuilds arrays divided by vsplit.
> 
> This function makes most sense for arrays with up to 3 dimensions. For instance, for pixel-data with a height (first axis), width (second axis), and r/g/b channels (third axis). The functions concatenate, stack and block provide more general stacking and concatenation operations.
> 
> np.row_stack is an alias for vstack. They are the same function.

```python
import numpy as np

a = np.arange(0, 10)
print(a)  # -> [0 1 2 3 4 5 6 7 8 9]
print(a.shape)  # -> (10,)

b = np.row_stack((a, a))
print(b)
print(b.shape)  # -> (2, 10)
```

Output:

```python
[[0 1 2 3 4 5 6 7 8 9]
 [0 1 2 3 4 5 6 7 8 9]]
```

## [numpy.vstack](https://numpy.org/doc/stable/reference/generated/numpy.vstack.html)

```python
numpy.vstack(tup, *, dtype=None, casting='same_kind')
```

> Stack arrays in sequence vertically (row wise).
> 
> This is equivalent to concatenation along the first axis after 1-D arrays of shape (N,) have been reshaped to (1,N). Rebuilds arrays divided by vsplit.
> 
> This function makes most sense for arrays with up to 3 dimensions. For instance, for pixel-data with a height (first axis), width (second axis), and r/g/b channels (third axis). The functions concatenate, stack and block provide more general stacking and concatenation operations.
> 
> np.row_stack is an alias for vstack. They are the same function.

```python
import numpy as np

a = np.zeros((2, 3, 4))
print(a.shape)  # -> (2, 3, 4)

b = np.vstack((a, a))
print(b.shape)  # -> (4, 3, 4)
```



## [numpy.hstack](https://numpy.org/doc/stable/reference/generated/numpy.hstack.html)

```python
numpy.hstack(tup, *, dtype=None, casting='same_kind')
```

> Stack arrays in sequence horizontally (column wise).
> 
> This is equivalent to concatenation along the second axis, except for 1-D arrays where it concatenates along the first axis. Rebuilds arrays divided by hsplit.
> 
> This function makes most sense for arrays with up to 3 dimensions. For instance, for pixel-data with a height (first axis), width (second axis), and r/g/b channels (third axis). The functions concatenate, stack and block provide more general stacking and concatenation operations.

```python
import numpy as np

a = np.zeros((2, 3, 4))
print(a.shape)  # -> (2, 3, 4)

b = np.hstack((a, a))
print(b.shape)  # -> (2, 6, 4)
```

## [numpy.dstack](https://numpy.org/doc/stable/reference/generated/numpy.dstack.html)

```python
numpy.dstack(tup)
```

> Stack arrays in sequence depth wise (along third axis).
> 
> This is equivalent to concatenation along the third axis after 2-D arrays of shape (M,N) have been reshaped to (M,N,1) and 1-D arrays of shape (N,) have been reshaped to (1,N,1). Rebuilds arrays divided by dsplit.
> 
> This function makes most sense for arrays with up to 3 dimensions. For instance, for pixel-data with a height (first axis), width (second axis), and r/g/b channels (third axis). The functions concatenate, stack and block provide more general stacking and concatenation operations.

```python
import numpy as np

a = np.zeros((2, 3, 4))
print(a.shape)  # -> (2, 3, 4)

b = np.dstack((a, a))
print(b.shape)  # -> (2, 3, 8)
```

