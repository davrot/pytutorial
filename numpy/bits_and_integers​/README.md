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

```python
import numpy as np

v = np.uint16(255)

print(f"{v:016b}")  # -> 0000000011111111

print(f"{v.byteswap():016b}")  # -> 1111111100000000
```

## [numpy.bitwise_and](https://numpy.org/doc/stable/reference/generated/numpy.bitwise_and.html)

```python
numpy.bitwise_and(x1, x2, /, out=None, *, where=True, casting='same_kind', order='K', dtype=None, subok=True[, signature, extobj])
```

> Compute the bit-wise AND of two arrays element-wise.
> 
> Computes the bit-wise AND of the underlying binary representation of the integers in the input arrays. This ufunc implements the C/Python operator &.

```python
import numpy as np

a = [True, True, False, False]
b = [True, False, True, False]

u = 3
v = 5

print(f"{u:04b}")  # -> 0011
print(f"{v:04b}")  # -> 0101

print(np.bitwise_and(a, b)) # -> [ True False False False]
print(f"{np.bitwise_and(u, v):04b}") # -> 0001
```

## [numpy.bitwise_or](https://numpy.org/doc/stable/reference/generated/numpy.bitwise_or.html)

```python
numpy.bitwise_or(x1, x2, /, out=None, *, where=True, casting='same_kind', order='K', dtype=None, subok=True[, signature, extobj]) 
```

>  Compute the bit-wise OR of two arrays element-wise.
>  
> Computes the bit-wise OR of the underlying binary representation of the integers in the input arrays. This ufunc implements the C/Python operator \|.

```python
import numpy as np

a = [True, True, False, False]
b = [True, False, True, False]

u = 3
v = 5

print(f"{u:04b}")  # -> 0011
print(f"{v:04b}")  # -> 0101

print(np.bitwise_or(a, b))  # -> [ True  True  True False]
print(f"{np.bitwise_or(u, v):04b}")  # -> 0111
```

## [numpy.bitwise_xor](https://numpy.org/doc/stable/reference/generated/numpy.bitwise_xor.html)

```python
numpy.bitwise_xor(x1, x2, /, out=None, *, where=True, casting='same_kind', order='K', dtype=None, subok=True[, signature, extobj])
```

> Compute the bit-wise XOR of two arrays element-wise.
> 
> Computes the bit-wise XOR of the underlying binary representation of the integers in the input arrays. This ufunc implements the C/Python operator ^.

```python
import numpy as np

a = [True, True, False, False]
b = [True, False, True, False]

u = 3
v = 5

print(f"{u:04b}")  # -> 0011
print(f"{v:04b}")  # -> 0101

print(np.bitwise_xor(a, b))  # -> [False  True  True False]
print(f"{np.bitwise_xor(u, v):04b}")  # -> 0110
```

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

```python
import numpy as np

a = [True, True, False, False]

u = 3
v = np.uint8(u)

print(f"{u:08b}")  # -> 00000011
print(f"{v:08b}")  # -> 00000011

print(np.bitwise_not(a))  # -> [False False  True  True]
print(f"{np.bitwise_not(u)}")  # -> -4
print(f"{np.bitwise_not(v):08b}")  # -> 11111100
```


## [numpy.left_shift](https://numpy.org/doc/stable/reference/generated/numpy.left_shift.html)

```python
numpy.left_shift(x1, x2, /, out=None, *, where=True, casting='same_kind', order='K', dtype=None, subok=True[, signature, extobj])
```

> Shift the bits of an integer to the left.
> 
> Bits are shifted to the left by appending x2 0s at the right of x1. Since the internal representation of numbers is in binary format, this operation is equivalent to multiplying x1 by 2**x2

## [numpy.right_shift](https://numpy.org/doc/stable/reference/generated/numpy.right_shift.html)

```python
numpy.right_shift(x1, x2, /, out=None, *, where=True, casting='same_kind', order='K', dtype=None, subok=True[, signature, extobj])
```

> Shift the bits of an integer to the right.
> 
> Bits are shifted to the right x2. Because the internal representation of numbers is in binary format, this operation is equivalent to dividing x1 by 2**x2.

## [numpy.binary_repr](https://numpy.org/doc/stable/reference/generated/numpy.binary_repr.html)

```python
numpy.binary_repr(num, width=None)
```

> Return the binary representation of the input number as a string.





