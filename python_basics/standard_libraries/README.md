## The Python Standard Library​
{:.no_toc}

<nav markdown="1" class="toc-class">
* TOC
{:toc}
</nav>

## The goal

More than the standard instruction set...​

Questions to [David Rotermund](mailto:davrot@uni-bremen.de)

## [Text Processing Services](https://docs.python.org/3/library/text.html​)

> The modules described in this chapter provide a wide range of string manipulation operations and other text processing services.​

|||
|---|---|
|**[​string](https://docs.python.org/3/library/string.html)** | **Common string operations​** |
|re | Regular expression operations​|
|difflib | Helpers for computing deltas​|
|textwrap | Text wrapping and filling​|
|unicodedata | Unicode Database​|
|stringprep | Internet String Preparation​|
|readline | GNU readline interface​|
|rlcompleter | Completion function for GNU readline|


## [Binary Data Services​](https://docs.python.org/3/library/binary.html​)

> The modules described in this chapter provide some basic services operations for manipulation of binary data. Other operations on binary data, specifically in relation to file formats and network protocols, are described in the relevant sections.​

|||
|---|---|
|struct | Interpret bytes as packed binary data​|
|codecs | Codec registry and base classes|

## [Data Types](https://docs.python.org/3/library/datatypes.html​)

> The modules described in this chapter provide a variety of specialized data types such as dates and times, fixed-type arrays, heap queues, double-ended queues, and enumerations.​

|||
|---|---|
|**[datetime](https://docs.python.org/3/library/datetime.html)** | **Basic date and time types​**|
|zoneinfo | IANA time zone support​|
|calendar | General calendar-related functions​|
|collections | Container datatypes​|
|collections.abc | Abstract Base Classes for Containers​|
|heapq | Heap queue algorithm​|
|bisect | Array bisection algorithm​|
|array | Efficient arrays of numeric values​|
|weakref | Weak references​|
|**[types](https://docs.python.org/3/library/types.html)** | **Dynamic type creation and names for built-in types​**|
|copy | Shallow and deep copy operations​|
|pprint | Data pretty printer​|
|reprlib | Alternate repr() implementation​|
|enum | Support for enumerations​|
|graphlib | Functionality to operate with graph-like structures|

## [Numeric and Mathematical Modules​](https://docs.python.org/3/library/numeric.html)

> The modules described in this chapter provide numeric and math-related functions and data types. The numbers module defines an abstract hierarchy of numeric types. The math and cmath modules contain various mathematical functions for floating-point and complex numbers. The decimal module supports exact representations of decimal numbers, using arbitrary precision arithmetic.

|||
|---|---|
|numbers | Numeric abstract base classes​|
|**[math](https://docs.python.org/3/library/math.html)** | **Mathematical functions​**|
|cmath | Mathematical functions for complex numbers​|
|decimal | Decimal fixed point and floating point arithmetic​|
|fractions | Rational numbers​|
|**[random](https://docs.python.org/3/library/random.html)** | **Generate pseudo-random numbers​**|
|statistics | Mathematical statistics functions|

## [Functional Programming Modules](https://docs.python.org/3/library/functional.html)

> The modules described in this chapter provide functions and classes that support a functional programming style, and general operations on callables.

|||
|---|---|
|itertools | Functions creating iterators for efficient looping​|
|**[functools](https://docs.python.org/3/library/functools.html)** | **Higher-order functions and operations on callable objects​**|
|**[operator](https://docs.python.org/3/library/operator.html)** | **Standard operators as functions**|

## [File and Directory Access​](​https://docs.python.org/3/library/filesys.html)

> ​The modules described in this chapter deal with disk files and directories. For example, there are modules for reading the properties of files, manipulating paths in a portable way, and creating temporary files.

|||
|---|---|
|pathlib | Object-oriented filesystem paths​|
|**[os.path](https://docs.python.org/3/library/os.path.html)** | **Common pathname manipulations​**|
|fileinput | Iterate over lines from multiple input streams​|
|stat | Interpreting stat() results​|
|filecmp | File and Directory Comparisons​|
|tempfile | Generate temporary files and directories​|
|**[glob](https://docs.python.org/3/library/glob.html)** | **Unix style pathname pattern expansion​**|
|fnmatch | Unix filename pattern matching​|
|linecache | Random access to text lines​|
|shutil | High-level file operations|

## [Data Persistence​](​https://docs.python.org/3/library/persistence.html)

> The modules described in this chapter support storing Python data in a persistent form on disk. The pickle and marshal modules can turn many Python data types into a stream of bytes and then recreate the objects from the bytes. The various DBM-related modules support a family of hash-based file formats that store a mapping of strings to other strings.​

|||
|---|---|
|**[pickle](https://docs.python.org/3/library/pickle.html)** | **Python object serialization​**|
|copyreg | Register pickle support functions​|
|shelve | Python object persistence​|
|marshal | Internal Python object serialization​|
|dbm | Interfaces to Unix “databases”​|
|sqlite3 | DB-API 2.0 interface for SQLite databases|

## [Data Compression and Archiving](​https://docs.python.org/3/library/archiving.html)

> The modules described in this chapter support data compression with the zlib, gzip, bzip2 and lzma algorithms, and the creation of ZIP- and tar-format archives. See also Archiving operations provided by the shutil module.

​|||
|---|---|
|zlib | Compression compatible with gzip​|
|gzip | Support for gzip files​|
|bz2 | Support for bzip2 compression​|
|lzma | Compression using the LZMA algorithm​|
|zipfile | Work with ZIP archives​|
|tarfile | Read and write tar archive files|



