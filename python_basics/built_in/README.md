# [Built-in Functions](https://docs.python.org/3/library/functions.html#built-in-functions)
{:.no_toc}

<nav markdown="1" class="toc-class">
* TOC
{:toc}
</nav>

## The goal

Do I need to know what all these functions are doing? No, but you are shouldn't use these function names for your own functions!​

Questions to [David Rotermund](mailto:davrot@uni-bremen.de)

|||
|---|---|
|[abs()](https://docs.python.org/3/library/functions.html#abs)|Return the absolute value of a number.|
|[aiter()](https://docs.python.org/3/library/functions.html#aiter)|Return an asynchronous iterator for an asynchronous iterable.|
|[all()](https://docs.python.org/3/library/functions.html#all)|Return True if all elements of the iterable are true (or if the iterable is empty).|
|[anext()](https://docs.python.org/3/library/functions.html#anext)|When awaited, return the next item from the given asynchronous iterator, or default if given and the iterator is exhausted.|
|[any()](https://docs.python.org/3/library/functions.html#any)|Return True if any element of the iterable is true. If the iterable is empty, return False.|
|[ascii()](https://docs.python.org/3/library/functions.html#ascii)|As repr(), return a string containing a printable representation of an object, but escape the non-ASCII characters in the string|
|[bin()](https://docs.python.org/3/library/functions.html#bin)|Convert an integer number to a binary string prefixed with “0b”. |
|[bool()](https://docs.python.org/3/library/functions.html#bool)|Return a Boolean value, i.e. one of True or False.|
|[breakpoint()](https://docs.python.org/3/library/functions.html#breakpoint)|This function drops you into the debugger at the call site.|
|[bytearray()](https://docs.python.org/3/library/functions.html#func-bytearray)|Return a new array of bytes.|
|[bytes()](https://docs.python.org/3/library/functions.html#func-bytes)| Return a new “bytes” object which is an immutable sequence of integers in the range 0 <= x < 256.|
|[callable()](https://docs.python.org/3/library/functions.html#callable)|Return True if the object argument appears callable, False if not. If this returns True, it is still possible that a call fails, but if it is False, calling object will never succeed. |
|[chr()](https://docs.python.org/3/library/functions.html#chr)|Return the string representing a character whose Unicode code point is the integer i. |
|[classmethod()](https://docs.python.org/3/library/functions.html#classmethod)|Transform a method into a class method.|
|[compile()](https://docs.python.org/3/library/functions.html#compile)|Compile the source into a code or AST object. Code objects can be executed by exec() or eval(). source can either be a normal string, a byte string, or an AST object. |
|[complex()](https://docs.python.org/3/library/functions.html#complex)|Return a complex number with the value real + imag*1j or convert a string or number to a complex number. |
|[delattr()](https://docs.python.org/3/library/functions.html#delattr)|This is a relative of setattr().|
|[dict()](https://docs.python.org/3/library/functions.html#func-dict)|Create a new dictionary. |
|[dir()](https://docs.python.org/3/library/functions.html#dir)|Without arguments, return the list of names in the current local scope. With an argument, attempt to return a list of valid attributes for that object.|
|[divmod()](https://docs.python.org/3/library/functions.html#divmod)|Take two (non-complex) numbers as arguments and return a pair of numbers consisting of their quotient and remainder when using integer division. |
|[enumerate()](https://docs.python.org/3/library/functions.html#enumerate)|Return an enumerate object. iterable must be a sequence, an iterator, or some other object which supports iteration.|
|[eval()](https://docs.python.org/3/library/functions.html#eval)|The expression argument is parsed and evaluated as a Python expression (technically speaking, a condition list) using the globals and locals dictionaries as global and local namespace.|
|[exec()](https://docs.python.org/3/library/functions.html#exec)|This function supports dynamic execution of Python code. |
|[filter()](https://docs.python.org/3/library/functions.html#filter)|Construct an iterator from those elements of iterable for which function is true.|
|[float()](https://docs.python.org/3/library/functions.html#float)|Return a floating point number constructed from a number or string x.|
|[format()](https://docs.python.org/3/library/functions.html#format)|Convert a value to a “formatted” representation, as controlled by format_spec.|
|[frozenset()](https://docs.python.org/3/library/functions.html#func-frozenset)|Return a new frozenset object, optionally with elements taken from iterable. |
|[getattr()](https://docs.python.org/3/library/functions.html#getattr)|Return the value of the named attribute of object. name must be a string. |
|[globals()](https://docs.python.org/3/library/functions.html#globals)|Return the dictionary implementing the current module namespace.|
|[hasattr()](https://docs.python.org/3/library/functions.html#hasattr)|The arguments are an object and a string. The result is True if the string is the name of one of the object’s attributes, False if not. |
|[hash()](https://docs.python.org/3/library/functions.html#hash)|Return the hash value of the object (if it has one). Hash values are integers. They are used to quickly compare dictionary keys during a dictionary lookup.|
|[help()](https://docs.python.org/3/library/functions.html#help)|Invoke the built-in help system. (This function is intended for interactive use.)|
|[hex()](https://docs.python.org/3/library/functions.html#hex)|Convert an integer number to a lowercase hexadecimal string prefixed with “0x”.|
|[id()](https://docs.python.org/3/library/functions.html#id)|Return the “identity” of an object. This is an integer which is guaranteed to be unique and constant for this object during its lifetime. Two objects with non-overlapping lifetimes may have the same id() value.|
|[input()](https://docs.python.org/3/library/functions.html#input)|If the prompt argument is present, it is written to standard output without a trailing newline. The function then reads a line from input, converts it to a string (stripping a trailing newline), and returns that. |
|[int()](https://docs.python.org/3/library/functions.html#int)|Return an integer object constructed from a number or string x, or return 0 if no arguments are given. |
|[isinstance()](https://docs.python.org/3/library/functions.html#isinstance)|Return True if the object argument is an instance of the classinfo argument, or of a (direct, indirect, or virtual) subclass thereof. If object is not an object of the given type, the function always returns False. If classinfo is a tuple of type objects (or recursively, other such tuples) or a Union Type of multiple types, return True if object is an instance of any of the types.|
|[issubclass()](https://docs.python.org/3/library/functions.html#issubclass)|Return True if class is a subclass (direct, indirect, or virtual) of classinfo. A class is considered a subclass of itself. |
|[iter()](https://docs.python.org/3/library/functions.html#iter)|Return an iterator object.|
|[len()](https://docs.python.org/3/library/functions.html#len)|Return the length (the number of items) of an object.|
|[list()](https://docs.python.org/3/library/functions.html#func-list)|Rather than being a function, list is actually a mutable sequence type|
|[locals()](https://docs.python.org/3/library/functions.html#locals)|Update and return a dictionary representing the current local symbol table.|
|[map()](https://docs.python.org/3/library/functions.html#map)|Return an iterator that applies function to every item of iterable, yielding the results. |
|[max()](https://docs.python.org/3/library/functions.html#max)|Return the largest item in an iterable or the largest of two or more arguments.|
|[memoryview()](https://docs.python.org/3/library/functions.html#func-memoryview)|Return a “memory view” object created from the given argument. |
|[min()](https://docs.python.org/3/library/functions.html#min)|Return the smallest item in an iterable or the smallest of two or more arguments.|
|[next()](https://docs.python.org/3/library/functions.html#next)|Retrieve the next item from the iterator by calling its \_\_next\_\_() method.|
|[object()](https://docs.python.org/3/library/functions.html#object)|Return a new featureless object. object is a base for all classes.|
|[oct()](https://docs.python.org/3/library/functions.html#oct)|Convert an integer number to an octal string prefixed with “0o”. |
|[open()](https://docs.python.org/3/library/functions.html#open)|Open file and return a corresponding file object.|
|[ord()](https://docs.python.org/3/library/functions.html#ord)|Given a string representing one Unicode character, return an integer representing the Unicode code point of that character.|
|[pow()](https://docs.python.org/3/library/functions.html#pow)|Return base to the power exp|
|[print()](https://docs.python.org/3/library/functions.html#print)|Print objects to the text stream|
|[property()](https://docs.python.org/3/library/functions.html#property)|Return a property attribute.|
|[range()](https://docs.python.org/3/library/functions.html#func-range)|Rather than being a function, range is actually an immutable sequence type|
|[repr()](https://docs.python.org/3/library/functions.html#repr)|Return a string containing a printable representation of an object.|
|[reversed()](https://docs.python.org/3/library/functions.html#reversed)|Return a reverse iterator. |
|[round()](https://docs.python.org/3/library/functions.html#round)|Return number rounded to ndigits precision after the decimal point. If ndigits is omitted or is None, it returns the nearest integer to its input.|
|[set()](https://docs.python.org/3/library/functions.html#func-set)|Return a new set object, optionally with elements taken from iterable.|
|[setattr()](https://docs.python.org/3/library/functions.html#setattr)|This is the counterpart of getattr(). |
|[slice()](https://docs.python.org/3/library/functions.html#slice)|Return a slice object representing the set of indices specified by range(start, stop, step). The start and step arguments default to None.|
|[sorted()]()|
|[staticmethod()]()|
|[str()]()|
|[sum()]()|
|[super()]()|
|[tuple()]()|
|[type()]()|
|[vars()]()|
|[zip()]()|
|[\_\_import\_\_()]()|

