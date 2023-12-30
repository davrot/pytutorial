# zip
{:.no_toc}

<nav markdown="1" class="toc-class">
* TOC
{:toc}
</nav>

## Top

Questions to [David Rotermund](mailto:davrot@uni-bremen.de)

## [zip](https://docs.python.org/3/library/functions.html#zip)


```python
zip(*iterables, strict=False)
```

> Iterate over several iterables in parallel, producing tuples with an item from each one.

```python
a = zip([1, 2, 3], ["sugar", "spice", "everything nice"])
print(a)  # -> <zip object at 0x7f34987f4380>

for item in zip([1, 2, 3], ["sugar", "spice", "everything nice"]):
    print(item)
```

Output:

```python
(1, 'sugar')
(2, 'spice')
(3, 'everything nice')
```

> More formally: zip() returns an iterator of tuples, where the i-th tuple contains the i-th element from each of the argument iterables.

> By default, zip() stops when the shortest iterable is exhausted. It will ignore the remaining items in the longer iterables, cutting off the result to the length of the shortest iterable

> zip() is often used in cases where the iterables are assumed to be of equal length. In such cases, it’s recommended to use the strict=True option. Its output is the same as regular zip(). Unlike the default behavior, it raises a ValueError if one iterable is exhausted before the others.

