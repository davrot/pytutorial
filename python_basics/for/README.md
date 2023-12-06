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

## for loop (enumerate)​

XXXXXXXXX

## for loop (the truth)​

{: .topic-optional}
This is an optional topic!

The for loop is not counting up itself. It uses the \_\_iter\_\_ & \_\_next\_\_ combo of a instance of a class or a generator via [yield](https://docs.python.org/3/reference/simple_stmts.html#the-yield-statement).

XXXXXXXXX


