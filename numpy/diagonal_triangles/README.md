# Dealing with the main diagonal / triangles of a matrix
{:.no_toc}

<nav markdown="1" class="toc-class">
* TOC
{:toc}
</nav>

## Top

Questions to [David Rotermund](mailto:davrot@uni-bremen.de)

{: .topic-optional}
This is an optional topic!


## [numpy.fill_diagonal](https://numpy.org/doc/stable/reference/generated/numpy.fill_diagonal.html)

```python
numpy.fill_diagonal(a, val, wrap=False)
```

> Fill the main diagonal of the given array of any dimensionality.
> 
> For an array a with a.ndim >= 2, the diagonal is the list of locations with indices a[i, ..., i] all identical. This function modifies the input array in-place, it does not return a value.


## [numpy.diag_indices](https://numpy.org/doc/stable/reference/generated/numpy.diag_indices.html)

```python
numpy.diag_indices(n, ndim=2)
```

> Return the indices to access the main diagonal of an array.
> 
> This returns a tuple of indices that can be used to access the main diagonal of an array a with a.ndim >= 2 dimensions and shape (n, n, …, n). For a.ndim = 2 this is the usual diagonal, for a.ndim > 2 this is the set of indices to access a[i, i, ..., i] for i = [0..n-1].

## [numpy.diag_indices_from](https://numpy.org/doc/stable/reference/generated/numpy.diag_indices_from.html)

```python
numpy.diag_indices_from(arr)
```

> Return the indices to access the main diagonal of an n-dimensional array.


## [numpy.diag](https://numpy.org/doc/stable/reference/generated/numpy.diag.html)

```python
numpy.diag(v, k=0)
```

> Extract a diagonal or construct a diagonal array.
> 
> See the more detailed documentation for numpy.diagonal if you use this function to extract a diagonal and wish to write to the resulting array; whether it returns a copy or a view depends on what version of numpy you are using.


## [numpy.diagonal](https://numpy.org/doc/stable/reference/generated/numpy.diagonal.html)

```python
numpy.diagonal(a, offset=0, axis1=0, axis2=1)
```

> Return specified diagonals.
> 
> If a is 2-D, returns the diagonal of a with the given offset, i.e., the collection of elements of the form a[i, i+offset]. If a has more than two dimensions, then the axes specified by axis1 and axis2 are used to determine the 2-D sub-array whose diagonal is returned. The shape of the resulting array can be determined by removing axis1 and axis2 and appending an index to the right equal to the size of the resulting diagonals.

## [numpy.tril_indices_from](https://numpy.org/doc/stable/reference/generated/numpy.tril_indices_from.html)

```python
numpy.tril_indices_from(arr, k=0)
```

> Return the indices for the lower-triangle of arr.

## [numpy.tril_indices](https://numpy.org/doc/stable/reference/generated/numpy.tril_indices.html)

```python
numpy.tril_indices(n, k=0, m=None)
```

> Return the indices for the lower-triangle of an (n, m) array.

## [numpy.triu_indices_from](https://numpy.org/doc/stable/reference/generated/numpy.triu_indices_from.html)

```python
numpy.triu_indices_from(arr, k=0)
```

> Return the indices for the upper-triangle of arr.

## [numpy.triu_indices](https://numpy.org/doc/stable/reference/generated/numpy.triu_indices.html)

```python
numpy.triu_indices(n, k=0, m=None)
```

> Return the indices for the upper-triangle of an (n, m) array.

