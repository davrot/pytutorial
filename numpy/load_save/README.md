# [numpy.save](https://numpy.org/doc/stable/reference/generated/numpy.save.html) and [numpy.load](https://numpy.org/doc/stable/reference/generated/numpy.load.html)
{:.no_toc}

<nav markdown="1" class="toc-class">
* TOC
{:toc}
</nav>

## The goal
Let's [save and load data under numpy](https://numpy.org/doc/stable/reference/routines.io.html). This can be more complicated than expected.

Questions to [David Rotermund](mailto:davrot@uni-bremen.de)

## [np.save](https://numpy.org/doc/stable/reference/generated/numpy.save.html) and [np.load](https://numpy.org/doc/stable/reference/generated/numpy.load.html)
A normal np.save and np.load cycle may look like this:

```python
import numpy as np

rng = np.random.default_rng()

a_original: np.ndarray = rng.random((100, 10))

np.save("a.npy", a_original)
a_load: np.ndarray = np.load("a.npy")

print(np.abs(a_original - a_load).sum()) # -> 0.0
```

## [np.savez](https://numpy.org/doc/stable/reference/generated/numpy.savez.html)

We can save more than one variable into one file. We need to use np.savez for this. Now the file extension is npz instead of npy. This is required! 

```python
import numpy as np

rng = np.random.default_rng()

a_original = rng.random((100, 10))
b_original = rng.random((100, 10))
c_original = rng.random((100, 10))

np.savez("c.npz", a_original=a_original, b_original=b_original, c_original=c_original)

np_file = np.load("c.npz")

np_file_keys: list = list(np_file.keys())
print(np_file_keys) # -> ['a_original', 'b_original', 'c_original']
```

Please don't use savez like this because this can cause human errors down the road:

```python
import numpy as np

rng = np.random.default_rng()

a_original = rng.random((100, 10))
b_original = rng.random((100, 10))
c_original = rng.random((100, 10))

# np.savez("c.npz", a_original=a_original, b_original=b_original, c_original=c_original)
np.savez("d.npz", a_original, b_original, c_original)

np_file = np.load("d.npz")

np_file_keys: list = list(np_file.keys())
print(np_file_keys) # -> ['arr_0', 'arr_1', 'arr_2']
```

You don't need to keep the variable name but keep it human readable:

```python
import numpy as np

rng = np.random.default_rng()

a_original = rng.random((100, 10))
b_original = rng.random((100, 10))
c_original = rng.random((100, 10))
d_original = rng.random((100, 10))

np.savez("e.npz", what=a_original, a=b_original, nice=c_original, day=d_original)

np_file = np.load("e.npz")

np_file_keys: list = list(np_file.keys())
print(np_file_keys) # -> ['what', 'a', 'nice', 'day']
```
Now we can work with the file and the stored variables: 

```python
import numpy as np

rng = np.random.default_rng()

a_original = rng.random((100, 10))
b_original = rng.random((100, 10))
c_original = rng.random((100, 10))

np.savez("c.npz", a_original=a_original, b_original=b_original, c_original=c_original)

np_file = np.load("c.npz")

print(np.abs(a_original - np_file["a_original"]).sum())  # -> 0.0
print(np.abs(b_original - np_file["b_original"]).sum())  # -> 0.0
print(np.abs(c_original - np_file["c_original"]).sum())  # -> 0.0
```

## [np.savez_compressed](https://numpy.org/doc/stable/reference/generated/numpy.savez_compressed.html)

We can compress the data too:

```python
import numpy as np

rng = np.random.default_rng()

a_original = rng.random((100, 10))
b_original = rng.random((100, 10))
c_original = rng.random((100, 10))

np.savez_compressed(
    "f.npz", a_original=a_original, b_original=b_original, c_original=c_original
)

np_file = np.load("f.npz")

print(np.abs(a_original - np_file["a_original"]).sum())  # -> 0.0
print(np.abs(b_original - np_file["b_original"]).sum())  # -> 0.0
print(np.abs(c_original - np_file["c_original"]).sum())  # -> 0.0
```

## Text files [numpy.savetxt](https://numpy.org/doc/stable/reference/generated/numpy.savetxt.html) and [numpy.loadtxt](https://numpy.org/doc/stable/reference/generated/numpy.loadtxt.html)

```python
numpy.savetxt(fname, X, fmt='%.18e', delimiter=' ', newline='\n', header='', footer='', comments='# ', encoding=None)
```

> Save an array to a text file.

```python
import numpy as np

rng = np.random.default_rng()

a_original = rng.random((100, 10))

np.savetxt("data.txt", a_original)
```

```python
numpy.loadtxt(fname, dtype=<class 'float'>, comments='#', delimiter=None, converters=None, skiprows=0, usecols=None, unpack=False, ndmin=0, encoding='bytes', max_rows=None, *, quotechar=None, like=None)
```

> Load data from a text file.

```python
import numpy as np

rng = np.random.default_rng()

a_original = rng.random((100, 10))

np.savetxt("data.txt", a_original)

a_load = np.loadtxt("data.txt")

print(a_original.shape)  # -> (100, 10)
print(a_load.shape)  # -> (100, 10)
print(np.abs(a_original - a_load).sum())  # -> 0.0
```

### [numpy.genfromtxt](https://numpy.org/doc/stable/reference/generated/numpy.genfromtxt.html)

{: .topic-optional}
This is an optional topic!

```python
numpy.genfromtxt(fname, dtype=<class 'float'>, comments='#', delimiter=None, skip_header=0, skip_footer=0, converters=None, missing_values=None, filling_values=None, usecols=None, names=None, excludelist=None, deletechars=" !#$%&'()*+, -./:;<=>?@[\\]^{|}~", replace_space='_', autostrip=False, case_sensitive=True, defaultfmt='f%i', unpack=None, usemask=False, loose=True, invalid_raise=True, max_rows=None, encoding='bytes', *, ndmin=0, like=None)
```

> Load data from a text file, with missing values handled as specified.
> 
> Each line past the first skip_header lines is split at the delimiter character, and characters following the comments character are discarded.
