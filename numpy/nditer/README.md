# nditer
{:.no_toc}

<nav markdown="1" class="toc-class">
* TOC
{:toc}
</nav>

## The goal

More iterating over an array...

Questions to [David Rotermund](mailto:davrot@uni-bremen.de)

{: .topic-optional}
This is an optional topic!

## [numpy.nditer](https://numpy.org/doc/stable/reference/generated/numpy.nditer.html)

```python
class numpy.nditer(op, flags=None, op_flags=None, op_dtypes=None, order='K', casting='safe', op_axes=None, itershape=None, buffersize=0)
```

> Efficient multi-dimensional iterator object to iterate over arrays. To get started using this object, see the [introductory guide to array iteration](https://numpy.org/doc/stable/reference/arrays.nditer.html#arrays-nditer).


## As a simple array iterator

Visiting every individual element of a matrix:​ 

```python
import numpy as np

a = np.arange(0, 9).reshape(3, 3)

for i in np.nditer(a):
    print(i)
```

Output:

```python
0
1
2
3
4
5
6
7
8
```

Ordered according to their memory layout. ​The parameter order can be used to change this behaviour:

> **order** : {‘C’, ‘F’, ‘A’, ‘K’}, optional
> 
> Controls the iteration order. ‘C’ means C order, ‘F’ means Fortran order, ‘A’ means ‘F’ order if all the arrays are Fortran contiguous, ‘C’ order otherwise, and ‘K’ means as close to the order the array elements appear in memory as possible. This also affects the element memory order of allocate operands, as they are allocated to be compatible with iteration order. Default is ‘K’.

```python
import numpy as np

a = np.arange(0, 9).reshape(3, 3)

print(a)
print()

for i in np.nditer(a, order="F"):
    print(i)
```

Output:

```python
[[0 1 2]
 [3 4 5]
 [6 7 8]]

0
3
6
1
4
7
2
5
8
```

## [readwrite](https://numpy.org/doc/stable/reference/arrays.nditer.html#modifying-array-values)

> **op_flags** : list of list of str, optional
> 
> The standard for nditer is **readonly** but we can change this to **readwrite** or **writeonly**:​
> 
> This is a list of flags for each operand. At minimum, one of readonly, readwrite, or writeonly must be specified.
> 
> **readonly** indicates the operand will only be read from.
> 
> **readwrite** indicates the operand will be read from and written to.
> 
> **writeonly** indicates the operand will only be written to.


> By default, the nditer treats the input operand as a read-only object. To be able to modify the array elements, you must specify either read-write or write-only mode using the ‘readwrite’ or ‘writeonly’ per-operand flags.
> 
> The nditer will then yield writeable buffer arrays which you may modify. However, because the nditer must copy this buffer data back to the original array once iteration is finished, you must signal when the iteration is ended, by one of two methods. You may either:
> 
> * used the nditer as a context manager using the with statement, and the temporary data will be written back when the context is exited.
> 
> * call the iterator’s close method once finished iterating, which will trigger the write-back.
> 
> The nditer can no longer be iterated once either close is called or its context is exited.

```python
import numpy as np

a = np.arange(0, 9).reshape(3, 3)

print(a)

with np.nditer(a, op_flags=["readwrite"]) as iterator:
    for i in iterator:
        i[...] = i + 10

print()
print(a)
```

Output:

```python
[[0 1 2]
 [3 4 5]
 [6 7 8]]

[[10 11 12]
 [13 14 15]
 [16 17 18]]
```

## [external_loop​](https://numpy.org/doc/stable/reference/arrays.nditer.html#using-an-external-loop)

> **flags** : sequence of str, optional
>
> **external_loop** causes the values given to be one-dimensional arrays with multiple values instead of zero-dimensional arrays.

> A better approach is to move the one-dimensional innermost loop into your code, external to the iterator. This way, NumPy’s vectorized operations can be used on larger chunks of the elements being visited.
>
> The nditer will try to provide chunks that are as large as possible to the inner loop. By forcing ‘C’ and ‘F’ order, we get different external loop sizes. This mode is enabled by specifying an iterator flag.


```python
import numpy as np

a = np.arange(0, 9).reshape(3, 3)

print(a)
print()

for i in np.nditer(a, flags=["external_loop"]):
    print(i)

print()
for i in np.nditer(a, flags=["external_loop"], order="F"):
    print(i)
```

Output:

```python
[[0 1 2]
 [3 4 5]
 [6 7 8]]

[0 1 2 3 4 5 6 7 8]

[0 3 6]
[1 4 7]
[2 5 8]
```

## external_loop and [buffered​](https://numpy.org/doc/stable/reference/arrays.nditer.html#buffering-the-array-elements)

> **flags** : sequence of str, optional
>
> **buffered** enables buffering when required.

Depending on the memory order you might get a set of chunks instead of one array. You can modify this via the **buffered** flag.​

```python
import numpy as np

a = np.arange(0, 9).reshape(3, 3)

print(a)
print()


for i in np.nditer(a, flags=["external_loop", "buffered"], order="F"):
    print(i)
```

Output:

```python
[[0 1 2]
 [3 4 5]
 [6 7 8]]

[0 3 6 1 4 7 2 5 8]
```

## Tracking an index [{c,f}_index](https://numpy.org/doc/stable/reference/arrays.nditer.html#alternative-looping-and-element-access)

> **flags** : sequence of str, optional
>
> * **c_index causes** a C-order index to be tracked.
>
> * **f_index** causes a Fortran-order index to be tracked.

```python
import numpy as np

a = np.arange(10, 19).reshape(3, 3)
b = np.arange(20, 29).reshape(3, 3)

print(a)
print()
print(b)
print()


with np.nditer(a, flags=["c_index"]) as iterator:
    for i in iterator:
        print(f"Index: {iterator.index} value a:{i} value b:{b.flat[iterator.index]}")

```

Output:

```python
[[10 11 12]
 [13 14 15]
 [16 17 18]]

[[20 21 22]
 [23 24 25]
 [26 27 28]]

Index: 0 value a:10 value b:20
Index: 1 value a:11 value b:21
Index: 2 value a:12 value b:22
Index: 3 value a:13 value b:23
Index: 4 value a:14 value b:24
Index: 5 value a:15 value b:25
Index: 6 value a:16 value b:26
Index: 7 value a:17 value b:27
Index: 8 value a:18 value b:28
```

## Tracking a [multi-index](https://numpy.org/doc/stable/reference/arrays.nditer.html#tracking-an-index-or-multi-index)

> **flags** : sequence of str, optional
> **multi_index** causes a multi-index, or a tuple of indices with one per iteration dimension, to be tracked.

```python
import numpy as np

a = np.arange(10, 19).reshape(3, 3)
b = np.arange(20, 29).reshape(3, 3)

print(a)
print()
print(b)
print()


with np.nditer(a, flags=["multi_index"]) as iterator:
    for i in iterator:
        print(f"Index: {iterator.multi_index} value a:{i}")


with np.nditer(a, flags=["multi_index"], op_flags=["readwrite"]) as iterator:
    for i in iterator:
        i[...] = b[iterator.multi_index] * 10

print()
print(a)
```

Output:

```python
[[10 11 12]
 [13 14 15]
 [16 17 18]]

[[20 21 22]
 [23 24 25]
 [26 27 28]]

Index: (0, 0) value a:10
Index: (0, 1) value a:11
Index: (0, 2) value a:12
Index: (1, 0) value a:13
Index: (1, 1) value a:14
Index: (1, 2) value a:15
Index: (2, 0) value a:16
Index: (2, 1) value a:17
Index: (2, 2) value a:18

[[200 210 220]
 [230 240 250]
 [260 270 280]]
```

## [Alternative looping​](https://numpy.org/doc/stable/reference/arrays.nditer.html#alternative-looping-and-element-access)

```python
nditer.iternext()
```
> Check whether iterations are left, and perform a single internal iteration without returning the result. Used in the C-style pattern do-while pattern. For an example, see nditer.
> 
> Returns:
> 
> **iternext** : bool
> Whether or not there are iterations left.


My personal suggestion/ taste is to adopt one style and stick to it. Use the with & for or the with & while construct, even if you only use ‘readonly’.​

```python
import numpy as np

a = np.arange(10, 19).reshape(3, 3)


print(a)
print()

with np.nditer(a, flags=["multi_index"], op_flags=["readwrite"]) as iterator:
    while not iterator.finished:
        iterator[0] = iterator[0] * 10
        status = (
            iterator.iternext()
        )  # If you forget this then you bought a ticket straight to hell.​
        print(status)

print()
print(a)
```

Output:

```python
[[10 11 12]
 [13 14 15]
 [16 17 18]]

True
True
True
True
True
True
True
True
False

[[100 110 120]
 [130 140 150]
 [160 170 180]]
```

**Note: If you forget iterator.iternext() then you bought a ticket straight to hell.​**

## [dtype casting​](https://numpy.org/doc/stable/reference/arrays.nditer.html#iterating-as-a-specific-data-type)


For dtype casting via **op_dtypes** parameter you need to activate **buffered** or **copy**.

> **op_dtypes**: dtype or tuple of dtype(s), optional
> 
> The required data type(s) of the operands. If **copying or buffering is enabled**, the data will be converted to/from their original types.

> **flags** : sequence of str, optional
> 
> **buffered** enables buffering when required.

> **op_flags** : list of list of str, optional
>
> **copy** allows a temporary read-only copy if required.

You can use this parameter to enable or disable safety functions:

> **casting** : {‘no’, ‘equiv’, ‘safe’, ‘same_kind’, ‘unsafe’}, optional
> 
> Controls what kind of data casting may occur when making a copy or buffering. Setting this to ‘unsafe’ is not recommended, as it can adversely affect accumulations.
> 
> * ‘no’ means the data types should not be cast at all.
> * ‘equiv’ means only byte-order changes are allowed.
> * ‘safe’ means only casts which can preserve values are allowed.
> * ‘same_kind’ means only safe casts or casts within a kind, like float64 to float32, are allowed.
> * ‘unsafe’ means any data conversions may be done.

## multi variable iteration (same shape)

```python
import numpy as np

a = np.arange(10, 19).reshape(3, 3)
b = np.arange(20, 29).reshape(3, 3)

print(a)
print()
print(b)
print()


with np.nditer([a, b], op_flags=["readwrite"]) as iterator:
    for x, y in iterator:
        print(f"value a:{x} value b:{y}")
        x[...] += y 

print()
print(a)
```

Output:

```python
[[10 11 12]
 [13 14 15]
 [16 17 18]]

[[20 21 22]
 [23 24 25]
 [26 27 28]]

value a:10 value b:20
value a:11 value b:21
value a:12 value b:22
value a:13 value b:23
value a:14 value b:24
value a:15 value b:25
value a:16 value b:26
value a:17 value b:27
value a:18 value b:28

[[30 32 34]
 [36 38 40]
 [42 44 46]]
```

## multi variable iteration (readonly, broadcast)​

In the case you do **NOT** want this this:

> **op_flags** : list of list of str, optional
> 
> **no_broadcast** prevents the operand from being broadcasted.

```python
import numpy as np

a = np.arange(10, 19).reshape(3, 3)
b = np.arange(20, 23)

print(a)
print()
print(b)
print()


with np.nditer([a, b]) as iterator:
    for x, y in iterator:
        print(f"value a:{x} value b:{y}")
```

Output:

```python
[[10 11 12]
 [13 14 15]
 [16 17 18]]

[20 21 22]

value a:10 value b:20
value a:11 value b:21
value a:12 value b:22
value a:13 value b:20
value a:14 value b:21
value a:15 value b:22
value a:16 value b:20
value a:17 value b:21
value a:18 value b:22
```

**readwrite** fails with this exception: 

```python
with np.nditer([a, b], op_flags=["readwrite"]) as iterator: ​# ValueError: output operand requires a reduction, but reduction is not enabled
    for x, y in iterator:
        print(f"value a:{x} value b:{y}")
```

## multi variable iteration (broadcast, selective rights)​

We can mark only the bigger one as writeable:​

```python
import numpy as np

a = np.arange(10, 19).reshape(3, 3)
b = np.arange(20, 23)

print(a)
print()
print(b)
print()


with np.nditer([a, b], op_flags=[["readwrite"], ["readonly"]]) as iterator:
    for x, y in iterator:
        print(f"value a:{x} value b:{y}")
```

Output:

```python
[[10 11 12]
 [13 14 15]
 [16 17 18]]

[20 21 22]

value a:10 value b:20
value a:11 value b:21
value a:12 value b:22
value a:13 value b:20
value a:14 value b:21
value a:15 value b:22
value a:16 value b:20
value a:17 value b:21
value a:18 value b:22
```

Or we can activate the **reduce_ok** flag for the smaller one:​

> **flags** : sequence of str, optional
> 
> **reduce_ok** enables iteration of readwrite operands which are broadcasted, also known as reduction operands.

```python
import numpy as np

a = np.arange(10, 19).reshape(3, 3)
b = np.zeros((3))

print(a)
print()
print(b)
print()


with np.nditer([a, b], flags=["reduce_ok"], op_flags=["readwrite"]) as iterator:
    for x, y in iterator:
        y[...] += x

print(b)
```

Output:

```python
[[10 11 12]
 [13 14 15]
 [16 17 18]]

[0. 0. 0.]

[39. 42. 45.]
```

## [making something from nothing (i.e. None)](https://numpy.org/doc/stable/reference/arrays.nditer.html#iterator-allocated-output-arrays)

> By default, the nditer uses the flags ‘allocate’ and ‘writeonly’ for operands that are passed in as None. This means we were able to provide just the two operands to the iterator, and it handled the rest.

**However, “None” is full of junk in the beginning!**

```python
import numpy as np

a = np.arange(10, 19).reshape(3, 3)

print(a)
print()


with np.nditer([a, None]) as iterator:
    for x, y in iterator:
        y[...] += x**2
    out_1 = iterator.operands[0]
    out_2 = iterator.operands[1]
print(out_1)
print()
print(out_2)
```

* **iterator.operands[0] formerly known as A**
* **iterator.operands[1] formerly known as None**

Output:

```python
[[10 11 12]
 [13 14 15]
 [16 17 18]]

[[10 11 12]
 [13 14 15]
 [16 17 18]]

[[130 153 178]
 [205 234 265]
 [298 333 370]]
```

You can fix the junk in None by: 

```python
import numpy as np

a = np.arange(10, 19).reshape(3, 3)

print(a)
print()


with np.nditer([a, None]) as iterator:
    iterator.operands[1][...] = 0
    for x, y in iterator:
        y[...] += x**2
    out_1 = iterator.operands[0]
    out_2 = iterator.operands[1]
print(out_1)
print()
print(out_2)
```

Output:

```python
[[10 11 12]
 [13 14 15]
 [16 17 18]]

[[10 11 12]
 [13 14 15]
 [16 17 18]]

[[100 121 144]
 [169 196 225]
 [256 289 324]]
```

## op_axes​

> **op_axes** : list of list of ints, optional
> 
> If provided, is a list of ints or None for each operands. The list of axes for an operand is a mapping from the dimensions of the iterator to the dimensions of the operand. A value of -1 can be placed for entries, causing that dimension to be treated as newaxis.

```python
import numpy as np

a = np.arange(0, 9).reshape(3, 3)
b = np.arange(0, 3)

print(a)
print()
print(b)
print()


with np.nditer([a, b]) as iterator:
    for x, y in iterator:
        print(f"a:{x} b:{y}")
print()

with np.nditer([a, b], op_axes=[[0, 1], [-1, 0]]) as iterator:
    for x, y in iterator:
        print(f"a:{x} b:{y}")
print()

with np.nditer([a, b], op_axes=[[0, 1], [0, -1]]) as iterator:
    for x, y in iterator:
        print(f"a:{x} b:{y}")
print()
```

Output:

```python
[[0 1 2]
 [3 4 5]
 [6 7 8]]

[0 1 2]

a:0 b:0
a:1 b:1
a:2 b:2
a:3 b:0
a:4 b:1
a:5 b:2
a:6 b:0
a:7 b:1
a:8 b:2

a:0 b:0
a:1 b:1
a:2 b:2
a:3 b:0
a:4 b:1
a:5 b:2
a:6 b:0
a:7 b:1
a:8 b:2

a:0 b:0
a:1 b:0
a:2 b:0
a:3 b:1
a:4 b:1
a:5 b:1
a:6 b:2
a:7 b:2
a:8 b:2
```

Or only one matrix: 

```python
import numpy as np

a = np.arange(0, 9).reshape(3, 3)

print(a)
print()


with np.nditer([a]) as iterator:
    for x in iterator:
        print(f"a:{x}")
print()

with np.nditer([a], op_axes=[[0]]) as iterator:
    for x in iterator:
        print(f"a:{x}")
print()

with np.nditer([a], op_axes=[[1]]) as iterator:
    for x in iterator:
        print(f"a:{x}")
print()
```

Output:

```python
[[0 1 2]
 [3 4 5]
 [6 7 8]]

a:0
a:1
a:2
a:3
a:4
a:5
a:6
a:7
a:8

a:0
a:3
a:6

a:0
a:1
a:2
```

## parameters galore

> **flags** : sequence of str, optional
>
> **delay_bufalloc** delays allocation of the buffers until a **reset()** call is made. Allows allocate operands to be initialized before their values are copied into the buffers.

> **op_flags** : list of list of str, optional
>
> **allocate** causes the array to be allocated if it is None in the op parameter.

```python
nditer.reset()
```

> Reset the iterator to its initial state.

```python
import numpy as np

a = np.arange(0, 9).reshape(3, 3)

print(a)
print()

with np.nditer(
    [a, None],
    flags=["reduce_ok", "buffered", "delay_bufalloc"],
    op_flags=[["readonly"], ["readwrite", "allocate"]],
    op_axes=[None, [0, -1]],
) as iterator:
    iterator.operands[1][...] = 0
    iterator.reset()

    for x, y in iterator:
        y[...] += x
    out = iterator.operands[1]
print(out)
```

Output:

```python
[[0 1 2]
 [3 4 5]
 [6 7 8]]

[ 3 12 21]
```

