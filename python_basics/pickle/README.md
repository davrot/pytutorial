# Pickle
{:.no_toc}

<nav markdown="1" class="toc-class">
* TOC
{:toc}
</nav>

## The goal



Questions to [David Rotermund](mailto:davrot@uni-bremen.de)

## [pickle.dump](https://docs.python.org/3/library/pickle.html#pickle.dump) and [pickle.dumps](https://docs.python.org/3/library/pickle.html#pickle.dumps)

```python
pickle.dump(obj, file, protocol=None, *, fix_imports=True, buffer_callback=None)
```

> Write the pickled representation of the object obj to the open file object file. This is equivalent to Pickler(file, protocol).dump(obj).
> 
> Arguments file, protocol, fix_imports and buffer_callback have the same meaning as in the Pickler constructor.

```python
pickle.dumps(obj, protocol=None, *, fix_imports=True, buffer_callback=None)
```

> Return the pickled representation of the object obj as a bytes object, instead of writing it to a file.
> 
> Arguments protocol, fix_imports and buffer_callback have the same meaning as in the Pickler constructor.


```python
import pickle
import numpy as np


class Example:
    a: int
    b: float
    c: np.ndarray

    def __init__(self) -> None:
        super().__init__()
        self.a = 0
        self.b = 0
        self.c = np.zeros((1, 2))


instance_to_save = Example()
instance_to_save.a = 1
instance_to_save.b = 2
instance_to_save.c[0, 0] = 3
instance_to_save.c[0, 1] = 4

with open("test.pkl", "wb") as file:
    pickle.dump(instance_to_save, file)

print(instance_to_save.a)  # -> 1
print(instance_to_save.b)  # -> 2
print(instance_to_save.c)  # -> [[3. 4.]]
```

## [pickle.load](https://docs.python.org/3/library/pickle.html#pickle.load) and [pickle.loads](https://docs.python.org/3/library/pickle.html#pickle.loads)

```python
pickle.load(file, *, fix_imports=True, encoding='ASCII', errors='strict', buffers=None)
```

> Read the pickled representation of an object from the open file object file and return the reconstituted object hierarchy specified therein. This is equivalent to Unpickler(file).load().
> 
> The protocol version of the pickle is detected automatically, so no protocol argument is needed. Bytes past the pickled representation of the object are ignored.
> 
> Arguments file, fix_imports, encoding, errors, strict and buffers have the same meaning as in the Unpickler constructor.

```python
pickle.loads(data, /, *, fix_imports=True, encoding='ASCII', errors='strict', buffers=None)
```

> Return the reconstituted object hierarchy of the pickled representation data of an object. data must be a bytes-like object.
> 
> The protocol version of the pickle is detected automatically, so no protocol argument is needed. Bytes past the pickled representation of the object are ignored.
> 
> Arguments fix_imports, encoding, errors, strict and buffers have the same meaning as in the Unpickler constructor.

```python
import pickle
import numpy as np


class Example:
    a: int
    b: float
    c: np.ndarray

    def __init__(self) -> None:
        super().__init__()
        self.a = 0
        self.b = 0
        self.c = np.zeros((1, 2))


with open("test.pkl", "rb") as file:
    instance_to_load = pickle.load(file)

print(instance_to_load.a)  # -> 1
print(instance_to_load.b)  # -> 2
print(instance_to_load.c)  # -> [[3. 4.]]
```

