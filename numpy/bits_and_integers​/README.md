# Bits and Integers​
{:.no_toc}

<nav markdown="1" class="toc-class">
* TOC
{:toc}
</nav>

## The goal

Manipulation of integers and their bits

Questions to [David Rotermund](mailto:davrot@uni-bremen.de)

## [numpy.ndarray.byteswap](https://numpy.org/doc/stable/reference/generated/numpy.ndarray.byteswap.html)

```python
ndarray.byteswap(inplace=False)
```

> Swap the bytes of the array elements
> 
> Toggle between low-endian and big-endian data representation by returning a byteswapped array, optionally swapped in-place. Arrays of byte-strings are not swapped. The real and imaginary parts of a complex number are swapped individually.
>
> **inplace** : bool, optional
> 
> If True, swap bytes in-place, default is False.


## [numpy.bitwise_and](https://numpy.org/doc/stable/reference/generated/numpy.bitwise_and.html)

```python
numpy.bitwise_and(x1, x2, /, out=None, *, where=True, casting='same_kind', order='K', dtype=None, subok=True[, signature, extobj])
```

> Compute the bit-wise AND of two arrays element-wise.
> 
> Computes the bit-wise AND of the underlying binary representation of the integers in the input arrays. This ufunc implements the C/Python operator &.


## [numpy.bitwise_or](https://numpy.org/doc/stable/reference/generated/numpy.bitwise_or.html)

```python
numpy.bitwise_or(x1, x2, /, out=None, *, where=True, casting='same_kind', order='K', dtype=None, subok=True[, signature, extobj]) 
```

>  Compute the bit-wise OR of two arrays element-wise.
>  
> Computes the bit-wise OR of the underlying binary representation of the integers in the input arrays. This ufunc implements the C/Python operator \|.

## [numpy.bitwise_xor](https://numpy.org/doc/stable/reference/generated/numpy.bitwise_xor.html)

```python
numpy.bitwise_xor(x1, x2, /, out=None, *, where=True, casting='same_kind', order='K', dtype=None, subok=True[, signature, extobj])
```

> Compute the bit-wise XOR of two arrays element-wise.
> 
> Computes the bit-wise XOR of the underlying binary representation of the integers in the input arrays. This ufunc implements the C/Python operator ^.

## [bitwise_not](https://numpy.org/doc/stable/reference/generated/numpy.invert.html)

> **bitwise_not is an alias for invert**

```python
numpy.invert(x, /, out=None, *, where=True, casting='same_kind', order='K', dtype=None, subok=True[, signature, extobj])
```

> Compute bit-wise inversion, or bit-wise NOT, element-wise.
> 
> Computes the bit-wise NOT of the underlying binary representation of the integers in the input arrays. This ufunc implements the C/Python operator ~.
> 
> For signed integer inputs, the two’s complement is returned.




