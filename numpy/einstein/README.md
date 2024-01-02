# Einstein summation
{:.no_toc}

<nav markdown="1" class="toc-class">
* TOC
{:toc}
</nav>

## Top

Questions to [David Rotermund](mailto:davrot@uni-bremen.de)

## Examples

$$b = \sum_i a_{i,i}$$

```python
import numpy as np

a = np.arange(0, 25).reshape(5, 5)
print(a)
print(a.shape)  # -> (5, 5)

print(np.einsum("ii", a)) # -> 60
print(np.einsum(a, [0, 0]))  # -> 60
print(np.einsum(a, [0, 0], []))  # -> 60
```

Output:

```python
[[ 0  1  2  3  4]
 [ 5  6  7  8  9]
 [10 11 12 13 14]
 [15 16 17 18 19]
 [20 21 22 23 24]]
```

$$b(i) = a_{i,i}$$

```python
import numpy as np

a = np.arange(0, 25).reshape(5, 5)
print(np.einsum("ii->i", a))  # -> [ 0  6 12 18 24]
print(np.einsum(a, [0, 0], [0]))  # -> [ 0  6 12 18 24]
```

$$b(i) = \sum_j a_{i,j}$$

```python
import numpy as np

a = np.arange(0, 25).reshape(5, 5)
print(np.einsum("ij->i", a))  # -> [ 10  35  60  85 110]
print(np.einsum(a, [0, 1], [0]))  # -> [ 10  35  60  85 110]
print(np.einsum("...j->...", a))  # -> [ 10  35  60  85 110]
print(np.einsum(a, [..., 1], [...]))  # -> [ 10  35  60  85 110]
```

$$b(j,i) = a_{i,j}$$

```python
import numpy as np

a = np.arange(0, 25).reshape(5, 5)
print(a)
print()
print(np.einsum("ij->ji", a))
print()
print(np.einsum(a, [0, 1], [1, 0]))
```

Output:

```python
[[ 0  1  2  3  4]
 [ 5  6  7  8  9]
 [10 11 12 13 14]
 [15 16 17 18 19]
 [20 21 22 23 24]]

[[ 0  5 10 15 20]
 [ 1  6 11 16 21]
 [ 2  7 12 17 22]
 [ 3  8 13 18 23]
 [ 4  9 14 19 24]]

[[ 0  5 10 15 20]
 [ 1  6 11 16 21]
 [ 2  7 12 17 22]
 [ 3  8 13 18 23]
 [ 4  9 14 19 24]]
```

$$b = \sum_i a_i a_i$$

```python
import numpy as np

a = np.arange(0, 5)
print(a) # -> [0 1 2 3 4]
print(np.einsum("i,i", a, a)) # -> 30
print(np.einsum(a, [0], a, [0]))  # -> 30
print(np.einsum(a, [0], a, [0], []))  # -> 30
```

$$c(i) = \sum_j a_{i,j} b_j$$

```python
import numpy as np


a = np.arange(0, 25).reshape(5, 5)
b = np.arange(0, 5)
print(a)
print()
print(b)  # -> [0 1 2 3 4]
print(np.einsum("ij,j", a, b))  # -> [ 30  80 130 180 230]
print(np.einsum(a, [0, 1], b, [1]))  # -> [ 30  80 130 180 230]
print(np.einsum(a, [0, 1], b, [1], [0]))  # -> [ 30  80 130 180 230]
```

```python
[[ 0  1  2  3  4]
 [ 5  6  7  8  9]
 [10 11 12 13 14]
 [15 16 17 18 19]
 [20 21 22 23 24]]
```

**Note: If you are repeating one einsum configuration, [numpy.einsum_path](https://numpy.org/doc/stable/reference/generated/numpy.einsum_path.html#numpy.einsum_path) might speed it up.**


## [numpy.einsum](https://numpy.org/doc/stable/reference/generated/numpy.einsum.html)

```python
numpy.einsum(subscripts, *operands, out=None, dtype=None, order='K', casting='safe', optimize=False)
```


> Evaluates the Einstein summation convention on the operands.
> 
> Using the Einstein summation convention, many common multi-dimensional, linear algebraic array operations can be represented in a simple fashion. In implicit mode einsum computes these values.
> 
> In explicit mode, einsum provides further flexibility to compute other array operations that might not be considered classical Einstein summation operations, by disabling, or forcing summation over specified subscript labels.
>
> 

> **subscripts** : str
> 
> Specifies the subscripts for summation as comma separated list of subscript labels. An implicit (classical Einstein summation) calculation is performed unless the explicit indicator ‘->’ is included as well as subscript labels of the precise output form.
> 
> **operands** : list of array_like
> 
> These are the arrays for the operation.

> The Einstein summation convention can be used to compute many multi-dimensional, linear algebraic array operations. einsum provides a succinct way of representing these.
>
> The subscripts string is a comma-separated list of subscript labels, where each label refers to a dimension of the corresponding operand. Whenever a label is repeated it is summed, so np.einsum('i,i', a, b) is equivalent to np.inner(a,b). If a label appears only once, it is not summed, so np.einsum('i', a) produces a view of a with no changes. A further example np.einsum('ij,jk', a, b) describes traditional matrix multiplication and is equivalent to np.matmul(a,b). Repeated subscript labels in one operand take the diagonal. For example, np.einsum('ii', a) is equivalent to np.trace(a).
> 
> In **implicit mode**, the chosen subscripts are important since the axes of the output are reordered alphabetically. This means that np.einsum('ij', a) doesn’t affect a 2D array, while np.einsum('ji', a) takes its transpose. Additionally, np.einsum('ij,jk', a, b) returns a matrix multiplication, while, np.einsum('ij,jh', a, b) returns the transpose of the multiplication since subscript ‘h’ precedes subscript ‘i’.
> 
> In **explicit mode** the output can be directly controlled by specifying output subscript labels. This requires the identifier ‘->’ as well as the list of output subscript labels. This feature increases the flexibility of the function since summing can be disabled or forced when required. The call np.einsum('i->', a) is like np.sum(a, axis=-1), and np.einsum('ii->i', a) is like np.diag(a). The difference is that einsum does not allow broadcasting by default. Additionally np.einsum('ij,jh->ih', a, b) directly specifies the order of the output subscript labels and therefore returns matrix multiplication, unlike the example above in implicit mode.
> 
> To enable and control broadcasting, use an ellipsis. Default NumPy-style broadcasting is done by adding an ellipsis to the left of each term, like np.einsum('...ii->...i', a). To take the trace along the first and last axes, you can do np.einsum('i...i', a), or to do a matrix-matrix product with the left-most indices instead of rightmost, one can do np.einsum('ij...,jk...->ik...', a, b).
> 
> When there is only one operand, no axes are summed, and no output parameter is provided, a view into the operand is returned instead of a new array. Thus, taking the diagonal as np.einsum('ii->i', a) produces a view (changed in version 1.10.0).
> 
> einsum also provides an alternative way to provide the subscripts and operands as einsum(op0, sublist0, op1, sublist1, ..., [sublistout]). If the output shape is not provided in this format einsum will be calculated in implicit mode, otherwise it will be performed explicitly. The examples below have corresponding einsum calls with the two parameter methods.

## [numpy.einsum_path](https://numpy.org/doc/stable/reference/generated/numpy.einsum_path.html#numpy-einsum-path)

```python
numpy.einsum_path(subscripts, *operands, optimize='greedy')
```

> Evaluates the lowest cost contraction order for an einsum expression by considering the creation of intermediate arrays.


```python
import numpy as np

rng = np.random.default_rng()

a = rng.random((2, 2))
b = rng.random((2, 5))
c = rng.random((5, 2))

print(a.shape)  # -> (2, 2)
print(b.shape)  # -> (2, 5)
print(c.shape)  # -> (5, 2)

path_info = np.einsum_path("ij,jk,kl->il", a, b, c, optimize="optimal")

print(path_info[0])  # -> ['einsum_path', (1, 2), (0, 1)]
print(path_info[1])
print()

print(np.einsum("ij,jk,kl->il", a, b, c, optimize=path_info[0]))
```

```python
  Complete contraction:  ij,jk,kl->il
         Naive scaling:  4
     Optimized scaling:  3
      Naive FLOP count:  1.200e+02
  Optimized FLOP count:  5.700e+01
   Theoretical speedup:  2.105
  Largest intermediate:  4.000e+00 elements
--------------------------------------------------------------------------
scaling                  current                                remaining
--------------------------------------------------------------------------
   3                   kl,jk->jl                                ij,jl->il
   3                   jl,ij->il                                   il->il

[[0.69016492 0.59064076]
 [1.32938288 1.14208553]]
```
