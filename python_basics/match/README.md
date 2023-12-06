# Flow control: match case
{:.no_toc}

<nav markdown="1" class="toc-class">
* TOC
{:toc}
</nav>

## The goal
There is a new flow control in town. A switch case replacement, called match case.

Questions to [David Rotermund](mailto:davrot@uni-bremen.de)

## The [match](https://docs.python.org/3/reference/compound_stmts.html#the-match-statement) statement

The match statement is used for pattern matching. Syntax:

```python
match_stmt   ::=  'match' subject_expr ":" NEWLINE INDENT case_block+ DEDENT
subject_expr ::=  star_named_expression "," star_named_expressions?
                  | named_expression
case_block   ::=  'case' patterns [guard] ":" block
```

## Normal "switch" case

```python
for i in range(0, 4):

    match (i):
        case 0:
            print("This is a 0")

        case 0:
            print("This is a 0 too.")

        case 1:
            print("This is a 1.")

        case 2:
            print("This is a 2.")

        case _:
            print(f"I don't know what to do with a {i}!")
```

Output:

```python
This is a 0
This is a 1.
This is a 2.
I don't know what to do with a 3!
```

\_ is the default. And after every case state has an in-build **break;** (If you don't know what this means: A. You are not a C/C++ programmer. B. You can ignore this information. :-) ).

## Unpacking parameters 

{: .topic-optional}
This is an optional topic!


Different from a normal switch we can deal with several input parameters at the same time and even use wildcards:

```python
def what_to_do(input):
    match (input):
        case (0, 0):
            print("This is (0,0) - A")

        case (0, 1):
            print("This is (0,1) - B")

        case (x, 0):
            print(f"This is a {x} - C")

        case (x, y):
            print(f"This is a {x} and {y} - D")

        case _:
            print(f"I don't know what to do with {input}- E!")
    print("")


second_parameter: int = 0
for i in range(0, 2):
    input = (i, second_parameter)
    print(f"Input: {input}")
    what_to_do(input)

second_parameter = 1
for i in range(0, 2):
    input = (i, second_parameter)
    print(f"Input: {input}")
    what_to_do(input)

input = "Hello!"
print(f"Input: {input}")
what_to_do(input)
```

Output:

```python
Input: (0, 0)
This is (0,0) - A

Input: (1, 0)
This is a 1 - C

Input: (0, 1)
This is (0,1) - B

Input: (1, 1)
This is a 1 and 1 - D

Input: Hello!
I don't know what to do with Hello!- E!
```

### OR

{: .topic-optional}
This is an optional topic!


We can combine patter by | (or):

```python
def what_to_do(input):
    match (input):
        case (0, 0) | (0, 1):
            print("This is (0,0) or (0,1) - A")

        case (x, 0):
            print(f"This is a {x} - C")

        case (x, y):
            print(f"This is a {x} and {y} - D")

        case _:
            print(f"I don't know what to do with {input}- E!")
    print("")


second_parameter: int = 0
for i in range(0, 2):
    input = (i, second_parameter)
    print(f"Input: {input}")
    what_to_do(input)

second_parameter = 1
for i in range(0, 2):
    input = (i, second_parameter)
    print(f"Input: {input}")
    what_to_do(input)
```

Output:

```python
Input: (0, 0)
This is (0,0) or (0,1) - A

Input: (1, 0)
This is a 1 - C

Input: (0, 1)
This is (0,0) or (0,1) - A

Input: (1, 1)
This is a 1 and 1 - D
```

You can also use the **or** on parts of the pattern (output is the same as before):

```python
def what_to_do(input):
    match (input):
        case (0, (0 | 1)):
            print("This is (0,0) or (0,1) - A")

        case (x, 0):
            print(f"This is a {x} - C")

        case (x, y):
            print(f"This is a {x} and {y} - D")

        case _:
            print(f"I don't know what to do with {input}- E!")
    print("")


second_parameter: int = 0
for i in range(0, 2):
    input = (i, second_parameter)
    print(f"Input: {input}")
    what_to_do(input)

second_parameter = 1
for i in range(0, 2):
    input = (i, second_parameter)
    print(f"Input: {input}")
    what_to_do(input)
```

### If guards

{: .topic-optional}
This is an optional topic!


We can distinguish between cases by using **if guard**:

```python
def what_to_do(input):
    match (input):
        case (x, y) if x == y:
            print(f"Both are {x} - A ")
        case (x, y):
            print(f"This is a {x} and {y} - B ")

    print("")


second_parameter: int = 0
for i in range(0, 2):
    input = (i, second_parameter)
    print(f"Input: {input}")
    what_to_do(input)

second_parameter = 1
for i in range(0, 2):
    input = (i, second_parameter)
    print(f"Input: {input}")
    what_to_do(input)
```

Output:

```python
Input: (0, 0)
Both are 0 - A 

Input: (1, 0)
This is a 1 and 0 - B 

Input: (0, 1)
This is a 0 and 1 - B 

Input: (1, 1)
Both are 1 - A 
```

### Data classes

{: .topic-optional}
This is an optional topic!

We can combine it nicely with data classes:

```python
from dataclasses import dataclass


@dataclass
class SomeDataStructure:
    x: int
    y: int


def what_to_do(input):
    print(input)
    match (input):
        case SomeDataStructure(x=0, y=0):
            print("case A")
        case SomeDataStructure(x=1, y=0):
            print("case B")
        case SomeDataStructure():
            print("case C")
        case _:
            print("What?")

    print("")


data_0_0 = SomeDataStructure(0, 0)
what_to_do(data_0_0)
data_0_1 = SomeDataStructure(0, 1)
what_to_do(data_0_1)
data_1_0 = SomeDataStructure(1, 0)
what_to_do(data_1_0)
data_1_1 = SomeDataStructure(1, 1)
what_to_do(data_1_1)
data_broken = "I am broken!"
what_to_do(data_broken)
```

Output:

```python
SomeDataStructure(x=0, y=0)
case A

SomeDataStructure(x=0, y=1)
case C

SomeDataStructure(x=1, y=0)
case B

SomeDataStructure(x=1, y=1)
case C

I am broken!
What?
```

### As

{: .topic-optional}
This is an optional topic!


We can use **as** to name a variable in a case clause (if you have a sequence i.e. tuple or list of elements then you can use **as** on the individual elements): 

```python
from dataclasses import dataclass


@dataclass
class SomeDataStructure:
    x: int
    y: int


def what_to_do(input):
    print(input)
    match (input):
        case SomeDataStructure(x=0, y=0):
            print("case A")
        case SomeDataStructure(x=1, y=0):
            print("case B")
        case SomeDataStructure() as someinput:
            print(f"case C : {someinput.x} {someinput.y}")
        case _:
            print("What?")

    print("")


data_0_0 = SomeDataStructure(0, 0)
what_to_do(data_0_0)
data_0_1 = SomeDataStructure(0, 1)
what_to_do(data_0_1)
data_1_0 = SomeDataStructure(1, 0)
what_to_do(data_1_0)
data_1_1 = SomeDataStructure(1, 1)
what_to_do(data_1_1)
data_broken = "I am broken!"
what_to_do(data_broken)
```

Output:

```python
SomeDataStructure(x=0, y=0)
case A

SomeDataStructure(x=0, y=1)
case C : 0 1

SomeDataStructure(x=1, y=0)
case B

SomeDataStructure(x=1, y=1)
case C : 1 1

I am broken!
What?
```

### List

{: .topic-optional}
This is an optional topic!


This is how we can deal with lists that have different length:

```python
def what_to_do(input):
    print(input)
    match (input):
        case []:
            print("case A")
        case [0]:
            print("case B")
        case [x]:
            print(f"case C {x}")
        case [0, 0]:
            print("case D")
        case _:
            print("What?")

    print("")


what_to_do([])
what_to_do([0])
what_to_do([1])
what_to_do([0, 0])
what_to_do([0, 1])
what_to_do("Hello")
```

Output:

```python
[]
case A

[0]
case B

[1]
case C 1

[0, 0]
case D

[0, 1]
What?

Hello
What?
```

### Dictionaries

{: .topic-optional}
This is an optional topic!


The whole match apparatus works also with dictionaries. You can even distinguish between what kind of variable is stored behind a key (e.g. int vs str): 

```python
def what_to_do(input):
    print(input)
    match (input):
        case {"x": str() as x}:
            print(f"{x} - str")
        case {"x": int() as x}:
            print(f"{x} - int")
        case {"y": value}:
            print(f"{value} - A")
        case {"a": value_a, "b": value_b}:
            print(f"a={value_a} b={value_b} - B")
    print("")


dictionary_a = {"x": str(1)}
what_to_do(dictionary_a)
dictionary_b = {"x": int(1)}
what_to_do(dictionary_b)
dictionary_c = {"x": int(1), "y": 5}
what_to_do(dictionary_c)
dictionary_d = {"y": 5}
what_to_do(dictionary_d)
dictionary_e = {"a": 6, "b": 7}
what_to_do(dictionary_e)
dictionary_f = {"b": 8, "a": 10}
what_to_do(dictionary_f)
```

Output:

```python
{'x': '1'}
1 - str

{'x': 1}
1 - int

{'x': 1, 'y': 5}
1 - int

{'y': 5}
5 - A

{'a': 6, 'b': 7}
a=6 b=7 - B

{'b': 8, 'a': 10}
a=10 b=8 - B
```

## Reference
* [PEP 636 – Structural Pattern Matching: Tutorial](https://peps.python.org/pep-0636/)
  
