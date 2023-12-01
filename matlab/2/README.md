# Representation of Numbers in the Computer

By Jan Wiersig, modified by Udo Ernst and translated into English by Daniel Harnack.

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
