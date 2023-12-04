# Python : os.makedirs -- Creating order via sub-directories 
{:.no_toc}

<nav markdown="1" class="toc-class">
* TOC
{:toc}
</nav>

## The goal
How can I make sure that the directory for my output data is always there? We just create it automatically every time via [os.makedirs](https://docs.python.org/3/library/os.html#os.makedirs)! 

Questions to [David Rotermund](mailto:davrot@uni-bremen.de)

## Creating a directory

```python
import os

some_path: str = "a_home_for_my_data"
os.makedirs(some_path, exist_ok=True)
```

## Creating a sub-sub-sub-directory

First of all, it is important to be aware that different operation systems have different separators in path names. Thus we don't want to write the directory ourself. We want python to handle it for us.

There are different ways to do that. 

One way is to use [os.path.join](https://docs.python.org/3/library/os.path.html#os.path.join):

```python
import os

some_path: str = os.path.join("a", "b", "c")
print(some_path) # -> a/b/c under Linux and a\b\c under Windows. 
```

An alternative way is to use [os.sep](https://docs.python.org/3/library/os.html#os.sep):

```python
import os

some_path: str = f"a{os.sep}b{os.sep}c"
print(some_path) # -> a/b/c under Linux and a\b\c under Windows. 
```

Now we can create sub-sub-sub-directory with such a path. 

```python
import os

some_path: str = f"a{os.sep}b{os.sep}c"
os.makedirs(some_path, exist_ok=True)
```

## Checking if a directory exists

There are two nice ways to check if a directory exists: 
[os.path.isdir](https://docs.python.org/3/library/os.path.html#os.path.isdir) and [os.path.exists](https://docs.python.org/3/library/os.path.html#os.path.exists)
How ever the latter is also return true if a file with the same name exists. 

```python
import os

some_path: str = f"a{os.sep}b{os.sep}c"
os.makedirs(some_path, exist_ok=True)

print(os.path.exists(some_path)) # -> True
print(os.path.isfile(some_path)) # -> False
print(os.path.isdir(some_path)) # -> True
```
