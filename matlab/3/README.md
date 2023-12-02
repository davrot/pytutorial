# Basic Commands and Variables

By Jan Wiersig, modified by Udo Ernst and translated into English by Daniel Harnack.

Matlab is an interactive system used for numerical calculations and visualization in almost every field of technical and scientific research. Matlab excels in its ease of use, good graphics and high efficiency.

This introduction explains the basics mandatory to perform simple numerical calculations. First, we use Matlab as a command line interpreter. Entering of single commands will follow a prompt, here `>>`. An important command is `help`. This command returns descriptions and syntax for functions and commands. For example


`help sin`

shows information regarding the sine function. Also a link to the detailed documentations can be found, that can directly be called alternatively with the command `doc`. Short descriptions of commands, that match certain search pattern, can be obtained by `lookfor`.

Further useful commands include `quit` and `exit`, with which the Matlab session is terminated.

## Variables
Variables are introduced by assignment and do not have to be declared or defined. Names of the variables can be chosen freely. The only forbidden things are the use of special characters and digits at the beginning of the name. A distinction between uppercase and lowercase letters is not made. Examples:

| | |
| ------------- |:-------------:|
|`a = 3;`|	3 is assigned to a (no output)|
|`a`|	result output|
|`b = -2.5`	|-2,5 is assigned to b (with output)|


Note that Matlab uses a point to separate pre-decimal places and post-decimal places, following the conventions of the English language.

A major advantage of Matlab in comparison to a conventional programming language is the possibility to directly work with vectors. This concept shall only be touched briefly here, since it will be extensively treated in a separate chapter:

| | | |
| ------------- |:-------------:|:-------------:|
| `a = [3;1];`	| defines a column vector	| $\vec{a} = \left(\begin{array}{c}3 & 1 \end{array}\right)$ |
| `a(k)`	| means the vector component	| $a_k$ |
| `b = [0,3,-4];` |	defines a row vector	| $\vec{b} = (0,3,-4)$ |

The commas in square brackets can also be replaced by blank spaces.

Matlab cannot only calculate with vectors, but also with matrices. Thus, linear system of equations, such as

$x+2y = 3$

$3x+y = 1 $

can be formulated elegantly:

$$ \left(\begin{array}{cc} 1 & 2 \\ 3 & 1 \end{array}\right) \left(\begin{array}{c} x & y \end{array}\right) = \left(\begin{array}{c} 3 & 1 \end{array}\right) $$

respectively

$$D\,\vec{x} = \vec{b} $$

with the $2\times 2$ matrix

$$ D = \left(\begin{array}{cc}1 & 2 \\ 3 & 1 \end{array}\right) \begin{array}{c}\leftarrow\;\;\mbox{1. line} \\ \leftarrow\;\;\mbox{2. line} \\ \end{array}$$

$$\nearrow \nwarrow$$

1. line 2. line

and the column vectors

$$ \vec{x} = \left(\begin{array}{c}x & y \end{array}\right) \quad\mbox{and}\quad \vec{b} = \left(\begin{array}{c}3 & 1 \end{array}\right) $$

Here, $\vec{x}$ is the solution vector being sought.

The formal solution of the equation $D\,\vec{x} = \vec{b}$ is given by

&$\vec{x} = D^{-1}\, \vec{b} \, ,$&

where $D^{-1}$ denotes the inverse of the matrix $D$.

Matrices are introduced in Matlab as the following

