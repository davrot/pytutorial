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

## The main style rulez... (condensed)

I can not stress enough: Use a good editor!!! Then you don't even read this text. Well... except the programming recommendations. 

### [Code Lay-out](https://peps.python.org/pep-0008/#code-lay-out)

#### [Indentation](https://peps.python.org/pep-0008/#indentation)

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

#### [Tabs or Spaces?](https://peps.python.org/pep-0008/#tabs-or-spaces)

Spaces are the preferred indentation method.

#### [Maximum Line Length](https://peps.python.org/pep-0008/#maximum-line-length)

* **Limit all lines to a maximum of 79 characters.**
* For flowing long blocks of text with fewer structural restrictions **(docstrings or comments), the line length should be limited to 72 characters.**
* The preferred way of wrapping long lines is by using Python’s implied line continuation inside parentheses, brackets and braces. Long lines can be broken over multiple lines by wrapping expressions in parentheses. These should be used in preference to using a backslash for line continuation.
* **Backslashes may still be appropriate at times.** For example, long, multiple with-statements could not use implicit continuation before Python 3.10, so backslashes were acceptable for that case:

```python
with open('/path/to/some/file/you/want/to/read') as file_1, \
     open('/path/to/some/file/being/written', 'w') as file_2:
    file_2.write(file_1.read())
```

#### [Should a Line Break Before or After a Binary Operator?](https://peps.python.org/pep-0008/#should-a-line-break-before-or-after-a-binary-operator)

```python
# Correct:
# easy to match operators with operands
income = (gross_wages
          + taxable_interest
          + (dividends - qualified_dividends)
          - ira_deduction
          - student_loan_interest)
```

#### [Blank Lines](https://peps.python.org/pep-0008/#blank-lines)

* Surround top-level function and class definitions with two blank lines.
* Method definitions inside a class are surrounded by a single blank line.
* Extra blank lines may be used (sparingly) to separate groups of related functions. Blank lines may be omitted between a bunch of related one-liners (e.g. a set of dummy implementations).
* Use blank lines in functions, sparingly, to indicate logical sections.

#### [Source File Encoding](https://peps.python.org/pep-0008/#source-file-encoding)

* Code [...] should always use UTF-8 […]
* […] All identifiers in the Python standard library MUST use ASCII-only identifiers, and SHOULD use English words wherever feasible (in many cases, abbreviations and technical terms are used which aren't English). In addition, string literals and comments must also be in ASCII. […]
* […] Open source projects with a global audience are encouraged to adopt a similar policy.

#### [Imports](https://peps.python.org/pep-0008/#imports)

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

* **Wildcard imports (from <module> import *) should be avoided** [...]
