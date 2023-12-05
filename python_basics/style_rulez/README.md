# Python : Style rulez (PEP8, PEP20)
{:.no_toc}

<nav markdown="1" class="toc-class">
* TOC
{:toc}
</nav>

## The goal
Obviously, you can write your code as YOU want.

However, if there is at least a small probability that you will exchange your code with someone (e.g. me!) or the source code is required to accompany a paper then…

**... you should NOT ignore PEP 8.**

A good source code editor (like Visual Studio Code) will try to enforce many of the PEP 8 rules on you automatically. You need to allow it to help you… Don’t work against it! This is one of the main reasons why to use such an complex editor!

**Or in short: You don't need to know these rules (i don't know them too) if your editor does it for you!!!**

Questions to [David Rotermund](mailto:davrot@uni-bremen.de)

Note: [Python Enhancement Proposals](https://peps.python.org/) (PEPs) are the past, present and future of Python. 

Note: If you don’t trust you editor or your editor hasn’t this capability then there are tools for that:

[Flake8](https://flake8.pycqa.org/en/latest/): Your Tool For Style Guide Enforcement
*flake8 is a command-line utility for enforcing style consistency across Python projects. By default it includes lint checks provided by the PyFlakes project, PEP-0008 inspired style checks provided by the PyCodeStyle project, and McCabe complexity checking provided by the McCabe project. It will also run third-party extensions if they are found and installed.*

[Black](https://github.com/psf/black): The Uncompromising Code Formatter

*Black is the uncompromising Python code formatter. By using it, you agree to cede control over minutiae of hand-formatting. In return, Black gives you speed, determinism, and freedom from pycodestyle nagging about formatting. You will save time and mental energy for more important matters.*

*Blackened code looks the same regardless of the project you're reading. Formatting becomes transparent after a while and you can focus on the content instead. Black makes code review faster by producing the smallest diffs possible.*

The main style rulez will be presented very condensed.

I can not stress enough: Use a good editor!!! Then you don't even read this text. Well... except the programming recommendations. 

## [PEP 20 – The Zen of Python](https://peps.python.org/pep-0020/)

The rules behind Python are:
||
|---|
|**Beautiful is better than ugly.**|
|Explicit is better than implicit.|
|Simple is better than complex.|
|Complex is better than complicated.|
|Flat is better than nested.|
|Sparse is better than dense.|
|**Readability counts.**|
|Special cases aren't special enough to break the rules.|
|Although practicality beats purity.|
|Errors should never pass silently.|
|Unless explicitly silenced.|
|In the face of ambiguity, refuse the temptation to guess.|
|There should be one-- and preferably only one --obvious way to do it.|
|Although that way may not be obvious at first unless you're Dutch.|
|Now is better than never.|
|Although never is often better than *right* now.|
|If the implementation is hard to explain, it's a bad idea.|
|If the implementation is easy to explain, it may be a good idea.|
|Namespaces are one honking great idea -- let's do more of those!|


## [Code Lay-out](https://peps.python.org/pep-0008/#code-lay-out)

### [Indentation](https://peps.python.org/pep-0008/#indentation)

Use 4 spaces per indentation level. Spaces are the preferred indentation method.

```python
# Correct:

# Aligned with opening delimiter.
foo = long_function_name(var_one, var_two,
                         var_three, var_four)

# Add 4 spaces (an extra level of indentation) to distinguish arguments from the rest.
def long_function_name(
        var_one, var_two, var_three,
        var_four):
    print(var_one)

# Hanging indents should add a level.
foo = long_function_name(
    var_one, var_two,
    var_three, var_four)
```

### [Tabs or Spaces?](https://peps.python.org/pep-0008/#tabs-or-spaces)

Spaces are the preferred indentation method.

### [Maximum Line Length](https://peps.python.org/pep-0008/#maximum-line-length)

* **Limit all lines to a maximum of 79 characters.**
* For flowing long blocks of text with fewer structural restrictions **(docstrings or comments), the line length should be limited to 72 characters.**
* The preferred way of wrapping long lines is by using Python’s implied line continuation inside parentheses, brackets and braces. Long lines can be broken over multiple lines by wrapping expressions in parentheses. These should be used in preference to using a backslash for line continuation.
* **Backslashes may still be appropriate at times.** For example, long, multiple with-statements could not use implicit continuation before Python 3.10, so backslashes were acceptable for that case:

```python
with open('/path/to/some/file/you/want/to/read') as file_1, \
     open('/path/to/some/file/being/written', 'w') as file_2:
    file_2.write(file_1.read())
```

### [Should a Line Break Before or After a Binary Operator?](https://peps.python.org/pep-0008/#should-a-line-break-before-or-after-a-binary-operator)

```python
# Correct:
# easy to match operators with operands
income = (gross_wages
          + taxable_interest
          + (dividends - qualified_dividends)
          - ira_deduction
          - student_loan_interest)
```

## [Blank Lines](https://peps.python.org/pep-0008/#blank-lines)

* Surround top-level function and class definitions with two blank lines.
* Method definitions inside a class are surrounded by a single blank line.
* Extra blank lines may be used (sparingly) to separate groups of related functions. Blank lines may be omitted between a bunch of related one-liners (e.g. a set of dummy implementations).
* Use blank lines in functions, sparingly, to indicate logical sections.

## [Source File Encoding](https://peps.python.org/pep-0008/#source-file-encoding)

* Code [...] should always use UTF-8 […]
* […] All identifiers in the Python standard library MUST use ASCII-only identifiers, and SHOULD use English words wherever feasible (in many cases, abbreviations and technical terms are used which aren't English). In addition, string literals and comments must also be in ASCII. […]
* […] Open source projects with a global audience are encouraged to adopt a similar policy.

## [Imports](https://peps.python.org/pep-0008/#imports)

* Imports should usually be on separate lines:
```python
# Correct:
import os
import sys

# Wrong:
import sys, os
It’s okay to say this though:

# Correct:
from subprocess import Popen, PIPE
```

* Imports are always put at the top of the file, just after any module comments and docstrings, and before module globals and constants.

Imports should be grouped in the following order:

1. Standard library imports.
2. Related third party imports.
3. Local application/library specific imports.
You should put a blank line between each group of imports.

* Absolute imports are recommended, as they are usually more readable and tend to be better behaved (or at least give better error messages) if the import system is incorrectly configured [...]:

```python 
import mypkg.sibling
from mypkg import sibling
from mypkg.sibling import example
```

* When importing a class from a class-containing module, it's usually okay to spell this:

```python 
from myclass import MyClass
from foo.bar.yourclass import YourClass
```

* **Wildcard imports** (from <module> import *) **should be avoided** [...]

## [Module Level Dunder Names](https://peps.python.org/pep-0008/#module-level-dunder-names)

Module level “dunders” (i.e. names with two leading and two trailing underscores) such as __all__, __author__, __version__, etc. should be placed after the module docstring but before any import statements except from __future__ imports. Python mandates that future-imports must appear in the module before any other code except docstrings:

```python
"""This is the example module.

This module does stuff.
"""

from __future__ import barry_as_FLUFL

__all__ = ['a', 'b', 'c']
__version__ = '0.1'
__author__ = 'Cardinal Biggles'

import os
import sys
```

## [String Quotes](https://peps.python.org/pep-0008/#string-quotes)

In Python, single-quoted strings and double-quoted strings are the same. This PEP does not make a recommendation for this. Pick a rule and stick to it. When a string contains single or double quote characters, however, use the other one to avoid backslashes in the string. It improves readability.

For triple-quoted strings, always use double quote characters to be consistent with the docstring convention in [PEP 257](https://peps.python.org/pep-0257).

## [Whitespace in Expressions and Statements](https://peps.python.org/pep-0008/#whitespace-in-expressions-and-statements)

* Immediately inside parentheses, brackets or braces:

```python
# Correct:
spam(ham[1], {eggs: 2})
```  

* Between a trailing comma and a following close parenthesis:

```python
# Correct:
foo = (0,)
```  

* Immediately before a comma, semicolon, or colon:

```python
# Correct:
if x == 4: print(x, y); x, y = y, x
``` 
* Immediately before the open parenthesis that starts the argument list of a function call:

```python
# Correct:
spam(1)
```

* Immediately before the open parenthesis that starts an indexing or slicing:

```python
# Correct:
dct['key'] = lst[index]
```  

* However, in a slice the colon acts like a binary operator, and should have equal amounts on either side (treating it as the operator with the lowest priority). In an extended slice, both colons must have the same amount of spacing applied. Exception: when a slice parameter is omitted, the space is omitted:

```python
# Correct:
ham[1:9], ham[1:9:3], ham[:9:3], ham[1::3], ham[1:9:]
ham[lower:upper], ham[lower:upper:], ham[lower::step]
ham[lower+offset : upper+offset]
ham[: upper_fn(x) : step_fn(x)], ham[:: step_fn(x)]
ham[lower + offset : upper + offset]
```  

* More than one space around an assignment (or other) operator to align it with another:

```python
# Correct:
x = 1
y = 2
long_variable = 3
```

## [Other Recommendations](https://peps.python.org/pep-0008/#other-recommendations)

* Avoid trailing whitespace anywhere.
* Always surround these binary operators with a single space on either side: assignment (=), augmented assignment (+=, -= etc.), comparisons (==, <, >, !=, <>, <=, >=, in, not in, is, is not), Booleans (and, or, not).
* If operators with different priorities are used, consider adding whitespace around the operators with the lowest priority(ies). 

```python
# Correct:
i = i + 1
submitted += 1
x = x*2 - 1
hypot2 = x*x + y*y
c = (a+b) * (a-b)
```

* Function annotations should use the normal rules for colons and always have spaces around the -> arrow if present.

```python
# Correct:
def munge(input: AnyStr): ...
def munge() -> PosInt: ...
```

* Don't use spaces around the = sign when used to indicate a keyword argument, or when used to indicate a default value for an unannotated function parameter:

```python
# Correct:
def complex(real, imag=0.0):
    return magic(r=real, i=imag)
```

* When combining an argument annotation with a default value, however, do use spaces around the = sign:

```python
# Correct:
def munge(sep: AnyStr = None): ...
def munge(input: AnyStr, sep: AnyStr = None, limit=1000): ...
```

* Compound statements (multiple statements on the same line) are generally discouraged:

```python
# Correct:
if foo == 'blah':
    do_blah_thing()
do_one()
do_two()
do_three()
```

## When to Use Trailing Commas

Trailing commas are usually optional, except they are mandatory when making a tuple of one element [...] For clarity, it is recommended to surround the latter in (technically redundant) parentheses:

```python
# Correct:
FILES = ('setup.cfg',)
```

When trailing commas are redundant, they are often helpful when a version control system is used, [...] However it does not make sense to have a trailing comma on the same line as the closing delimiter (except in the above case of singleton tuples):

```python
# Correct:
FILES = [
    'setup.cfg',
    'tox.ini',
    ]
initialize(FILES,
           error=True,
           )
```

## [Comments](https://peps.python.org/pep-0008/#comments)

Comments that contradict the code are worse than no comments. Always make a priority of keeping the comments up-to-date when the code changes!
Comments should be complete sentences. The first word should be capitalized, unless it is an identifier that begins with a lower case letter (never alter the case of identifiers!).
[...]
Ensure that your comments are clear and easily understandable to other speakers of the language you are writing in.
Python coders from non-English speaking countries: please write your comments in English, unless you are 120% sure that the code will never be read by people who don't speak your language.

### [Block Comments](https://peps.python.org/pep-0008/#block-comments)

Block comments generally apply to some (or all) code that follows them, and are indented to the same level as that code. Each line of a block comment starts with a # and a single space (unless it is indented text inside the comment).

Paragraphs inside a block comment are separated by a line containing a single #

### [Inline Comments](https://peps.python.org/pep-0008/#inline-comments)

Use inline comments sparingly.
An inline comment is a comment on the same line as a statement. Inline comments should be separated by at least two spaces from the statement. They should start with a # and a single space.

Inline comments are unnecessary and in fact distracting if they state the obvious. Don't do this:

```python
x = x + 1                 # Increment x
```

But sometimes, this is useful:
```python
x = x + 1                 # Compensate for border
```

## [Documentation Strings](https://peps.python.org/pep-0008/#documentation-strings)

Conventions for writing good documentation strings (a.k.a. "docstrings") are immortalized in PEP 257.

* Write docstrings for all public modules, functions, classes, and methods. Docstrings are not necessary for non-public methods, but you should have a comment that describes what the method does. This comment should appear after the def line.
* […] Note that most importantly, the """ that ends a multiline docstring should be on a line by itself:

```python
"""Return a foobang

Optional plotz says to frobnicate the bizbaz first.
"""
```

* For one liner docstrings, please keep the closing """ on the same line:

```python
"""Return an ex-parrot."""
```

## [Naming Conventions](https://peps.python.org/pep-0008/#naming-conventions)

The naming conventions of Python’s library are a bit of a mess, so we’ll never get this completely consistent – nevertheless, here are the currently recommended naming standards. New modules and packages (including third party frameworks) should be written to these standards, but where an existing library has a different style, internal consistency is preferred.

### [Overriding Principle](https://peps.python.org/pep-0008/#overriding-principle)

Names that are visible to the user as public parts of the API should follow conventions that reflect usage rather than implementation.

### [Descriptive: Naming Styles](https://peps.python.org/pep-0008/#descriptive-naming-styles)

Note: I switched to lower_case_with_underscores for everything except the name of a class definition (and its filename). There I use CapitalizedWords.

### [Prescriptive: Naming Conventions](https://peps.python.org/pep-0008/#prescriptive-naming-conventions)

#### [Names to Avoid](https://peps.python.org/pep-0008/#names-to-avoid)

Never use the characters ‘l’ (lowercase letter el), ‘O’ (uppercase letter oh), or ‘I’ (uppercase letter eye) as single character variable names.

In some fonts, these characters are indistinguishable from the numerals one and zero. When tempted to use ‘l’, use ‘L’ instead.

#### [ASCII Compatibility](https://peps.python.org/pep-0008/#ascii-compatibility)

Identifiers used in the standard library must be ASCII compatible as described in the [policy section](https://peps.python.org/pep-3131#policy-specification) of [PEP 3131](https://peps.python.org/pep-3131).

#### [Package and Module Names](https://peps.python.org/pep-0008/#package-and-module-names)

Modules should have short, all-lowercase names. Underscores can be used in the module name if it improves readability. Python packages should also have short, all-lowercase names, although the use of underscores is discouraged.

#### [Class Names](https://peps.python.org/pep-0008/#class-names)

Class names should normally use the CapWords convention.

#### [Type Variable Names](https://peps.python.org/pep-0008/#type-variable-names)

Names of type variables introduced in [PEP 484](https://peps.python.org/pep-0484) should normally use CapWords preferring short names: T, AnyStr, Num. It is recommended to add suffixes _co or _contra to the variables used to declare covariant or contravariant behavior correspondingly

#### [Exception Names](https://peps.python.org/pep-0008/#exception-names)

Because exceptions should be classes, the class naming convention applies here. However, you should use the suffix “Error” on your exception names (if the exception actually is an error).

#### [Global Variable Names](https://peps.python.org/pep-0008/#global-variable-names)

(Let’s hope that these variables are meant for use inside one module only.) The conventions are about the same as those for functions.

#### [Function and Variable Names](https://peps.python.org/pep-0008/#function-and-variable-names)

Function names should be lowercase, with words separated by underscores as necessary to improve readability.

Variable names follow the same convention as function names.

#### [Function and Method Arguments](https://peps.python.org/pep-0008/#function-and-method-arguments)

* Always use self for the first argument to instance methods.
* Always use cls for the first argument to class methods.

If a function argument’s name clashes with a reserved keyword, it is generally better to append a single trailing underscore rather than use an abbreviation or spelling corruption. Thus class_ is better than clss. (Perhaps better is to avoid such clashes by using a synonym.)

#### [Method Names and Instance Variables](https://peps.python.org/pep-0008/#method-names-and-instance-variables)

Use the function naming rules: lowercase with words separated by underscores as necessary to improve readability.

Use one leading underscore only for non-public methods and instance variables.

To avoid name clashes with subclasses, use two leading underscores to invoke Python’s name mangling rules.

#### [Constants](https://peps.python.org/pep-0008/#constants)

Constants are usually defined on a module level and written in all capital letters with underscores separating words. Examples include MAX_OVERFLOW and TOTAL.

#### [Designing for Inheritance](https://peps.python.org/pep-0008/#designing-for-inheritance)

Always decide whether a class's methods and instance variables (collectively: "attributes") should be public or non-public. If in doubt, choose non-public; it's easier to make it public later than to make a public attribute non-public. […] Public attributes should have no leading underscores.
[+ many rules we --- hopefully -- might not need in our daily use… I will spare you those.]







