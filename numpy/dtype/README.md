# dtype
{:.no_toc}

<nav markdown="1" class="toc-class">
* TOC
{:toc}
</nav>

## The goal

A numpy matrix can have differnt dtype or -- in other words -- differnt types of numbers with different precisions. 

Questions to [David Rotermund](mailto:davrot@uni-bremen.de)

## Signed integer types​​

**Please use numpy.int8, numpy.int16, numpy.int32, and numpy.int64 !!!**


* *numpy.int8*: 8-bit signed integer (-128 to 127). Compatible with C char.​
  * *numpy.byte*​
  * Character code 'b'​

* *numpy.int16*: 16-bit signed integer (-32 768 to 32 767). Compatible with C short​
  * *numpy.short​*
  * Character code 'h'​

* *numpy.int32*: 32-bit signed integer (-2 147 483 648 to 2 147 483 647). Compatible with C int​

  * *numpy.intc​*
  * Character code 'i'​

​* *numpy.int64*: 64-bit signed integer (-9 223 372 036 854 775 808 to 9 223 372 036 854 775 807). ​Compatible with Python int and C long​
  * *numpy.intp​*
  * *numpy.int_​*
  * Character code 'l'​

  *numpy.longlong*: Compatible with C long long ​
  * Character code 'q'​

​
## Unsigned integer types​​

**Please use numpy.uint8, numpy.uint16, numpy.uint32, and numpy.uint64 !!!​**

* *numpy.uint8*: 8-bit unsigned integer (0 to 255). Compatible with C unsigned char.​
  * *numpy.ubyte​*
  * Character code 'B'​

* *numpy.uint16*: 16-bit unsigned integer (0 to 65 535). Compatible with C unsigned short.​
  * *numpy.ushort​*
  * Character code 'H'​

​* *numpy.uint32*: 32-bit unsigned integer (0 to 4 294 967 295). Compatible with C unsigned int.​
  * *numpy.uintc​*
  * Character code 'I'​

​* *numpy.uint64*: 64-bit unsigned integer (0 to 18 446 744 073 709 551 615). Compatible with C unsigned long​
  * numpy.uint​
  * numpy.uintp​
  * Character code 'L'​
  * numpy.ulonglong: Compatible with C unsigned long long​
  * Character code 'Q'


​

​

​

​
