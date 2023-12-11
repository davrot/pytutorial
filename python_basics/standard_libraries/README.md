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


|||
|---|---|
|zlib | Compression compatible with gzip​|
|gzip | Support for gzip files​|
|bz2 | Support for bzip2 compression​|
|lzma | Compression using the LZMA algorithm​|
|zipfile | Work with ZIP archives​|
|tarfile | Read and write tar archive files|

## [File Formats](https://docs.python.org/3/library/fileformats.html)

> The modules described in this chapter parse various miscellaneous file formats that aren’t markup languages and are not related to e-mail.

|||
|---|---|
|csv | CSV File Reading and Writing​|
|configparser | Configuration file parser​|
|netrc | netrc file processing​|
|xdrlib | Encode and decode XDR data​|
|plistlib | Generate and parse Apple .plist files|

## [Cryptographic Services​](​https://docs.python.org/3/library/crypto.html)

> The modules described in this chapter implement various algorithms of a cryptographic nature. They are available at the discretion of the installation. On Unix systems, the crypt module may also be available.

|||
|---|---|
|hashlib | Secure hashes and message digests​|
|hmac | Keyed-Hashing for Message Authentication​|
|secrets | Generate secure random numbers for managing secrets​|

## [Generic Operating System Services​](https://docs.python.org/3/library/allos.html​)

> The modules described in this chapter provide interfaces to operating system features that are available on (almost) all operating systems, such as files and a clock. The interfaces are generally modeled after the Unix or C interfaces, but they are available on most other systems as well.

|||
|---|---|
|**[os](https://docs.python.org/3/library/os.html)** | **Miscellaneous operating system interfaces​** |
|io | Core tools for working with streams​|
|**[time](https://docs.python.org/3/library/time.html)** | **Time access and conversions​**|
|argparse | Parser for command-line options, arguments and sub-commands​|
|getopt | C-style parser for command line options​|
|**[logging](https://docs.python.org/3/library/logging.html)** | **Logging facility for Python​**|
|logging.config | Logging configuration​|
|logging.handlers | Logging handlers​|
|**[getpass](https://docs.python.org/3/library/getpass.html)** | **Portable password input​**|
|curses | Terminal handling for character-cell displays​|
|curses.textpad | Text input widget for curses programs​|
|curses.ascii | Utilities for ASCII characters​|
|curses.panel | A panel stack extension for curses​|
|platform | Access to underlying platform’s identifying data​|
|errno | Standard errno system symbols​|
|ctypes | A foreign function library for Python|

## [Concurrent Execution](https://docs.python.org/3/library/concurrency.html)

> The modules described in this chapter provide support for concurrent execution of code. The appropriate choice of tool will depend on the task to be executed (CPU bound vs IO bound) and preferred style of development (event driven cooperative multitasking vs preemptive multitasking).

|||
|---|---|
|threading | Thread-based parallelism​|
|**[multiprocessing](https://docs.python.org/3/library/multiprocessing.html)** | **Process-based parallelism​**|
|multiprocessing.shared_memory | Provides shared memory for direct access across processes​|
|concurrent.futures | Launching parallel tasks​|
|subprocess | Subprocess management​|
|sched | Event scheduler​|
|**[queue](https://docs.python.org/3/library/queue.html)** | **A synchronized queue class​**|
|contextvars | Context Variables​|
|_thread | Low-level threading API|

## [Networking and Interprocess Communication](https://docs.python.org/3/library/ipc.html)

> The modules described in this chapter provide mechanisms for networking and inter-processes communication.​

> Some modules only work for two processes that are on the same machine, e.g. signal and mmap. Other modules support networking protocols that two or more processes can use to communicate across machines.​

|||
|---|---|
|asyncio | Asynchronous I/O​|
|socket | Low-level networking interface​|
|ssl | TLS/SSL wrapper for socket objects​|
|select | Waiting for I/O completion​|
|selectors | High-level I/O multiplexing​|
|asyncore | Asynchronous socket handler​|
|asynchat | Asynchronous socket command/response handler​|
|signal | Set handlers for asynchronous events​|
|mmap | Memory-mapped file support|

## [Internet Data Handling​](https://docs.python.org/3/library/netdata.html)

> This chapter describes modules which support handling data formats commonly used on the Internet.

|||
|---|---|
|email | An email and MIME handling package​|
|**[json](https://docs.python.org/3/library/json.html)** | **JSON encoder and decoder**​|
|mailcap | Mailcap file handling​|
|mailbox | Manipulate mailboxes in various formats​|
|mimetypes | Map filenames to MIME types​|
|base64 | Base16, Base32, Base64, Base85 Data Encodings​|
|binhex | Encode and decode binhex4 files​|
|binascii | Convert between binary and ASCII​|
|quopri | Encode and decode MIME quoted-printable data​|

## [Structured Markup Processing Tools](https://docs.python.org/3/library/markup.html)

> Python supports a variety of modules to work with various forms of structured data markup. This includes modules to work with the Standard Generalized Markup Language (SGML) and the Hypertext Markup Language (HTML), and several interfaces for working with the Extensible Markup Language (XML).

​
|||
|---|---|
|html | HyperText Markup Language support​|
|html.parser | Simple HTML and XHTML parser​|
|html.entities | Definitions of HTML general entities​|
|xml.etree.ElementTree | The ElementTree XML API​|
|xml.dom | The Document Object Model API​|
|xml.dom.minidom | Minimal DOM implementation​|
|xml.dom.pulldom | Support for building partial DOM trees​|
|xml.sax | Support for SAX2 parsers​|
|xml.sax.handler | Base classes for SAX handlers​|
|xml.sax.saxutils | SAX Utilities​|
|xml.sax.xmlreader | Interface for XML parsers​|
|xml.parsers.expat | Fast XML parsing using Expat|


## [Internet Protocols and Support​](https://docs.python.org/3/library/internet.html)

> The modules described in this chapter implement Internet protocols and support for related technology. They are all implemented in Python. Most of these modules require the presence of the system-dependent module socket, which is currently supported on most popular platforms.

|||
|---|---|
|webbrowser | Convenient Web-browser controller​|
|cgi | Common Gateway Interface support​|
|cgitb | Traceback manager for CGI scripts​|
|wsgiref | WSGI Utilities and Reference Implementation​|
|urllib | URL handling modules​|
|urllib.request | Extensible library for opening URLs​|
|urllib.response | Response classes used by urllib​|
|urllib.parse | Parse URLs into components​|
|urllib.error | Exception classes raised by urllib.request​|
|urllib.robotparser | Parser for robots.txt​|
|http | HTTP modules​|
|http.client | HTTP protocol client​|
|ftplib | FTP protocol client|
|poplib | POP3 protocol client|​
|imaplib | IMAP4 protocol client​|
|nntplib | NNTP protocol client​|
|smtplib | SMTP protocol client​|
|smtpd | SMTP Server​|
|telnetlib | Telnet client​|
|uuid | UUID objects according to RFC 4122​|
|socketserver | A framework for network servers​|
|http.server | HTTP servers​|
|http.cookies | HTTP state management​|
|http.cookiejar | Cookie handling for HTTP clients​|
|xmlrpc | XMLRPC server and client modules​|
|xmlrpc.client | XML-RPC client access​|
|xmlrpc.server | Basic XML-RPC servers​|
|ipaddress | IPv4/IPv6 manipulation library|

## [Multimedia Service](https://docs.python.org/3/library/mm.html)
​
> The modules described in this chapter implement various algorithms or interfaces that are mainly useful for multimedia applications. They are available at the discretion of the installation. ​

|||
|---|---|
|audioop | Manipulate raw audio data​|
|aifc | Read and write AIFF and AIFC files​|
|sunau | Read and write Sun AU files​|
|wave | Read and write WAV files​|
|chunk | Read IFF chunked data​|
|colorsys | Conversions between color systems​|
|imghdr | Determine the type of an image​|
|sndhdr | Determine type of sound file​|
|ossaudiodev | Access to OSS-compatible audio devices|

## [Internationalization​](https://docs.python.org/3/library/i18n.html)

> The modules described in this chapter help you write software that is independent of language and locale by providing mechanisms for selecting a language to be used in program messages or by tailoring output to match local conventions.

|||
|---|---|
|gettext | Multilingual internationalization services​|
|locale | Internationalization services|

​
## [Program Frameworks​](https://docs.python.org/3/library/frameworks.html​)

> The modules described in this chapter are frameworks that will largely dictate the structure of your program. Currently the modules described here are all oriented toward writing command-line interfaces.

​
|||
|---|---|
|turtle | Turtle graphics​|
|cmd | Support for line-oriented command interpreters​|
|shlex | Simple lexical analysis|

## [Graphical User Interfaces with Tk​](​https://docs.python.org/3/library/tk.html)

|||
|---|---|
|**[tkinter](https://docs.python.org/3/library/tkinter.html)** | **Python interface to Tcl/Tk​**|
|tkinter.colorchooser | Color choosing dialog​|
|tkinter.font | Tkinter font wrapper​|
|tkinter.messagebox | Tkinter message prompts​|
|tkinter.scrolledtext | Scrolled Text Widget​|
|tkinter.dnd | Drag and drop support​|
|tkinter.ttk | Tk themed widgets​|
|tkinter.tix | Extension widgets for Tk​|

## [Development Tools](https://docs.python.org/3/library/development.html​)

> The modules described in this chapter help you write software. For example, the pydoc module takes a module and generates documentation based on the module’s contents. The doctest and unittest modules contains frameworks for writing unit tests that automatically exercise code and verify that the expected output is produced.

|||
|---|---|
|**[typing](https://docs.python.org/3/library/typing.html)** | **Support for type hints​**|
|pydoc | Documentation generator and online help system​|
|doctest | Test interactive Python examples​|
|unittest | Unit testing framework​|
|unittest.mock | mock object library​|
|unittest.mock | getting started​|
|2to3 | Automated Python 2 to 3 code translation​|
|test | Regression tests package for Python​|
|test.support | Utilities for the Python test suite​|
|test.support.socket_helper | Utilities for socket tests​|
|test.support.script_helper | Utilities for the Python execution tests​|
|test.support.bytecode_helper | Support tools for testing correct bytecode generation​|

## [Debugging and Profiling​](​https://docs.python.org/3/library/debug.html)

> These libraries help you with Python development: the debugger enables you to step through code, analyze stack frames and set breakpoints etc., and the profilers run code and give you a detailed breakdown of execution times, allowing you to identify bottlenecks in your programs. Auditing events provide visibility into runtime behaviors that would otherwise require intrusive debugging or patching.

|||
|---|---|
|bdb | Debugger framework​|
|faulthandler | Dump the Python traceback​|
|pdb | The Python Debugger​|
|timeit | Measure execution time of small code snippets​|
|trace | Trace or track Python statement execution​|
|tracemalloc | Trace memory allocations|

## [Software Packaging and Distribution​](https://docs.python.org/3/library/distribution.html​)

> ​These libraries help you with publishing and installing Python software. While these modules are designed to work in conjunction with the Python Package Index, they can also be used with a local index server, or without any index server at all.

|||
|---|---|
|distutils | Building and installing Python modules​|
|ensurepip | Bootstrapping the pip installer​|
|venv | Creation of virtual environments​|
|zipapp | Manage executable Python zip archives|

## [Python Runtime Services](https://docs.python.org/3/library/python.html​)

|||
|---|---|
|**[sys](https://docs.python.org/3/library/sys.html)** | **System-specific parameters and functions​**|
|sysconfig | Provide access to Python’s configuration information​|
|builtins | Built-in objects​|
|**[\_\_main\_\_](https://docs.python.org/3/library/__main__.html)** | **Top-level script environment​**|
|warnings | Warning control​|
|**[dataclasses](https://docs.python.org/3/library/dataclasses.html)** | **Data Classes​**|
|**[contextlib](https://docs.python.org/3/library/contextlib.html)** | **Utilities for with-statement contexts​**|
|**[abc](https://docs.python.org/3/library/abc.html)** | **Abstract Base Classes​**|
|atexit | Exit handlers​|
|traceback | Print or retrieve a stack traceback​|
|\_\_future\_\_ | Future statement definitions​|
|gc | Garbage Collector interface​|
|inspect | Inspect live objects​|
|site | Site-specific configuration hook|

## [Custom Python Interpreters​](https://docs.python.org/3/library/custominterp.html)

> The modules described in this chapter allow writing interfaces similar to Python’s interactive interpreter. If you want a Python interpreter that supports some special feature in addition to the Python language, you should look at the code module. (The codeop module is lower-level, used to support compiling a possibly-incomplete chunk of Python code.)

|||
|---|---|
|code | Interpreter base classes​|
|codeop | Compile Python code|

## [Importing Modules​](https://docs.python.org/3/library/modules.html​)

> The modules described in this chapter provide new ways to import other Python modules and hooks for customizing the import process.

|||
|---|---|
|zipimport | Import modules from Zip archives​|
|pkgutil | Package extension utility​|
|modulefinder | Find modules used by a script​|
|runpy | Locating and executing Python modules|​
|importlib | The implementation of import​|

## [Python Language Services​](https://docs.python.org/3/library/language.html​)

> Python provides a number of modules to assist in working with the Python language. These modules support tokenizing, parsing, syntax analysis, bytecode disassembly, and various other facilities.​

|||
|---|---|
|parser | Access Python parse trees​|
|ast | Abstract Syntax Trees​|
|symtable | Access to the compiler’s symbol tables​|
|symbol | Constants used with Python parse trees​|
|token | Constants used with Python parse trees​|
|keyword | Testing for Python keywords​|
|tokenize | Tokenizer for Python source​|
|tabnanny | Detection of ambiguous indentation​|
|pyclbr | Python module browser support​|
|py_compile | Compile Python source files​|
|compileall | Byte-compile Python libraries​|
|dis | Disassembler for Python bytecode​|
|pickletools | Tools for pickle developers|

## [Miscellaneous Services](https://docs.python.org/3/library/misc.html​)

> The modules described in this chapter provide miscellaneous services that are available in all Python versions.

|||
|---|---|
|formatter | Generic output formatting​|

## [MS Windows Specific Services​](https://docs.python.org/3/library/windows.html)

> This chapter describes modules that are only available on MS Windows platforms.

|||
|---|---|
|msilib | Read and write Microsoft Installer files​|
|msvcrt | Useful routines from the MS VC++ runtime​|
|winreg | Windows registry access​|
|winsound | Sound-playing interface for Windows|

## [Unix Specific Services​](​https://docs.python.org/3/library/unix.html)

> The modules described in this chapter provide interfaces to features that are unique to the Unix operating system, or in some cases to some or many variants of it.

|||
|---|---|
|posix | The most common POSIX system calls​|
|pwd | The password database​|
|spwd | The shadow password database​|
|grp | The group database​|
|crypt | Function to check Unix passwords​|
|termios | POSIX style tty control​|
|tty | Terminal control functions​|
|pty | Pseudo-terminal utilities​|
|fcntl | The fcntl and ioctl system calls​|
|pipes | Interface to shell pipelines​|
|resource | Resource usage information|​
|nis | Interface to Sun’s NIS (Yellow Pages)​|
|syslog | Unix syslog library routines|


