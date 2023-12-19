# Dimensions and shape
{:.no_toc}

<nav markdown="1" class="toc-class">
* TOC
{:toc}
</nav>

## The goal



Questions to [David Rotermund](mailto:davrot@uni-bremen.de)

## [numpy.ndarray.shape](https://numpy.org/doc/stable/reference/generated/numpy.ndarray.shape.html)

```python
ndarray.shape
```

> Tuple of array dimensions.
> 
> The shape property is usually used to get the current shape of an array, but may also be used to reshape the array in-place by assigning a tuple of array dimensions to it. As with numpy.reshape, one of the new shape dimensions can be -1, in which case its value is inferred from the size of the array and the remaining dimensions. Reshaping an array in-place will fail if a copy is required.

```python
import numpy as np

data = np.zeros((2, 4, 2, 7, 2))
print(data.shape)  # -> (2, 4, 2, 7, 2)
```

## Vanishing dimensions

```python
import numpy as np

data = np.zeros((5, 3, 2))

# All the same dimensionwise
print(data.shape)  # -> (5, 3, 2)
print(data[:].shape)  # ->  (5, 3, 2)
print(data[:, :, :].shape)  # ->  (5, 3, 2)
print(data[...].shape)  # ->  (5, 3, 2)


print(data[0, :, :].shape)  # ->  (3, 2)
print(data[:, 0, :].shape)  # ->  (5, 2)
print(data[:, :, 0].shape)  # ->  (5, 3)

print(data[:, 0, 0].shape)  # ->  (5,)
print(data[0, :, 0].shape)  # ->  (3,)
print(data[0, 0, :].shape)  # ->  (2,)

print(data[0, 0, 0].shape)  # ->  ()
print(type(data[0, 0, 0]))  # ->  <class 'numpy.float64'>
```

```python
import numpy as np

data = np.zeros((5, 3, 2))

# All the same dimensionwise
print(data.shape)  # -> (5, 3, 2)
print(data.sum().shape)  # -> ()
print(data.sum(axis=0).shape)  # -> (3, 2)
print(data.sum(axis=1).shape)  # -> (5, 2)
print(data.sum(axis=2).shape)  # -> (5, 3)

# You can use keepdims:

print(data.sum(axis=0, keepdims=True).shape)  # -> (1, 3, 2)
print(data.sum(axis=1, keepdims=True).shape)  # -> (5, 1, 2)
print(data.sum(axis=2, keepdims=True).shape)  # -> (5, 3, 1)
```


