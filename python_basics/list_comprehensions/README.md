# List Comprehensions​
{:.no_toc}

<nav markdown="1" class="toc-class">
* TOC
{:toc}
</nav>

## Top

Questions to [David Rotermund](mailto:davrot@uni-bremen.de)


## [List Comprehension](https://docs.python.org/3/tutorial/datastructures.html#list-comprehensions)


> List comprehensions provide a concise way to create lists. Common applications are to make new lists where each element is the result of some operations applied to each member of another sequence or iterable, or to create a subsequence of those elements that satisfy a certain condition.

> For example, assume we want to create a list of squares

```python
 squares = [x**2 for x in range(10)]
```

> **A list comprehension consists of brackets containing an expression followed by a for clause, then zero or more for or if clauses. The result will be a new list resulting from evaluating the expression in the context of the for and if clauses which follow it.**

```python
a = [(x, y) for x in [1, 2, 3] for y in [3, 1, 4] if x != y]
print(a) # -> [(1, 3), (1, 4), (2, 3), (2, 1), (2, 4), (3, 1), (3, 4)]
```


### [Nested List Comprehensions](https://docs.python.org/3/tutorial/datastructures.html#list-comprehensions)

> The initial expression in a list comprehension can be any arbitrary expression, including another list comprehension.
