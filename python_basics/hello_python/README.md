# Hello, Python
{:.no_toc}

<nav markdown="1" class="toc-class">
* TOC
{:toc}
</nav>

## The goal

This is the first step in running something in Python.

Questions to [David Rotermund](mailto:davrot@uni-bremen.de)

## These are the same stings

```python
some_string = "this is a string"
some_string = 'this is a string'
```

```python
print(some_string)​
```

Output: 

```python
this is a string​
```

## These are comments

```python
# This is comment​
a = 1  # This is a comment too! (not the a=1)​
```

## [print](https://docs.python.org/3/library/functions.html#print​)

```python
print(*objects, sep=' ', end='\n', file=None, flush=False)
```

> Print objects to the text stream file, separated by sep and followed by end. sep, end, file, and flush, if present, must be given as keyword arguments.
>
> All non-keyword arguments are converted to strings like str() does and written to the stream, separated by sep and followed by end. Both sep and end must be strings; they can also be None, which means to use the default values. If no objects are given, print() will just write end.
> 
> The file argument must be an object with a write(string) method; if it is not present or None, sys.stdout will be used. Since printed arguments are converted to text strings, print() cannot be used with binary mode file objects. For these, use file.write(...) instead.
>
> Output buffering is usually determined by file. However, if flush is true, the stream is forcibly flushed.

## [Help!](https://docs.python.org/3/library/functions.html#help)

### Help for a function 

Here the function round() as an example. Please note that () is missing with the help function:

```python
help(round)
```

```python
Help on built-in function round in module builtins:

round(number, ndigits=None)
    Round a number to a given precision in decimal digits.
    
    The return value is an integer if ndigits is omitted or None.  Otherwise
    the return value has the same type as the number.  ndigits may be negative.
```

### Help for a keyword 

Keywords are build-in core instructions. 

```python
help("for")
```

```python
The "for" statement
*******************

The "for" statement is used to iterate over the elements of a sequence
(such as a string, tuple or list) or other iterable object:

   for_stmt ::= "for" target_list "in" expression_list ":" suite
                ["else" ":" suite]

The expression list is evaluated once; it should yield an iterable
object.  An iterator is created for the result of the
[...]
```

In the case when you are not sure if something is a keyword, you can check it like [this](https://docs.python.org/3/library/keyword.html):

```python
import keyword
print(keyword.kwlist)
print(keyword.softkwlist)
```

```python
['False', 'None', 'True', 'and', 'as', 'assert', 'async', 'await', 'break', 'class', 'continue', 'def', 'del', 'elif', 'else', 'except', 'finally', 'for', 'from', 'global', 'if', 'import', 'in', 'is', 'lambda', 'nonlocal', 'not', 'or', 'pass', 'raise', 'return', 'try', 'while', 'with', 'yield']
['_', 'case', 'match']
```

