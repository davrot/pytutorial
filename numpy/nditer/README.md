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


