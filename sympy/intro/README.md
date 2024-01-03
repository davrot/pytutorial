# Symbolic Computation
{:.no_toc}

<nav markdown="1" class="toc-class">
* TOC
{:toc}
</nav>

## Top

Questions to [David Rotermund](mailto:davrot@uni-bremen.de)

```shell
pip install sympy
```

||
|---|
|[Basic Operations](https://docs.sympy.org/latest/tutorials/intro-tutorial/basic_operations.html)|
|[Printing](https://docs.sympy.org/latest/tutorials/intro-tutorial/printing.html)|
|[Simplification](https://docs.sympy.org/latest/tutorials/intro-tutorial/simplification.html)|
|[Calculus](https://docs.sympy.org/latest/tutorials/intro-tutorial/calculus.html) |
|[Solvers](https://docs.sympy.org/latest/tutorials/intro-tutorial/solvers.html)|


## [Some examples](https://docs.sympy.org/latest/tutorials/intro-tutorial/intro.html#a-more-interesting-example)

## [Substitution](https://docs.sympy.org/latest/tutorials/intro-tutorial/basic_operations.html#substitution)
```python
import sympy

x, y = sympy.symbols("x y")

expr = sympy.cos(x) + 1
z = expr.subs(x, y**2)
print(z) # -> cos(y**2) + 1
```

### [Derivatives](https://docs.sympy.org/latest/tutorials/intro-tutorial/calculus.html#derivatives)

```python
import sympy

x, y = sympy.symbols("x y")

y = sympy.diff(sympy.sin(x) * sympy.exp(x), x)
print(y) # -> exp(x)*sin(x) + exp(x)*cos(x)
```

### [Integrals](https://docs.sympy.org/latest/tutorials/intro-tutorial/calculus.html#integrals)

```python
import sympy

x, y = sympy.symbols("x y")

y = sympy.integrate(sympy.cos(x), x)
print(y)  # -> sin(x)
```


### [(Taylor) Series Expansion](https://docs.sympy.org/latest/tutorials/intro-tutorial/calculus.html#series-expansion)

```python
import sympy

x, y, z = sympy.symbols("x y z")
y = sympy.cos(x)
z = y.series(x, 0, 8) # around x = 0 , up order 7

print(z)  # -> 1 - x**2/2 + x**4/24 - x**6/720 + O(x**8)
```

### [simplify](https://docs.sympy.org/latest/tutorials/intro-tutorial/simplification.html#simplify)

```python
import sympy

x, y, z = sympy.symbols("x y z")
y = sympy.simplify(sympy.sin(x) ** 2 + sympy.cos(x) ** 2)

print(y)  # -> 1
```

### [Solving Equations Algebraically](https://docs.sympy.org/latest/tutorials/intro-tutorial/solvers.html)

```python
solveset(equation, variable=None, domain=S.Complexes)
```

> Recall from the [gotchas section](https://docs.sympy.org/latest/tutorials/intro-tutorial/gotchas.html#tutorial-gotchas-equals) of this tutorial that symbolic equations in SymPy are not represented by = or ==, but by Eq.

```python
import sympy

x, y, z = sympy.symbols("x y z")

z = sympy.Eq(x, y)
```

Output:

$$x=y$$


```python
import sympy

x, y, z = sympy.symbols("x y z")

y = sympy.Eq(x**2 - x, 0)
z = sympy.solveset(y, x)
print(z) # -> {0, 1}
```

### [Solving Differential Equations](https://docs.sympy.org/latest/tutorials/intro-tutorial/solvers.html#solving-differential-equations)

```python
import sympy

# Undefined functions
f = sympy.symbols("f", cls=sympy.Function)

x = sympy.symbols("x")


diffeq = sympy.Eq(f(x).diff(x, x) - 2 * f(x).diff(x) + f(x), sympy.sin(x))

print(diffeq)  # -> Eq(f(x) - 2*Derivative(f(x), x) + Derivative(f(x), (x, 2)), sin(x))

result = sympy.dsolve(diffeq, f(x))
print(result)  # -> Eq(f(x), (C1 + C2*x)*exp(x) + cos(x)/2)
```

