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

* If the type starts with an upper letter then you might import it from the typing module like

```python
from typing import Any
```

* If you have no clue what type something has, well use **type()**:

```python
import numpy as np
import torch


def func() -> None:
    return


a = 0
b = np.zeros((10,))
c = torch.zeros((10, 1))
d = func

print(type(a))
print(type(b))
print(type(c))
print(type(d))
```

Output:

```python
<class 'int'>
<class 'numpy.ndarray'>
<class 'torch.Tensor'>
<class 'function'>
```

The correct typing would have been: 

```python
import numpy as np
import torch
from typing import Callable


def func() -> None:
    return


a: int = 0
b: np.ndarray = np.zeros((10,))
c: torch.Tensor = torch.zeros((10, 1))
d: Callable = func
```

As you can see, we had to change **b** a bit because we didn't use **import numpy** but used **import numpy as np**. Thus we had to use **np.ndarray** instead of **numpy.ndarray**.

Concerning **<class 'function'>**, this is a specical case. And requires an import from the typing module via **from typing import Callable**. More about that later. 

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

```python
a: int = 0
b: float = 0.0
c: bool = True
d: str = "LaLa"
```

### [Any type](https://mypy.readthedocs.io/en/latest/builtin_types.html#any-type) 

Special type indicating an unconstrained type.

```python
from typing import Any
a: Any = 0
b: float = 0.0
a = b
```

### [Generic types](https://mypy.readthedocs.io/en/latest/builtin_types.html#generic-types)

|Type|Description|
|---|---|
|list[str]|list of str objects|
|tuple[int, int]|tuple of two int objects (tuple[()] is the empty tuple)|
|tuple[int, ...]|tuple of an arbitrary number of int objects|
|dict[str, int]|dictionary from str keys to int values|
|Iterable[int]|iterable object containing ints|
|Sequence[bool]|sequence of booleans (read-only)|
|Mapping[str, int]|mapping from str keys to int values (read-only)|
|type[C]|type object of C (C is a class/type variable/union of types)|

Examples: 

```python
la: list = ["a", 1, 3.3]

ta: tuple = ("a", 1, 3.3)
tb: tuple[str, int, float] = ("a", 1, 3.3)
```

Wrong:

```python
la: list[str, int, float] = ["a", 1, 3.3]
```

Correct:

```python
la: list[str | int | float] = ["a", 1, 3.3]
```

## [\|](https://docs.python.org/3/library/typing.html#typing.Union)

In the case you expect a variable that can have differnt types over it's lifetime. Let us say you initialize it with None and later want to store integer in it:

```python
a: None | int = None
```

An other example is this:

```python
import torch
import numpy as np
a: np.ndarray  | torch.Tensor = torch.zeros((100,))
```

This is called a [Union](https://docs.python.org/3/library/typing.html#typing.Union). The Union with **None** is called [Optional](https://docs.python.org/3/library/typing.html#typing.Optional). But nowadays you just need to remember **\|**. 

In the real world I encountered this problem:

```python
a: int | None = 1
b: int

b = a  # Incompatible types in assignment (expression has type "int | None", variable has type "int")
```

The solution is to use [assert](https://docs.python.org/3/reference/simple_stmts.html#the-assert-statement):

```python
a: int | None = 1
b: int

assert a is not None

b = a
```


## [TypeAlias](https://docs.python.org/3/library/typing.html#typing.TypeAlias)

You can create an alias for more complicated types

```python
from typing import TypeAlias

Numbis: TypeAlias = int | float
a: Numbis

a = 1
a = 1.1
a = "Hello" # Incompatible types in assignment (expression has type "str", variable has type "int | float")
```

## [Tuple](https://docs.python.org/3/library/typing.html#typing.Tuple)

```python
a: tuple[int, str, int] = (5, "Hello", 6)
a = (
    "Hello",
    4,
    4,
)  # Incompatible types in assignment (expression has type "Tuple[str, int, int]", variable has type "Tuple[int, str, int]")
```

Or if you don't care about what is in the tuple

```python
a: tuple = (5, "Hello", 6)
a = ("Hello", 4, 4)
```

## [List](https://docs.python.org/3/library/typing.html#typing.List)

A generic list:

```python
mylist: list = []

mylist.append(1)
mylist.append(2)
mylist.append("Hello")
```

Or defining more details about the list: 

```python
mylist: list[int] = []

mylist.append(1)
mylist.append(2)
mylist.append(
    "Hello"
)  # Argument 1 to "append" of "list" has incompatible type "str"; expected "int"

print(mylist) # -> [1, 2, 'Hello']
```

## [Dict](https://docs.python.org/3/library/typing.html#typing.Dict)

Generic dictionary: 

```python
mydict: dict = {"A": 1, "B": 3.14, "C": "Hello"}
```

We can give it more information. However, we have to be careful to include the types correctly. 

This is wrong: 

```python
mydict_a: dict[str, int] = {"A": 1, "B": 3.14, "C": "Hello", 1: 1}
```

We get these errors: 

```python
Dict entry 1 has incompatible type "str": "float"; expected "str": "int"
Dict entry 2 has incompatible type "str": "str"; expected "str": "int"
Dict entry 3 has incompatible type "int": "int"; expected "str": "int"
```

These are correct ways to handle it: 

```python
mydict_a: dict[str | int, str | int | float] = {"A": 1, "B": 3.14, "C": "Hello", 1: 1}
mydict_b: dict[str, str | int | float] = {"A": 1, "B": 3.14, "C": "Hello", "1": 1}
```

## [Numpy](https://numpy.org/devdocs/reference/typing.html)

Generic:

```python
import numpy as np
a: np.ndarray = np.zeros((10, 1))
```

Protecting against a wrong dtype:


```python
import numpy as np
from typing import Any

a: np.ndarray[Any, np.dtype[np.uint64]]

a = np.zeros((10, 1), dtype=np.uint64)
a = np.zeros((10, 1)) # -> Incompatible types in assignment (expression has type "ndarray[Any, dtype[floating[_64Bit]]]", variable has type "ndarray[Any, dtype[unsignedinteger[_64Bit]]]")
```

## PyTorch
Please note the big T!

```python
import torch

a: torch.Tensor = torch.zeros((10, 1))
```

## [Callable](https://docs.python.org/3/library/typing.html#annotating-callable-objects)

Callable means "function". As you know, you can shove functions objects around and also use then as function arguments of other function. It is helpful to make sure that the function you get has the properties you expect. 

```python
Callable[[Arg1Type, Arg2Type], ReturnType]
```

```python
from typing import Callable


def function_a(x: int) -> int:
    return x + 1


def function_a_bad(x: int, y: int) -> int:
    return x + y


def function_b(x, other_function: Callable[[int], int]) -> int:
    return other_function(x) ** 2


print(function_b(1, function_a))  # -> 4

print(function_b(1, function_b)) # -> Argument 2 to "function_b" has incompatible type "Callable[[Any, Callable[[int], int]], int]"; expected "Callable[[int], int]"
```

## [NewType](https://docs.python.org/3/library/typing.html#newtype), [Generics](https://docs.python.org/3/library/typing.html#generics), [User-defined generic types](https://docs.python.org/3/library/typing.html#user-defined-generic-types)

{: .topic-optional}
This is an optional topic!

Well... this exists... never used it. 

|||
|---|---|
|NewType | Use the NewType helper to create distinct types|
|Generics| Since type information about objects kept in containers cannot be statically inferred in a generic way, many container classes in the standard library support subscription to denote the expected types of container elements. |
|User-defined generic types|A user-defined class can be defined as a generic class.|


## References

* [Type hints cheat sheet](https://mypy.readthedocs.io/en/stable/cheat_sheet_py3.html)
* [typing — Support for type hints](https://docs.python.org/3/library/typing.html)

