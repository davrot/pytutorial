# Class
{:.no_toc}

<nav markdown="1" class="toc-class">
* TOC
{:toc}
</nav>

## The goal

Class has a very important job as a core container type in Python. It is really hard to find a good overview how to use them in a good practice manner. 

Questions to [David Rotermund](mailto:davrot@uni-bremen.de)

## Basics

[Class](https://en.wikipedia.org/wiki/Class_(computer_programming)) is the core component of [object-oriented programming](https://en.wikipedia.org/wiki/Object-oriented_programming) (OOP). 
A class is an [object](https://docs.python.org/3/reference/datamodel.html) that can contain data i.e. class variables (also called fields, attributes or properties) and code, called class methods. 
Here we will look at the basic [Python class](https://docs.python.org/3/tutorial/classes.html#classes). 
For data science there is a simplified derivation available called dataclass.

```python
class MostSimplestClass:
    pass
```

## Instance

What is an instance? After defining a class we need to put it into memory. Every instance of a class generated in memory is... well... an instance. Here is an example how we create two instances of a class: 

```python
class SimpleClass(object):
    variable_a: int

instance_a = SimpleClass()
instance_a.variable_a = 1

instance_b = SimpleClass()
instance_b.variable_a = 2

print(instance_a.variable_a)  # -> 1
print(instance_b.variable_a)  # -> 2
```

In this example we create an instance with **SimpleClass()** . Reading the content of the ( ) it depends on how you define the method \_\_init\_\_ . By default it doesn't take any arguments from you.

## Variables

Code and data are the components a class is made of. Let us look at the data (i.e. variables) first. 

**Note: If we want to use a variable (or a method) of the class from within the class we need to use the prefix self.**

### BEST (in my opinion)
To make a long story short, you want to do it like this:

```python
class MostSimplestClass:
    a: int
    b: list

    def __init__(self):
        self.a = 0
        self.b = []
```

or use direclty a dataclass when possible!

### BAD: How we DON'T want to do it

We have the option to add variables from outside to the class:

```python
class MostSimplestClass:
    pass

instance = MostSimplestClass()
instance.a: int = 1
print(instance.a)
```

or you can define variables in any of the methods:

```python
class MostSimplestClass:
    def __init__(self):
        self.a: int = 1

    def first_run(self):
        self.b: int = 2


instance = MostSimplestClass()
print(instance.a) # -> 1
instance.first_run()
print(instance.b) # -> 2
```

This is valid and working code. However, you will create a mess. If someone else (or yourself after a few weeks later) needs to look at your source code, there will be tears and hate.  

Better, but not good, is to define everything in \_\_init\_\_():

```python
class MostSimplestClass:
    def __init__(self):
        self.a: int = 1
        self.b: int = 0

    def first_run(self):
        self.b = 2


instance = MostSimplestClass()
print(instance.a)  # -> 1
instance.first_run()
print(instance.b)  # -> 2
```

However, if your \_\_init\_\_ is more complex, you have to search through it for finding the variables. 

### GOOD

For a better code quality we should look at the Python dataclass. 

```python
class MostSimplestClass:
    a: int = 1
    b: int = 0

    def first_run(self):
        self.b = 2


instance = MostSimplestClass()
print(instance.a)  # -> 1
instance.first_run()
print(instance.b)  # -> 2
```

Now every class variable is defined in the beginning at one place. Easy to find. Easy to look through. We also add the type of the variable here, since we should provide it at the first use of the variable. All question or uncertainty where the first appearance of a variable will be is removed. 

However, we need to talk about [mutable objects](https://docs.python.org/3/glossary.html#term-mutable) and [the problem with mutable objects](https://docs.python.org/3/tutorial/classes.html#class-and-instance-variables) and their initialization.

### The danger of initializing mutable variables

* [immutable](https://docs.python.org/3/glossary.html#term-immutable) (e.g. numbers, string, tuples) : "An object with a fixed value. Immutable objects include numbers, strings and tuples. Such an object cannot be altered. A new object has to be created if a different value has to be stored."
* [mutable](https://docs.python.org/3/glossary.html#term-mutable) ([list](https://docs.python.org/3/tutorial/introduction.html#lists), [dictionary](https://docs.python.org/3/tutorial/datastructures.html#dictionaries), [set](https://docs.python.org/3/tutorial/datastructures.html#sets)) : "Mutable objects can change their value but keep their [id()](https://docs.python.org/3/library/functions.html#id)."

This is how the problem looks like:

```python
class SimpleClass:
    a: int = 0
    b: list = []

instance_a = SimpleClass()
instance_b = SimpleClass()

instance_a.a = 1
print(instance_a.a)  # -> 1
print(instance_b.a)  # -> 0

instance_a.b.append("X")
print(instance_a.b)  # -> ['X']
print(instance_b.b)  # -> ['X']
```

The correct way to handle it is:

```python
class SimpleClass:
    a: int
    b: list

    def __init__(self):
        self.a = 0
        self.b = []


instance_a = SimpleClass()
instance_b = SimpleClass()

instance_a.a = 1
print(instance_a.a)  # -> 1
print(instance_b.a)  # -> 0

instance_a.b.append("X")
print(instance_a.b)  # -> ['X']
print(instance_b.b)  # -> []
```

Since you have defined the variables in the beginning of the class and know the type of it (due to the type annotation), you can just copy the list into the constructor \_\_init\_\_ and initialize the variables there. 

### The alternative: dataclass

Maybe you want to consider using dataclass where it is possible instead. There you are protected against this error:

```python
from dataclasses import dataclass

@dataclass
class SimpleClass:
    a: list = [] 
```

```python
ValueError: mutable default <class 'list'> for field a is not allowed: use default_factory
```

And you get there a nice way to initialize mutable objects safely via default_factory: 

```python
from dataclasses import dataclass, field

@dataclass
class SimpleClass:
    a: list = field(default_factory=list)

instance_a = SimpleClass()
instance_b = SimpleClass()

instance_a.a.append("X")
print(instance_a.a)  # -> ['X']
print(instance_b.a)  # -> []
```

### [@property()](https://docs.python.org/3/library/functions.html#property)

If a variable starts with one \_ this tells us that it is "private" and we shouldn't touch it directly with our dirty hands from the outside. However, we can use @property to control the communication with the outside world:  

```python
class SimpleClass:
    _a: int = 0

    @property
    def a(self) -> int:
        return self._a

instance = SimpleClass()

print(instance.a)  

instance.a = 1  
```

```python
0
[...]
AttributeError: property 'a' of 'SimpleClass' object has no setter
```

If we want to then we can allow writing and deleting of the variable too:

```python
class SimpleClass:
    _variablename: int = 0

    @property
    def variablename(self) -> int:
        return self._variablename

    @variablename.setter
    def variablename(self, value):
        self._variablename = value

    @variablename.deleter
    def variablename(self):
        del self._variablename


instance = SimpleClass()

print(instance.variablename)  # -> 0

instance.variablename = 1
print(instance.variablename)  # -> 1
```

### [\_\_slots\_\_](https://docs.python.org/3/reference/datamodel.html#slots)

[They say:](https://docs.python.org/3/reference/datamodel.html#slots)

* \_\_slots\_\_ allow us to explicitly declare data members (like properties) and deny the creation of [\_\_dict\_\_](https://docs.python.org/3/library/stdtypes.html#object.__dict__) and \_\_weakref\_\_ (unless explicitly declared in \_\_slots\_\_ or available in a parent.)
The space saved over using [\_\_dict\_\_](https://docs.python.org/3/library/stdtypes.html#object.__dict__) can be significant. Attribute lookup speed can be significantly improved as well.
Let's test if they are really smaller (Note: I will use the memory_profiler module which doesn't work with ipython: pip install memory_profiler ): 

With slots:

```python
from memory_profiler import profile

class SimpleClass:
    __slots__ = ["variable_a", "variable_b", "variable_c"]
    variable_a: int
    variable_b: float
    variable_c: float

    def __init__(self, value) -> None:
        self.variable_a = value
        self.variable_b = value * 2
        self.variable_c = value * 3


@profile
def main():
    instances = []
    for i in range(0, 100000):
        instances.append(SimpleClass(i))

main()
```

Note: The default values are set in the \_\_init\_\_ and in the section not above. \_\_slots\_\_ doesn't like it if you provide directly default values. 

```python
Line #    Mem usage    Increment  Occurrences   Line Contents
=============================================================
    17     39.2 MiB     39.2 MiB           1   @profile
    18                                         def main():
    19     39.2 MiB      0.0 MiB           1       instances = []
    20     56.0 MiB     13.9 MiB      100001       for i in range(0, 100000):
    21     56.0 MiB      2.8 MiB      100000           instances.append(SimpleClass(i))
```

Without slots:

```python
from memory_profiler import profile


class SimpleClass:
    variable_a: int
    variable_b: float
    variable_c: float

    def __init__(self, value) -> None:
        self.variable_a = value
        self.variable_b = value * 2
        self.variable_c = value * 3


@profile
def main():
    instances = []
    for i in range(0, 100000):
        instances.append(SimpleClass(i))

main()
```

```python
Line #    Mem usage    Increment  Occurrences   Line Contents
=============================================================
    17     39.4 MiB     39.4 MiB           1   @profile
    18                                         def main():
    19     39.4 MiB      0.0 MiB           1       instances = []
    20     65.2 MiB      6.2 MiB      100001       for i in range(0, 100000):
    21     65.2 MiB     19.6 MiB      100000           instances.append(SimpleClass(i))
```

Why don't we use it all the time? Well, dynamic maneuvers like this are now denied:  

```python
class SimpleClass:
    __slots__ = ["variable_a", "variable_b", "variable_c"]
    variable_a: int
    variable_b: float
    variable_c: float

    def __init__(self, value) -> None:
        self.variable_a = value
        self.variable_b = value * 2
        self.variable_c = value * 3
        self.b = 1 # AttributeError: 'SimpleClass' object has no attribute 'b'


instances = SimpleClass(1)
instances.a = 1  # AttributeError: 'SimpleClass' object has no attribute 'a'
```

## Methods

**Note: If we want to use a method (or a variable) of the class from within the class we need to use the prefix self.**

In this example we have defined two methods: **\_\_init\_\_** which is the constructor and **some_method** . Methods are "just" functions defined in a class. 

Typically (except you deal with @classmethod or @staticmethod) the first argument of a method is **self**.

```python
class SimpleClass:
    variable_a: int

    def __init__(self) -> None:
        self.variable_a = 1

    def some_method(self, input: int) -> int:
        return self.variable_a + input


instance = SimpleClass()
print(instance.some_method(678)) # -> 679
```

In case we use a function from the outside of the class, we don't see / provide **self** as an input argument.

```python
class SimpleClass:
    variable_a: int

    def __init__(self) -> None:
        self.variable_a = 1

    def some_method(self, input: int) -> int:
        return self.variable_a + input

    def some_other_method(self, input: int) -> int:
        return self.some_method(input)


instance = SimpleClass()
print(instance.some_other_method(678))  # -> 679
```

### [Constructor: __init__](https://docs.python.org/3/reference/datamodel.html#object.__init__)

When we [create](https://docs.python.org/3/reference/datamodel.html#object.__init__) a new instance, two internal functions of the class are called \_\_new\_\_ and \_\_init\_\_ . \_\_new\_\_ creates it and \_\_init\_\_ customize it. Normally there is no reason to touch \_\_new\_\_.

**Note: No return values except None are allowed.**

We will otherwise get errors like: "TypeError: \_\_init\_\_() should return None, not 'int'"

The first parameter of \_\_init\_\_ is always **self**!

```python
class SimpleClass:
    variable_a: int

    def __init__(self) -> None:
        self.variable_a = 1

instance = SimpleClass()
```

We can add more arguments if we want to. Here an example with one additional argument: 

```python
class SimpleClass:
    variable_a: int

    def __init__(self, value) -> None:
        self.variable_a = value

instance = SimpleClass(1)
```

### [\_\_str\_\_](https://docs.python.org/3/reference/datamodel.html#object.__str__) and [\_\_repr\_\_](https://docs.python.org/3/reference/datamodel.html#object.__repr__)

If we print our class then this happens:

```python
class SimpleClass:
    variable_a: int

    def __init__(self, value) -> None:
        self.variable_a = value


instance = SimpleClass(1)
print(instance) # -> <__main__.SimpleClass object at 0x7fcab0600b80>
```

However, we can add a \_\_str\_\_ function and then we can customize our output:

```python
class SimpleClass:
    variable_a: int

    def __init__(self, value) -> None:
        self.variable_a = value

    def __str__(self) -> str:
        return f"{self.variable_a}"

instance = SimpleClass(1)
print(instance)
```

But please be aware that there are more than one putative functions for producing output information: 

* [object.\_\_str\_\_(self)](https://docs.python.org/3/reference/datamodel.html#object.__str__) **human friendly** : Called by str(object) and the built-in functions format() and print() to compute the “informal” or nicely printable string representation of an object. The return value must be a string object.
* [object.\_\_repr\_\_(self)](https://docs.python.org/3/reference/datamodel.html#object.__repr__)  **unambiguous** : Called by the repr() built-in function to compute the “official” string representation of an object. If at all possible, this should look like a valid Python expression that could be used to recreate an object with the same value (given an appropriate environment). If this is not possible, a string of the form <...some useful description...> should be returned. The return value must be a string object. If a class defines \_\_repr\_\_() but not \_\_str\_\_(), then \_\_repr\_\_() is also used when an “informal” string representation of instances of that class is required. This is typically used for debugging, so it is important that the representation is information-rich and unambiguous.

