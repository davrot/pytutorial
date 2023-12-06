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

{: .topic-optional}
This is an optional topic!


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

### [@staticmethod](https://docs.python.org/3/library/functions.html#staticmethod) and [@classmethod](https://docs.python.org/3/library/functions.html#classmethod)
**Let us be blunt here: I am not sure if you want/ need to know what @staticmethod and @classmethod does.** I was interested in this topic because I saw these decorators and asked myself what they are for. 

This is a normal class method: 

```python
class SimpleClass:
    def normal_class_method(self, input: int) -> int:
        return input


instance = SimpleClass()
x = instance.normal_class_method(123)
print(x) # -> 123

print(instance.normal_class_method)  # -> <bound method SimpleClass.normal_class_method of <__main__.SimpleClass object at 0x7fcaac3334c0>>
```

The normal class method is bound (i.e. connected) to its class. 


In the case of a **@staticmethod**, it has no first argument self. And it is not bound to the class. Or in other words: The class is just a container for this @staticmethod or "regular" function. 

```python
class SimpleClass:
    @staticmethod
    def static_class_method(input: int) -> int:
        return input

instance = SimpleClass()
x = instance.static_class_method(123)
print(x)  # -> 123

print(
    instance.static_class_method
)  # -> <function SimpleClass.static_class_method at 0x7fca969036d0>
```

In the case of a **@classmethod**, we generate a function that can be called via the class and NOT via the 
instance: 

```python
class SimpleClass:
    @classmethod
    def class_class_method(cls, input: int) -> int:
        return input


x = SimpleClass.class_class_method(123)
print(x)  # -> 123
```

Note: cls is the replacement for self here. cls gives the class and self the instance to the function. 

## Inherentence

Inherentence allows us to add on variables and/or methods to a existing class without copying the whole source code. We inherent from a class if the put it into ( ) in the class definition:

```python
class BaseClassA:
    a: int = 0


class ClassA(BaseClassA):
    b: int = 1


instance = ClassA()
print(instance.a)  # -> 0
print(instance.b)  # -> 1
```

Also we can replace functions:

```python
class BaseClassA:
    def print_something(self):
        print("BaseClassA")


class ClassA(BaseClassA):
    def print_something(self):
        print("ClassA")


instance = ClassA()
instance.print_something() # -> ClassA
```

## Multiple inheritance

And we inherent from more than one class: 

```python
class BaseClassA:
    def print_something(self):
        print("BaseClassA")


class BaseClassB:
    def print_something(self):
        print("BaseClassB")


class ClassA(BaseClassA, BaseClassB):
    pass


class ClassB(BaseClassB, BaseClassA):
    pass


instance_a = ClassA()
instance_a.print_something()  # -> BaseClassA
instance_b = ClassB()
instance_b.print_something()  # -> BaseClassB

print(ClassA.__mro__) # -> (<class '__main__.ClassA'>, <class '__main__.BaseClassA'>, <class '__main__.BaseClassB'>, <class 'object'>)
print(ClassB.__mro__) # -> (<class '__main__.ClassB'>, <class '__main__.BaseClassB'>, <class '__main__.BaseClassA'>, <class 'object'>)
```

As you can see: Which version of the functions survives can be complicated. If you want to understand the MRO (Method resolution order) you can look up [C3 linearization](https://en.wikipedia.org/wiki/C3_linearization). Personally, I would try to avoid this unclear situations everywhere. 

We can define more precisely and prevent surprises: 

```python
class BaseClassA:
    a = 1

    def print_something(self):
        print(f"BaseClassA {self.a}")


class BaseClassB:
    a = 2

    def print_something(self):
        print(f"BaseClassB {self.a}")


class ClassA(BaseClassA, BaseClassB):
    a = 3

    def print_something(self):
        BaseClassB.print_something(self)


instance_a = ClassA()
instance_a.print_something() # -> BaseClassB 3
```

If we only inherent from one class we can use super().

## [super()](https://docs.python.org/3/library/functions.html#super)

* "There are two typical use cases for super. In a class hierarchy with single inheritance, super can be used to refer to parent classes without naming them explicitly, thus making the code more maintainable. This use closely parallels the use of super in other programming languages."
* "The second use case is to support cooperative multiple inheritance in a dynamic execution environment."

Or in other words: super() will call the version of a function that is next in line in the MRO. 

As a simple example lets look at BaseClassA -> BaseClassB -> BaseClassC: 

```python
class BaseClassA:
    a = 1

    def print_something(self):
        print(f"BaseClassA {self.a}")


class BaseClassB(BaseClassA):
    a = 2

    def print_something(self):
        super().print_something()
        print(f"BaseClassB {self.a}")


class BaseClassC(BaseClassB):
    a = 3

    def print_something(self):
        super().print_something()
        print(f"BaseClassC {self.a}")


instance_a = BaseClassC()
instance_a.print_something()
```

Output

```python
BaseClassA 3
BaseClassB 3
BaseClassC 3
```

Note that for BaseClassA there is no super() because there is no higher level to call. But in the case of \_\_init\_\_ we can do that:

```python
class BaseClassA:
    a = 1

    def __init__(self):
        super().__init__()
        print(f"BaseClassA {self.a}")


class BaseClassB(BaseClassA):
    a = 2

    def __init__(self):
        super().__init__()
        print(f"BaseClassB {self.a}")


class BaseClassC(BaseClassB):
    a = 3

    def __init__(self):
        super().__init__()
        print(f"BaseClassC {self.a}")


instance_a = BaseClassC()
```

Output

```python
BaseClassA 3
BaseClassB 3
BaseClassC 3
```

Why can we do that? Well, **class BaseClassA**: is just a shorthand for **class BaseClassA(object)**:

[Object](https://docs.python.org/3/reference/datamodel.html#basic-customization) already provides us with some basic functionality like \_\_init\_\_ which is contained in all user custom classes (if not removed). 

## [ABC (Abstract Base Classes)](https://docs.python.org/3/library/abc.html#module-abc) and [@abstractmethod](https://docs.python.org/3/library/abc.html#abc.abstractmethod)

Maybe you need a placeholder for a future function but also want to make REALLY sure that the new class defines the function. For such a case you can use the base class ABC with @abstractmethod

Deliberately not working:

```python
from abc import ABC, abstractmethod


class BaseClassA(ABC):
    @abstractmethod
    def function_a(self):
        pass


instance = BaseClassA() # -> TypeError: Can't instantiate abstract class BaseClassA with abstract method function_a
```

Also deliberately not working:

```python
from abc import ABC, abstractmethod


class BaseClassA(ABC):
    @abstractmethod
    def function_a(self):
        pass


class BaseClassB(BaseClassA):
    pass

instance = BaseClassB() # TypeError: Can't instantiate abstract class BaseClassB with abstract method function_a
```

This is working:

```python
from abc import ABC, abstractmethod


class BaseClassA(ABC):
    @abstractmethod
    def function_a(self):
        pass


class BaseClassB(BaseClassA):
    def function_a(self):
        pass


instance = BaseClassB()
```

## Compositions -- Against the curse of dimensionality

While inherentence is a nice tool, it leads very fast to an explosion of specialized classes.

An alternative is the composition approach. Here a base class for a functionality is prepared with the required abstract placeholders. This base class is then inherented by classes that provide the required spectrum of functionality. Then a composition class is designed. During instancing the composition class we plug in the functionality we want. 

Hard to explain in words. Easy to show in an example: 

```python
from abc import ABC, abstractmethod


class BaseFunction(ABC):
    @abstractmethod
    def add_something(self, input: int) -> int:
        pass


class AddOne(BaseFunction):
    def add_something(self, input: int) -> int:
        return input + 1


class AddTwo(BaseFunction):
    def add_something(self, input: int) -> int:
        return input + 2


class CompositionClass:
    method_one: BaseFunction
    method_two: BaseFunction

    def __init__(self, method_one: BaseFunction, method_two: BaseFunction) -> None:
        super().__init__()
        self.method_one = method_one
        self.method_two = method_two

    def processing(self, input: int) -> int:
        return self.method_two.add_something(self.method_one.add_something(input))


variant_a = CompositionClass(method_one=AddOne(), method_two=AddOne())
print(variant_a.processing(0))  # -> 2

variant_b = CompositionClass(method_one=AddTwo(), method_two=AddTwo())
print(variant_b.processing(0))  # -> 4

variant_c = CompositionClass(method_one=AddOne(), method_two=AddTwo())
print(variant_c.processing(0))  # -> 3

variant_d = CompositionClass(method_one=AddTwo(), method_two=AddOne())
print(variant_d.processing(0))  # -> 3
```

## [functools](https://docs.python.org/3/library/functools.html)

### [@cached_property](https://docs.python.org/3/library/functools.html#functools.cached_property) (not recommended)

I am not really a fan of this one. It allows you to cache calculations. However, this works only if the data behind the calculation doesn't change in any way, shape or form. If you change it then result is NOT updated. 

```python
from functools import cached_property


class SimpleClass:
    _a: int
    _b: int

    def __init__(self):
        self._a = 1
        self._b = 2

    @cached_property
    def value_x(self):
        return self._a + self._b


instance = SimpleClass()
print(instance.value_x)  # -> 3
instance._a = 7
print(instance.value_x)  # -> 3
```

### [partialmethod](https://docs.python.org/3/library/functools.html#functools.partialmethod)

Partialmethod allows you to create an alias for an already defined function but with partially pre-defined arguments:

```python
from functools import partialmethod


class SimpleClass:
    def function_a(self, input_1: int, input_2: int) -> int:
        return input_1 + input_2

    add_one = partialmethod(function_a, 1)


instance = SimpleClass()

print(instance.function_a(1, 1))  # -> 2
print(instance.add_one(1))  # -> 2
```

## [Iterators](https://wiki.python.org/moin/Iterator)

Iterators are used in e.g. for loops. Iterators are classes that provide the methods [\_\_iter\_\_](https://docs.python.org/3/reference/datamodel.html#object.__iter__) and [\_\_next\_\_](https://docs.python.org/3/library/stdtypes.html#iterator.__next__) . \_\_iter\_\_ just returns itself. \_\_next\_\_ does something. If \_\_next\_\_ can not do anything more (e.g. because there is not more data) then it raises the exception StopIteration.

```python
class IterExample:
    a_max: int
    a: int

    def __init__(self):
        self.a_max = 10
        self.a = 0

    def __iter__(self):
        return self

    def __next__(self):
        if self.a < self.a_max:
            self.a += 1
        else:
            raise StopIteration
        return self.a**2


instance = IterExample()

for i in instance:
    print(i)
```

We can also use the iterator class manually via [next()](https://docs.python.org/3/library/functions.html#next):

```python
class IterExample:
    a_max: int
    a: int

    def __init__(self):
        self.a_max = 10
        self.a = 0

    def __iter__(self):
        return self

    def __next__(self):
        if self.a < self.a_max:
            self.a += 1
        else:
            raise StopIteration
        return self.a**2


instance = IterExample()

print(next(instance))  # -> 1
print(next(instance))  # -> 4
print(next(instance))  # -> 9
print(next(instance))  # -> 16
print(next(instance))  # -> 25
print(next(instance))  # -> 36
print(next(instance))  # -> 49
print(next(instance))  # -> 64
print(next(instance))  # -> 81
print(next(instance))  # -> 100
print(next(instance))  # -> StopIteration:
```

## [Generators](https://docs.python.org/3/glossary.html#term-generator)

"A function which returns a [generator iterator](https://docs.python.org/3/glossary.html#term-generator-iterator). It looks like a normal function except that it contains [yield](https://docs.python.org/3/reference/simple_stmts.html#yield) expressions for producing a series of values usable in a for-loop or that can be retrieved one at a time with the [next()](https://docs.python.org/3/library/functions.html#next) function."

Manually:

```python
def generator(start_value: int, end_value: int):
    for i in range(start_value, end_value):
        yield i**2


i = iter(generator(1, 11))

print(next(i))  # -> 1
print(next(i))  # -> 4
print(next(i))  # -> 9
print(next(i))  # -> 16
print(next(i))  # -> 25
print(next(i))  # -> 36
print(next(i))  # -> 49
print(next(i))  # -> 64
print(next(i))  # -> 81
print(next(i))  # -> 100
print(next(i))  # -> StopIteration:
```

Via for-loop:

```python
def generator(start_value: int, end_value: int):
    for i in range(start_value, end_value):
        yield i**2


for i in generator(1, 11):
    print(i)
```

Output:

```python
1
4
9
16
25
36
49
64
81
100
```

## [dir](https://docs.python.org/3/library/functions.html#dir)

"Without arguments, return the list of names in the current local scope. With an argument, attempt to return a list of valid attributes for that object."

```python
class BaseClassA:
    a: int

    def __init__(self):
        super().__init__()
        self.a = 1

    def function_a(self):
        pass

    def function_b(self):
        pass


print(dir(BaseClassA))
```

Output

```python
['__annotations__', '__class__', '__delattr__', '__dict__', '__dir__', '__doc__', '__eq__', '__format__', '__ge__', '__getattribute__', '__gt__', '__hash__', '__init__', '__init_subclass__', '__le__', '__lt__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', 'function_a', 'function_b']
```

If you look carefully through the list you will notice that the variable a is not there. The reason for this is that it doesn't exist until the instance is created:  

```python
class BaseClassA:
    __slots__ = ["a"]
    a: int

    def __init__(self):
        super().__init__()
        self.a = 1

    def function_a(self):
        pass

    def function_b(self):
        pass


instance = BaseClassA()
print(dir(instance))
```

Output

Even with \_\_slots\_\_ use, now the variable a is included in the list: 

```python
['__annotations__', '__class__', '__delattr__', '__dir__', '__doc__', '__eq__', '__format__', '__ge__', '__getattribute__', '__gt__', '__hash__', '__init__', '__init_subclass__', '__le__', '__lt__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__slots__', '__str__', '__subclasshook__', 'a', 'function_a', 'function_b']
```

## References

* [Classes](https://docs.python.org/3/tutorial/classes.html)
* [Objects: Special method names](https://docs.python.org/3/reference/datamodel.html#special-method-names)
