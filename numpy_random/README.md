# Numpy -- Random numbers the non-legacy way
## Goal
If you don't see something like **np.random.default_rng()** in your code then you are probably using the old [Legacy Random Generation](https://numpy.org/doc/stable/reference/random/legacy.html#legacy-random-generation).

**Don't use the legacy methods** for new source code!!!

Do it like this:
```python
import numpy as np

rng = np.random.default_rng()
random_values = rng.random(size=(2, 10))
```
Questions to [David Rotermund](mailto:davrot@uni-bremen.de)

## [Random Generator](https://numpy.org/doc/stable/reference/random/generator.html#random-generator)

### Typical usage
```python
import numpy as np

rng = np.random.default_rng()
random_values = rng.random(size=(2, 10))

print(random_values)
```
Output:
```
[[0.81103943 0.1110591  0.42978062 0.47818377 0.91138636 0.47051031
  0.08662082 0.1643707  0.48717037 0.17870536]
 [0.94499902 0.74089677 0.12221184 0.61603001 0.91198789 0.33900609
  0.75832792 0.74465679 0.19940125 0.56674595]]
```
### With seed:
```python
import numpy as np

rng = np.random.default_rng(seed=23)
random_values = rng.random(size=(2, 10))

print(random_values)
```
Output:
```
[[0.69393308 0.64145822 0.12864422 0.11370805 0.65334552 0.85345711
  0.20177913 0.21801864 0.71658464 0.47069967]
 [0.41522193 0.3491478  0.06385375 0.45466617 0.30145328 0.38907675
  0.54029782 0.68358969 0.62475238 0.74270445]]
```

## [Changing the random number generator](https://numpy.org/doc/stable/reference/random/bit_generators/index.html)
### Default
```python
import numpy as np

rng = np.random.default_rng()
print(rng)  # -> Generator(PCG64)
```
If you don't like it there are other options:

| | 
| -------------|
|[MT19937](https://numpy.org/doc/stable/reference/random/bit_generators/mt19937.html)|
|[PCG64](https://numpy.org/doc/stable/reference/random/bit_generators/pcg64.html)|
|[PCG64DXSM](https://numpy.org/doc/stable/reference/random/bit_generators/pcg64dxsm.html)|
|[Philox](https://numpy.org/doc/stable/reference/random/bit_generators/philox.html)|
|[SFC64](https://numpy.org/doc/stable/reference/random/bit_generators/sfc64.html)|

## [Distributions](https://numpy.org/doc/stable/reference/random/generator.html#distributions) (you will use)
The most important ones are in **bold**. If you see a function argument *out*, then you can reuse an existing np array (i.e. [in-place operation](https://numpy.org/doc/stable/reference/random/generator.html#in-place-vs-copy)) as target.

| | |
| ------------- |:-------------:|
|**[integers(low[, high, size, dtype, endpoint])](https://numpy.org/doc/stable/reference/random/generated/numpy.random.Generator.integers.html#numpy.random.Generator.integers)**| Return random integers from low (inclusive) to high (exclusive), or if endpoint=True, low (inclusive) to high (inclusive). |
|**[random([size, dtype, out])](https://numpy.org/doc/stable/reference/random/generated/numpy.random.Generator.random.html#numpy.random.Generator.random)** | Return random floats in the half-open interval [0.0, 1.0). |
|**[choice(a[, size, replace, p, axis, shuffle])](https://numpy.org/doc/stable/reference/random/generated/numpy.random.Generator.choice.html#numpy.random.Generator.choice)** | Generates a random sample from a given array |
|[bytes(length)](https://numpy.org/doc/stable/reference/random/generated/numpy.random.Generator.bytes.html#numpy.random.Generator.bytes) | Return random bytes. |
|[binomial(n, p[, size])](https://numpy.org/doc/stable/reference/random/generated/numpy.random.Generator.binomial.html#numpy.random.Generator.binomial) | Draw samples from a binomial distribution.|
|[multinomial(n, pvals[, size])](https://numpy.org/doc/stable/reference/random/generated/numpy.random.Generator.multinomial.html#numpy.random.Generator.multinomial) |Draw samples from a multinomial distribution. |
|[multivariate_normal(mean, cov[, size, ...])](https://numpy.org/doc/stable/reference/random/generated/numpy.random.Generator.multivariate_normal.html#numpy.random.Generator.multivariate_normal) | Draw random samples from a multivariate normal distribution.|
|**[normal([loc, scale, size])](https://numpy.org/doc/stable/reference/random/generated/numpy.random.Generator.normal.html#numpy.random.Generator.normal)** | Draw random samples from a normal (Gaussian) distribution.|
|**[poisson([lam, size])](https://numpy.org/doc/stable/reference/random/generated/numpy.random.Generator.poisson.html#numpy.random.Generator.poisson)** | Draw samples from a Poisson distribution.|
|[standard_normal([size, dtype, out])](https://numpy.org/doc/stable/reference/random/generated/numpy.random.Generator.standard_normal.html#numpy.random.Generator.standard_normal) | Draw samples from a standard Normal distribution (mean=0, stdev=1).|
|**[uniform([low, high, size])](https://numpy.org/doc/stable/reference/random/generated/numpy.random.Generator.uniform.html#numpy.random.Generator.uniform)** |Draw samples from a uniform distribution. |

### random
```python
import numpy as np

rng = np.random.default_rng()
random_values = rng.random(size=(2, 10))
print(random_values)
```
Output:
```
[[0.75309105 0.15751286 0.49454759 0.18204807 0.88459006 0.78685769
  0.68525047 0.4000365  0.45317167 0.62412358]
 [0.01082224 0.13257961 0.75638974 0.84886965 0.19755022 0.18697649
  0.47064409 0.66128207 0.30285691 0.53465021]]
```
### integers
```python
import numpy as np

rng = np.random.default_rng()
random_values = rng.integers(
    low=1, high=3, size=(2, 10), dtype=np.uint64, endpoint=True
)
print(random_values)
```
Output:
```
[[2 3 3 2 1 3 1 1 2 2]
 [3 3 2 3 3 2 3 3 1 3]]
```

### choice
```python
import numpy as np

rng = np.random.default_rng()
p = np.array([1, 2, 3]).astype(np.float64)
p /= p.sum()
print(f"p: {p}")
random_values = rng.choice(a=p.shape[0], p=p, size=(2, 10))
print(random_values)
```
Output:
```
p: [0.16666667 0.33333333 0.5       ]
[[0 2 2 1 2 1 2 1 0 1]
 [2 0 1 2 2 1 0 2 1 2]]
```

## [Permutations](https://numpy.org/doc/stable/reference/random/generator.html#permutations)

| | |
| ------------- |:-------------:|
|[shuffle(x[, axis])](https://numpy.org/doc/stable/reference/random/generated/numpy.random.Generator.shuffle.html#numpy.random.Generator.shuffle)|Modify an array or sequence in-place by shuffling its contents.|
|[permutation(x[, axis])](https://numpy.org/doc/stable/reference/random/generated/numpy.random.Generator.permutation.html#numpy.random.Generator.permutation)|Randomly permute a sequence, or return a permuted range.|
|[permuted(x[, axis, out])](https://numpy.org/doc/stable/reference/random/generated/numpy.random.Generator.permuted.html#numpy.random.Generator.permuted)|Randomly permute x along axis axis.|

|method |copy/in-place | [	axis handling](https://numpy.org/doc/stable/reference/random/generator.html#handling-the-axis-parameter) | 
| ------------- |:-------------:|:-------------:|
|shuffle|in-place|as if 1d|
|permutation|copy|as if 1d|
|permuted|either (use ‘out’ for in-place)|axis independent|

### shuffle
```python
import numpy as np

rng = np.random.default_rng()
idx_randomized = np.arange(0, 10)
rng.shuffle(idx_randomized)

print(idx_randomized)
```
Output:
```
[0 2 8 9 5 4 3 6 1 7]
```

### permutation
```python
import numpy as np

rng = np.random.default_rng()
idx_randomized = rng.permutation(10)

print(idx_randomized)
```
Output:
```
[9 4 7 2 6 3 1 8 5 0]
```

### permuted
```python
import numpy as np

rng = np.random.default_rng()
idx = np.arange(0, 10)

idx_randomized = rng.permuted(idx)

print(idx_randomized)
```
Output:
```
[4 1 2 8 9 6 0 5 7 3]
```
## All Distributions

You need more distributions? [Go here.](https://numpy.org/doc/stable/reference/random/generator.html#distributions)

## Multithreaded Generation

The four core distribution (random, standard_normal, standard_exponential, and standard_gamma) can be used with multi-threading. Please look [here for an example](https://numpy.org/doc/stable/reference/random/multithreading.html#multithreaded-generation). 


