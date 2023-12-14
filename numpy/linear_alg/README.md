# Linear algebra 
{:.no_toc}

<nav markdown="1" class="toc-class">
* TOC
{:toc}
</nav>

## The goal


Questions to [David Rotermund](mailto:davrot@uni-bremen.de)


The @ operator
Introduced in NumPy 1.10.0, the @ operator is preferable to other methods when computing the matrix product between 2d arrays. The numpy.matmul function implements the @ operator.

## [numpy.linalg](https://numpy.org/doc/stable/reference/routines.linalg.html)

### Matrix and vector products


|||
|---|---|
|[**dot(a, b[, out])**](https://numpy.org/doc/stable/reference/generated/numpy.dot.html#numpy.dot)|**Dot product of two arrays.**|
|[linalg.multi_dot(arrays, *[, out])](https://numpy.org/doc/stable/reference/generated/numpy.linalg.multi_dot.html#numpy.linalg.multi_dot)|Compute the dot product of two or more arrays in a single function call, while automatically selecting the fastest evaluation order.|
|[**vdot(a, b, /)**](https://numpy.org/doc/stable/reference/generated/numpy.vdot.html#numpy.vdot)|**Return the dot product of two vectors.**|
|[**inner(a, b, /)**](https://numpy.org/doc/stable/reference/generated/numpy.inner.html#numpy.inner)|**Inner product of two arrays.**|
|[**outer(a, b[, out])**](https://numpy.org/doc/stable/reference/generated/numpy.outer.html#numpy.outer)|**Compute the outer product of two vectors.**|
|[matmul(x1, x2, /[, out, casting, order, ...])](https://numpy.org/doc/stable/reference/generated/numpy.matmul.html#numpy.matmul)|Matrix product of two arrays.|
|[**tensordot(a, b[, axes])**](https://numpy.org/doc/stable/reference/generated/numpy.tensordot.html#numpy.tensordot)|**Compute tensor dot product along specified axes.**|
|[einsum(subscripts, *operands[, out, dtype, ...])](https://numpy.org/doc/stable/reference/generated/numpy.einsum.html#numpy.einsum)|Evaluates the Einstein summation convention on the operands.|
|[einsum_path(subscripts, *operands[, optimize])](https://numpy.org/doc/stable/reference/generated/numpy.einsum_path.html#numpy.einsum_path)|Evaluates the lowest cost contraction order for an einsum expression by considering the creation of intermediate arrays.|
|[linalg.matrix_power(a, n)](https://numpy.org/doc/stable/reference/generated/numpy.linalg.matrix_power.html#numpy.linalg.matrix_power)|Raise a square matrix to the (integer) power n.|
|[kron(a, b)](https://numpy.org/doc/stable/reference/generated/numpy.kron.html#numpy.kron)|Kronecker product of two arrays.|

### Decompositions

|||
|---|---|
|[linalg.cholesky(a)](https://numpy.org/doc/stable/reference/generated/numpy.linalg.cholesky.html#numpy.linalg.cholesky)|Cholesky decomposition.|
|[linalg.qr(a[, mode])](https://numpy.org/doc/stable/reference/generated/numpy.linalg.qr.html#numpy.linalg.qr)|Compute the qr factorization of a matrix.|
|[**linalg.svd(a[, full_matrices, compute_uv, ...])**](https://numpy.org/doc/stable/reference/generated/numpy.linalg.svd.html#numpy.linalg.svd)|**Singular Value Decomposition.**|

### Matrix eigenvalues

|||
|---|---|
|[**linalg.eig(a)**](https://numpy.org/doc/stable/reference/generated/numpy.linalg.eig.html#numpy.linalg.eig)|**Compute the eigenvalues and right eigenvectors of a square array.**|
|[linalg.eigh(a[, UPLO])](https://numpy.org/doc/stable/reference/generated/numpy.linalg.eigh.html#numpy.linalg.eigh)|Return the eigenvalues and eigenvectors of a complex Hermitian (conjugate symmetric) or a real symmetric matrix.|
|[linalg.eigvals(a)](https://numpy.org/doc/stable/reference/generated/numpy.linalg.eigvals.html#numpy.linalg.eigvals)|Compute the eigenvalues of a general matrix.|
|[linalg.eigvalsh(a[, UPLO])](https://numpy.org/doc/stable/reference/generated/numpy.linalg.eigvalsh.html#numpy.linalg.eigvalsh)|Compute the eigenvalues of a complex Hermitian or real symmetric matrix.|

### Norms and other numbers

|||
|---|---|
|[**linalg.norm(x[, ord, axis, keepdims])**](https://numpy.org/doc/stable/reference/generated/numpy.linalg.norm.html#numpy.linalg.norm)|**Matrix or vector norm.**|
|[linalg.cond(x[, p])](https://numpy.org/doc/stable/reference/generated/numpy.linalg.cond.html#numpy.linalg.cond)|Compute the condition number of a matrix.|
|[**linalg.det(a)**](https://numpy.org/doc/stable/reference/generated/numpy.linalg.det.html#numpy.linalg.det)|**Compute the determinant of an array.**|
|[linalg.matrix_rank(A[, tol, hermitian])](https://numpy.org/doc/stable/reference/generated/numpy.linalg.matrix_rank.html#numpy.linalg.matrix_rank)|Return matrix rank of array using SVD method|
|[linalg.slogdet(a)](https://numpy.org/doc/stable/reference/generated/numpy.linalg.slogdet.html#numpy.linalg.slogdet)|Compute the sign and (natural) logarithm of the determinant of an array.|
|[**trace(a[, offset, axis1, axis2, dtype, out])**](https://numpy.org/doc/stable/reference/generated/numpy.trace.html#numpy.trace)|**Return the sum along diagonals of the array.**|

### Solving equations and inverting matrices

|||
|---|---|
|[**linalg.solve(a, b)**](https://numpy.org/doc/stable/reference/generated/numpy.linalg.solve.html#numpy.linalg.solve)|**Solve a linear matrix equation, or system of linear scalar equations.**|
|[**linalg.tensorsolve(a, b[, axes])**](https://numpy.org/doc/stable/reference/generated/numpy.linalg.tensorsolve.html#numpy.linalg.tensorsolve)|**Solve the tensor equation a x = b for x.**|
|[linalg.lstsq(a, b[, rcond])](https://numpy.org/doc/stable/reference/generated/numpy.linalg.lstsq.html#numpy.linalg.lstsq)|Return the least-squares solution to a linear matrix equation.|
|[**linalg.inv(a)**](https://numpy.org/doc/stable/reference/generated/numpy.linalg.inv.html#numpy.linalg.inv)|**Compute the (multiplicative) inverse of a matrix.**|
|[**linalg.pinv(a[, rcond, hermitian])**](https://numpy.org/doc/stable/reference/generated/numpy.linalg.pinv.html#numpy.linalg.pinv)|**Compute the (Moore-Penrose) pseudo-inverse of a matrix.**|
|[**linalg.tensorinv(a[, ind])**](https://numpy.org/doc/stable/reference/generated/numpy.linalg.tensorinv.html#numpy.linalg.tensorinv)|**Compute the 'inverse' of an N-dimensional array.**|


