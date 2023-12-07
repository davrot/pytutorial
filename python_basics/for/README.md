# Flow Control for-loop
{:.no_toc}

<nav markdown="1" class="toc-class">
* TOC
{:toc}
</nav>

## The goal

For what reason...

Questions to [David Rotermund](mailto:davrot@uni-bremen.de)

**Logic blocks need to be indented.​ Preferable with 4 spaces!**

## [The for statement](https://docs.python.org/3/reference/compound_stmts.html#the-for-statement)

> The for statement is used to iterate over the elements of a sequence (such as a string, tuple or list) or other iterable object

### With range()

```python
for i in range(0, 3):​
    print(i)​
```

Output:

```python
0​
1​
2
```

### [range()](https://docs.python.org/3/library/stdtypes.html#ranges)

```python
class range(stop)
class range(start, stop[, step])
```

### With a list

```python
for i in [0, "A", 7, "nom num"]:​
    print(i)
```

Output:

```python
0​
A​
7​
nom num​
```


## The full statement

```python
for_stmt ::=  "for" target_list "in" starred_list ":" suite
              ["else" ":" suite]
```

## for loop (the truth)​

{: .topic-optional}
This is an optional topic!

The for loop is not counting up itself. It uses the \_\_iter\_\_ & \_\_next\_\_ combo of a instance of a class or a generator via [yield](https://docs.python.org/3/reference/simple_stmts.html#the-yield-statement).

### Class

```python
class ClassIterExample:
    counter: int
    counter_max: int

    def __init__(self):
        self.counter = 8
        self.counter_max = 12

    def __iter__(self):
        return self

    def __next__(self):
        if self.counter < self.counter_max:
            self.counter += 1
        else:
            raise StopIteration

        important_result: int = self.counter**2

        return f"Element: {self.counter}", important_result


test_instance = ClassIterExample()

for i in test_instance:
    print(i)
```

Output:

```python
('Element: 9', 81)
('Element: 10', 100)
('Element: 11', 121)
('Element: 12', 144)
```

### Generator yield

```python
from typing import Generator


def do_more(min_value: int, max_value: int) -> Generator:
    for index in range(min_value, max_value):
        yield index**2


for i in do_more(min_value=3, max_value=8):
    print(i)
```

Output:

```python
9
16
25
36
49
```


## for loop -- [enumerate](https://docs.python.org/3/library/functions.html#enumerate)

```python
enumerate(iterable, start=0)
```

If you need the index of the element then you can use enumerate:

```python
for i in enumerate(range(10, 13)):
    print(i)
```

Output:
 
```python
(0, 10)
(1, 11)
(2, 12)
```

{: .topic-optional}
This is an optional topic!

```python
for i in enumerate(range(10, 13)):
    print(i)
else:
    print("*")
    print(i)
```

Output:
 
```python
(0, 10)
(1, 11)
(2, 12)
*
(2, 12)
```

{: .topic-optional}
This is an optional topic!

```python
class ClassIterExample:
    counter: int
    counter_max: int

    def __init__(self):
        self.counter = 8
        self.counter_max = 12

    def __iter__(self):
        return self

    def __next__(self):
        if self.counter < self.counter_max:
            self.counter += 1
        else:
            raise StopIteration

        important_result: int = self.counter**2

        return f"Element: {self.counter}", important_result


test_instance = ClassIterExample()

for i in enumerate(test_instance):
    print(i)
```

Output:

```python
(0, ('Element: 9', 81))
(1, ('Element: 10', 100))
(2, ('Element: 11', 121))
(3, ('Element: 12', 144))
```

You see a tuple with the enumerate id as a first component and a second tuple as result from the iterator. 


## [break](https://docs.python.org/3/reference/simple_stmts.html#the-break-statement)

> break may only occur syntactically nested in a for or while loop, but not nested in a function or class definition within that loop.

> It terminates the nearest enclosing loop, skipping the optional else clause if the loop has one.

> If a for loop is terminated by break, the loop control target keeps its current value.

```python
break_stmt ::=  "break"
```

```python
for i in range(0, 5):​
    if i == 2:​
        break​
    print(i)
```

Output:

```python
0
1
```


## [continue](https://docs.python.org/3/reference/simple_stmts.html#the-continue-statement)

> continue may only occur syntactically nested in a for or while loop, but not nested in a function or class definition within that loop. It continues with the next cycle of the nearest enclosing loop.

```python
continue_stmt ::=  "continue"
```

```python
for i in range(0, 5):​
    if i == 2:​
        continue​
    print(i)
```

Output:

```python
0
1
3
4
```


