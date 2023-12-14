# Boolean matricies and logic functions
{:.no_toc}

<nav markdown="1" class="toc-class">
* TOC
{:toc}
</nav>

## The goal


Questions to [David Rotermund](mailto:davrot@uni-bremen.de)


## [Logic functions](https://numpy.org/doc/stable/reference/routines.logic.html)

### [Truth value testing](https://numpy.org/doc/stable/reference/routines.logic.html#truth-value-testing)

|||
|---|---|
|[all(a[, axis, out, keepdims, where])](https://numpy.org/doc/stable/reference/generated/numpy.all.html#numpy.all)|Test whether all array elements along a given axis evaluate to True.|
|[any(a[, axis, out, keepdims, where])](https://numpy.org/doc/stable/reference/generated/numpy.any.html#numpy.any)|Test whether any array element along a given axis evaluates to True.|

### [Array contents](https://numpy.org/doc/stable/reference/routines.logic.html#array-contents)

|||
|---|---|
|[isfinite(x, /[, out, where, casting, order, ...])](https://numpy.org/doc/stable/reference/generated/numpy.isfinite.html#numpy.isfinite)|Test element-wise for finiteness (not infinity and not Not a Number).|
|[isinf(x, /[, out, where, casting, order, ...])](https://numpy.org/doc/stable/reference/generated/numpy.isinf.html#numpy.isinf)|Test element-wise for positive or negative infinity.|
|[isnan(x, /[, out, where, casting, order, ...])](https://numpy.org/doc/stable/reference/generated/numpy.isnan.html#numpy.isnan)|Test element-wise for NaN and return result as a boolean array.|
|[isnat(x, /[, out, where, casting, order, ...])](https://numpy.org/doc/stable/reference/generated/numpy.isnat.html#numpy.isnat)|Test element-wise for NaT (not a time) and return result as a boolean array.|
|[isneginf(x[, out])](https://numpy.org/doc/stable/reference/generated/numpy.isneginf.html#numpy.isneginf)|Test element-wise for negative infinity, return result as bool array.|
|[isposinf(x[, out])](https://numpy.org/doc/stable/reference/generated/numpy.isposinf.html#numpy.isposinf)|Test element-wise for positive infinity, return result as bool array.|

### [Array type testing](https://numpy.org/doc/stable/reference/routines.logic.html#array-type-testing)

|||
|---|---|
|[iscomplex(x)](https://numpy.org/doc/stable/reference/generated/numpy.iscomplex.html#numpy.iscomplex)|Returns a bool array, where True if input element is complex.|
|[iscomplexobj(x)](https://numpy.org/doc/stable/reference/generated/numpy.iscomplexobj.html#numpy.iscomplexobj)|Check for a complex type or an array of complex numbers.|
|[isfortran(a)](https://numpy.org/doc/stable/reference/generated/numpy.isfortran.html#numpy.isfortran)|Check if the array is Fortran contiguous but not C contiguous.|
|[isreal(x)](https://numpy.org/doc/stable/reference/generated/numpy.isreal.html#numpy.isreal)|Returns a bool array, where True if input element is real.|
|[isrealobj(x)](https://numpy.org/doc/stable/reference/generated/numpy.isrealobj.html#numpy.isrealobj)|Return True if x is a not complex type or an array of complex numbers.|
|[isscalar(element)](https://numpy.org/doc/stable/reference/generated/numpy.isscalar.html#numpy.isscalar)|Returns True if the type of element is a scalar type.|

### [Logical operations](https://numpy.org/doc/stable/reference/routines.logic.html#logical-operations)

|||
|---|---|
|[logical_and(x1, x2, /[, out, where, ...])](https://numpy.org/doc/stable/reference/generated/numpy.logical_and.html#numpy.logical_and)|Compute the truth value of x1 AND x2 element-wise.|
|[logical_or(x1, x2, /[, out, where, casting, ...])](https://numpy.org/doc/stable/reference/generated/numpy.logical_or.html#numpy.logical_or)|Compute the truth value of x1 OR x2 element-wise.|
|[logical_not(x, /[, out, where, casting, ...])](https://numpy.org/doc/stable/reference/generated/numpy.logical_not.html#numpy.logical_not)|Compute the truth value of NOT x element-wise.|
|[logical_xor(x1, x2, /[, out, where, ...])](https://numpy.org/doc/stable/reference/generated/numpy.logical_xor.html#numpy.logical_xor)|Compute the truth value of x1 XOR x2, element-wise.|

### [Comparison](https://numpy.org/doc/stable/reference/routines.logic.html#comparison)

|||
|---|---|
|[allclose(a, b[, rtol, atol, equal_nan])](https://numpy.org/doc/stable/reference/generated/numpy.allclose.html#numpy.allclose)|Returns True if two arrays are element-wise equal within a tolerance.|
|[isclose(a, b[, rtol, atol, equal_nan])](https://numpy.org/doc/stable/reference/generated/numpy.isclose.html#numpy.isclose)|Returns a boolean array where two arrays are element-wise equal within a tolerance.|
|[array_equal(a1, a2[, equal_nan])](https://numpy.org/doc/stable/reference/generated/numpy.array_equal.html#numpy.array_equal)|True if two arrays have the same shape and elements, False otherwise.|
|[array_equiv(a1, a2)](https://numpy.org/doc/stable/reference/generated/numpy.array_equiv.html#numpy.array_equiv)|Returns True if input arrays are shape consistent and all elements equal.|
|[greater(x1, x2, /[, out, where, casting, ...])](https://numpy.org/doc/stable/reference/generated/numpy.greater.html#numpy.greater)|Return the truth value of (x1 > x2) element-wise.|
|[greater_equal(x1, x2, /[, out, where, ...])](https://numpy.org/doc/stable/reference/generated/numpy.greater_equal.html#numpy.greater_equal)|Return the truth value of (x1 >= x2) element-wise.|
|[less(x1, x2, /[, out, where, casting, ...])](https://numpy.org/doc/stable/reference/generated/numpy.less.html#numpy.less)|Return the truth value of (x1 < x2) element-wise.|
|[less_equal(x1, x2, /[, out, where, casting, ...])](https://numpy.org/doc/stable/reference/generated/numpy.less_equal.html#numpy.less_equal)|Return the truth value of (x1 <= x2) element-wise.|
|[equal(x1, x2, /[, out, where, casting, ...])](https://numpy.org/doc/stable/reference/generated/numpy.equal.html#numpy.equal)|Return (x1 == x2) element-wise.|
|[not_equal(x1, x2, /[, out, where, casting, ...])](https://numpy.org/doc/stable/reference/generated/numpy.not_equal.html#numpy.not_equal)|Return (x1 != x2) element-wise.|

