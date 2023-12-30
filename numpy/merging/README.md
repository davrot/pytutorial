# Merging matrices
{:.no_toc}

<nav markdown="1" class="toc-class">
* TOC
{:toc}
</nav>

## Top

Questions to [David Rotermund](mailto:davrot@uni-bremen.de)


## [numpy.choose](https://numpy.org/doc/stable/reference/generated/numpy.choose.html#numpy-choose)

```python
numpy.choose(a, choices, out=None, mode='raise')
```

> Construct an array from an index array and a list of arrays to choose from.
> 
> First of all, if confused or uncertain, definitely look at the Examples - in its full generality, this function is less simple than it might seem from the following code description (below ndi = numpy.lib.index_tricks):
> 
> np.choose(a,c) == np.array([c[a[I]][I] for I in ndi.ndindex(a.shape)]).
> 
> But this omits some subtleties. Here is a fully general summary:
> 
> Given an “index” array (a) of integers and a sequence of n arrays (choices), a and each choice array are first broadcast, as necessary, to arrays of a common shape; calling these Ba and Bchoices[i], i = 0,…,n-1 we have that, necessarily, Ba.shape == Bchoices[i].shape for each i. Then, a new array with shape Ba.shape is created as follows:
> * if mode='raise' (the default), then, first of all, each element of a (and thus Ba) must be in the range [0, n-1]; now, suppose that i (in that range) is the value at the (j0, j1, ..., jm) position in Ba - then the value at the same position in the new array is the value in Bchoices[i] at that same position;
> * if mode='wrap', values in a (and thus Ba) may be any (signed) integer; modular arithmetic is used to map integers outside the range [0, n-1] back into that range; and then the new array is constructed as above;
> * if mode='clip', values in a (and thus Ba) may be any (signed) integer; negative integers are mapped to 0; values greater than n-1 are mapped to n-1; and then the new array is constructed as above.

```python
import numpy as np

a = np.arange(0, 9).reshape((3, 3))
print(a)
print()

b = np.arange(10, 19).reshape((3, 3))
print(b)
print()

c = np.arange(20, 29).reshape((3, 3))
print(c)
print()


rng = np.random.default_rng()
chosen_mask = rng.integers(size=c.shape, low=0, high=3)
print(chosen_mask)
print()

d = chosen_mask.choose((a, b, c))
print(d)
```

Output: 

```python
[[0 1 2]
 [3 4 5]
 [6 7 8]]

[[10 11 12]
 [13 14 15]
 [16 17 18]]

[[20 21 22]
 [23 24 25]
 [26 27 28]]

[[1 2 2]
 [0 0 1]
 [1 2 2]]

[[10 21 22]
 [ 3  4 15]
 [16 27 28]]
```

