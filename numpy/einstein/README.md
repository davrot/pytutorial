# Einstein summation
{:.no_toc}

<nav markdown="1" class="toc-class">
* TOC
{:toc}
</nav>

## Top

Questions to [David Rotermund](mailto:davrot@uni-bremen.de)


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
> In implicit mode, the chosen subscripts are important since the axes of the output are reordered alphabetically. This means that np.einsum('ij', a) doesn’t affect a 2D array, while np.einsum('ji', a) takes its transpose. Additionally, np.einsum('ij,jk', a, b) returns a matrix multiplication, while, np.einsum('ij,jh', a, b) returns the transpose of the multiplication since subscript ‘h’ precedes subscript ‘i’.
> 
> In explicit mode the output can be directly controlled by specifying output subscript labels. This requires the identifier ‘->’ as well as the list of output subscript labels. This feature increases the flexibility of the function since summing can be disabled or forced when required. The call np.einsum('i->', a) is like np.sum(a, axis=-1), and np.einsum('ii->i', a) is like np.diag(a). The difference is that einsum does not allow broadcasting by default. Additionally np.einsum('ij,jh->ih', a, b) directly specifies the order of the output subscript labels and therefore returns matrix multiplication, unlike the example above in implicit mode.
> 
> To enable and control broadcasting, use an ellipsis. Default NumPy-style broadcasting is done by adding an ellipsis to the left of each term, like np.einsum('...ii->...i', a). To take the trace along the first and last axes, you can do np.einsum('i...i', a), or to do a matrix-matrix product with the left-most indices instead of rightmost, one can do np.einsum('ij...,jk...->ik...', a, b).
> 
> When there is only one operand, no axes are summed, and no output parameter is provided, a view into the operand is returned instead of a new array. Thus, taking the diagonal as np.einsum('ii->i', a) produces a view (changed in version 1.10.0).
> 
> einsum also provides an alternative way to provide the subscripts and operands as einsum(op0, sublist0, op1, sublist1, ..., [sublistout]). If the output shape is not provided in this format einsum will be calculated in implicit mode, otherwise it will be performed explicitly. The examples below have corresponding einsum calls with the two parameter methods.


