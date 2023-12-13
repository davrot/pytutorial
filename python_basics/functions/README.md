# Functions
{:.no_toc}

<nav markdown="1" class="toc-class">
* TOC
{:toc}
</nav>

## The goal

A function allows to seperate a part of the code in a logical module that can be reused. 

Questions to [David Rotermund](mailto:davrot@uni-bremen.de)

**Logic blocks need to be indented.​ Preferable with 4 spaces!**

## [Most simple function](https://docs.python.org/3/tutorial/controlflow.html#defining-functions)

These three functions are equivalent: 

```python
def my_function():
    pass

def my_function():
    return

def my_function():
    return None
```

> return leaves the current function call with the expression list (or None) as return value.

There is a return at the end, even if you don't put it there. 

## [def](https://docs.python.org/3/reference/compound_stmts.html?highlight=funcdef#function-definitions) 

```python
funcdef                   ::=  [decorators] "def" funcname [type_params] "(" [parameter_list] ")"
                               ["->" expression] ":" suite
decorators                ::=  decorator+
decorator                 ::=  "@" assignment_expression NEWLINE
parameter_list            ::=  defparameter ("," defparameter)* "," "/" ["," [parameter_list_no_posonly]]
                                 | parameter_list_no_posonly
parameter_list_no_posonly ::=  defparameter ("," defparameter)* ["," [parameter_list_starargs]]
                               | parameter_list_starargs
parameter_list_starargs   ::=  "*" [parameter] ("," defparameter)* ["," ["**" parameter [","]]]
                               | "**" parameter [","]
parameter                 ::=  identifier [":" expression]
defparameter              ::=  parameter ["=" expression]
funcname                  ::=  identifier
```

## [pass](https://docs.python.org/3/reference/simple_stmts.html#the-pass-statement)

```python
pass_stmt ::=  "pass"
```

> pass is a null operation — when it is executed, nothing happens. It is useful as a placeholder when a statement is required syntactically, but no code needs to be executed
> 

## [return](https://docs.python.org/3/reference/simple_stmts.html#the-return-statement)

```python
return_stmt ::=  "return" [expression_list]
```

> return may only occur syntactically nested in a function definition, not within a nested class definition.
>
> If an expression list is present, it is evaluated, else None is substituted.
>
> return leaves the current function call with the expression list (or None) as return value.
>
> When return passes control out of a try statement with a finally clause, that finally clause is executed before really leaving the function.

## [Return values​](https://docs.python.org/3/reference/simple_stmts.html#return)

### No return value
As we stated above these functions all return None:

```python
def my_function():
    pass

def my_function():
    return

def my_function():
    return None
```

### One return value
These functions return one value:

```python
def my_function():
    return 1

def my_function():
    return "Hello"

def my_function():
    return (1+1)/1
```

e.g. 

```python
def my_function():
    return 1

print(my_function())
```

### Many return values

```python
def my_function():
    return 2, "A", 79, 3.1314


print(my_function()) # -> (2, 'A', 79, 3.1314)
abcd = my_function() # -> (2, 'A', 79, 3.1314)
print(abcd) # -> (2, 'A', 79, 3.1314)

a, b, c, d = my_function()

print(a) # -> 2
print(b) # -> A
print(c) # -> 79
print(d) # -> 3.1314

a, b, c = my_function() # ValueError: too many values to unpack (expected 3)
```
## [Functions are objects](https://docs.python.org/3/tutorial/controlflow.html#defining-functions)

Functions are objects. Without **()** at the end, you interact with the function. With the **()** you use the function: 

```python
def my_function():
    return 1

print(my_function)  # -> <function my_function at 0x7f956166a520>
print(my_function())  # -> 1
```

Interesting, but why do I need to know this? Good question, imaginary person! We can use functions as "parameters" via arguments for other functions: 

```python
def my_function_0():
    return 3

def my_function_1():
    return 2


def my_function_2(func):
    return func() ** 2

print(my_function_2(my_function_0))  # -> 9
print(my_function_2(my_function_1))  # -> 4
```

## [Default Argument Values](https://docs.python.org/3/tutorial/controlflow.html#default-argument-values)

We can define a default value for arguments: 

```python
def my_function(a=2, b=7, c=5, d=8):
    return a + b**2 + c**3 + d**4

print(my_function()) # -> 4272
```

We can (partially) overwrite the default values: 

```python
def my_function(a=2, b=7, c=5, d=8):
    return a + b**2 + c**3 + d**4

print(my_function(b=2,a=3)) # -> 4228
print(my_function(d=7))  # -> 2577
print(my_function(3,2)) # -> 4228
print(my_function(3,b=2))  # -> 4228
print(my_function(b=2,3)) # SyntaxError: positional argument follows keyword argument
```

In the case of **my_function(3,2)**, the default values are replaced in the order the arguments of the function are defined. a,b,c, and finally d. When using the keyword e.g. d. Then I can overwrite only selected arguments.

## [Important warning](https://docs.python.org/3/tutorial/controlflow.html#default-argument-values) -- Mutable objects

> Important warning: **The default value is evaluated only once**. This makes a difference when the default is a mutable object such as a list, dictionary, or instances of most classes.

Deadly: 

```python
def f(a, L=[]):
    L.append(a)
    return L

print(f(1)) # -> [1]
print(f(2)) # -> [1, 2]
print(f(3)) # -> [1, 2, 3]
```

Correct:
```python
def f(a, L=None):
    if L is None:
        L = []
    L.append(a)
    return L

print(f(1))  # -> [1]
print(f(2))  # -> [2]
print(f(3))  # -> [3]
```

## Mutable arguments don't need return values​

```python
def f(x):
    x.append(1)

y = []
f(y)
print(y)
```

## [Arguments: Positional and Keywords](https://docs.python.org/3/tutorial/controlflow.html#special-parameters)

> A function definition may look like:

```python
def f(pos1, pos2, /, pos_or_kwd, *, kwd1, kwd2):
      -----------    ----------     ----------
        |             |                  |
        |        Positional or keyword   |
        |                                - Keyword only
         -- Positional only
```

**This is the typical case:**

[Positional-or-Keyword Arguments](https://docs.python.org/3/tutorial/controlflow.html#positional-or-keyword-arguments)
> **If / and * are not present** in the function definition, arguments may be passed to a function by position or by keyword.

[Keyword Arguments](https://docs.python.org/3/tutorial/controlflow.html#keyword-arguments)

{: .topic-optional}
This is an optional topic!

> Functions can also be called using keyword arguments of the form kwarg=value.

[Positional-Only Parameters](https://docs.python.org/3/tutorial/controlflow.html#positional-only-parameters)

{: .topic-optional}
This is an optional topic!

>  If positional-only, the parameters’ order matters, and the parameters cannot be passed by keyword.
>
> If there is no / in the function definition, there are no positional-only parameters.

[Keyword-Only Arguments](https://docs.python.org/3/tutorial/controlflow.html#keyword-only-arguments)

{: .topic-optional}
This is an optional topic!

> To mark parameters as keyword-only, indicating the parameters must be passed by keyword argument, place an * in the arguments list just before the first keyword-only parameter.

## [Arbitrary Argument Lists](https://docs.python.org/3/tutorial/controlflow.html#arbitrary-argument-lists) 

```python
def f(p1, *arguments, **keywords):
    print("p1:")
    print(p1)
    print()

    print("*arguments")
    for arg in arguments:
        print(arg)
    print()

    print("**keywords")
    for kw in keywords:
        print(f"{kw}: {keywords[kw]}")
    print()


f(1, 2, 3, a=4, b=5)
```

Output:

```python
p1:
1

*arguments
2
3

**keywords
a: 4
b: 5
```

## [Unpacking Argument Lists](https://docs.python.org/3/tutorial/controlflow.html#unpacking-argument-lists)

```python
def f(a: int, b: int, c: int, d: int) -> int:
    return a * b * c * d

print(f(2, 3, 4, 5))  # -> 120

my_list_a = [2, 3, 4]
my_list_b = [2, 3, 4, 5]
my_list_c = [3, 4, 5]
print(f(*my_list_a, 5))  # -> 120 (plus a false warning: 'Too many arguments for "f"' from MyPy)
print(f(*my_list_b))  # -> 120
print(f(2, *my_list_c))  # -> 120

my_tuple_c = [3, 4, 5]
print(f(2, *my_tuple_c))  # -> 120
```

## [Documentation strings​](https://peps.python.org/pep-0257/)

```python
def my_function():
    """This is a universal function.
    It does nothing."""
    pass

help(my_function)
```

Output:

```python
Help on function my_function in module __main__:

my_function()
    This is a universal function.
    It does nothing.
```

One liner:

```python
def my_function():
    """This is a universal function."""
    pass
```

Novelization: 

```python
def my_function():
    """This is a universal function.
        a
        b
        d
        end"""
    pass
```

## [Lambda expressions / anonymous functions​](https://docs.python.org/3/reference/expressions.html#lambda)

```python
lambda_expr ::=  "lambda" [parameter_list] ":" expression
```
> Lambda expressions (sometimes called lambda forms) are used to create anonymous functions. The expression lambda parameters: expression yields a function object. The unnamed object behaves like a function object defined with:

```python
def <lambda>(parameters):
    return expression
```

Example 1:

```python
pairs = [(1, "one"), (2, "two"), (3, "three"), (4, "four")]

def f(x):
    return x[1]

print(pairs) # -> [(1, 'one'), (2, 'two'), (3, 'three'), (4, 'four')]

print((lambda x: x[1])(pairs)) # -> (2, 'two')
print(f(pairs)) # -> (2, 'two')
```

Example 2:

With a normal function:

```python
pairs = [(1, "one"), (2, "two"), (3, "three"), (4, "four")]

def f(x):
    return x[1]

print(pairs)  # -> [(1, 'one'), (2, 'two'), (3, 'three'), (4, 'four')]

pairs.sort(key=f) 
print(pairs) # -> [(4, 'four'), (1, 'one'), (3, 'three'), (2, 'two')]
```

```python
pairs = [(1, "one"), (2, "two"), (3, "three"), (4, "four")]


print(pairs)  # -> [(1, 'one'), (2, 'two'), (3, 'three'), (4, 'four')]

pairs.sort(key=(lambda x: x[1]))
print(pairs) # -> [(4, 'four'), (1, 'one'), (3, 'three'), (2, 'two')]
```

Small warning: 

```python
print(pairs.sort()) # -> None
```

because **.sort()** is an inplace function.


