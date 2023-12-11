# Sequence Types: list
{:.no_toc}

<nav markdown="1" class="toc-class">
* TOC
{:toc}
</nav>

## The goal

> Lists are **mutable** sequences, **typically** used to store collections of **homogeneous** items (where the precise degree of similarity will vary by application).​

[Quote](https://docs.python.org/3/library/stdtypes.html#lists)

Questions to [David Rotermund](mailto:davrot@uni-bremen.de)

## Example Lists

With homogeneous items:

```python
primes = [2, 3, 5, 7]

collection_of_strings = [
    "AA",
    "BB",
    "CC",
    "DD",
    "EE",
    "FF",
    "GG",
    "HH",
]
```

A mixture of type:

```python
def my_function(a):
    return a

my_favourite_things = [32, "sleep", my_function]
```

## Indexing

```python
collection_of_strings = [
    "AA",
    "BB",
    "CC",
    "DD",
    "EE",
    "FF",
    "GG",
    "HH",
]


print(collection_of_strings[0])  # -> AA
print(collection_of_strings[1])  # -> BB
print(collection_of_strings[-2])  # -> GG
print(collection_of_strings[-1])  # -> HH
```

## Slicing

```python
collection_of_strings = [
    "AA",
    "BB",
    "CC",
    "DD",
    "EE",
    "FF",
    "GG",
    "HH",
]


print(collection_of_strings[0:3])  # -> ['AA', 'BB', 'CC']
print(collection_of_strings[:3])  # -> ['AA', 'BB', 'CC']
print(collection_of_strings[3:])  # -> ['DD', 'EE', 'FF', 'GG', 'HH']
print(collection_of_strings[1:-1])  # -> ['BB', 'CC', 'DD', 'EE', 'FF', 'GG']
print(collection_of_strings[-3:])  # -> ['FF', 'GG', 'HH']
```

## Changing lists

```python
collection_of_strings = [
    "AA",
    "BB",
    "CC",
    "DD",
    "EE",
    "FF",
    "GG",
    "HH",
]

collection_of_strings[3] = "II"
print(collection_of_strings)  # -> ['AA', 'BB', 'CC', 'II', 'EE', 'FF', 'GG', 'HH']
collection_of_strings[:3] = ["JJ", "KK", "LL"]
print(collection_of_strings)  # -> ['JJ', 'KK', 'LL', 'II', 'EE', 'FF', 'GG', 'HH']
collection_of_strings[:4] = [
    "MM",
    "NN",
    "OO",
    "PP",
]
print(collection_of_strings)  # -> ['MM', 'NN', 'OO', 'PP', 'EE', 'FF', 'GG', 'HH']
```

## List functions

### [len()](https://docs.python.org/3/library/functions.html#len) and [sorted()](https://docs.python.org/3/library/functions.html#sorted)


```python
collection_of_strings = [
    "GG",
    "HH",
    "AA",
    "BB",
    "EE",
    "FF",
    "CC",
    "DD",
]


print(len(collection_of_strings))  # -> 8
print(sorted(collection_of_strings)) # -> ['AA', 'BB', 'CC', 'DD', 'EE', 'FF', 'GG', 'HH']
```

### [max()](https://docs.python.org/3/library/functions.html#max) and [sum()](https://docs.python.org/3/library/functions.html#sum)

```python
primes = [2, 3, 5, 7]
print(sum(primes)) # -> 17
print(max(primes)) # -> 7
```

### [append()](https://docs.python.org/3/tutorial/datastructures.html#more-on-lists), [pop()](https://docs.python.org/3/tutorial/datastructures.html#more-on-lists), and [remove()](https://docs.python.org/3/tutorial/datastructures.html#more-on-lists)

```python
collection_of_strings = [
    "AA",
    "BB",
    "BB",
    "CC",
    "DD",
    "EE",
    "FF",
    "GG",
    "HH",
]

collection_of_strings.append("II")
print(
    collection_of_strings
)  # -> ['AA', 'BB', 'BB', 'CC', 'DD', 'EE', 'FF', 'GG', 'HH', 'II']
print(collection_of_strings.pop())  # -> II
print(
    collection_of_strings
)  # -> ['AA', 'BB', 'BB', 'CC', 'DD', 'EE', 'FF', 'GG', 'HH']

collection_of_strings.remove("BB")
print(collection_of_strings)  # -> ['AA', 'BB', 'CC', 'DD', 'EE', 'FF', 'GG', 'HH']

collection_of_strings.remove("BB")
print(collection_of_strings)  # -> ['AA', 'BB', 'CC', 'DD', 'EE', 'FF', 'GG', 'HH']

collection_of_strings.remove("BB")
print(collection_of_strings)  # -> ValueError: list.remove(x): x not in list
```

## [Index](https://docs.python.org/3/tutorial/datastructures.html#more-on-lists)

```python
collection_of_strings = [
    "AA",
    "BB",
    "CC",
    "DD",
    "EE",
    "FF",
    "GG",
    "HH",
]

print(collection_of_strings.index("CC"))  # -> 2
print(collection_of_strings.index("XX"))  # -> ValueError: 'XX' is not in list
```

## [del](https://docs.python.org/3/tutorial/datastructures.html#the-del-statement) and [insert()](https://docs.python.org/3/tutorial/datastructures.html#more-on-lists)

```python
collection_of_strings = []
collection_of_strings.append("BB")
collection_of_strings.append("CC")
collection_of_strings.append("DD")
print(collection_of_strings)  # -> ['BB', 'CC', 'DD']

collection_of_strings.insert(0, "AA")
print(collection_of_strings)  # -> ['AA', 'BB', 'CC', 'DD']

del collection_of_strings[1]
print(collection_of_strings)  # -> ['AA', 'CC', 'DD']
```

## [Additional commands](https://docs.python.org/3/tutorial/datastructures.html)

||
|---|
|list.append(x)​|
|list.extend(iterable)​|
|list.insert(i, x)​|
|list.remove(x)|​
|list.pop([i])|​
|list.clear()​|
|list.index(x[, start[, end]])​|
|list.count(x)​|
|list.sort(*, key=None, reverse=False)​|
|list.reverse()|​
|list.copy()​|

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





