# Input, Output, string, int, float
{:.no_toc}

<nav markdown="1" class="toc-class">
* TOC
{:toc}
</nav>

## The goal



Questions to [David Rotermund](mailto:davrot@uni-bremen.de)


## Examples

### Input / Print

```python
a = input() # <- test
print(a) # -> test
```

### String to int

```python
a = int(5)
print(a)  # -> 5
print(type(a))  # -> <class 'int'>
a = int(-5)
print(a)  # -> -5
print(type(a))  # -> <class 'int'>
a = int("5")
print(a)  # -> 5
print(type(a))  # -> <class 'int'>
a = int("-5")
print(a)  # -> -5
print(type(a))  # -> <class 'int'>
a = int("   5     ")
print(a)  # -> 5
print(type(a))  # -> <class 'int'>
a = int("3.4")  #  ValueError: invalid literal for int() with base 10: '3.4'
a = int("Hello")  # ValueError: invalid literal for int() with base 10: 'Hello'
```

### String to float

```python
a = float(5)
print(a)  # -> 5.0
print(type(a))  # -> <class 'float'>
a = float(5.1)
print(a)  # -> 5.1
print(type(a))  # -> <class 'float'>
a = float(-5.1)
print(a)  # -> -5.1
print(type(a))  # -> <class 'float'>
a = float("5.1")
print(a)  # -> 5.1
print(type(a))  # -> <class 'float'>
a = float("-5.1")
print(a)  # -> -5.1
print(type(a))  # -> <class 'float'>
a = float("   5.1     ")
print(a)  # -> 5.1
print(type(a))  # -> <class 'float'>
a = float("Hello")  # ValueError: could not convert string to float: 'Hello'
```

## Strings

For formating string look [here](https://davrot.github.io/pytutorial/python_basics/formatted_string_literals/)

```python
a = "Part1 " "Part2 " "Part3 "
print(a) # -> Part1 Part2 Part3


a = "Part1 " + "Part2 " + "Part3 "
print(a) # -> Part1 Part2 Part3

x = 1
y = 2
z = 3
u = "Part"
v = " "
a = u + str(x) + v + u + str(y) + v + u + str(z)
print(a) # -> Part1 Part2 Part3
```



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

### selected [string methods](https://docs.python.org/3/library/stdtypes.html#string-methods)

|||
|---|---|
|[str.capitalize()](https://docs.python.org/3/library/stdtypes.html#str.capitalize) |Return a copy of the string with its first character capitalized and the rest lowercased.|
|[str.casefold()](https://docs.python.org/3/library/stdtypes.html#str.casefold) |Return a casefolded copy of the string. Casefolded strings may be used for caseless matching.|
|[str.center(width[, fillchar])](https://docs.python.org/3/library/stdtypes.html#str.center) |Return centered in a string of length width.|
|[str.count(sub[, start[, end]])](https://docs.python.org/3/library/stdtypes.html#str.count) |Return the number of non-overlapping occurrences of substring sub in the range [start, end]. |
|[str.encode(encoding='utf-8', errors='strict')](https://docs.python.org/3/library/stdtypes.html#str.encode) |Return the string encoded to bytes.|
|[str.endswith(suffix[, start[, end]])](https://docs.python.org/3/library/stdtypes.html#str.endswith)|Return True if the string ends with the specified suffix, otherwise return False. suffix can also be a tuple of suffixes to look for. |
|[str.expandtabs(tabsize=8)](https://docs.python.org/3/library/stdtypes.html#str.expandtabs)|Return a copy of the string where all tab characters are replaced by one or more spaces, depending on the current column and the given tab size. |
|[str.find(sub[, start[, end]])](https://docs.python.org/3/library/stdtypes.html#str.find)|Return the lowest index in the string where substring sub is found within the slice s[start:end]. |
|[str.lower()](https://docs.python.org/3/library/stdtypes.html#str.lower)|Return a copy of the string with all the cased characters converted to lowercase.|
|[str.lstrip([chars])](https://docs.python.org/3/library/stdtypes.html#str.lstrip)|Return a copy of the string with leading characters removed. The chars argument is a string specifying the set of characters to be removed. If omitted or None, the chars argument defaults to removing whitespace.|
|[str.replace(old, new[, count])](https://docs.python.org/3/library/stdtypes.html#str.replace)|Return a copy of the string with all occurrences of substring old replaced by new. |
|[str.rfind(sub[, start[, end]])](https://docs.python.org/3/library/stdtypes.html#str.rfind)|Return the highest index in the string where substring sub is found, such that sub is contained within s[start:end]. |
|[str.rsplit(sep=None, maxsplit=- 1)](https://docs.python.org/3/library/stdtypes.html#str.rsplit)|Return a list of the words in the string, using sep as the delimiter string. If maxsplit is given, at most maxsplit splits are done, the rightmost ones. If sep is not specified or None, any whitespace string is a separator.| 
|[str.rstrip([chars])](https://docs.python.org/3/library/stdtypes.html#str.rstrip)|Return a copy of the string with trailing characters removed. The chars argument is a string specifying the set of characters to be removed. If omitted or None, the chars argument defaults to removing whitespace.|
|[str.split(sep=None, maxsplit=- 1)](https://docs.python.org/3/library/stdtypes.html#str.split)| Return a list of the words in the string, using sep as the delimiter string. If maxsplit is given, at most maxsplit splits are done (thus, the list will have at most maxsplit+1 elements). If maxsplit is not specified or -1, then there is no limit on the number of splits (all possible splits are made). |
|[str.splitlines(keepends=False)](https://docs.python.org/3/library/stdtypes.html#str.split)| Return a list of the lines in the string, breaking at line boundaries. Line breaks are not included in the resulting list unless keepends is given and true.|
|[str.startswith(prefix[, start[, end]])](https://docs.python.org/3/library/stdtypes.html#str.startswith)|Return True if string starts with the prefix, otherwise return False. prefix can also be a tuple of prefixes to look for. With optional start, test string beginning at that position.|
|[str.strip([chars])](https://docs.python.org/3/library/stdtypes.html#str.strip)| Return a copy of the string with the leading and trailing characters removed. The chars argument is a string specifying the set of characters to be removed. If omitted or None, the chars argument defaults to removing whitespace. The chars argument is not a prefix or suffix; rather, all combinations of its values are stripped|
|[str.swapcase()](https://docs.python.org/3/library/stdtypes.html#str.swapcase)|Return a copy of the string with uppercase characters converted to lowercase and vice versa.|
|[str.upper()](https://docs.python.org/3/library/stdtypes.html#str.upper)|Return a copy of the string with all the cased characters converted to uppercase.|
|[str.zfill(width)](https://docs.python.org/3/library/stdtypes.html#str.zfill)|Return a copy of the string left filled with ASCII '0' digits to make a string of length width. A leading sign prefix ('+'/'-') is handled by inserting the padding after the sign character rather than before. The original string is returned if width is less than or equal to len(s).|


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

## [type](https://docs.python.org/3/library/functions.html#type)

```python
class type(object)
class type(name, bases, dict, **kwds)
```

> With one argument, return the type of an object. The return value is a type object and generally the same object as returned by object.\_\_class\_\_.
> 
> **The isinstance() built-in function is recommended for testing the type of an object, because it takes subclasses into account.**

