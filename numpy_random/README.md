# Numpy -- Random numbers the non-legacy way
## Goal
If you don't see something like **np.random.default_rng()** in your code then you are probably using the old [Legacy Random Generation] (https://numpy.org/doc/stable/reference/random/legacy.html#legacy-random-generation).

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


