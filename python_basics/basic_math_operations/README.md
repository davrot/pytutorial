# Basic math operations​
{:.no_toc}

<nav markdown="1" class="toc-class">
* TOC
{:toc}
</nav>

Questions to [David Rotermund](mailto:davrot@uni-bremen.de)

## [Basic math operations​](https://docs.python.org/3/library/stdtypes.html#numeric-types-int-float-complex​)

Order of operations​:
1. Parentheses
2. Exponents
3. Multiplication/Division
4. Addition/Subtraction

|Operator​|Description​|
|---|---|
|x + y​|sum of x and y​|
|x - y​|difference of x and y​|
|x * y​|product of x and y​|
|x / y​|quotient of x and y​|
|x // y​|floored quotient of x and y​|
|x % y​|remainder of x / y​|
|-x​|x negated​|
|+x​|x unchanged​|

|Operator|Description​|
|---|---|
|abs(x)​|absolute value or magnitude of x​|
|int(x)​|x converted to integer​|
|float(x)​|x converted to floating point​|
|complex(re, im)​|a complex number with real part re, imaginary part im. im defaults to zero.​|
|c.conjugate()​|conjugate of the complex number c​|
|divmod(x, y)​|the pair (x // y, x % y)​|
|pow(x, y)​|x to the power y​|
|x ** y​|x to the power y​|

## "True division"

```python
print(5 / 2)​ # -> 2.5
print(6 / 2)​ # -> 3.0
```

## “Floor division”

```python
print(5 // 2)​ # -> 2
print(6 // 2)​ # -> 3
```

## [Bitwise Operations on Integer Types​](https://docs.python.org/3/library/stdtypes.html?highlight=elif#bitwise-operations-on-integer-types​)


|Operation​|Result​|
|---|---|
|x \| y​| bitwise or of x and y​|
|x ^ y​|bitwise exclusive or of x and y​|
|x & y​|bitwise and of x and y​|
|x << n​|x shifted left by n bits​|
|x >> n​|x shifted right by n bits​|
|~x​|the bits of x inverted​|

## [More math operations​ (math lib)](https://docs.python.org/3/library/math.html​)

You need to include the math lib for that! (Only once per .py file and in the beginning of the file)

However, don't get used to it. As a data scientist you will not use it. You will use Numpy. 

```python
import math
print(math.cos(math.pi))​
```

### Examples

|[Number-theoretic and representation functions](https://docs.python.org/3/library/math.html#number-theoretic-and-representation-functions)|
|---|
|math.ceil(x)​|
|math.comb(n, k)|
|math.fabs(x)​|
|math.factorial(n)|
|math.floor(x)​|
|math.fmod(x, y)​|
|math.fsum(iterable)​|
|math.isclose(a, b, *, rel_tol=1e-09, abs_tol=0.0)|
|math.isfinite(x)​|
|math.isinf(x)​|
|math.isnan(x)|
|math.perm(n, k=None)|
|math.prod(iterable, *, start=1)​|
|math.trunc(x)​|

|[Constants](https://docs.python.org/3/library/math.html#constants)|
|---|
|math.pi​|
|math.e​|
|math.inf​|
|math.nan​|

|[Power and logarithmic functions](https://docs.python.org/3/library/math.html#power-and-logarithmic-functions)|
|---|
|math.cbrt(x)​|
|math.exp(x)​|
|math.exp2(x)​|
|math.expm1(x)|
|math.log(x[,base])​|
|math.log1p(x)|
|math.log2(x)​|
|math.log10(x)​|
|math.pow(x, y)​|
|math.sqrt(x)​|


|[Trigonometric functions](https://docs.python.org/3/library/math.html#trigonometric-functions)|
|---|
|math.acos(x)​|
|math.asin(x)​|
|math.atan(x)​|
|math.atan2(y, x)​|
|math.cos(x)​|
|math.sin(x)​|
|math.tan(x)​|
|math.dist(p, q)​|

|[Angular conversion](https://docs.python.org/3/library/math.html#angular-conversion)|
|---|
|math.degrees(x)​|
|math.radians(x)​|

|[Hyperbolic functions](https://docs.python.org/3/library/math.html#hyperbolic-functions)|
|---|
|math.acosh(x)​|
|math.asinh(x)​|
|math.atanh(x)​|
|math.cosh(x)​|
|math.sinh(x)​|
|math.tanh(x)​|











