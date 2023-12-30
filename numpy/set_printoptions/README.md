# set_printoptions
{:.no_toc}

<nav markdown="1" class="toc-class">
* TOC
{:toc}
</nav>

## Top

Questions to [David Rotermund](mailto:davrot@uni-bremen.de)


## [numpy.set_printoptions](https://numpy.org/doc/stable/reference/generated/numpy.set_printoptions.html)

```python
numpy.set_printoptions(precision=None, threshold=None, edgeitems=None, linewidth=None, suppress=None, nanstr=None, infstr=None, formatter=None, sign=None, floatmode=None, *, legacy=None)[source]
```

> Set printing options.

```python
import numpy as np

rng = np.random.default_rng()
a = rng.random((4, 4))
print(a)
print()

np.set_printoptions(precision=2)
print(a)
```

Output:

```python
[[0.87875352 0.59057583 0.19169303 0.80039844]
 [0.90600053 0.98123781 0.42216646 0.40366859]
 [0.43339631 0.26896463 0.79994133 0.13280545]
 [0.93352167 0.46244181 0.58408661 0.09560924]]

[[0.88 0.59 0.19 0.8 ]
 [0.91 0.98 0.42 0.4 ]
 [0.43 0.27 0.8  0.13]
 [0.93 0.46 0.58 0.1 ]]
```

