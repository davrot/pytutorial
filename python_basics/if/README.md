# Flow Control if, elif, else
{:.no_toc}

<nav markdown="1" class="toc-class">
* TOC
{:toc}
</nav>

## The goal

If I would have... 

Questions to [David Rotermund](mailto:davrot@uni-bremen.de)

**Logic blocks need to be indented.​ Preferable with 4 spaces!**

## [The if statement](https://docs.python.org/3/reference/compound_stmts.html#the-if-statement)

```python
if i == 1:​
    print("if")​
elif i == 2:​
    print("elif brach A")​
elif i == 3:​
    print("elif brach B")​
else:​
    print("else -- default")​
```

## The full statement

```python
if_stmt ::=  "if" assignment_expression ":" suite
             ("elif" assignment_expression ":" suite)*
             ["else" ":" suite]
```

## if, elif, else with lists

```python
A = 1​
if A in [0, 2, 4, 6, 8]:​
    print("found")​
else:​
    print("NOT found")​
```

Output 

```python
NOT found
```

```python
A = 2
if A in [0, 2, 4, 6, 8]:​
    print("found")​
else:​
    print("NOT found")​
```

Output 

```python
found
```
