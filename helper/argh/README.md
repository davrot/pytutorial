# Argh
{:.no_toc}

<nav markdown="1" class="toc-class">
* TOC
{:toc}
</nav>

## The goal

Argh helps to handle command line arguments in a big way. Don't use the build-in Python stuff for that.   

Questions to [David Rotermund](mailto:davrot@uni-bremen.de)

```shell
pip install argh
```

## Simple example

### No argument is required​

The arguments are now only optional for the function call:

```python
import argh


def main(first_parameter: int = 1, second_parameter: int = 2, third_parameter: bool = True) -> None:
    print("Main")


if __name__ == "__main__":
    argh.dispatch_command(main)
```

```shell
python test.py
```

Output

```shell
Main
```

```shell
python test.py --help
```

Output

```shell
usage: test.py [-h] [-f FIRST_PARAMETER] [-s SECOND_PARAMETER] [-t]

options:
  -h, --help            show this help message and exit
  -f FIRST_PARAMETER, --first-parameter FIRST_PARAMETER
                        1
  -s SECOND_PARAMETER, --second-parameter SECOND_PARAMETER
                        2
  -t, --third-parameter
                        True
```

Note: For boolean parameters using the option switches them to the other state. Here **python test.py** sets **third-parameter=True** and **python test.py -t** sets **third-parameter=False**.


### One argument is required​

```python
import argh


def main(first_parameter: int, second_parameter: int = 2, third_parameter: bool = True) -> None:
    print("Main")


if __name__ == "__main__":
    argh.dispatch_command(main)
```

```shell
python test.py
```

Output

```shell
usage: test.py [-h] [-s SECOND_PARAMETER] [-t] first-parameter
test.py: error: the following arguments are required: first-parameter
```

```shell
python test.py 1
```

Output

```shell
Main
```

## More than one function​

Sometimes we have a collection of function. This is how we select one of those:

```python
import argh


def main_1(
    first_parameter: int = 1, second_parameter: int = 2, third_parameter: bool = True
) -> None:
    print("Main 1")


def main_2(first_parameter: int = 1) -> None:
    print("Main 2")


if __name__ == "__main__":
    parser = argh.ArghParser()
    parser.add_commands([main_1, main_2])
    parser.dispatch()
```

```shell
python test.py
```

Output

```shell
usage: test.py [-h] {main-1,main-2} ...
```

```shell
python test.py main-1
python test.py main-2
```

Output:

```shell
Main 1
Main 2
```

```shell
python test.py main-1 --help
python test.py main-2 --help
```

Output: 

```shell
usage: test.py main-1 [-h] [-f FIRST_PARAMETER] [-s SECOND_PARAMETER] [-t]

options:
  -h, --help            show this help message and exit
  -f FIRST_PARAMETER, --first-parameter FIRST_PARAMETER
                        1
  -s SECOND_PARAMETER, --second-parameter SECOND_PARAMETER
                        2
  -t, --third-parameter
                        True

usage: test.py main-2 [-h] [-f FIRST_PARAMETER]

options:
  -h, --help            show this help message and exit
  -f FIRST_PARAMETER, --first-parameter FIRST_PARAMETER
                        1
```





