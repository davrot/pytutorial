# [The N-dimensional array (ndarray)​](https://numpy.org/doc/stable/reference/arrays.ndarray.html)
{:.no_toc}

<nav markdown="1" class="toc-class">
* TOC
{:toc}
</nav>

## The goal

Class has a very important job as a core container type in Python. It is really hard to find a good overview how to use them in a good practice manner.

Questions to [David Rotermund](mailto:davrot@uni-bremen.de)

## Chaining of (ndarray) methods​

```python
import numpy as np
a = np.ones((3, 3))
b = a.mean(axis=1).max()
print(b) # -> 1.0
```

## [numpy.ndarray.fill​](https://numpy.org/doc/stable/reference/generated/numpy.ndarray.fill.html)

```python
ndarray.fill(value)
```

> Fill the array with a scalar value.

```python
import numpy as np
A = np.ones((3, 3))
A.fill(7)
print(A)
```

Output: 

```python
[[7. 7. 7.]
 [7. 7. 7.]
 [7. 7. 7.]]
```

## [numpy.ndarray.ndim​](https://numpy.org/doc/stable/reference/generated/numpy.ndarray.ndim.html)

```python
ndarray.ndim
```

> Number of array dimensions.

```python
import numpy as np

A = np.ones((3, 3))
print(A.ndim)  # -> 2
```

## [numpy.ndarray.shape](https://numpy.org/doc/stable/reference/generated/numpy.ndarray.shape.html)

```python
ndarray.shape
```

> Tuple of array dimensions.

```python
import numpy as np

A = np.ones((3, 3))
print(A.shape)  # -> (3, 3)
```

## [numpy.ndarray.size](https://numpy.org/doc/stable/reference/generated/numpy.ndarray.size.html)

```python
ndarray.size
```

> Number of elements in the array.

```python
import numpy as np

A = np.ones((3, 3))
print(A.size) # -> 9
```

## [numpy.ndarray.nbytes](https://numpy.org/doc/stable/reference/generated/numpy.ndarray.nbytes.html)

{: .topic-optional}
This is an optional topic!

```python
ndarray.nbytes
```

> Total bytes consumed by the elements of the array.


## [numpy.ndarray.itemsize](https://numpy.org/doc/stable/reference/generated/numpy.ndarray.itemsize.html)

{: .topic-optional}
This is an optional topic!

```python
ndarray.itemsize
```

> Length of one array element in bytes.

## [numpy.ndarray.copy](https://numpy.org/doc/stable/reference/generated/numpy.ndarray.copy.html)

```python
ndarray.copy(order='C')
```

> Return a copy of the array.


## [numpy.ndarray.view](https://numpy.org/doc/stable/reference/generated/numpy.ndarray.view.html)

```python
ndarray.view([dtype][, type])
```

> New view of array with the same data.

## [numpy.ndarray.reshape](https://numpy.org/doc/stable/reference/generated/numpy.ndarray.reshape.html)

```python
ndarray.reshape(shape, order='C')
```

> Returns an array containing the same data with a new shape.

```python
import numpy as np

A = np.arange(0, 6)
print(A.reshape((2, 3)))
```

Output:

```python
[[0 1 2]
 [3 4 5]]
```

**WARNING!!! Don't confuse reshape with resize!**

## [numpy.ndarray.squeeze](https://numpy.org/doc/stable/reference/generated/numpy.ndarray.squeeze.html)

```python
ndarray.squeeze(axis=None)
```

> Remove axes of length one from a.

```python
import numpy as np

A = np.zeros((4, 1, 1)) 
print(A.shape) # -> (4, 1, 1)
A = A.squeeze()
print(A.shape) # -> (4,)

A = np.zeros((4, 1, 9, 1)) # -> (4, 1, 9, 1)
print(A.shape)
B = A.squeeze(axis=1) # -> (4, 9, 1)
print(B.shape)
```
## [numpy.moveaxis](https://numpy.org/doc/stable/reference/generated/numpy.moveaxis.html)

```python
numpy.moveaxis(a, source, destination)
```

> Move axes of an array to new positions.
> 
> Other axes remain in their original order.

```python
import numpy as np

A = np.zeros((4, 1, 9, 1)) 
print(A.shape) # -> (4, 1, 9, 1)
B = np.moveaxis(A, 0, 1)
print(B.shape) # -> (1, 4, 9, 1)
```

## [Array methods](https://numpy.org/doc/stable/reference/arrays.ndarray.html#array-methods)

### [Array conversion](https://numpy.org/doc/stable/reference/arrays.ndarray.html#array-conversion)

|||
|---|---|
|[ndarray.item(*args)](https://numpy.org/doc/stable/reference/generated/numpy.ndarray.item.html#numpy.ndarray.item)|Copy an element of an array to a standard Python scalar and return it.|
|[ndarray.tolist()](https://numpy.org/doc/stable/reference/generated/numpy.ndarray.tolist.html#numpy.ndarray.tolist)|Return the array as an a.ndim-levels deep nested list of Python scalars.|
|[ndarray.itemset(*args)](https://numpy.org/doc/stable/reference/generated/numpy.ndarray.itemset.html#numpy.ndarray.itemset)|Insert scalar into an array (scalar is cast to array's dtype, if possible)|
|[ndarray.tostring([order])](https://numpy.org/doc/stable/reference/generated/numpy.ndarray.tostring.html#numpy.ndarray.tostring)|A compatibility alias for tobytes, with exactly the same behavior.|
|[ndarray.tobytes([order])](https://numpy.org/doc/stable/reference/generated/numpy.ndarray.tobytes.html#numpy.ndarray.tobytes)|Construct Python bytes containing the raw data bytes in the array.|
|[ndarray.tofile(fid[, sep, format])](https://numpy.org/doc/stable/reference/generated/numpy.ndarray.tofile.html#numpy.ndarray.tofile)|Write array to a file as text or binary (default).|
|[ndarray.dump(file)](https://numpy.org/doc/stable/reference/generated/numpy.ndarray.dump.html#numpy.ndarray.dump)|Dump a pickle of the array to the specified file.|
|[ndarray.dumps()](https://numpy.org/doc/stable/reference/generated/numpy.ndarray.dumps.html#numpy.ndarray.dumps)|Returns the pickle of the array as a string.|
|[ndarray.astype(dtype[, order, casting, ...])](https://numpy.org/doc/stable/reference/generated/numpy.ndarray.astype.html#numpy.ndarray.astype)|Copy of the array, cast to a specified type.|
|[ndarray.byteswap([inplace])](https://numpy.org/doc/stable/reference/generated/numpy.ndarray.byteswap.html#numpy.ndarray.byteswap)|Swap the bytes of the array elements|
|[ndarray.copy([order])](https://numpy.org/doc/stable/reference/generated/numpy.ndarray.copy.html#numpy.ndarray.copy)|Return a copy of the array.|
|[ndarray.view([dtype][, type])](https://numpy.org/doc/stable/reference/generated/numpy.ndarray.view.html#numpy.ndarray.view)|New view of array with the same data.|
|[ndarray.getfield(dtype[, offset])](https://numpy.org/doc/stable/reference/generated/numpy.ndarray.getfield.html#numpy.ndarray.getfield)|Returns a field of the given array as a certain type.|
|[ndarray.setflags([write, align, uic])](https://numpy.org/doc/stable/reference/generated/numpy.ndarray.setflags.html#numpy.ndarray.setflags)|Set array flags WRITEABLE, ALIGNED, WRITEBACKIFCOPY, respectively.|
|[ndarray.fill(value)](https://numpy.org/doc/stable/reference/generated/numpy.ndarray.fill.html#numpy.ndarray.fill)|Fill the array with a scalar value.|

### [Shape manipulation](https://numpy.org/doc/stable/reference/arrays.ndarray.html#shape-manipulation)

|||
|---|---|
|[ndarray.reshape(shape[, order])](https://numpy.org/doc/stable/reference/generated/numpy.ndarray.reshape.html#numpy.ndarray.reshape)|Returns an array containing the same data with a new shape.|
|[ndarray.resize(new_shape[, refcheck])](https://numpy.org/doc/stable/reference/generated/numpy.ndarray.resize.html#numpy.ndarray.resize)|Change shape and size of array in-place.|
|[ndarray.transpose(*axes)](https://numpy.org/doc/stable/reference/generated/numpy.ndarray.transpose.html#numpy.ndarray.transpose)|Returns a view of the array with axes transposed.|
|[ndarray.swapaxes(axis1, axis2)](https://numpy.org/doc/stable/reference/generated/numpy.ndarray.swapaxes.html#numpy.ndarray.swapaxes)|Return a view of the array with axis1 and axis2 interchanged.|
|[ndarray.flatten([order])](https://numpy.org/doc/stable/reference/generated/numpy.ndarray.flatten.html#numpy.ndarray.flatten)|Return a copy of the array collapsed into one dimension.|
|[ndarray.ravel([order])](https://numpy.org/doc/stable/reference/generated/numpy.ndarray.ravel.html#numpy.ndarray.ravel)|Return a flattened array.|
|[ndarray.squeeze([axis])](https://numpy.org/doc/stable/reference/generated/numpy.ndarray.squeeze.html#numpy.ndarray.squeeze)|Remove axes of length one from a.|

### [Item selection and manipulation](https://numpy.org/doc/stable/reference/arrays.ndarray.html#item-selection-and-manipulation)

|||
|---|---|
|[ndarray.take(indices[, axis, out, mode])](https://numpy.org/doc/stable/reference/generated/numpy.ndarray.take.html#numpy.ndarray.take)|Return an array formed from the elements of a at the given |indices.
|[ndarray.put(indices, values[, mode])](https://numpy.org/doc/stable/reference/generated/numpy.ndarray.put.html#numpy.ndarray.put)|Set a.flat[n] = values[n] for all n in indices.|
|[ndarray.repeat(repeats[, axis])](https://numpy.org/doc/stable/reference/generated/numpy.ndarray.repeat.html#numpy.ndarray.repeat)|Repeat elements of an array.|
|[ndarray.choose(choices[, out, mode])](https://numpy.org/doc/stable/reference/generated/numpy.ndarray.choose.html#numpy.ndarray.choose)|Use an index array to construct a new array from a set of choices.|
|[ndarray.sort([axis, kind, order])](https://numpy.org/doc/stable/reference/generated/numpy.ndarray.sort.html#numpy.ndarray.sort)|Sort an array in-place.|
|[ndarray.argsort([axis, kind, order])](https://numpy.org/doc/stable/reference/generated/numpy.ndarray.argsort.html#numpy.ndarray.argsort)|Returns the indices that would sort this array.|
|[ndarray.partition(kth[, axis, kind, order])](https://numpy.org/doc/stable/reference/generated/numpy.ndarray.partition.html#numpy.ndarray.partition)|Rearranges the elements in the array in such a way that the value of the element in kth position is in the position it would be in a sorted array.|
|[ndarray.argpartition(kth[, axis, kind, order])](https://numpy.org/doc/stable/reference/generated/numpy.ndarray.argpartition.html#numpy.ndarray.argpartition)|Returns the indices that would partition |this array.
|[ndarray.searchsorted(v[, side, sorter])](https://numpy.org/doc/stable/reference/generated/numpy.ndarray.searchsorted.html#numpy.ndarray.searchsorted)|Find indices where elements of v should be inserted in a to maintain order.|
|[ndarray.nonzero()](https://numpy.org/doc/stable/reference/generated/numpy.ndarray.nonzero.html#numpy.ndarray.nonzero)|Return the indices of the elements that are non-zero.|
|[ndarray.compress(condition[, axis, out])](https://numpy.org/doc/stable/reference/generated/numpy.ndarray.compress.html#numpy.ndarray.compress)|Return selected slices of this array along given axis.|
|[ndarray.diagonal([offset, axis1, axis2])](https://numpy.org/doc/stable/reference/generated/numpy.ndarray.diagonal.html#numpy.ndarray.diagonal)|Return specified diagonals.|

### [Calculation](https://numpy.org/doc/stable/reference/arrays.ndarray.html#calculation)

|||
|---|---|
|[ndarray.max([axis, out, keepdims, initial, ...])](https://numpy.org/doc/stable/reference/generated/numpy.ndarray.max.html#numpy.ndarray.max)|Return the maximum along a given axis.|
|[ndarray.argmax([axis, out, keepdims])](https://numpy.org/doc/stable/reference/generated/numpy.ndarray.argmax.html#numpy.ndarray.argmax)|Return indices of the maximum values along the given axis.|
|[ndarray.min([axis, out, keepdims, initial, ...])](https://numpy.org/doc/stable/reference/generated/numpy.ndarray.min.html#numpy.ndarray.min)|Return the minimum along a given axis.|
|[ndarray.argmin([axis, out, keepdims])](https://numpy.org/doc/stable/reference/generated/numpy.ndarray.argmin.html#numpy.ndarray.argmin)|Return indices of the minimum values along the given axis.|
|[ndarray.ptp([axis, out, keepdims])](https://numpy.org/doc/stable/reference/generated/numpy.ndarray.ptp.html#numpy.ndarray.ptp)|Peak to peak (maximum - minimum) value along a given axis.|
|[ndarray.clip([min, max, out])](https://numpy.org/doc/stable/reference/generated/numpy.ndarray.clip.html#numpy.ndarray.clip)|Return an array whose values are limited to [min, max].|
|[ndarray.conj()](https://numpy.org/doc/stable/reference/generated/numpy.ndarray.conj.html#numpy.ndarray.conj)|Complex-conjugate all elements.|
|[ndarray.round([decimals, out])](https://numpy.org/doc/stable/reference/generated/numpy.ndarray.round.html#numpy.ndarray.round)|Return a with each element rounded to the given number of decimals.|
|[ndarray.trace([offset, axis1, axis2, dtype, out])](https://numpy.org/doc/stable/reference/generated/numpy.ndarray.trace.html#numpy.ndarray.trace)|Return the sum along diagonals of the array.|
|[ndarray.sum([axis, dtype, out, keepdims, ...])](https://numpy.org/doc/stable/reference/generated/numpy.ndarray.sum.html#numpy.ndarray.sum)|Return the sum of the array elements over the given axis.|
|[ndarray.cumsum([axis, dtype, out])](https://numpy.org/doc/stable/reference/generated/numpy.ndarray.cumsum.html#numpy.ndarray.cumsum)|Return the cumulative sum of the elements along the given axis.|
|[ndarray.mean([axis, dtype, out, keepdims, where])](https://numpy.org/doc/stable/reference/generated/numpy.ndarray.mean.html#numpy.ndarray.mean)|Returns the average of the array elements along given axis.|
|[ndarray.var([axis, dtype, out, ddof, ...])](https://numpy.org/doc/stable/reference/generated/numpy.ndarray.var.html#numpy.ndarray.var)|Returns the variance of the array elements, along given axis.|
|[ndarray.std([axis, dtype, out, ddof, ...])](https://numpy.org/doc/stable/reference/generated/numpy.ndarray.std.html#numpy.ndarray.std)|Returns the standard deviation of the array elements along given axis.|
|[ndarray.prod([axis, dtype, out, keepdims, ...])](https://numpy.org/doc/stable/reference/generated/numpy.ndarray.prod.html#numpy.ndarray.prod)|Return the product of the array elements over the given axis|
|[ndarray.cumprod([axis, dtype, out])](https://numpy.org/doc/stable/reference/generated/numpy.ndarray.cumprod.html#numpy.ndarray.cumprod)|Return the cumulative product of the elements along the given axis.|
|[ndarray.all([axis, out, keepdims, where])](https://numpy.org/doc/stable/reference/generated/numpy.ndarray.all.html#numpy.ndarray.all)|Returns True if all elements evaluate to True.|
|[ndarray.any([axis, out, keepdims, where])](https://numpy.org/doc/stable/reference/generated/numpy.ndarray.any.html#numpy.ndarray.any)|Returns True if any of the elements of a evaluate to True.|

## [Arithmetic, matrix multiplication, and comparison operations](https://numpy.org/doc/stable/reference/arrays.ndarray.html#arithmetic-matrix-multiplication-and-comparison-operations)

> Each of the arithmetic operations (+, -, *, /, //, %, divmod(), ** or pow(), <<, >>, &, ^, |, ~) and the comparisons (==, <, >, <=, >=, !=) is equivalent to the corresponding universal function (or ufunc for short) in NumPy. 

for in-place operations see [here](https://numpy.org/doc/stable/reference/arrays.ndarray.html#arithmetic-matrix-multiplication-and-comparison-operations)

|||
|---|---|
|[ndarray.\_\_lt\_\_(value, /)](https://numpy.org/doc/stable/reference/generated/numpy.ndarray.__lt__.html#numpy.ndarray.__lt__)|Return self<value.|
|[ndarray.\_\_le\_\_(value, /)](https://numpy.org/doc/stable/reference/generated/numpy.ndarray.__le__.html#numpy.ndarray.__le__)|Return self<=value.|
|[ndarray.\_\_gt\_\_(value, /)](https://numpy.org/doc/stable/reference/generated/numpy.ndarray.__gt__.html#numpy.ndarray.__gt__)|Return self>value.|
|[ndarray.\_\_ge\_\_(value, /)](https://numpy.org/doc/stable/reference/generated/numpy.ndarray.__ge__.html#numpy.ndarray.__ge__)|Return self>=value.|
|[ndarray.\_\_eq\_\_(value, /)](https://numpy.org/doc/stable/reference/generated/numpy.ndarray.__eq__.html#numpy.ndarray.__eq__)|Return self==value.|
|[ndarray.\_\_ne\_\_(value, /)](https://numpy.org/doc/stable/reference/generated/numpy.ndarray.__ne__.html#numpy.ndarray.__ne__)|Return self!=value.|
|[ndarray.\_\_bool\_\_(/)](https://numpy.org/doc/stable/reference/generated/numpy.ndarray.__bool__.html#numpy.ndarray.__bool__)|True if self else False|
|[ndarray.\_\_neg\_\_(/)](https://numpy.org/doc/stable/reference/generated/numpy.ndarray.__neg__.html#numpy.ndarray.__neg__)|-self|
|[ndarray.\_\_pos\_\_(/)](https://numpy.org/doc/stable/reference/generated/numpy.ndarray.__pos__.html#numpy.ndarray.__pos__)|+self|
|[ndarray.\_\_abs\_\_(self)](https://numpy.org/doc/stable/reference/generated/numpy.ndarray.__abs__.html#numpy.ndarray.__abs__)||
|[ndarray.\_\_invert\_\_(/)](https://numpy.org/doc/stable/reference/generated/numpy.ndarray.__invert__.html#numpy.ndarray.__invert__)|~self|
|[ndarray.\_\_add\_\_(value, /)](https://numpy.org/doc/stable/reference/generated/numpy.ndarray.__add__.html#numpy.ndarray.__add__)|Return self+value.|
|[ndarray.\_\_sub\_\_(value, /)](https://numpy.org/doc/stable/reference/generated/numpy.ndarray.__sub__.html#numpy.ndarray.__sub__)|Return self-value.|
|[ndarray.\_\_mul\_\_(value, /)](https://numpy.org/doc/stable/reference/generated/numpy.ndarray.__mul__.html#numpy.ndarray.__mul__)|Return self*value.|
|[ndarray.\_\_truediv\_\_(value, /)](https://numpy.org/doc/stable/reference/generated/numpy.ndarray.__truediv__.html#numpy.ndarray.__truediv__)|Return self/value.|
|[ndarray.\_\_floordiv\_\_(value, /)](https://numpy.org/doc/stable/reference/generated/numpy.ndarray.__floordiv__.html#numpy.ndarray.__floordiv__)|Return self//value.|
|[ndarray.\_\_mod\_\_(value, /)](https://numpy.org/doc/stable/reference/generated/numpy.ndarray.__mod__.html#numpy.ndarray.__mod__)|Return self%value.|
|[ndarray.\_\_divmod\_\_(value, /)](https://numpy.org/doc/stable/reference/generated/numpy.ndarray.__divmod__.html#numpy.ndarray.__divmod__)|Return divmod(self, value).|
|[ndarray.\_\_pow\_\_(value[, mod])](https://numpy.org/doc/stable/reference/generated/numpy.ndarray.__pow__.html#numpy.ndarray.__pow__)|Return pow(self, value, mod).|
|[ndarray.\_\_lshift\_\_(value, /)](https://numpy.org/doc/stable/reference/generated/numpy.ndarray.__lshift__.html#numpy.ndarray.__lshift__)|Return self<<value.|
|[ndarray.\_\_rshift\_\_(value, /)](https://numpy.org/doc/stable/reference/generated/numpy.ndarray.__rshift__.html#numpy.ndarray.__rshift__)|Return self>>value.|
|[ndarray.\_\_and\_\_(value, /)](https://numpy.org/doc/stable/reference/generated/numpy.ndarray.__and__.html#numpy.ndarray.__and__)|Return self&value.|
|[ndarray.\_\_or\_\_(value, /)](https://numpy.org/doc/stable/reference/generated/numpy.ndarray.__or__.html#numpy.ndarray.__or__)|Return self|value.|
|[ndarray.\_\_xor\_\_(value, /)](https://numpy.org/doc/stable/reference/generated/numpy.ndarray.__xor__.html#numpy.ndarray.__xor__)|Return self^value.|
|[ndarray.\_\_matmul\_\_(value, /)](https://numpy.org/doc/stable/reference/generated/numpy.ndarray.__matmul__.html#numpy.ndarray.__matmul__)|Return self@value.|


### [Special methods](https://numpy.org/doc/stable/reference/arrays.ndarray.html#special-methods)

[special methods](https://numpy.org/doc/stable/reference/arrays.ndarray.html#special-methods)



