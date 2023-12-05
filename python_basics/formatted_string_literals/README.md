# Python : Formatted String Literals
{:.no_toc}

<nav markdown="1" class="toc-class">
* TOC
{:toc}
</nav>

## The goal
Using formated string literals is an easy way to produce formated strings from data / variables.

Questions to [David Rotermund](mailto:davrot@uni-bremen.de)

## Basic Formatted String Literals
A formatted string literals starts with an f and the variables that you want to print are placed at their intended position embeded into { }.  For example:

```python
import numpy as np

a: str = "Hello"
b: int = 1
c: float = np.pi

mystring: str = f"A: {a} B: {b} C: {c}"
print(mystring)
```

```python
A: Hello B: 1 C: 3.141592653589793
```

In the case the string is to long (i.e. longer than the 80 character limit), you can use this construct to break the line into several lines:

```python
import numpy as np

a: str = "Hello"
b: int = 1
c: float = np.pi


mystring: str = (
    f"Variable A: {a} " 
    "Blablablablabla " 
    f"Variable B: {b} " 
    f"Variable C: {c} "
)

print(mystring)
```

```python
Variable A: Hello Blablablablabla Variable B: 1 Variable C: 3.141592653589793
```

## [Formats](https://docs.python.org/3/library/string.html#formatspec)

```python
format_spec     ::=  [[fill]align][sign][#][0][width][grouping_option][.precision][type]
fill            ::=  <any character>
align           ::=  "<" | ">" | "=" | "^"
sign            ::=  "+" | "-" | " "
width           ::=  digit+
grouping_option ::=  "_" | ","
precision       ::=  digit+
type            ::=  "b" | "c" | "d" | "e" | "E" | "f" | "F" | "g" | "G" | "n" | "o" | "s" | "x" | "X" | "%"
```

### Integer formats

|||
|---|---|
|'b'|	Binary format.|
|'c'|	Character.|
|'d'|	Decimal Integer.|
|'o'|	Octal format.|
|'x'|	Hex format. |
|'X'|	Hex format. |
|'n'|	Number.|
|**None**|	**'d'**|

|||
|---|---|
|'+'|	indicates that a sign should be used for both positive as well as negative numbers.|
|'-'|	indicates that a sign should be used only for negative numbers (this is the default behavior).|
|space|	indicates that a leading space should be used on positive numbers, and a minus sign on negative numbers.|

|||
|---|---|
|'<'|	Forces the field to be left-aligned within the available space (this is the default for most objects).|
|'>'|	Forces the field to be right-aligned within the available space (this is the default for numbers).|
|'='|	Forces the padding to be placed after the sign (if any) but before the digits.|
|'^'|	Forces the field to be centered within the available space.|

### Float formats

|||
|---|---|
|'e'|	Scientific notation.|
|'E'|	Scientific notation.|
|**'f'**|	**Fixed-point notation.**|
|'F'|	Fixed-point notation.|
|'g'|	General format.|
|'G'|	General format.|
|'n'|	Number.|
|'%'|	Percentage. |
|None|	'g'|

|||
|---|---|
|'+'|	indicates that a sign should be used for both positive as well as negative numbers.|
|'-'|	indicates that a sign should be used only for negative numbers (this is the default behavior).|
|space|	indicates that a leading space should be used on positive numbers, and a minus sign on negative numbers.|

```python
import numpy as np

value: float = np.pi

print(f"{value}")
print(f"{value:.3f}")
print(f"{value:+.3f}")
print(f"{-value:+.3f}")
```

```python
3.141592653589793
3.142
+3.142
-3.142
```

```python
import numpy as np

value: float = np.pi

print(f"{value:>30.2f}")
print(f"{value:<30.2f}")
print(f"{value:=30.2f}")
print(f"{value:^30.2f}")
```

```python
                          3.14
3.14                          
                          3.14
             3.14             
```

### String formats

|||
|---|---|
|'s'|	String format.|
|**None** |	**'s'**|

### Dates

```python
# %%
from datetime import datetime

d = datetime.now()
print(f"{d:%Y-%m-%d %H:%M:%S}")
```

```python
2022-04-03 01:18:45
```

| Directive | Meaning | Example |
|---|---|---|
|%a|Weekday as locale’s abbreviated name.|Sun, Mon, …, Sat (en_US); So, Mo, …, Sa (de_DE) |
|%A|Weekday as locale’s full name.|Sunday, Monday, …, Saturday (en_US);Sonntag, Montag, …, Samstag (de_DE)|
|%w|Weekday as a decimal number, where 0 is Sunday and 6 is Saturday.| 0, 1, …, 6 |
|%d|Day of the month as a zero-padded decimal number.|01, 02, …, 31 |
|%b|Month as locale’s abbreviated name.|Jan, Feb, …, Dec (en_US); Jan, Feb, …, Dez (de_DE) | 
|%B|Month as locale’s full name.|January, February, …, December (en_US); Januar, Februar, …, Dezember (de_DE) |
|%m|Month as a zero-padded decimal number.|01, 02, …, 12|
|%y|Year without century as a zero-padded decimal number.|00, 01, …, 99|
|%Y|Year with century as a decimal number.|0001, 0002, …, 2013, 2014, …, 9998, 9999|
|%H|Hour (24-hour clock) as a zero-padded decimal number.|00, 01, …, 23|
|%I|Hour (12-hour clock) as a zero-padded decimal number.|01, 02, …, 12|
|%p|Locale’s equivalent of either AM or PM.| AM, PM (en_US); am, pm (de_DE)|
|%M|Minute as a zero-padded decimal number.|00, 01, …, 59|
|%S| Second as a zero-padded decimal number. | 00, 01, …, 59 |
|%f|Microsecond as a decimal number, zero-padded to 6 digits.|000000, 000001, …, 999999|
|%z|UTC offset in the form ±HHMM[SS[.ffffff]] (empty string if the object is naive).|(empty), +0000, -0400, +1030, +063415, -030712.345216|
|%Z|Time zone name (empty string if the object is naive).|(empty), UTC, GMT|
|%j|Day of the year as a zero-padded decimal number.|001, 002, …, 366|
|%U|Week number of the year (Sunday as the first day of the week) as a zero-padded decimal number. All days in a new year preceding the first Sunday are considered to be in week 0.|00, 01, …, 53|
|%W|Week number of the year (Monday as the first day of the week) as a zero-padded decimal number. All days in a new year preceding the first Monday are considered to be in week 0.| 00, 01, …, 53|
|%c|Locale’s appropriate date and time representation. | Tue Aug 16 21:30:00 1988 (en_US); Di 16 Aug 21:30:00 1988 (de_DE) |
|%x|Locale’s appropriate date representation. | 08/16/88 (None); 08/16/1988 (en_US); 16.08.1988 (de_DE) |
|%X|Locale’s appropriate time representation. | 21:30:00 (en_US); 21:30:00 (de_DE) |
|%%|A literal '%' character.|%|

see [here](https://docs.python.org/3/library/datetime.html#strftime-and-strptime-format-codes) for the date formats 

## [Escape Sequence​](https://docs.python.org/3/reference/lexical_analysis.html#escape-sequences)

|Escape Sequence|Meaning|
|---|---|
|\<newline>|Backslash and newline ignored|
|\\ \\ |Backslash (\\)|
|\\'|Single quote (')|
|\\"|Double quote (")|
|\a|ASCII Bell (BEL)|
|\b|ASCII Backspace (BS)|
|\f|ASCII Formfeed (FF)|
|\n|ASCII Linefeed (LF)|
|\r|ASCII Carriage Return (CR)|
|\t|ASCII Horizontal Tab (TAB)|
|\v|ASCII Vertical Tab (VT)|
|\ooo|Character with octal value ooo|
|\xhh|Character with hex value hh|

|Escape Sequence|Meaning|
|---|---|
|\N{name}| Character named name in the Unicode database>
|\uxxxx|Character with 16-bit hex value xxxx|
|\Uxxxxxxxx|Character with 32-bit hex value xxxxxxxx|

## Reference
* [Formatted String Literals](https://docs.python.org/3/tutorial/inputoutput.html#formatted-string-literals)
* [Format Specification Mini-Language](https://docs.python.org/3/library/string.html#formatspec)
