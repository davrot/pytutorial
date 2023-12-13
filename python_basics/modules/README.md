# [Modules](https://docs.python.org/3/tutorial/modules.html)
{:.no_toc}

<nav markdown="1" class="toc-class">
* TOC
{:toc}
</nav>

## The goal



Questions to [David Rotermund](mailto:davrot@uni-bremen.de)

## [Basics](https://docs.python.org/3/tutorial/modules.html)

> A module is a file containing Python definitions and statements. The file name is the module name with the suffix .py appended. Within a module, the module’s name (as a string) is available as the value of the global variable \_\_name\_\_. For instance, use your favorite text editor to create a file called fibo.py in the current directory with the following contents:


Let us assume we have a file with the name fibo.py and the following content in our working directory 

```python
> def fib(n):    # write Fibonacci series up to n​
    a, b = 0, 1

    while a < n:
        print(a, end=' ')
        a, b = b, a+b
    print()


def fib2(n):   # return Fibonacci series up to n​
    result = []
    a, b = 0, 1

    while a < n:
        result.append(a)
        a, b = b, a+b

    return result
```

> We can now import this module with the following command​


```python
import fibo
```

> This does not enter the names of the functions defined in fibo directly in the current symbol table; it only enters the module name fibo there. Using the module name you can access the functions:

```python
import fibo

fibo.fib(1000) # -> 0 1 1 2 3 5 8 13 21 34 55 89 144 233 377 610 987 

x = fibo.fib2(100) 
print(x) # -> [0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89]

print(fibo.__name__) # -> fibo
```

> If you intend to use a function often you can assign it to a local name:

```python
import fibo

fib = fibo.fib
fib(500) # -> 0 1 1 2 3 5 8 13 21 34 55 89 144 233 377
```

## [from](https://docs.python.org/3/tutorial/modules.html#more-on-modules)

> A module can contain executable statements as well as function definitions. These statements are intended to initialize the module. They are executed only the first time the module name is encountered in an import statement. (They are also run if the file is executed as a script.)
>
> Each module has its own private symbol table, which is used as the global symbol table by all functions defined in the module. Thus, the author of a module can use global variables in the module without worrying about accidental clashes with a user’s global variables. On the other hand, if you know what you are doing you can touch a module’s global variables with the same notation used to refer to its functions, modname.itemname.​
>
> Modules can import other modules. It is customary but not required to place all import statements at the beginning of a module (or script, for that matter). The imported module names are placed in the importing module’s global symbol table.

> There is a variant of the import statement that imports names from a module directly into the importing module’s symbol table. For example:​

```python
from fibo import fib, fib2
fib(500) # -> 0 1 1 2 3 5 8 13 21 34 55 89 144 233 377
print(fib2(100))  #-> [0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89]
```

> This does not introduce the module name from which the imports are taken in the local symbol table (so in the example, fibo is not defined).

> There is even a variant to import all names that a module defines:​

```python
from fibo import *
```

> This imports all names except those beginning with an underscore (_).​

**However, this is bad style!!! Don't use "import \*" or you are a bad person!**


## [as](https://docs.python.org/3/tutorial/modules.html#more-on-modules)

If the module name is followed by **as**, then the name following as is bound directly to the imported module.​

```python
import fibo as fib
fib.fib(500)
```

> This is effectively importing the module in the same way that import fibo will do, with the only difference of it being available as fib.

Typical examples are: 

```python
import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
```

## [as and from](https://docs.python.org/3/tutorial/modules.html#more-on-modules)

> It can also be used when utilising from with similar effects:​

```python
from fibo import fib as fibonacci
fibonacci(500)
```

## [Changing a loaded lib](https://docs.python.org/3/tutorial/modules.html#more-on-modules)

> **Note** For efficiency reasons, each module is only imported once per interpreter session. Therefore, if you change your modules, you must restart the interpreter – or, if it’s just one module you want to test interactively, use importlib.reload(), e.g.

```python
import importlib
importlib.reload(modulename)
```

## [The import statement](https://docs.python.org/3/reference/simple_stmts.html#the-import-statement)

```python
import_stmt     ::=  "import" module ["as" identifier] ("," module ["as" identifier])*
                     | "from" relative_module "import" identifier ["as" identifier]
                     ("," identifier ["as" identifier])*
                     | "from" relative_module "import" "(" identifier ["as" identifier]
                     ("," identifier ["as" identifier])* [","] ")"
                     | "from" relative_module "import" "*"
module          ::=  (identifier ".")* identifier
relative_module ::=  "."* module | "."+
```

Python code in one [module](https://docs.python.org/3/glossary.html#term-module) gains access to the code in another module by the process of [importing](https://docs.python.org/3/glossary.html#term-importing) it. 

see [The import system](https://docs.python.org/3/reference/import.html) for more details. 

## Subdirectories

If a file **myfunctions.py** with **thefunction** is places in a subdirectory **sub1** then we need to write:​

```python
from sub1.myfunctions import thefunction
```

If a file **myfunctions.py** with **thefunction** is places in a subdirectory **sub1/sub2** (**sub1\\sub2** depending on the OS) then we need to write:​

```python
from sub1.sub2.myfunctions import thefunction
```



