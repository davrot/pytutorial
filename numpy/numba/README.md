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

For the example that will show you the options of optimization we need to understand the numba naming schema. 

### Numbers

For the function signatures we need to be able to translate the usual np.dtype into numpy.types.

For doing so we just replace **np.** by **numba.types.** .

|Type name(s)|	Shorthand|	Comments|
|---|---|---|
|numba.types.boolean	|b1|	represented as a byte|
|numba.types.uint8, byte	|u1|	8-bit unsigned byte|
|numba.types.uint16	|u2|	16-bit unsigned integer|
|numba.types.uint32	|u4|	32-bit unsigned integer|
|numba.types.uint64	|u8|	64-bit unsigned integer|
|numba.types.int8, char	|i1|	8-bit signed byte|
|numba.types.int16	|i2|	16-bit signed integer|
|numba.types.int32	|i4|	32-bit signed integer|
|numba.types.int64	|i8|	64-bit signed integer|
|numba.types.intc	|–|	C int-sized integer|
|numba.types.uintc	|–|	C int-sized unsigned integer|
|numba.types.intp	|–|	pointer-sized integer|
|numba.types.uintp	|–|	pointer-sized unsigned integer|
|numba.types.float32|	f4|	single-precision floating-point number|
|numba.types.float64, double|	f8|	double-precision floating-point number|
|numba.types.complex64|	c8|	single-precision complex number|
|numba.types.complex128|	c16|	double-precision complex number|

### Arrays

If we have arrays in the function signature, which is a very likely senario, we might want to give as much information to numpy as possible about the numpy.ndarray. In some cases it is very benificial to make a np.ndarray an array with C memory layout and tell numba about it.

We can use the numpy function **numpy.ascontiguousarray for** converting a numpy array into a C memory layout.

We can also check a numpy array, let's call it X, if it is already in the C memory layout. This is done by looking at **X.flags['C_CONTIGUOUS']**.

Some example for array signatures are: 

|||
|---|---|
|numba.types.float32[:]|	1d array of float32 with no particular memory layout|
|numba.types.float32[:,:]|	2d array of float32 with no particular memory layout|
|numba.types.float32[:,:,:]|	3d array of float32 with no particular memory layout|
|numba.types.float32[::1]|	1d array of float32 with C memory layout|
|numba.types.float32[:,::1]|	2d array of float32 with C memory layout|
|numba.types.float32[:,:,::1]|	3d array of float32 with C memory layout|
|numba.types.float32[::1,:]|	2d array of float32 with Fortran memory layout|
|numba.types.float32[::1,:,:]| 3d array of float32 with Fortran memory layout|

## An example (up to 437x faster)

