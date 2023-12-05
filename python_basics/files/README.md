# [Files](https://docs.python.org/3/tutorial/inputoutput.html#reading-and-writing-files​)
{:.no_toc}

<nav markdown="1" class="toc-class">
* TOC
{:toc}
</nav>

## The goal
How to deal with (non-numpy) files under Python?

Questions to [David Rotermund](mailto:davrot@uni-bremen.de)

## [Open](https://docs.python.org/3/library/functions.html#open) a file​

```python
open(file, mode='r', buffering=- 1, encoding=None, errors=None, newline=None, closefd=True, opener=None)
```
The available modes are:

|Character​|Meaning​|
|---|---|
|**'r'**​|**open for reading (default)​**|
|'w'​|open for writing, truncating the file first​|
|'x'​|open for exclusive creation, failing if the file already exists​|
|'a'​|open for writing, appending to the end of file if it exists​|
|'b'​|binary mode​|
|**'t'**​|**text mode (default)​**|
|'+'​|open for updating (reading and writing)​|

## [Close](https://docs.python.org/3/library/io.html#io.IOBase.close) the file

If you open a file then you have to close the file. Otherwise this can end in information lost or broken files. 
Nowadays we use a with instead. 


## [with](https://docs.python.org/3/reference/compound_stmts.html#with​) is better than close​

It is good practice to use the [with](https://docs.python.org/3/reference/compound_stmts.html#with​) keyword when dealing with file objects. The advantage is that the file is properly closed after its suite finishes, even if an exception is raised at some point.

```python
with_stmt          ::=  "with" ( "(" with_stmt_contents ","? ")" | with_stmt_contents ) ":" suite​
with_stmt_contents ::=  with_item ("," with_item)*​
with_item          ::=  expression ["as" target]
```

```python
with open('workfile', mode="r") as f:​
    read_data = f.read()
```

## [Text vs binary​](https://docs.python.org/3/library/io.html#io-overview​)

### Text I/O​

*Text I/O expects and produces str objects. This means that whenever the backing store is natively made of bytes (such as in the case of a file), encoding and decoding of data is made transparently as well as optional translation of platform-specific newline characters.​*
*The easiest way to create a text stream is with open(), optionally specifying an encoding:*

```python
f = open("myfile.txt", "r", encoding="utf-8")​
```

*The text stream API is described in detail in the documentation of [TextIOBase](https://docs.python.org/3/library/io.html#io.TextIOBase).​*
[Quote](https://docs.python.org/3/library/io.html#text-i-o)

#### [Methods](https://docs.python.org/3/library/io.html#io.TextIOBase)

|Methods|Description|
|---|---|
|read(size=- 1, /)​|Read and return at most size characters from the stream as a single str. If size is negative or None, reads until EOF.​|
|readline(size=- 1, /)​|Read until newline or EOF and return a single str. If the stream is already at EOF, an empty string is returned.​ <br> If size is specified, at most size characters will be read.​|
|seek(offset, whence=SEEK_SET, /)​ | Change the stream position to the given offset. Behaviour depends on the whence parameter. The default value for whence is SEEK_SET.​ <br> SEEK_SET or 0: seek from the start of the stream (the default); offset must either be a number returned by TextIOBase.tell(), or zero. Any other offset value produces undefined behaviour.​ <br> ​SEEK_CUR or 1: “seek” to the current position; offset must be zero, which is a no-operation (all other values are unsupported).​ <br> ​SEEK_END or 2: seek to the end of the stream; offset must be zero (all other values are unsupported).​ <br> Return the new absolute position as an opaque number.​ |
|tell()​|Return the current stream position as an opaque number. The number does not usually represent a number of bytes in the underlying binary storage.​|
|write(s, /)​|Write the string s to the stream and return the number of characters written.​|

### Binary I/O

*​Binary I/O (also called buffered I/O) expects bytes-like objects and produces bytes objects. No encoding, decoding, or newline translation is performed. This category of streams can be used for all kinds of non-text data, and also when manual control over the handling of text data is desired.​*

*The easiest way to create a binary stream is with open() with 'b' in the mode string:*

```python
f = open("myfile.jpg", "rb")​
```

*The binary stream API is described in detail in the docs of [BufferedIOBase](https://docs.python.org/3/library/io.html#io.BufferedIOBase).*
[Quote](https://docs.python.org/3/library/io.html#binary-i-o)

#### [Methods](https://docs.python.org/3/library/io.html#io.BufferedIOBase)


|Methods|Description|
|---|---|
|read(size=- 1, /)​|Read and return up to size bytes. If the argument is omitted, None, or negative, data is read and returned until EOF is reached. An empty bytes object is returned if the stream is already at EOF.​ <br>If the argument is positive, and the underlying raw stream is not interactive, multiple raw reads may be issued to satisfy the byte count (unless EOF is reached first). But for interactive raw streams, at most one raw read will be issued, and a short result does not imply that EOF is imminent.​ <br>A BlockingIOError is raised if the underlying raw stream is in non blocking-mode, and has no data available at the moment.​ |
|read1(size=- 1, /)​|Read and return up to size bytes, with at most one call to the underlying raw stream’s read() (or readinto()) method. This can be useful if you are implementing your own buffering on top of a BufferedIOBase object.​<br>​If size is -1 (the default), an arbitrary number of bytes are returned (more than zero unless EOF is reached).​|
|readinto(b, /)​|Read bytes into a pre-allocated, writable bytes-like object b and return the number of bytes read. For example, b might be a bytearray.​<br>Like read(), multiple reads may be issued to the underlying raw stream, unless the latter is interactive.​<br>A BlockingIOError is raised if the underlying raw stream is in non blocking-mode, and has no data available at the moment.​|
|readinto1(b, /)​|Read bytes into a pre-allocated, writable bytes-like object b, using at most one call to the underlying raw stream’s read() (or readinto()) method. Return the number of bytes read.​<br>A BlockingIOError is raised if the underlying raw stream is in non blocking-mode, and has no data available at the moment.​|
|write(b, /)​|Write the given bytes-like object, b, and return the number of bytes written (always equal to the length of b in bytes, since if the write fails an OSError will be raised). Depending on the actual implementation, these bytes may be readily written to the underlying stream, or held in a buffer for performance and latency reasons.​<br>When in non-blocking mode, a BlockingIOError is raised if the data needed to be written to the raw stream but it couldn’t accept all the data without blocking.​<br>The caller may release or mutate b after this method returns, so the implementation should only access b during the method call.​|

## [os.path](https://docs.python.org/3/library/os.path.html​) 

### [os.path.exists](https://docs.python.org/3/library/os.path.html#os.path.exists)

```python
os.path.exists(path)​
```

*Return True if path refers to an existing path or an open file descriptor. Returns False for broken symbolic links. On some platforms, this function may return False if permission is not granted to execute os.stat() on the requested file, even if the path physically exists.*

### [os.path.isfile](https://docs.python.org/3/library/os.path.html#os.path.isfile)

```python
os.path.isdir(path)
```

*Return True if path is an existing regular file. This follows symbolic links, so both islink() and isfile() can be true for the same path.*

### [os.path.getsize](https://docs.python.org/3/library/os.path.html#os.path.getsize)

```python
os.path.getsize(path)
```

*Return the size, in bytes, of path. Raise OSError if the file does not exist or is inaccessible.*




