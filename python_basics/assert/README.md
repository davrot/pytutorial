# Assert
{:.no_toc}

<nav markdown="1" class="toc-class">
* TOC
{:toc}
</nav>

## The goal

assert helps you to check your assumptions and stops the program if they are not met.  

Questions to [David Rotermund](mailto:davrot@uni-bremen.de)


## [The assert statement](https://docs.python.org/3/reference/simple_stmts.html#the-assert-statement)

> Assert statements are a convenient way to insert debugging assertions into a program:

```python
assert_stmt ::=  "assert" expression ["," expression]
```

> The simple form, assert expression, is equivalent to

```python
if __debug__:
    if not expression: raise AssertionError
```

> The extended form, assert expression1, expression2, is equivalent to

```python
if __debug__:
    if not expression1: raise AssertionError(expression2)
```

> These equivalences assume that [\_\_debug\_\_](https://docs.python.org/3/library/constants.html#debug__) and AssertionError refer to the built-in variables with those names. In the current implementation, the built-in variable \_\_debug\_\_ is True under normal circumstances, False when optimization is requested (command line option -O). The current code generator emits no code for an assert statement when optimization is requested at compile time. Note that it is unnecessary to include the source code for the expression that failed in the error message; it will be displayed as part of the stack trace.
> 
> Assignments to \_\_debug\_\_ are illegal. The value for the built-in variable is determined when the interpreter starts.


## Example: 

```python
assert 1 == 2
```

Output:

```python
---------------------------------------------------------------------------
AssertionError                            Traceback (most recent call last)
/home/admin/pypy/test3.py in line 2
      1 # %%
----> 2 assert 1 == 2

AssertionError: 
```

or with expression 2:

```python
assert 1 == 2, "1 should be the same as 2" 
```

Output:

```python
---------------------------------------------------------------------------
AssertionError                            Traceback (most recent call last)
/home/admin/pypy/test3.py in line 2
      1 # %%
----> 2 assert 1 == 2, "1 should be the same as 2"

AssertionError: 1 should be the same as 2
```

## Stuff that is often tested against

### [isinstance](https://docs.python.org/3/library/functions.html#isinstance)

```python
isinstance(object, classinfo)
```

> Return True if the object argument is an instance of the classinfo argument, or of a (direct, indirect, or virtual) subclass thereof. If object is not an object of the given type, the function always returns False. If classinfo is a tuple of type objects (or recursively, other such tuples) or a Union Type of multiple types, return True if object is an instance of any of the types. If classinfo is not a type or tuple of types and such tuples, a TypeError exception is raised. TypeError may not be raised for an invalid type if an earlier check succeeds.


```python
a: int = 0
assert isinstance(a, float), f"a (value={a}) is not a float."
```

Output:

```python
---------------------------------------------------------------------------
AssertionError                            Traceback (most recent call last)
/home/admin/pypy/test3.py in line 3
      4 # %%
      5 a: int = 0
----> 6 assert isinstance(a, float), f"a (value={a}) is not a float."

AssertionError: a (value=0) is not a float.
```

### Numpy

#### [numpy.ndarray.ndim](https://numpy.org/doc/stable/reference/generated/numpy.ndarray.ndim.html)

```python
ndarray.ndim
```

> Number of array dimensions.


#### [numpy.ndarray.dtype](https://numpy.org/doc/stable/reference/generated/numpy.ndarray.dtype.html)

```python
ndarray.dtype
```

> Data-type of the array’s elements.

#### [numpy.ndarray.shape](https://numpy.org/doc/stable/reference/generated/numpy.ndarray.shape.html#numpy-ndarray-shape)

```python
ndarray.shape
```

> Tuple of array dimensions.
> 
> The shape property is usually used to get the current shape of an array, but may also be used to reshape the array in-place by assigning a tuple of array dimensions to it. As with numpy.reshape, one of the new shape dimensions can be -1, in which case its value is inferred from the size of the array and the remaining dimensions. Reshaping an array in-place will fail if a copy is required.

#### [numpy.ndarray.flags](https://numpy.org/doc/stable/reference/generated/numpy.ndarray.flags.html)

```python
ndarray.flags
```

> Information about the memory layout of the array.

> Attributes:
> 
> **C_CONTIGUOUS** (C)
> 
> The data is in a single, C-style contiguous segment.



