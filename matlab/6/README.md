# Vectorization and Vector Calculus in Matlab
{:.no_toc}

<nav markdown="1" class="toc-class">
* TOC
{:toc}
</nav>

Questions to [David Rotermund](mailto:davrot@uni-bremen.de)

*By Jan Wiersig, modified by Udo Ernst and translated into English by Daniel Harnack.*

A great advantage of Matlab is that all variables are matrices (or, more general, arrays).

The benefits of this principle are manifold: They encompass the simplicity of the syntax to formulate complex mathematical operations, avoidance of tedious for-loops and optimization of internal processing of huge amounts of data resulting in considerable acceleration of the program.

## Basic Syntax
The easiest definition of vectors and matrices is to put the elements of a matrix between square brackets. Column vectors are treated in Matlab as matrices of dimension $\;N\times 1$ , row vectors as matrices of dimension $\;1\times N$ and scalars (i.e. plain numbers) as matrices of dimension $\;1\times 1$.Rows are divided from other rows by the use of a semi-colon, and columns are separated by commata (oder simply by a blank space, as in the last of the following examples). Examples:

||||
|---|---|---|
|scalar|	`a_scalar = 1;`|	1x1-matrix
|column vector|	`a_column = [1; 2; 3];`|	3x1-matrix
|row vector|	`a_row = [1, 2, 3];`|	1x3-matrix
|matrix|	`a_fullmatrix = [1 2 3; 4 5 6; 7 8 9];`|	3x3-matrix

The same rules that subsume single elements or variables to a vector also apply for strings and so-called cell-arrays:

```matlab
b = ['A ' 'character' 'string' 'of four elements'];

c = {rand([4 4]) 1:17 complex(42) 'this is a cell of a cell-array!'};
```

For the ones interested to dive deeper into Matlab: Note that cell-arrays are extremely useful to save several aspects of data in the same variable. An example from the laboratory would be a variable that holds the measured data, a date for the day of recording, a description of the experimental setup in a string and the parameters of recording. Furthermore, structures exist, whose constituent parts have names that can be accessed with a syntax similar to the programming language C.

## Definition of Matrices and Arrays

Simple vectors can be defined with the already mentioned colon-operator. The syntax is start value:step width:end value. If the step width is omitted, the default step width of $1$ is used. Examples:

`1:7` creates a vector with the numbers 1, 2, 3, 4, 5, 6, 7.

`1:2:7` creates a vector with the numbers 1, 3, 5, 7.

`4:-0.3:2.8` creates a vector with the numbers 4.0, 3.7, 3.4, 3.1, 2.8.

The vectors defined in this way shall be assigned to a variable:

```matlab
p = 0:0.01:100;
```

Such vectors, if used in loops, will be processed element-wise. In the following example, a vector with the numbers 1, 17 and 42 is printed to the screen element-wise:

```matlab
to_process = [1 17 42];

for k=to_process;

    fprintf('k is %i\n', k);

end
```

The output is:

```matlab
k is 1

k is 17

k is 42
```

Furthermore, the colon operator can be used to access columns, rows or arbitrary dimensions of an array. The colon by **itself** selects **all** elements of the respective dimension. In the syntax introduced above, the colon operator can also be used to select a specific set of indices of a matrix:

`b = a(4, 7:5:17);` selects, from the 4. row of the matrix a the entries of the columns 7, 5 and 17. It creates a vector from these elements and assigns it to the variable b.

Bigger matrices and arrays are defined by the commands zeros, ones and eye. The two arguments of these functions assign the number of columns and rows, e.g. `fullofzeros = zeros(17, 42);`. zeros fills the created matrix with zeros,

ones with ones, and eye creates an identity matrix. More than two arguments result in multidimensional arrays (tensors). There are several shortened notations of these commands. Some examples:

|||
|---|---|
|`z = zeros([1 17]);`|	correct	creates 1x17-matrix.|
|`z = zeros(1, 17);`|	correct	creates 1x17-matrix.|
|`z = zeros([1, 17]);`|	correct	creates 1x17-matrix.|
|`z = zeros(1:17);`|	wrong	|

tries to create a 1x2x3x4x5x6x7x8x9x10x11x12x13x14x15x16x17-matrix

and does not find enough memory!

A similar problem can occur when invoking the commands with only one argument $n$. Matlab will try to create a $n$ x $n$ -Matrix instead of a $1$ x $n$ -vector (which might have been intended).

|||
|---|---|
|`z = zeros(1e6);`|	wrong	tries to create a 1000000x1000000-matrix!|
|`z = zeros(1, 1e6);`|	correct	creates a 1x1000000-vector.|

**If you are in doubt, use, as always, the help function!** Multidimensional arrays lend themselves for example to save the color planes of a digital image. A matrix for that purpose would be created by `a = zeros([1024 768 3]);`.

As the last command in this series we will cover meshgrid. meshgrid takes two vectors as arguments and duplicate the first vector in the rows of the output matrix. The second vector is duplicated along the columns of the output matrix. The number of duplications of a vector is determined by the number of elements of the other vector. Example:

`[x_matrix, y_matrix] = meshgrid(-10:10, -10:10);` creates two matrices, whose entries of the columns resp. of the rows range from $-10$ to $10$. This command is suitable to define coordinate axes for two-dimensional plots. An example can be found in the chapter 'Graphics in Matlab'.

When working with initializations and arrays, it is important to be aware of how the contents of these arrays are administrated in the computer. Matlab hides many tasks form our eyes, that have to be attended to in many other programming languages first before being able to work with variables and arrays.

One of these tasks is the declaration of variables. In a 'proper' programming language, one has to determine the type of a variable when introducing it. Different types are floating-point numbers, integers, strings, etc.

If a numerical value is assigned to a variable, Matlab automatically assumes that the type of the variable is intended to be a double-precision floating-point number. Other types have to be created by an explicit type conversion.

Another task is the allocation and deallocation of memory: An array needs memory to be represented in the computer. Before the variable can be used, the computer has to be advised first to reserve a fitting space in the memory for this variable (just as a real estate has to be bought first before one is allowed to start building a house on it). In the same manner, memory has to be freed again if it is no longer needed (to prevent that empty real estates are left in the memory that block the space from other house builders). Matlab hides these processes and does all the administrative work for us. This can become critical if one writes into a variable that was previously undefined. For example the command clear; a(100000)=pi; creates a vector with $100000$ entries, and only in the $100000$-th entry the number $\pi$ is written. If the range of the vector, for which only $100000$ elements were reserved, is now exceeded by writing a(100001)=pi;, the following will happen:

* a new vector with $100001$ elements is created.
* into element $100001$, $2\pi$ is written.
* the elements $1$ bis $100000$ are copied from the old to the new vector.
* the memory allocated by the old vector is deallocated.
* the new vector takes the name of the old vector.
  
...a lot of effort to append an element. This is why you should always keep in mind to properly define and initialize arrays (with zeros or ones) before using them!

## Simple, predefined Vector Operations

Matlab is capable to process all elements of a vector or a matrix in one go:

```matlab
a = rand([1 17]);

b = rand([1 17]);

c = a+b;
```

The mathematical equivalent is $c_i=a_i+b_i$, $\forall i=1,\ldots,17$.

Vectors and matrices have to match in their dimensions;

A prerequisite for the Addition of arrays is that all dimensions have the same size. The same holds for subtraction.

Element-wise multiplication, division and exponentiation is indicated by a preceded dot:

```matlab
c_mult = a.*b;

c_div = a./b;
```

This convention was introduced in Matlab to tell apart the element-wise multiplication from the matrix multiplication.

||||
|---|---|---|
|`C = [1,1;0,1];`|	defines the $2\times 2$ matrix	|$C = \left(\begin{array}{ccc}1 & 1\\0 & 1\\\end{array}\right)$|
|`D = [1,2;3,1];`|	defines the $2\times 2$ matrix	|$D = \left(\begin{array}{ccc}1 & 2\\3 & 1\\\end{array}\right)$|
|`G = C*D;`|	gives	|$G = \left(\begin{array}{ccc}4 & 3\\3 & 1\\\end{array}\right)$|

The mathematical equivalent is $G_{kl} = \sum_{j}C_{kj}D_{jl}$.

Transposing a matrix $C^t_{kl} = C_{lk}$ is done by

||||
|---|---|---|
|`K = C';`	|gives	|$K = \left(\begin{array}{ccc}1 & 0\\1 & 1\\\end{array}\right)$|

The function `transpose(C)` can be utilized alternatively.

Inverting a matrix is accomplished by

||||
|---|---|---|
|`M = D^-1;`	|gives	|$M = \left(\begin{array}{ccc}-0.2 & 0.4\\0.6 & -0.2\\\end{array}\right)\\$|

resp. `M = inv(D);`. Assuming a system of equations

$D\,\vec{x} = \vec{b}$ and the vector $\vec{b}$ with

$\vec{b} = \left(\begin{array}{c}3\\ 1\\\end{array}\right) \,$

is given, the solution, by using the inverse, is found in Matlab by:

$\left(\begin{array}{c}x\\ y\\\end{array}\right) = M \left(\begin{array}{c}3\\1\\\end{array}\right) = \left(\begin{array}{c}-0.2\cdot 3 + 0.4\cdot 1\\0.6\cdot 3 - 0.2\cdot 1\\\end{array}\right)= \left(\begin{array}{c}-0.2\\1.6\\\end{array}\right) $ .

The solution of a system of equations can also be found by using the non-inverted matrix and one of the symbols $/$, $\backslash$ resp. the commands mldivide and mrdivide.

Important in a physical or geometrical context is the cross product of two vectors, which is realized in Matlab by the command cross:

```matlab
a = [0; 0; 1];

b = [1; 0; 0];

c = cross(a, b);

c
```

The output of these lines is:

```matlab
c = 

    0

    1

    0
```

## Reshaping, Copying and Duplication of Matrices/Arrays
A useful command to reorganize data is reshape. The content of the array is not altered by this command, only the organization in columns and rows, respectively the other dimensions. The syntax is `result = reshape(array, [dim1 dim2 dim3 ... dimN]);`.

The result is an array of dimensions `dim1` to `dimN`.

The product of these dimension has to equal the product of the **old** dimension of the array.

In the following situations, the command is sensibly applied:

* Reshaping of arrays to a form that is suitable for vector operations. Let us assume that we have $8$ vectors of $10$ constellations each in a $3$ x $8$ x $10$ -array wit the name $r$. Now we want to rotate the vectors with a rotation matrix $D$ ,to simulate the movement of the night sky:

```matlab
dummy = D*reshape(r, [3 80]);

r = reshape(dummy, [3 8 10]);
```

We first reshaped the $8$ x $10$ -matrix of vectors to form a $800$ -element vector, then we applied the rotation and finally brought the result matrix back to its original form.

* Interpretation of data, that was initially written from a file into a one-dimensional array. Example:

```matlab
f = fopen('digitalfphoto.bin', 'r');

a = fread(f, 'uint8=>uint8');

fclose(f);

imagesc(reshape(a, [500 375 3]));

set(gca, 'DataAspectRatio', [1 1 1]);
```

The second to last command reshaped the array to enable the usage of imagesc to display the image correctly.

In the last example, the Matlab user might be annoyed that the imagesc-command projects the first dimension of the array (with length 500, thus e.g. the $x$ -axis of a photo in landscape format!) onto the $y$ -axis. The versatile command permute remedies this situation -- this command **swaps** single dimensions of an array. It is important to understand that not only the organization of an array in rows and columns is changed, but also the sequence of the entries in the memory! The syntax of the command is `permuted = permute(array, [dimidx_dim1, dimidx_dim2, ..., dimidx_dimN]);`. Here, the second argument holds the numbers from $1$ to $N$ (where $N$ is the number of dimensions of an array, i.e. $N=2$ for a matrix), that specify the permutation of the dimensions. In the array permuted, the first dimension will be the dimidx_dim1-th dimension of the old array array, the second dimension the dimidx_dim2-th dimension of the old array, etc.

In order to display the digital photo from our example correctly, we thus have to type:

```matlab
a_permuted = permute(reshape(a, [500 375 3]), [2 1 3]);

imagesc(a_permuted);
```

This interchanges the $x$ - and the $y$ - direction, while the color information is preserved in the third dimension.

`repmat`, another important command, duplicates an array or matrix along one or several dimensions. The syntax is similar to reshape,

```matlab
result = repmat(array, [rep_dim1 rep_dim2 rep_dim3 ... rep_dimN]);
```

The matrix array is cloned

`rep_dim1`-times along the first dimension, rep_dim2-times along the second dimension, etc.

For example, the following commands,

```matlab
a = [1 2; 3 4];

repmat(a, [3 4])
```

give the output:

```matlab
ans =

    1      2      1      2      1      2      1      2

    3      4      3      4      3      4      3      4

    1      2      1      2      1      2      1      2

    3      4      3      4      3      4      3      4

    1      2      1      2      1      2      1      2

    3      4      3      4      3      4      3      4
```


Using this command makes sense, if matrix operations are repeated with different operands on the same initial vector. An example may be found in the section 'vectorization'.

## What Size does an Array have?
Especially when manipulating a lot of different arrays, when a function is supposed to operate on an array of previously unknown size or when one wants to find out whether two arrays are compatible to serve as an input to a matrix operation, the following commands will be helpful: size, length and numel.

It follows a short explanation for their function:

* `size`
returns the size of an array in a vector that has as many elements as the array has dimensions. Example:

```matlab
size(zeros([17 42]))

ans =

    17     42
```

* `length`
  
returns the longest dimension of an array, irrespective of which dimension this is. Example:

```matlab
length(zeros([17 42]))

ans =

    42
```

```matlab
length(zeros([42 17]))

ans =

    42
```

* `numel`
returns the total number of all elements of an array and is identical with the construct `prod(size(array));`. Example:

```matlab
numel(zeros([17 42]))

ans =

    714
```

## Example: Vectorization of a Program
To close this chapter, we will discuss two examples of what to do when vectorizing a program. First, consider the problem of generating a $N$ x $N$ -Matrix with entries $a_{ij} = i \cdot j$.

The tedious way via loops looks like this:

```matlab
N = 17;

a1 = zeros([N N]);

for i=1:N, 
    for j=1:N; 
        a1(i, j) = i*j; 
    end; 
end
```

It is much simpler to first create a row vector of the numbers $1$ bis $N$, and subsequently duplicate this this vector via repmat to obtain a $N$ x $N$ -matrix. Finally, this matrix is multiplied element-wise with its transpose:

```matlab
N = 17;

onefold = 1:N;

manifold = repmat(onefold, [N 1]);

a2 = manifold.*manifold';
```

However, this is still not yet the pinnacle of elegance that can be reached. Thinking a little about this problem, one might come to the conclusion that the mathematical operation that is intended can be described as a matrix multiplication of a $N$ x $1$ -matrix with a $1$ x $N$ -matrix (the so-called outer product of two vectors):

```matlab
N = 17;

onefold = 1:N;

a3 = onefold'*onefold;
```

As a second example we consider the following program: It defines two vectors with $x$ - and $y$ -coordinates, performs a translation of these coordinates and finally a rotation.

```matlab
%%% Example: before vectorizing

x = [ 0 -1  0 -2  0 -3  0 -4  0 -5  0  0  ...
	0  5  0  4  0  3  0  2  0  1  0];
y = [ 6  4  4  2  2  0  0 -2 -2 -4 -4 -6 ...
	-4 -4 -2 -2  0  0  2  2  4  4  6];

%%% Translation in x- and y-direction
trans_x = 4;
trans_y = -4;

%%% Rotation
phi = pi/4;

n = numel(x);
for i=1:n

	%%% apply translation to x,y
	x(i) = x(i)+trans_x;
	y(i) = y(i)+trans_y;

end

for i=1:n

	%%% apply rotation to x,y
	x_temp =  x(i)*cos(phi)+y(i)*sin(phi);
	y_temp = -x(i)*sin(phi)+y(i)*cos(phi);

	x(i) = x_temp;
	y(i) = y_temp;

end
```

As a first step, we can subsume the $23$ coordinate-tuple to a $2x23$ -matrix, that we call r:

```matlab
r = [x; y];
```

Here we used the semicolon to stack the row vectors on top of each other. Every column of the matrix r now holds a coordinate tuple. In the next step, we rewrite the translation vector as well as a column vector:

```matlab
trans = [trans_x; trans_y];
```

Now we might be tempted to replace the first for-loop by an element-wise addition of trans and r. But beware! The dimensions of both variables are not compatible, trans has only one column. Thus we use the command repmat, to duplicate trans $23$ times. After this we can perform the addition:

```matlab
r = r+repmat(trans, [1 size(trans, 2)]);
```

Here, we used the command size to avoid having to use the constant 23 -- the code will thus also work with other, longer or shorter variables x or y.

Next up is the rotation. The rotation matrix `D` is quickly defined,

```matlab
D = [cos(phi) sin(phi); -sin(phi) cos(phi)];
```

and equally quickly applied to `r`:

```matlab
r = D*r;
```

In the end, we assign the result again to the variables x and y . For this we use the colon-operator that selects whole rows of the matrix r:

```matlab
x = r(1, :);

y = r(2, :);
```

We can even integrate rotation and translation:

```matlab
r = D*(r+repmat(trans, [1 size(r, 2)]));
```

This gives the vectorized program code:

```matlab
%%% Example: AFTER vectorization

x = [ 0 -1  0 -2  0 -3  0 -4  0 -5  0  0  ...
	0  5  0  4  0  3  0  2  0  1  0];
y = [ 6  4  4  2  2  0  0 -2 -2 -4 -4 -6 ...
	-4 -4 -2 -2  0  0  2  2  4  4  6];

%%% Translation in x- and y-direction
trans_x = 4;
trans_y = -4;

%%% Rotation
phi = pi/4;

%%% Definition of the vectors
r = [x; y];
trans = [trans_x; trans_y];
D = [cos(phi) sin(phi); -sin(phi) cos(phi)];

%%% Two to three loops vectorized:
r = D*(r+repmat(trans, [1 size(r, 2)]));

%%% assign the result
x = r(1, :);
y = r(2, :);
```
