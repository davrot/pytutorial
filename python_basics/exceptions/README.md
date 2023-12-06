# Exceptions
{:.no_toc}

<nav markdown="1" class="toc-class">
* TOC
{:toc}
</nav>

## The goal
The “modern” way (the concept is from the 1960) to deal with errors is to use exceptions. “Normal” errors just kill your program. Exceptions allow you to react to the error (if you want to). Plus, it is standardized and you don’t need to invent your own approach, which is important if source code is exchanged.

An exception is thrown (i.e. raised under Python). And the program has to catch and deal with the exception. 

Questions to [David Rotermund](mailto:davrot@uni-bremen.de)

[Notes:](https://docs.python.org/3/library/exceptions.html)

* **Never use the BaseException for developing your own exception. **
* **All user-defined exceptions should be derived from Exception.**
* The exception **KeyboardInterrupt** inherits directly from **BaseException** so as to not be accidentally caught by code that catches Exception and thus prevent the interpreter from exiting.
* The exception **SystemExit** inherits from **BaseException** instead of Exception so that it is not accidentally caught by code that catches Exception.
* Put as few commands as possible into the try section. (see [PEP8 style guide](https://peps.python.org/pep-0008/#programming-recommendations))
* The most laziest exception handling should use Exception as target. **Never** use a bare except:

```python
try:
    [...]
except Exception:
    [...]
```

## Examples of Exception

```python
10 * (1 / 0) # -> ZeroDivisionError: division by zero

4 * not_there_variable + 1 # -> NameError: name 'not_there_variable' is not defined

"1" + 1 # -> TypeError: can only concatenate str (not "int") to str

with open("file_that_is_not_there.nope", "r") as fid: # -> FileNotFoundError: [Errno 2] No such file or directory: 'file_that_is_not_there.nope'
    pass
```

## [How to deal with exceptions](https://docs.python.org/3/tutorial/errors.html#handling-exceptions)

We can use [try / except](https://docs.python.org/3/reference/compound_stmts.html#try) where we expect that a Exception could be raised: 

```python
try:
    x = 10 * (1 / 0)
except ZeroDivisionError:
    x = 0

print(x) #-> 0
```

We can also prepare for more than one Exception:

```python
try:
    x = "1" + 1
except ZeroDivisionError:
    x = 0
except NameError:
    x = 1
except TypeError:
    x = 3

print(x) # -> 3
```

## BAD: Catch all

You could **catch all** possible exceptions like this

```python
try:
    x = "1" + 1
except: # -> do not use bare 'except'
    x = 42
print(x)
```

but (as you already see of the error by the linting system) **it is a very bad idea**. Everybody will think that you are not really civilized and will avoid you for the rest of your life. 

You will block exception like KeyboardInterrupt which are required to abort your program with the keyboard.

**The maximum of laziness allowed is to use Exception** like show in this example: 

```python
try:
    x = "1" + 1
except Exception:
    x = 42
print(x)
```

Please take a look at the Exception hierarchy at the end of this guide. 

## Sort your exceptions

You need to sort the exceptions according the exception hierarchy. The more specialized come first. The broader ones come later. 

Correct:

```python
try:
    x = "1" + 1
except TypeError:
    x = 21
except Exception:
    x = 42
print(x) # -> 21
```

Wrong:

```python
try:
    x = "1" + 1
except Exception:
    x = 42
except TypeError:
    x = 21
print(x) # -> 42
```

## Using the information from within the Exception

Already the build-in exceptions contain additional information:

```python
try:
    x = "1" + 1
except TypeError as e:
    print(type(e))
    print("")
    print(dir(e))
    print("")
    print(e)
    print("")
    print(e.args)
```

Output:

```python
<class 'TypeError'>

['__cause__', '__class__', '__context__', '__delattr__', '__dict__', '__dir__', '__doc__', '__eq__', '__format__', '__ge__', '__getattribute__', '__gt__', '__hash__', '__init__', '__init_subclass__', '__le__', '__lt__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__setstate__', '__sizeof__', '__str__', '__subclasshook__', '__suppress_context__', '__traceback__', 'args', 'with_traceback']

can only concatenate str (not "int") to str

('can only concatenate str (not "int") to str',)
```

If we raise an exception then we can use this additional information to transfer information about the error and how to fix it. 

```python
try:
    raise Exception("User-Error1", "X is not a U")
except Exception as e:
    print(type(e))
    print("")
    print(e)
    print("")
    print(e.args[0])
    print("")
    print(e.args[1])
```

Output:

```python
<class 'Exception'>

('User-Error1', 'A X is not a U')

User-Error1

A X is not a U
```

## Custom Exceptions

We can and should build our own exceptions. It is recommended to create your own branch on the Exception hierarchy tree. In the example I made a branch BaseError derived from Exception. Now I can generate specialized errors from BaseError. The idea behind is that I now can catch all MY own errors with except BaseError if I don't want to distinguish between my errors.  

```python
class BaseError(Exception):
    def __init__(self, *args: object):
        super().__init__(*args)


class E1Error(BaseError):
    message: str
    error_value: str

    def __init__(self, *args: object):
        super().__init__(*args)
        self.message = str(args[0])
        self.error_value = str(args[1])


try:
    raise E1Error("User-Error1", "X is not a U")
except E1Error as e:
    print(e.message)
    print("")
    print(e.error_value)
```

Output:

```python
User-Error1

X is not a U
```

## Raise Exceptions

I you want to raise an exception in your source code, then you need to determine which exception class is the best for the problem. And then raise that exception with **raise**.

```python
raise NameError("My name is NameError") # -> NameError: My name is NameError
```

You can also re-raise an exception if you couldn't handle it or want to use the info for down the lane:

```python
try:
    try:
        raise NameError("My name is NameError")  # -> NameError: My name is NameError
    except NameError as e:
        print("A NameError:")
        print(e)
        raise
except Exception as e:
    print("An Exception:")
    print(e)
```

Output:

```python
A NameError:
My name is NameError
An Exception:
My name is NameError
```

## The full syntax [try / except / else / finally](https://docs.python.org/3/reference/compound_stmts.html#try)

We full syntax looks like this:

```python
try:
    ...
except Exception:
    ...
else:
    ...
finally:
    ...
```

**finally** is always executed. **else** is executed when NO exception was raised at all.

**If there is an exception, which is not excepted by except (because the exception type was not broad enough), it will stop the program AFTER finally.**

## Chaining exceptions

{: .topic-optional}
This is an optional topic!


Instead of just re-raising an exception we can also add to it with **from**. 

```python
def function() -> None:
    raise Exception("I broke it!")

try:
    function()
except Exception as e:
    raise Exception("I don't care") from e
```

Output:

```python
---------------------------------------------------------------------------
Exception                                 Traceback (most recent call last)
/data_1/davrot/test/xxxx.py in line 7
      9 try:
----> 10     function()
      11 except Exception as e:

/data_1/davrot/test/xxxx.py in line 3, in function()
      5 def function() -> None:
----> 6     raise Exception("I broke it!")

Exception: I broke it!

The above exception was the direct cause of the following exception:

Exception                                 Traceback (most recent call last)
/data_1/davrot/test/xxxx.py in line 9
      10     function()
      11 except Exception as e:
----> 12     raise Exception("I don't care") from e

Exception: I don't care
```

## [Exception hierarchy](https://docs.python.org/3/library/exceptions.html#exception-hierarchy)

```python
BaseException
 ├── BaseExceptionGroup
 ├── GeneratorExit
 ├── KeyboardInterrupt
 ├── SystemExit
 └── Exception
      ├── ArithmeticError
      │    ├── FloatingPointError
      │    ├── OverflowError
      │    └── ZeroDivisionError
      ├── AssertionError
      ├── AttributeError
      ├── BufferError
      ├── EOFError
      ├── ExceptionGroup [BaseExceptionGroup]
      ├── ImportError
      │    └── ModuleNotFoundError
      ├── LookupError
      │    ├── IndexError
      │    └── KeyError
      ├── MemoryError
      ├── NameError
      │    └── UnboundLocalError
      ├── OSError
      │    ├── BlockingIOError
      │    ├── ChildProcessError
      │    ├── ConnectionError
      │    │    ├── BrokenPipeError
      │    │    ├── ConnectionAbortedError
      │    │    ├── ConnectionRefusedError
      │    │    └── ConnectionResetError
      │    ├── FileExistsError
      │    ├── FileNotFoundError
      │    ├── InterruptedError
      │    ├── IsADirectoryError
      │    ├── NotADirectoryError
      │    ├── PermissionError
      │    ├── ProcessLookupError
      │    └── TimeoutError
      ├── ReferenceError
      ├── RuntimeError
      │    ├── NotImplementedError
      │    └── RecursionError
      ├── StopAsyncIteration
      ├── StopIteration
      ├── SyntaxError
      │    └── IndentationError
      │         └── TabError
      ├── SystemError
      ├── TypeError
      ├── ValueError
      │    └── UnicodeError
      │         ├── UnicodeDecodeError
      │         ├── UnicodeEncodeError
      │         └── UnicodeTranslateError
      └── Warning
           ├── BytesWarning
           ├── DeprecationWarning
           ├── EncodingWarning
           ├── FutureWarning
           ├── ImportWarning
           ├── PendingDeprecationWarning
           ├── ResourceWarning
           ├── RuntimeWarning
           ├── SyntaxWarning
           ├── UnicodeWarning
           └── UserWarning
```

## Resources

* [Built-in Exceptions](https://docs.python.org/3/library/exceptions.html)
 
