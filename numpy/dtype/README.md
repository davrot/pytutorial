# Available dtype
{:.no_toc}

<nav markdown="1" class="toc-class">
* TOC
{:toc}
</nav>

## The goal

A numpy matrix can have differnt dtype or -- in other words -- differnt types of numbers with different precisions. 

Questions to [David Rotermund](mailto:davrot@uni-bremen.de)

## [Signed integer types​​](https://numpy.org/doc/stable/reference/arrays.scalars.html#sized-aliases)

**Please use numpy.int8, numpy.int16, numpy.int32, and numpy.int64 !!!**

* *numpy.int8*:
  * 8-bit signed integer (-128 to 127). Compatible with C char.​
  * *numpy.byte*​
  * Character code 'b'​

* *numpy.int16*:
  * 16-bit signed integer (-32 768 to 32 767). Compatible with C short​
  * *numpy.short​*
  * Character code 'h'​

* *numpy.int32*:
  * 32-bit signed integer (-2 147 483 648 to 2 147 483 647). Compatible with C int​
  * *numpy.intc​*
  * Character code 'i'​

* *numpy.int64*:
  * 64-bit signed integer (-9 223 372 036 854 775 808 to 9 223 372 036 854 775 807). ​Compatible with Python int and C long​
  * *numpy.intp​*
  * *numpy.int_​*
  * Character code 'l'​
  * *numpy.longlong*: Compatible with C long long ​
  * Character code 'q'​

​
## [Unsigned integer types​​](https://numpy.org/doc/stable/reference/arrays.scalars.html#sized-aliases)

**Please use numpy.uint8, numpy.uint16, numpy.uint32, and numpy.uint64 !!!​**

* *numpy.uint8*:
  * 8-bit unsigned integer (0 to 255). Compatible with C unsigned char.​
  * *numpy.ubyte​*
  * Character code 'B'​

* *numpy.uint16*:
  * 16-bit unsigned integer (0 to 65 535). Compatible with C unsigned short.​
  * *numpy.ushort​*
  * Character code 'H'​

* *numpy.uint32*:
  * 32-bit unsigned integer (0 to 4 294 967 295). Compatible with C unsigned int.​
  * *numpy.uintc​*
  * Character code 'I'​

* *numpy.uint64*:
  * 64-bit unsigned integer (0 to 18 446 744 073 709 551 615). Compatible with C unsigned long​
  * numpy.uint​
  * numpy.uintp​
  * Character code 'L'​
  * *numpy.ulonglong*: Compatible with C unsigned long long​
  * Character code 'Q'

## [Floating-point types](https://numpy.org/doc/stable/reference/arrays.scalars.html#sized-aliases)
​
**Please use numpy.float32 and numpy.float64 !!! (And in very special cases numpy.float128)**
​
* *numpy.float16*:
  * 16-bit-precision. ​
  * *numpy.half*​
  * floating-point number type: sign bit, 5 bits exponent, 10 bits mantissa.​
  * Character code 'e'​

* *numpy.float32*:
  * 32-bit-precision. Compatible with C float​
  * *numpy.single​*
  * floating-point number type: sign bit, 8 bits exponent, 23 bits mantissa. ​
  * Character code 'f'​

* *numpy.float64*:
  * 64-bit precision. Compatible with Python float and C double. ​
  * *numpy.double​*
  * *numpy.float_​*
  * floating-point number type: sign bit, 11 bits exponent, 52 bits mantissa. ​
  * Character code 'd'​

* *numpy.float128*:
  * 128-bit extended-precision floating-point number type.​
  * *numpy.longdouble​*
  * *numpy.longfloat​*
  * Compatible with C long double but not necessarily with IEEE 754 quadruple-precision.​
  * Character code 'g'

​
## [Complex floating-point types​​](https://numpy.org/doc/stable/reference/arrays.scalars.html#sized-aliases)

**Please use numpy.complex64 and numpy.complex128 !!! (And in very special cases numpy.complex256)​**

* *​numpy.complex64*:
  * Composed of 2 32-bit-precision floating-point numbers.​
  * *numpy.singlecomplex​*
  * *numpy.csingle​*
  * Character code 'F'​

* *numpy.complex128*:
  * Composed of 2 64-bit-precision floating-point numbers. Compatible with Python complex. ​
  * *numpy.cdouble​*
  * *numpy.cfloat​*
  * *numpy.complex_​*
  * Character code 'D'

* *numpy.complex256*:
  * Composed of 2 128-bit extended-precision floating-point numbers. ​
  * *numpy.clongdouble​*
  * *numpy.clongfloat​*
  * *numpy.longcomplex​*
  * Character code 'G'

​
