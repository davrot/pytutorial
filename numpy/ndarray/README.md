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

### Shape manipulation

|||
|---|---|

|[ndarray.reshape(shape[, order])]()|
Returns an array containing the same data with a new shape.

|[ndarray.resize(new_shape[, refcheck])]()|
Change shape and size of array in-place.

|[ndarray.transpose(*axes)]()|
Returns a view of the array with axes transposed.

|[ndarray.swapaxes(axis1, axis2)]()|
Return a view of the array with axis1 and axis2 interchanged.

|[ndarray.flatten([order])]()|
Return a copy of the array collapsed into one dimension.

|[ndarray.ravel([order])]()|
Return a flattened array.

|[ndarray.squeeze([axis])]()|
Remove axes of length one from a.

### Item selection and manipulation

|[ndarray.take(indices[, axis, out, mode])]()|
Return an array formed from the elements of a at the given indices.

|[ndarray.put(indices, values[, mode])]()|
Set a.flat[n] = values[n] for all n in indices.

|[ndarray.repeat(repeats[, axis])]()|
Repeat elements of an array.

|[ndarray.choose(choices[, out, mode])]()|
Use an index array to construct a new array from a set of choices.

|[ndarray.sort([axis, kind, order])]()|
Sort an array in-place.

|[ndarray.argsort([axis, kind, order])]()|
Returns the indices that would sort this array.

|[ndarray.partition(kth[, axis, kind, order])]()|
Rearranges the elements in the array in such a way that the value of the element in kth position is in the position it would be in a sorted array.

|[ndarray.argpartition(kth[, axis, kind, order])]()|
Returns the indices that would partition this array.

|[ndarray.searchsorted(v[, side, sorter])]()|
Find indices where elements of v should be inserted in a to maintain order.

|[ndarray.nonzero()]()|
Return the indices of the elements that are non-zero.

|[ndarray.compress(condition[, axis, out])]()|
Return selected slices of this array along given axis.

|[ndarray.diagonal([offset, axis1, axis2])]()|
Return specified diagonals.

### [Calculation](https://numpy.org/doc/stable/reference/arrays.ndarray.html#calculation)

|[ndarray.max([axis, out, keepdims, initial, ...])]()|
Return the maximum along a given axis.

|[ndarray.argmax([axis, out, keepdims])]()|
Return indices of the maximum values along the given axis.

|[ndarray.min([axis, out, keepdims, initial, ...])]()|
Return the minimum along a given axis.

|[ndarray.argmin([axis, out, keepdims])]()|
Return indices of the minimum values along the given axis.

|[ndarray.ptp([axis, out, keepdims])]()|
Peak to peak (maximum - minimum) value along a given axis.

|[ndarray.clip([min, max, out])]()|
Return an array whose values are limited to [min, max].

|[ndarray.conj()]()|
Complex-conjugate all elements.

|[ndarray.round([decimals, out])]()|
Return a with each element rounded to the given number of decimals.

|[ndarray.trace([offset, axis1, axis2, dtype, out])]()|
Return the sum along diagonals of the array.

|[ndarray.sum([axis, dtype, out, keepdims, ...])]()|
Return the sum of the array elements over the given axis.

|[ndarray.cumsum([axis, dtype, out])]()|
Return the cumulative sum of the elements along the given axis.

|[ndarray.mean([axis, dtype, out, keepdims, where])]()|
Returns the average of the array elements along given axis.

|[ndarray.var([axis, dtype, out, ddof, ...])]()|
Returns the variance of the array elements, along given axis.

|[ndarray.std([axis, dtype, out, ddof, ...])]()|
Returns the standard deviation of the array elements along given axis.

|[ndarray.prod([axis, dtype, out, keepdims, ...])]()|
Return the product of the array elements over the given axis

|[ndarray.cumprod([axis, dtype, out])]()|
Return the cumulative product of the elements along the given axis.

|[ndarray.all([axis, out, keepdims, where])]()|
Returns True if all elements evaluate to True.

|[ndarray.any([axis, out, keepdims, where])]()|
Returns True if any of the elements of a evaluate to True.

## [Arithmetic, matrix multiplication, and comparison operations](https://numpy.org/doc/stable/reference/arrays.ndarray.html#arithmetic-matrix-multiplication-and-comparison-operations)

|[ndarray.\_\_lt\_\_(value, /)]()|
Return self<value.

|[ndarray.\_\_le\_\_(value, /)]()|
Return self<=value.

|[ndarray.\_\_gt\_\_(value, /)]()|
Return self>value.

|[ndarray.\_\_ge\_\_(value, /)]()|
Return self>=value.

|[ndarray.\_\_eq\_\_(value, /)]()|
Return self==value.

|[ndarray.\_\_ne\_\_(value, /)]()|
Return self!=value.

|[ndarray.\_\_bool\_\_(/)]()|
True if self else False

|[ndarray.\_\_neg\_\_(/)]()|
-self

|[ndarray.\_\_pos\_\_(/)]()|
+self

|[ndarray.\_\_abs\_\_(self)]()|

|[ndarray.\_\_invert\_\_(/)]()|
~self

|[ndarray.\_\_add\_\_(value, /)]()|
Return self+value.

|[ndarray.\_\_sub\_\_(value, /)]()|
Return self-value.

|[ndarray.\_\_mul\_\_(value, /)]()|
Return self*value.

|[ndarray.\_\_truediv\_\_(value, /)]()|
Return self/value.

|[ndarray.\_\_floordiv\_\_(value, /)]()|
Return self//value.

|[ndarray.\_\_mod\_\_(value, /)]()|
Return self%value.

|[ndarray.\_\_divmod\_\_(value, /)]()|
Return divmod(self, value).

|[ndarray.\_\_pow\_\_(value[, mod])]()|
Return pow(self, value, mod).

|[ndarray.\_\_lshift\_\_(value, /)]()|
Return self<<value.

|[ndarray.\_\_rshift\_\_(value, /)]()|
Return self>>value.

|[ndarray.\_\_and\_\_(value, /)]()|
Return self&value.

|[ndarray.\_\_or\_\_(value, /)]()|
Return self|value.

|[ndarray.\_\_xor\_\_(value, /)]()|
Return self^value.

|[ndarray.\_\_iadd\_\_(value, /)]()|
Return self+=value.

|[ndarray.\_\_isub\_\_(value, /)]()|
Return self-=value.

|[ndarray.\_\_imul\_\_(value, /)]()|
Return self*=value.

|[ndarray.\_\_itruediv\_\_(value, /)]()|
Return self/=value.

|[ndarray.\_\_ifloordiv\_\_(value, /)]()|
Return self//=value.

|[ndarray.\_\_imod\_\_(value, /)]()|
Return self%=value.

|[ndarray.\_\_ipow\_\_(value, /)]()|
Return self**=value.

|[ndarray.\_\_ilshift\_\_(value, /)]()|
Return self<<=value.

|[ndarray.\_\_irshift\_\_(value, /)]()|
Return self>>=value.

|[ndarray.\_\_iand\_\_(value, /)]()|
Return self&=value.

|[ndarray.\_\_ior\_\_(value, /)]()|
Return self|=value.

|[ndarray.\_\_ixor\_\_(value, /)]()|
Return self^=value.

|[ndarray.\_\_matmul\_\_(value, /)]()|
Return self@value.


### [Special methods](https://numpy.org/doc/stable/reference/arrays.ndarray.html#special-methods)

[special methods](https://numpy.org/doc/stable/reference/arrays.ndarray.html#special-methods)



