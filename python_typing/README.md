# Python -- Type annotations and static type checking for Python
## Goal
We want to use static type checking and type annotations in our Python code for detecting errors we made. We will use the tool mypy for that. 

```python
a: int = 0
b: float = 0.0
a = b     Incompatible types in assignment (expression has type "float", variable has type "int")
```
Questions to [David Rotermund](mailto:davrot@uni-bremen.de)

## Why [Type hints](https://peps.python.org/pep-0484/)?

Why we got type hints according PEP 484 -- Type Hints (29-Sep-2014):

> [Rationale and Goals](https://www.python.org/dev/peps/pep-0484/#id11)
> 
> This PEP aims to provide a standard syntax for type annotations, opening up Python code to easier static analysis and refactoring, potential runtime type checking, and (perhaps, in some contexts) code generation utilizing type information.
> 
> Of these goals, static analysis is the most important. This includes support for off-line type checkers such as mypy, as well as providing a standard notation that can be used by IDEs for code completion and refactoring.
> 
> [...]
> 
> It should also be emphasized that Python will remain a dynamically typed language, and the authors have no desire to ever make type hints mandatory, even by convention.

I would redefine this list a bit:
* It is a part of your automatic documentation (like with meaningful variable names). If another person gets your source code they understand it easier. 
* You editor might thank you. Do to some new features in Python 3.10, the modern editors that do syntax highlighting and error checking have a harder time to infer what you mean. The more it need to think about what you mean, the slower your editor might get or even fail to show you syntax highlighting. 
* Static code analysis is really helpful. It showed me any problems ahead that I would have figured out the hard way otherwise. 
* Packages like the just-in-time compiler numba can produce better results if you can tell it what the variables are. 

## How do we do it?
Variables are assigned to a type the ***first*** time when used or can be defined even before use: 

```python
a: int
b: int = 0
```
You are allowed to connect a variable ***once and only once*** to a type. If you assign a type a second time to a variable then you will get an error and have to remove the second assignment.

For functions it looks a bit different because we have to handle the type of the return value with the **->** construct:
```python
def this_is_a_function() -> None:
    pass

def this_is_a_function() -> int:
    return 5

def this_is_a_function(a: int) -> int:
    return a

def this_is_a_function(a: int, b: int = 8) -> int:
    return a + b

def this_is_a_function(a: int, b: int = 8) -> tuple[int, int]:
    return a, b
```

Please note, that there is a difference how type annotations worked for older version. I will cover only Python 3.10 and newer. The official documentation can be found [here](https://docs.python.org/3/library/typing.html).

## MyPy under VS Code
(also the header packages)

## [Built-in types](https://mypy.readthedocs.io/en/latest/builtin_types.html)

### [Simple types](https://mypy.readthedocs.io/en/latest/builtin_types.html#simple-types)

> Here are examples of some common built-in types:

|Type|Description|
|---|---|
|int|integer|
|float|floating point number|
|bool|boolean value (subclass of int)|
|str|text, sequence of unicode codepoints|
|bytes|8-bit string, sequence of byte values|
|object|an arbitrary object (object is the common base class)|



### Any type (Special type indicating an unconstrained type.)

```python
from typing import Any
a: Any = 0
b: float = 0.0
a = b
```
### Never type
This can be used to define a function that should never be called, or a function that never returns.


### Generic types





