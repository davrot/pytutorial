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
