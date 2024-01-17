# Representation of Numbers in the Computer
{:.no_toc}

<nav markdown="1" class="toc-class">
* TOC
{:toc}
</nav>

Questions to [David Rotermund](mailto:davrot@uni-bremen.de)

*By Jan Wiersig, modified by Udo Ernst and translated into English by Daniel Harnack.*

## Bits and Bytes

In digital computers, information is represented by discrete states of circuit elements. The smallest possible unit of information is one bit (binary digit). It can be in two different states, that may be described differently:

| | | |
| ------------- |:-------------:|:-------------:|
|true|	$\longleftrightarrow$|	false|
|yes|	$\longleftrightarrow$|	no|
|1|	$\longleftrightarrow$|	0|
||$\vdots$	||

A bit is easily realized physically:

| | | |
| ------------- |:-------------:|:-------------:|
|current flowing|	$\longleftrightarrow$|	current not flowing |
|voltage there|	$\longleftrightarrow$|	voltage gone |
|magnetized|	$\longleftrightarrow$|	not magnetized |
||$\vdots$ | |

For example, in the communication between integrated circuits, information is traded via changes in voltage, while the bits on the hard disk are written by magnetization of ferromagnetic materials. Between electronic musical instruments, bits are exchanged through current loops (MIDI-Standard). In the stone age of computers, the fifties, bits were even once realized as air bubbles in a liquid medium.

By combining several bits, complex information like numbers, letters (e.g. 8 bit-ASCII-code), images, color, music, etc, can be represented. Much like in the decimal system, where whole numbers are made up of the digits 0-9, the same numbers can be written in the so called dual system by sequences of 0 and 1:

| dual system |	decimal system |
| ------------- |:-------------:|
|000|	0|
|001|	1|
|010|	2|
|011|	3|
|100|	4|
|101|	5|
|110|	6|
|111|	7|
|$\vdots$|	$\vdots$|

Two further examples for 8-bit numbers:

01010101 $=1 \star 2^0+0 \star 2^1+1 \star 2^2+0 \star 2^3 +1 \star 2^4+0 \star 2^5+1 \star 2^6+0 \star 2^7 = 85$

10101010 $=0 \star 2^0+1 \star 2^1+0 \star 2^2+1 \star 2^3 +0 \star 2^4+1 \star 2^5+0 \star 2^6+1 \star 2^7 = 170$

To represent negative numbers, a small trick is necessary: one specific bit codes for the sign of the number. In an $n$-bit number, one would for example reserve the $n$-th it for the sign, and the remaining $n-1$ bits code, as usual, a binary number $z$: If the $n$-th bit is not set, then the result is by default $+z$. If the $n$-th bit is set, the result is $-(2^{n-1})+z$. For illustration, again a small table:

|dual system|	decimal system|
| ------------- |:-------------:|
|01111111|	+127|
|01111110|	+126|
|$\vdots$|	$\vdots$|
|00000010|	+2|
|00000001|	+1|
|00000000|	+0|
|11111111|	-1|
|11111110|	-2|
|$\vdots$|	$\vdots$|
|10000010|	-126|
|10000001|	-127|
|10000000|	-128|

Certain bit lengths have names:

| | |
| ------------- |:-------------:|
| 1 Byte|	8 Bit|
|1 Word|	16 Bit|
|1 Kilobyte|	1024 Byte|
|1 Megabyte|	1024 Kilobyte|
|1 Gigabyte|	1024 Megabyte|
|1 Terabyte|	1024 Gigabyte|

## Representation of Real Numbers and Numerical Errors
Real numbers are, by their nature, analogue quantities. Hence we would expect the handling of these numbers on digital computers not to be completely problem-free. Present digital computers usually represent real numbers as floating-point numbers.

$\mbox{floating-point number} = \mbox{mantissa} \cdot \mbox{basis}^{\mbox{exponent}} $

Thereby, the precision, with which the real number can be represented, is determined by the number of available bits."Simple precision" (i.e. float32) requires 4 Bytes, for *double precision* (i.e. float64) 8~Bytes are needed. The latter is the default configuration in Python and Matlab. The IEEE format of double precision uses 53-Bits for the mantissa, 11-Bits for the exponent and for the basis the remaining 2. One Bit of the mantissa respectively the exponent are used for the sign of the quantity. Thus, the exponent can vary between$-1024$ and $+1023$. The mantissa always represents a value in the interval $[1, 2[$ in the IEEE notation. Here, the $52$ Bits are utilized to add up fractions of exponents of 2. The value of the mantissa yields 
$$mantissa = 1 + \sum_{i=1}^{52} b_i 2^{-i}$$ 
, with $b_i=1$ , if the $i$-th bit in the mantissa is set.

## Range Error
The maximal range of the floating-point numbers is determined by the number of bits used to code for the exponent. A typical number for single precision is

$2^{\pm 127} \approx 10^{\pm 38}$

and for double precision

$2^{\pm 1023} \approx 10^{\pm 308} $

Via application of arithmetic operations on these numbers, the range can be exceeded. The error occurring in that case is named a range error. As an example we consider the Bohr radius in SI units

$a_0 = \frac{4\pi\varepsilon_0\hbar^2}{m_ee^2}\approx 5.3\times 10^{-11} \mbox{m} $

The quantity $\hbar$ is Planck's quantum of action divided by $2\pi$. Bohr's radius is in the range of single precision floating-point numbers. However, the same does not hold for the numerator $4\pi\varepsilon_0\hbar^2 \approx 1.24\cdot 10^{-78}\mbox{KgC}^2\mbox{m}$ and the denominator $m_ee^2 \approx 2.34\times 10^{-68}\mbox{KgC}^2$. I.e. neither the numerator nor the denominator can be represented as a single precision floating-point number. Hence, the calculation of Bohr's radius by the given formula can be problematic. A simple solution of this problem lies in the use of natural units, such as Bohr's radius, for distances, etc.

An even bigger problem can be illustrated by the calculation of the factorial. The factorial is defined as

$n! = n\cdot(n-1)\cdot(n-2)\cdot\ldots3\cdot 2\cdot 1 $

In Python or Matlab, it can be easily verified by using the function factorial(n), that the factorial for $n>170$ can not be represented, even with double precision numbers. A way out is provided by the use of logarithms, since the logarithm of a bigger number still gives moderately small values, e.g. $\log_{10}(10^{100}) = 100$. It ensues that

$\ln(n!) = \ln(n) + \ln(n-1) + \ldots + \ln(3) + \ln(2) + \ln(1) $

For bigger $n$, the evaluation of this expression is, however, to laborious. If $n>30$, one is advised to use Stirling's formula

$\ln(n!) = n\ln(n)-n+\frac{1}{2}\ln(2\pi n)+\ln\left(1+\frac{1}{12n}+\frac{1}{288n^2}+\ldots\right) $

The factorial $n!$ can than be written as the following

$n! = \mbox{mantissa}\times 10^{\mbox{exponent}} $

To get the mantissa and the exponent, we form the logarithm to the basis 10 (reminder: $\log_{10}(x) = \ln(x)/\ln(10)$)

$\log_{10}(n!) = \log_{10}(\mbox{mantissa})+{\mbox{exponent}} $

We now associate the integer part of $\log_{10}(n!)$ with the exponent. The post-decimal places are associated with the mantissa, i.e. mantissa = $10^a$ with $a = \log_{10}(n!)-\mbox{exponent}$. 

From these examples we learn that range errors can usually be circumvented with a little creativity.

## Rounding Error

Rounding errors stem from the finite precision of the mantissa. The following program illustrates this fact:

```python
x: float = 1.0

while 1 + x != 1:
    x = x / 2

x = x * 2
print(x) # -> 2.220446049250313e-16
```


One might think that this constitutes an infinite loop. To the contrary, the loop will be left in finite time. The result for double precision is $x \approx 2\times 10^{-16}$ (import sys ; print(sys.float_info.epsilon)). eps is the smallest number with $1+$eps$>1$, and is the \quoting{machine accuracy}. Rounding errors of this order of magnitude occur on a regular basis. For example, Python calculates $\sin{\pi} \approx 1.2246\times 10^{-16}$ (import math ; print(math.sin(math.pi)) # -> 1.2246467991473532e-16). It shall be mentioned hat the machine accuracy for double precision is exactly eps $= 2^{-52}$, since 52 bits (plus one bit for the sign) are used for the mantissa. This rounding error might appear to be small and negligible. However, if further calculations are performed with rounded numbers, the rounding errors can accumulate with each calculation and grow to a significant value.

