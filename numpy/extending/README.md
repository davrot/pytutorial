# Extending an existing matrix
{:.no_toc}

<nav markdown="1" class="toc-class">
* TOC
{:toc}
</nav>

## The goal



Questions to [David Rotermund](mailto:davrot@uni-bremen.de)

## [numpy.tile](https://numpy.org/doc/stable/reference/generated/numpy.tile.html)

```python
numpy.tile(A, reps)
```

> Construct an array by repeating A the number of times given by reps.
> 
> If reps has length d, the result will have dimension of max(d, A.ndim).
> 
> If A.ndim < d, A is promoted to be d-dimensional by prepending new axes. So a shape (3,) array is promoted to (1, 3) for 2-D replication, or shape (1, 1, 3) for 3-D replication. If this is not the desired behavior, promote A to d-dimensions manually before calling this function.
> 
> If A.ndim > d, reps is promoted to A.ndim by pre-pending 1’s to it. Thus for an A of shape (2, 3, 4, 5), a reps of (2, 2) is treated as (1, 1, 2, 2).
> 
> Note : Although tile may be used for broadcasting, it is strongly recommended to use numpy’s broadcasting operations and functions.

