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

```python
```

