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
