# Numba
{:.no_toc}

<nav markdown="1" class="toc-class">
* TOC
{:toc}
</nav>

## The goal

["Numba is an open source JIT compiler that translates a subset of Python and NumPy code into fast machine code."](https://numba.pydata.org/)

Questions to [David Rotermund](mailto:davrot@uni-bremen.de)

```shell
pip install numba
```

[A ~5 minute guide to Numba](https://numba.pydata.org/numba-doc/latest/user/5minguide.html)

## [Numba basic types](https://numba.pydata.org/numba-doc/dev/reference/types.html)


|Type name(s)|	Shorthand|	Comments|
|---|---|---|
|boolean	|b1|	represented as a byte|
|uint8, byte	|u1|	8-bit unsigned byte|
|uint16	|u2|	16-bit unsigned integer|
|uint32	|u4|	32-bit unsigned integer|
|uint64	|u8|	64-bit unsigned integer|
|int8, char	|i1|	8-bit signed byte|
|int16	|i2|	16-bit signed integer|
|int32	|i4|	32-bit signed integer|
|int64	|i8|	64-bit signed integer|
|intc	|–|	C int-sized integer|
|uintc	|–|	C int-sized unsigned integer|
|intp	|–|	pointer-sized integer|
|uintp	|–|	pointer-sized unsigned integer|
|float32|	f4|	single-precision floating-point number|
|float64, double|	f8|	double-precision floating-point number|
|complex64|	c8|	single-precision complex number|
|complex128|	c16|	double-precision complex number|


