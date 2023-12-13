# Functions
{:.no_toc}

<nav markdown="1" class="toc-class">
* TOC
{:toc}
</nav>

## The goal



Questions to [David Rotermund](mailto:davrot@uni-bremen.de)

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


## Arguments and Keywords


