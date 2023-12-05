# [Programming Recommendations](https://peps.python.org/pep-0008/#programming-recommendations)
{:.no_toc}

<nav markdown="1" class="toc-class">
* TOC
{:toc}
</nav>

## The goal

We want to improve the quality of the code. 

Questions to [David Rotermund](mailto:davrot@uni-bremen.de)

# The recommendations

*Comparisons to singletons like None should always be done with is or is not, never the equality operators.
*Use is not operator rather than not ... is. While both expressions are functionally identical, the former is more readable and preferred:

```python
# Correct:
if foo is not None:
```

* Always use a def statement instead of an assignment statement that binds a lambda expression directly to an identifier:

```python
# Correct:
def f(x): return 2*x

# Wrong:
f = lambda x: 2*x
```

* Derive exceptions from Exception rather than BaseException.
* When catching exceptions, mention specific exceptions whenever possible instead of using a bare except: clause:

```python
try:
    import platform_specific_module
except ImportError:
    platform_specific_module = None
```

* A bare except: clause will catch SystemExit and KeyboardInterrupt exceptions, making it harder to interrupt a program with Control-C, and can disguise other problems. If you want to catch all exceptions that signal program errors, use except Exception: (bare except is equivalent to except BaseException:).
* Additionally, for all try/except clauses, limit the try clause to the absolute minimum amount of code necessary. Again, this avoids masking bugs:

```python
# Correct:
try:
    value = collection[key]
except KeyError:
    return key_not_found(key)
else:
    return handle_value(value)
```

* When a resource is local to a particular section of code, use a with statement to ensure it is cleaned up promptly and reliably after use. A try/finally statement is also acceptable.
* Context managers should be invoked through separate functions or methods whenever they do something other than acquire and release resources:

```python
# Correct:
with conn.begin_transaction():
    do_stuff_in_transaction(conn)
```

* Be consistent in return statements. Either all return statements in a function should return an expression, or none of them should. If any return statement returns an expression, any return statements where no value is returned should explicitly state this as return None, and an explicit return statement should be present at the end of the function (if reachable):

```python
# Correct:

def foo(x):
    if x >= 0:
        return math.sqrt(x)
    else:
        return None

def bar(x):
    if x < 0:
        return None
    return math.sqrt(x) 
```

* Use ''.startswith() and ''.endswith() instead of string slicing to check for prefixes or suffixes.
startswith() and endswith() are cleaner and less error prone:

```python
# Correct:
if foo.startswith('bar'):

# Wrong:
if foo[:3] == 'bar':
```

* Object type comparisons should always use isinstance() instead of comparing types directly:

```python
# Correct:
if isinstance(obj, int):
```

* For sequences, (strings, lists, tuples), use the fact that empty sequences are false:

```python
# Correct:
if not seq:
if seq:
```

* Don’t write string literals that rely on significant trailing whitespace. Such trailing whitespace is visually indistinguishable and some editors (or more recently, reindent.py) will trim them.

  
