# Flow Control while, pass, break, continue
{:.no_toc}

<nav markdown="1" class="toc-class">
* TOC
{:toc}
</nav>

## The goal

While we wait... 

Questions to [David Rotermund](mailto:davrot@uni-bremen.de)

**Logic blocks need to be indented.​ Preferable with 4 spaces!**

## [The while statement](https://docs.python.org/3/reference/compound_stmts.html#the-while-statement)

```python
i = 0​
while i < 3:​
    print(i)​
    i += 1
```

Output

```python
0​
1​
2
```

## The full statement

```python
while_stmt ::=  "while" assignment_expression ":" suite
                ["else" ":" suite]
```

## [pass](https://docs.python.org/3/reference/simple_stmts.html#the-pass-statement)

Since Python uses indents as definition for a functional block it needs pass for signaling an empty functional block. ​

> pass is a null operation — when it is executed, nothing happens. It is useful as a placeholder when a statement is required syntactically, but no code needs to be executed

```python
pass_stmt ::=  "pass"
```

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
