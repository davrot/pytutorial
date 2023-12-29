# Input, Output, string, int, float
{:.no_toc}

<nav markdown="1" class="toc-class">
* TOC
{:toc}
</nav>

## The goal



Questions to [David Rotermund](mailto:davrot@uni-bremen.de)


## [input](https://docs.python.org/3/library/functions.html#input)

```python
input()
input(prompt)
```

> If the prompt argument is present, it is written to standard output without a trailing newline. The function then reads a line from input, converts it to a string (stripping a trailing newline), and returns that. When EOF is read, EOFError is raised. Example:

## [print](https://docs.python.org/3/library/functions.html#print)

```python
print(*objects, sep=' ', end='\n', file=None, flush=False)
```

> Print objects to the text stream file, separated by sep and followed by end. sep, end, file, and flush, if present, must be given as keyword arguments.
> 
> All non-keyword arguments are converted to strings like str() does and written to the stream, separated by sep and followed by end. Both sep and end must be strings; they can also be None, which means to use the default values. If no objects are given, print() will just write end.


## [str](https://docs.python.org/3/library/functions.html#func-str)

```python
class str(object='')
class str(object=b'', encoding='utf-8', errors='strict')
```

> Return a str version of object. See [str()](https://docs.python.org/3/library/stdtypes.html#str) for details.
> 
> If object is not provided, returns the empty string. Otherwise, the behavior of str() depends on whether encoding or errors is given, as follows.
> 
> If neither encoding nor errors is given, str(object) returns type(object).\_\_str\_\_(object), which is the “informal” or nicely printable string representation of object. For string objects, this is the string itself. If object does not have a \_\_str\_\_() method, then str() falls back to returning repr(object).

## [int](https://docs.python.org/3/library/functions.html#int)

```python
class int(x=0)
class int(x, base=10)
```

> Return an integer object constructed from a number or string x, or return 0 if no arguments are given. If x defines \_\_int\_\_(), int(x) returns x.\_\_int\_\_(). If x defines \_\_index\_\_(), it returns x.\_\_index\_\_(). If x defines \_\_trunc\_\_(), it returns x.\_\_trunc\_\_(). For floating point numbers, this truncates towards zero.
> 
> If x is not a number or if base is given, then x must be a string, bytes, or bytearray instance representing an integer in radix base. Optionally, the string can be preceded by + or - (with no space in between), have leading zeros, be surrounded by whitespace, and have single underscores interspersed between digits.
> 
> A base-n integer string contains digits, each representing a value from 0 to n-1. The values 0–9 can be represented by any Unicode decimal digit. The values 10–35 can be represented by a to z (or A to Z). The default base is 10. The allowed bases are 0 and 2–36. Base-2, -8, and -16 strings can be optionally prefixed with 0b/0B, 0o/0O, or 0x/0X, as with integer literals in code. For base 0, the string is interpreted in a similar way to an integer literal in code, in that the actual base is 2, 8, 10, or 16 as determined by the prefix. Base 0 also disallows leading zeros: int('010', 0) is not legal, while int('010') and int('010', 8) are.
> 
> The integer type is described in [Numeric Types — int, float, complex.](https://docs.python.org/3/library/stdtypes.html#typesnumeric)

## [float](https://docs.python.org/3/library/functions.html#float)

```python
class float(x=0.0)
```

> Return a floating point number constructed from a number or string x.
> 
> If the argument is a string, it should contain a decimal number, optionally preceded by a sign, and optionally embedded in whitespace. The optional sign may be '+' or '-'; a '+' sign has no effect on the value produced. The argument may also be a string representing a NaN (not-a-number), or positive or negative infinity. More precisely, the input must conform to the floatvalue production rule in the following grammar, after leading and trailing whitespace characters are removed:

```python
sign        ::=  "+" | "-"
infinity    ::=  "Infinity" | "inf"
nan         ::=  "nan"
digitpart   ::=  `!digit` (["_"] `!digit`)*
number      ::=  [digitpart] "." digitpart | digitpart ["."]
exponent    ::=  ("e" | "E") ["+" | "-"] digitpart
floatnumber ::=  number [exponent]
floatvalue  ::=  [sign] (floatnumber | infinity | nan)
```

> Here digit is a Unicode decimal digit (character in the Unicode general category Nd). Case is not significant, so, for example, “inf”, “Inf”, “INFINITY”, and “iNfINity” are all acceptable spellings for positive infinity.
> 
> Otherwise, if the argument is an integer or a floating point number, a floating point number with the same value (within Python’s floating point precision) is returned. If the argument is outside the range of a Python float, an OverflowError will be raised.
> 
> For a general Python object x, float(x) delegates to x.\_\_float\_\_(). If \_\_float\_\_() is not defined then it falls back to \_\_index\_\_().
> 
> If no argument is given, 0.0 is returned.

