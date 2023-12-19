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


