# Logging
{:.no_toc}

<nav markdown="1" class="toc-class">
* TOC
{:toc}
</nav>

## The goal

We want to log either or onto the screen or file. 

Questions to [David Rotermund](mailto:davrot@uni-bremen.de)



## [logging.getLogger](https://docs.python.org/3/library/logging.html#logging.getLogger)


```python
logging.getLogger(name=None)
```

> Return a logger with the specified name or, if name is None, return a logger which is the root logger of the hierarchy. If specified, the name is typically a dot-separated hierarchical name like ‘a’, ‘a.b’ or ‘a.b.c.d’. Choice of these names is entirely up to the developer who is using logging.
> 
> All calls to this function with a given name return the same logger instance. This means that logger instances never need to be passed between different parts of an application.

## [setLevel](https://docs.python.org/3/library/logging.html#logging.Logger.setLevel)

```python
setLevel(level)
```

> Sets the threshold for this logger to level. Logging messages which are less severe than level will be ignored; logging messages which have severity level or higher will be emitted by whichever handler or handlers service this logger, unless a handler’s level has been set to a higher severity level than level.
> 
> When a logger is created, the level is set to NOTSET (which causes all messages to be processed when the logger is the root logger, or delegation to the parent when the logger is a non-root logger). Note that the root logger is created with level WARNING.


|Level|Numeric value|What it means / When to use it|
|---|---|---|
|logging.NOTSET|0|When set on a logger, indicates that ancestor loggers are to be consulted to determine the effective level. If that still resolves to NOTSET, then all events are logged. When set on a handler, all events are handled.|
|logging.DEBUG|10|Detailed information, typically only of interest to a developer trying to diagnose a problem.|
|logging.INFO|20|Confirmation that things are working as expected.|
|logging.WARNING|30|An indication that something unexpected happened, or that a problem might occur in the near future (e.g. ‘disk space low’). The software is still working as expected.|
|logging.ERROR|40|Due to a more serious problem, the software has not been able to perform some function.|
|logging.CRITICAL|50|A serious error, indicating that the program itself may be unable to continue running.

## [Formatter](https://docs.python.org/3/library/logging.html#logging.Formatter)

```python
class logging.Formatter(fmt=None, datefmt=None, style='%', validate=True, *, defaults=None)
```

> Responsible for converting a LogRecord to an output string to be interpreted by a human or external system.


## [FileHandler](https://docs.python.org/3/library/logging.handlers.html#logging.FileHandler)

```python
class logging.FileHandler(filename, mode='a', encoding=None, delay=False, errors=None)
```

> Returns a new instance of the FileHandler class. The specified file is opened and used as the stream for logging. If mode is not specified, 'a' is used. If encoding is not None, it is used to open the file with that encoding. If delay is true, then file opening is deferred until the first call to emit(). By default, the file grows indefinitely. If errors is specified, it’s used to determine how encoding errors are handled.

## [StreamHandler](https://docs.python.org/3/library/logging.handlers.html#logging.StreamHandler)

```python
class logging.StreamHandler(stream=None)
```

> Returns a new instance of the StreamHandler class. If stream is specified, the instance will use it for logging output; otherwise, sys.stderr will be used.

## [setFormatter(fmt)](https://docs.python.org/3/library/logging.html#logging.Handler.setFormatter)

```python
setFormatter(fmt)
```

> Sets the Formatter for this handler to fmt.

## [addHandler(hdlr)](https://docs.python.org/3/library/logging.html#logging.Logger.addHandler)

```python
addHandler(hdlr)
```

> Adds the specified handler hdlr to this logger.


## Example code

```python
import logging
import datetime
import os


def create_logger(save_logging_messages: bool, display_logging_messages: bool):
    now = datetime.datetime.now()
    dt_string_filename = now.strftime("%Y_%m_%d_%H_%M_%S")

    logger = logging.getLogger("MyLittleLogger")
    logger.setLevel(logging.DEBUG)

    if save_logging_messages:
        time_format = "%b %-d %Y %H:%M:%S"
        logformat = "%(asctime)s %(message)s"
        file_formatter = logging.Formatter(fmt=logformat, datefmt=time_format)
        os.makedirs("logs", exist_ok=True)
        file_handler = logging.FileHandler(
            os.path.join("logs", f"log_{dt_string_filename}.txt")
        )
        file_handler.setLevel(logging.INFO)
        file_handler.setFormatter(file_formatter)
        logger.addHandler(file_handler)

    if display_logging_messages:
        time_format = "%H:%M:%S"
        logformat = "%(asctime)s %(message)s"
        stream_formatter = logging.Formatter(fmt=logformat, datefmt=time_format)

        stream_handler = logging.StreamHandler()
        stream_handler.setLevel(logging.INFO)
        stream_handler.setFormatter(stream_formatter)
        logger.addHandler(stream_handler)

    return logger
```

This is how you create a logger: 

```python
    logger = create_logger(
        save_logging_messages=bool(config["save_logging_messages"]),
        display_logging_messages=bool(config["display_logging_messages"]),
    )
```

After creating the logger, you can use e.g. like this:

```python
logger.info(f"Using {device_str} device")
```

## [debug](https://docs.python.org/3/library/logging.html#logging.debug) , [info](https://docs.python.org/3/library/logging.html#logging.info) ,  [warning](https://docs.python.org/3/library/logging.html#logging.warning), and [error](https://docs.python.org/3/library/logging.html#logging.error)

```python
logging.debug(msg, *args, **kwargs)
```

> Logs a message with level DEBUG on the root logger. The msg is the message format string, and the args are the arguments which are merged into msg using the string formatting operator. (Note that this means that you can use keywords in the format string, together with a single dictionary argument.)

```python
logging.info(msg, *args, **kwargs)
```

> Logs a message with level INFO on the root logger. The arguments are interpreted as for debug().

```python
logging.warning(msg, *args, **kwargs)
```

> Logs a message with level WARNING on the root logger. The arguments are interpreted as for debug().


```python
logging.error(msg, *args, **kwargs)
```

> Logs a message with level ERROR on the root logger. The arguments are interpreted as for debug().


    
