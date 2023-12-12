# Tuple
{:.no_toc}

<nav markdown="1" class="toc-class">
* TOC
{:toc}
</nav>

## The goal

Tuple are a non-mutable container which is typically used for heterogenic data types and is very important for functions with multiple return values.

Questions to [David Rotermund](mailto:davrot@uni-bremen.de)


## [Tuples​](https://docs.python.org/3/library/stdtypes.html#tuple​)

> Tuples are immutable sequences, typically used to store collections of heterogeneous data (such as the 2-tuples produced by the enumerate() built-in). Tuples are also used for cases where an immutable sequence of homogeneous data is needed (such as allowing storage in a set or dict instance).

# Examples

A tuple is a list of stuff that is enclosed in **( )** and seperated by **,** . An optional **,** after the last element is allowed. 

```python
a = (
    "a",
    "b",
    "c",
)
print(a)

a = ("a", "b", "c")
print(a)
```

Output:

```python
('a', 'b', 'c')
('a', 'b', 'c')
```

## Immutable

After creating a tuple cannot be modified. They are immutable.

```python
a = (
    "a",
    "b",
    "c",
)

a[0] = "d" # -> TypeError: 'tuple' object does not support item assignment
```

But this doesn't mean that we can not stored mutable objects in a tuple. Furthermore these mutable objects stay mutable. 

```python
a = (
    ["a"],
    "b",
    "c",
)

a[0][0] = "d" # Okay, because changes the content of the list stored in a[0]
a[0] = "d" # -> TypeError: 'tuple' object does not support item assignment
```

## Indexing

Idexing is the same as in lists. 

```python
a = (
    "a",
    2,
    3.3,
)

print(a[0]) # -> a
print(a[1]) # -> 2
print(a[-1]) # -> 3.3
print(a[:1]) # -> ('a',)
print(a[1:]) # -> (2, 3.3)
print(a[::2]) # -> ('a', 3.3)
```

## *

```python
a = (
    "a",
    2,
    3.3,
)

print(a*3)
print(3*a)
```

Output:

```python
('a', 2, 3.3, 'a', 2, 3.3, 'a', 2, 3.3)
('a', 2, 3.3, 'a', 2, 3.3, 'a', 2, 3.3)
```

## len()

```python
a = (
    "a",
    2,
    3.3,
)

print(len(a)) # -> 3
```

## +

```python
a = (
    "a",
    2,
    3.3,
)

b = (
    "b",
    8.8,
    5,
)

print(a+b) # -> ('a', 2, 3.3, 'b', 8.8, 5)
print(b+a) # -> ('b', 8.8, 5, 'a', 2, 3.3)
```

## in 

```python
a = (
    "a",
    2,
    3.3,
)


print(2 in a) # -> True
print(2 not in a) # -> False
```

## index()

```python
a = (
    "a",
    2,
    3.3,
)


print(a.index(2)) # -> 1 
print(a.index("a")) # -> 0
```

## count()

```python
a = (
    "a",
    2,
    3.3,
    "a",
    2,
    2,
)


print(a.count(2)) # -> 3
print(a.count("a")) # -> 2 
```

## min() and max()

```python
a = (
    9,
    2,
    3.3,
    22,
    2,
    2,
)

print(min(a)) # -> 2
print(max(a)) # -> 22
```

Strings are not allowed

```python
a = (
    "a",
    2,
    3.3,
    "a",
    2,
    2,
)


print(min(a))
print(max(a))
```

Output:

```python
TypeError: '<' not supported between instances of 'int' and 'str'
```

## [Common Sequence Operations](https://docs.python.org/3/library/stdtypes.html#sequence-types-list-tuple-range​)


|Operation​|Result​|
|---|---|
|x in s​|True if an item of s is equal to x, else False​|
|x not in s​|False if an item of s is equal to x, else True​|
|s + t​|the concatenation of s and t​|
|s * n or n * s​|equivalent to adding s to itself n times​|
|s[i]|​ith item of s, origin 0​|
|s[i:j]|​slice of s from i to j​|
|s[i:j:k]|​slice of s from i to j with step k​|
|len(s)​|length of s​|
|min(s)​|smallest item of s​|
|max(s)​|largest item of s​|
|s.index(x[, i[, j]])​|index of the first occurrence of x in s (at or after index i and before index j)​|
|s.count(x)​|total number of occurrences of x in s​|

