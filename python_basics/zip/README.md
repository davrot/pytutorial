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
