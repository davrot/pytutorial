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
### keepdims

There are functions like 
```python
ndarray.sum(axis=None, dtype=None, out=None, keepdims=False, initial=0, where=True)
ndarray.mean(axis=None, dtype=None, out=None, keepdims=False, *, where=True)
ndarray.prod(axis=None, dtype=None, out=None, keepdims=False, initial=1, where=True)
ndarray.max(axis=None, out=None, keepdims=False, initial=<no value>, where=True)
ndarray.min(axis=None, out=None, keepdims=False, initial=<no value>, where=True)
ndarray.argmax(axis=None, out=None, *, keepdims=False)
ndarray.argmin(axis=None, out=None, *, keepdims=False)
```
that normally make one dimension vanish. However, often this type of functions have an argument **keepdims** that keeps this dimension alive. 

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

As as reminder, shape is only availabe for np.ndarray and torch.Tensor matrices: 

```python
z = int(7)
print(np.array(z).shape)  # -> ()
print(type(np.array(z)))  # -> <class 'numpy.ndarray'>
print(type(z))  # -> <class 'int'>
print(z.shape)  # -> AttributeError: 'int' object has no attribute 'shape'
```

## Stop vanishing dimensions

One way to do stop vanishing dimensions is to use slices of thickness 1. If you want the nth element, then use **n:n+1**: 

```python
import numpy as np

data = np.zeros((5, 3, 2))

# All the same dimensionwise
print(data.shape)  # -> (5, 3, 2)

print(data[0:1, :, :].shape)  # ->  (1, 3, 2)
print(data[:, 0:1, :].shape)  # ->  (5, 1, 2)
print(data[:, :, 0:1].shape)  # ->  (5, 3, 1)

print(data[:, 0:1, 0:1].shape)  # ->  (5, 1, 1)
print(data[0:1, :, 0:1].shape)  # ->  (1, 3, 1)
print(data[0:1, 0:1, :].shape)  # ->  (1, 1, 2)

print(data[0:1, 0:1, 0:1].shape)  # ->  (1, 1, 1)
print(type(data[0:1, 0:1, 0:1]))  # ->  <class 'numpy.ndarray'>
```

**Please understand this creates a view which is connected to original data.** If necessary make a **copy()**. 

