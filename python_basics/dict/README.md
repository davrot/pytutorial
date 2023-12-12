# dict
{:.no_toc}

<nav markdown="1" class="toc-class">
* TOC
{:toc}
</nav>

## The goal



Questions to [David Rotermund](mailto:davrot@uni-bremen.de)

## [Mapping Types - dict​](https://docs.python.org/3/library/stdtypes.html#mapping-types-dict)

> A mapping object maps hashable values to arbitrary objects. Mappings are mutable objects. There is currently only one standard mapping type, the dictionary. ​
>
> A dictionary’s keys are almost arbitrary values. Values that are not hashable, that is, values containing lists, dictionaries or other mutable types (that are compared by value rather than by object identity) may not be used as keys. Numeric types used for keys obey the normal rules for numeric comparison: if two numbers compare equal (such as 1 and 1.0) then they can be used interchangeably to index the same dictionary entry. ​


## Examples 

### Keys with strings

To illustrate, the following examples all return a dictionary equal to ​

```python
{"one": 1, "two": 2, "three": 3}
```

```python
a = dict(one=1, two=2, three=3)
b = {"one": 1, "two": 2, "three": 3}
c = dict(zip(["one", "two", "three"], [1, 2, 3]))
d = dict([("two", 2), ("one", 1), ("three", 3)])
e = dict({"three": 3, "one": 1, "two": 2})
f = dict({"one": 1, "three": 3}, two=2)

print(a)
print(b)
print(c)
print(d)
print(e)
print(f)
```

Output:

```python
{'one': 1, 'two': 2, 'three': 3}
{'one': 1, 'two': 2, 'three': 3}
{'one': 1, 'two': 2, 'three': 3}
{'two': 2, 'one': 1, 'three': 3}
{'three': 3, 'one': 1, 'two': 2}
{'one': 1, 'three': 3, 'two': 2}
```
Even though they have a different order, they contain the same data. 

### Keys with numbers

A key doesn't need to be a string. A dictionary’s keys can be any hashable arbitrary values.

```python
a = {1: 1, 2: 2, 3: 3}
b = {1.1: 1, 2.2: 2, 3.3: 3}
print(a)
print(b)
```

Output:

```python
{1: 1, 2: 2, 3: 3}
{1.1: 1, 2.2: 2, 3.3: 3}
```

## [Operations](https://docs.python.org/3/library/stdtypes.html#mapping-types-dict)

|||
|---|---|
|list(d)​|Return a list of all the keys used in the dictionary d.​|
|len(d)​|Return the number of items in the dictionary d.​|
|d[key]|Return the item of d with key key. Raises a KeyError if key is not in the map.​|
|d[key] = value​|Set d[key] to value.​|
|del d[key]|Remove d[key] from d. Raises a KeyError if key is not in the map.​|
|key in d​|Return True if d has a key key, else False.​|
|key not in d​|Equivalent to not key in d.​|
|iter(d)​|Return an iterator over the keys of the dictionary. This is a shortcut for iter(d.keys()).​|
|clear()​|Remove all items from the dictionary.​|
|copy()​|Return a shallow copy of the dictionary.​|
|get(key[, default])​|Return the value for key if key is in the dictionary, else default. If default is not given, it defaults to None, so that this method never raises a KeyError.​|
|items()​|Return a new view of the dictionary’s items ((key, value) pairs). ​|
|keys()​|Return a new view of the dictionary’s keys.​|
|pop(key[, default])​|If key is in the dictionary, remove it and return its value, else return default. If default is not given and key is not in the dictionary, a KeyError is raised.​|
|popitem()​|Remove and return a (key, value) pair from the dictionary. Pairs are returned in LIFO order.​ popitem() is useful to destructively iterate over a dictionary, as often used in set algorithms. If the dictionary is empty, calling popitem() raises a KeyError.​|
|reversed(d)​|Return a reverse iterator over the keys of the dictionary. This is a shortcut for reversed(d.keys()).​|
|setdefault(key[, default])​|Update the dictionary with the key/value pairs from other, overwriting existing keys. Return None.​|
|values()​|Return a new view of the dictionary’s values. See the documentation of view objects.​|
|d \| other​|Create a new dictionary with the merged keys and values of d and other, which must both be dictionaries. The values of other take priority when d and other share keys.​|
|d \|= other​|Update the dictionary d with keys and values from other, which may be either a mapping or an iterable of key/value pairs. The values of other take priority when d and other share keys.​|

## list()

Convert the dictionary keys into a list.

```python
a = dict(one=1, two=2, three=3)
print(list(a)) # -> ['one', 'two', 'three']
```

## len()

```python
a = dict(one=1, two=2, three=3)
print(len(a)) # -> 3
```

## d[key]

```python
a = dict(one=1, two=2, three=3)
print(a["one"]) # -> 1
a["one"] = "Hello" 
print(a["one"]) # -> Hello
```

## in

```python
a = dict(one=1, two=2, three=3)
print("one" in a)  # -> True
print("xxx" not in a)  # -> True
print("one" not in a)  # -> False
```

# iter()

