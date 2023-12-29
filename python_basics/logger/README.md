# Logging
{:.no_toc}

<nav markdown="1" class="toc-class">
* TOC
{:toc}
</nav>

## The goal



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




## Example function

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


