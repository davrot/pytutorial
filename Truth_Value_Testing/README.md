# Python -- Truth Value Testing
{:.no_toc}

* TOC
{:toc}

Questions to [David Rotermund](mailto:davrot@uni-bremen.de)

["Any object can be tested for truth value, for use in an if or while condition or as operand of the Boolean operations below."](https://docs.python.org/3/library/stdtypes.html#truth-value-testing)

# Common mistake to avoid
For True, False, None we use is and is not for comparisons. They are objects and not values thus we need to use is and is not.

Correct
```python
if a: # "a is True" is shortend to "a" due to the official Python style guidelines
    pass

if a is not True:
    pass

if a is False:
    pass

if a is not False:
    pass

if a is None:
    pass

if a is not None:
    pass
```

Wrong
```python
if a == True:
    pass

if a == False:
    pass

if a != False:
    pass

if a != None:
    pass
```
## [Boolean Operations - and, or, not](https://docs.python.org/3/library/stdtypes.html#boolean-operations-and-or-not)

["These are the Boolean operations, ordered by ascending priority:"](https://docs.python.org/3/library/stdtypes.html#boolean-operations-and-or-not)

| | | |
| ------------- |:-------------:|:-------------:|
| x or y |	if x is false, then y, else x	| (1) |
| x or y |	if x is false, then x, else y	| (2) |
| not x |	if x is false, then True, else False	| (3) |

1. This is a short-circuit operator, so it only evaluates the second argument if the first one is false.
2. This is a short-circuit operator, so it only evaluates the second argument if the first one is true.
3. not has a lower priority than non-Boolean operators, so not a == b is interpreted as not (a == b), and a == not b is a syntax error.

## [Comparisons](https://docs.python.org/3/library/stdtypes.html#comparisons)

"There are eight comparison operations in Python. They all have the same priority (which is higher than that of the Boolean operations). Comparisons can be chained arbitrarily; for example, x < y <= z is equivalent to x < y and y <= z, except that y is evaluated only once (but in both cases z is not evaluated at all when x < y is found to be false)."

"This table summarizes the comparison operations:"

| | | | 
| ------------- |:-------------:|:-------------:|
| <	| strictly less than	| uses method: \_\_lt\_\_() |
|<=	| less than or equal |	uses method: \_\_le\_\_() |
|>	| strictly greater than |	uses method: \_\_gt\_\_() |
|>=	| greater than or equal |	uses method: \_\_ge\_\_() |
|==	| equal |	uses method: \_\_eq\_\_() |
|!=	| not equal	| |
|is	| object identity |	|
|is not	| negated object identity	| |

## Resource
[Built-in Types](https://docs.python.org/3/library/stdtypes.html)


