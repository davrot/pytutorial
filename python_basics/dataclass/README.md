# Data structures: [dataclass](https://docs.python.org/3/library/dataclasses.html)
{:.no_toc}

<nav markdown="1" class="toc-class">
* TOC
{:toc}
</nav>

## The goal

There is a new build-in [dataclass](https://docs.python.org/3/library/dataclasses.html) class which is highly interesting for data scientists. Obviously it is a class for storing your data. Who would have guessed...

Questions to [David Rotermund](mailto:davrot@uni-bremen.de)

**Type annotations required!!!**

This is the first construct in Python that requires type annotation. 

If we do this:

```python
from dataclasses import dataclass


@dataclass
class TestClass:
    a # -> NameError: name 'a' is not defined
    b
```

We get this nice error: 

![image0](2022-04-02_20-34_0.png)


With type annotations:

```python
from dataclasses import dataclass


@dataclass
class TestClass:
    a: int
    b: str
```

No error!!!


## What is a dataclass?

[@dataclass](https://docs.python.org/3/library/dataclasses.html) is a decorator that tells Python that this class is a dataclass. A dataclass is a class with different properties compared to a normal class. 

```python
from dataclasses import dataclass


@dataclass
class TestClassA:
    name: str
    number_of_electrodes: int
    sample_rate_in_hz: float
    dt: float


data_1 = TestClassA("Dataset A", 100, 1000, 1 / 1000)
print(data_1)
```

Output:

```python
TestClassA(name='Dataset A', number_of_electrodes=100, sample_rate_in_hz=1000, dt=0.001)
```

## Default values

```python
from dataclasses import dataclass


@dataclass
class TestClassA:
    name: str
    number_of_electrodes: int
    dt: float
    sample_rate_in_hz: float = 1000.0


data_1 = TestClassA("Dataset A", 100, 1 / 1000)
print(data_1)
```

Output:

```python
TestClassA(name='Dataset A', number_of_electrodes=100, dt=0.001, sample_rate_in_hz=1000.0)
```

An alternative is to use field with the default argument:

```python
from dataclasses import dataclass, field


@dataclass
class TestClassA:
    name: str
    number_of_electrodes: int
    dt: float
    sample_rate_in_hz: float = field(default=1000.0)


data_1 = TestClassA("Dataset A", 100, 1 / 1000)
print(data_1)
```


## Default factory

We can use the field's default_factory to put suitable generic default into attributes. default and default_factory can not used together. 
Why should we use a default_factory? Well, please see the problem with [mutable](https://docs.python.org/3/glossary.html#term-mutable) objects in the [official Python documentation](https://docs.python.org/3/tutorial/classes.html#class-and-instance-variables). 
Or in other words: Using = [ ] as default will cause you pain.

```python
from dataclasses import dataclass, field


@dataclass
class TestClassA:
    name: str = field(default_factory=str)
    number_of_electrodes: int = field(default_factory=int)
    dt: float = field(default_factory=float)
    sample_rate_in_hz: float = field(default_factory=float)


data_1 = TestClassA()
print(data_1)
```

## Keyword only attributes (Python >= 3.10)

We can mark attributes as key word only (kw_only=true). Normally we would need them to put at the end of the definition of attributes. However, with this allows us to mix it in between:  

```python
from dataclasses import dataclass, field


@dataclass
class TestClassA:
    name: str
    number_of_electrodes: int = field(kw_only=True, default=42)
    dt: float = field(init=False)
    sample_rate_in_hz: float = 1000.0

    def __post_init__(self) -> None:
        self.dt = 1.0 / self.sample_rate_in_hz

    def __str__(self) -> str:
        output: str = (
            f"Name: {self.name}"
            "\n"
            f"Number of electrodes: {self.number_of_electrodes}"
            "\n"
            f"dt: {self.dt:.4f}s"
            "\n"
            f"Sample Rate: {self.sample_rate_in_hz:.2f}Hz"
        )
        return output


data_1 = TestClassA("Dataset A", 500)
print(data_1)
print("")

data_2 = TestClassA("Dataset B", 500, number_of_electrodes=33)
print(data_2)
```

Output:

```python
Name: Dataset A
Number of electrodes: 42
dt: 0.0020s
Sample Rate: 500.00Hz

Name: Dataset B
Number of electrodes: 33
dt: 0.0020s
Sample Rate: 500.00Hz
```

## def \_\_post_init\_\_(self):

We can do operations after the init:

```python
from dataclasses import dataclass, field


@dataclass
class TestClassA:
    name: str
    number_of_electrodes: int
    dt: float = field(init=False)
    sample_rate_in_hz: float = 1000.0

    def __post_init__(self) -> None:
        self.dt = 1.0 / self.sample_rate_in_hz


data_1 = TestClassA("Dataset A", 100, 500)
print(data_1)
```

Output:

```python
TestClassA(name='Dataset A', number_of_electrodes=100, dt=0.002, sample_rate_in_hz=500)
 ```

## def \_\_str\_\_(self):

Make the print output nicer:

```python
from dataclasses import dataclass, field


@dataclass
class TestClassA:
    name: str
    number_of_electrodes: int
    dt: float = field(init=False)
    sample_rate_in_hz: float = 1000.0

    def __post_init__(self) -> None:
        self.dt = 1.0 / self.sample_rate_in_hz

    def __str__(self) -> str:
        output: str = (
            f"Name: {self.name}"
            "\n"
            f"Number of electrodes: {self.number_of_electrodes}"
            "\n"
            f"dt: {self.dt:.4f}s"
            "\n"
            f"Sample Rate: {self.sample_rate_in_hz:.2f}Hz"
        )
        return output


data_1 = TestClassA("Dataset A", 100, 500)
print(data_1)
```



Output
```python
Name: Dataset A
Number of electrodes: 100
dt: 0.0020s
Sample Rate: 500.00Hz
```

## Read Only data

We can protect the data from being modified later. Note: If we need to modify data in e.g. the \_\_post\_init\_\_ function then we need to use object.\_\_setattr\_\_. 

```python
from dataclasses import dataclass, field


@dataclass(frozen=True)
class TestClassA:
    name: str
    number_of_electrodes: int
    dt: float = field(init=False)
    sample_rate_in_hz: float = 1000.0

    def __post_init__(self) -> None:
        object.__setattr__(self, "dt", 1.0 / self.sample_rate_in_hz)

    def __str__(self) -> str:
        output: str = (
            f"Name: {self.name}"
            "\n"
            f"Number of electrodes: {self.number_of_electrodes}"
            "\n"
            f"dt: {self.dt:.4f}s"
            "\n"
            f"Sample Rate: {self.sample_rate_in_hz:.2f}Hz"
        )
        return output


data_1 = TestClassA("Dataset A", 100, 500)
data_1.name = "New Name" #  -> FrozenInstanceError: cannot assign to field 'name'
```

## Inheritance


```python
from dataclasses import dataclass


@dataclass
class BasicDataset:
    x: int = 1
    y: int = 2


@dataclass
class NewDataSet(BasicDataset):
    a: int = 3
    x: int = 4


data_1 = BasicDataset()
print(data_1)
data_2 = NewDataSet()
print(data_2)
```

Output:
```python
BasicDataset(x=1, y=2)
NewDataSet(x=4, y=2, a=3)
```

## Why should want we to use a data class?

### Comparing datasets

We can compare datasets now

```python
from dataclasses import dataclass


@dataclass
class MyDataset:
    x: int
    y: int


data_1a = MyDataset(x=1, y=1)
data_1b = MyDataset(x=1, y=1)
print(data_1a == data_1b)
data_2 = MyDataset(x=1, y=2)
print(data_1a == data_2)
```

Output:
```python
True
False
```

We can remove attributes from the comparison

```python
from dataclasses import dataclass, field


@dataclass
class MyDataset:
    x: int
    y: int = field(compare=False)


data_1a = MyDataset(x=1, y=1)
data_1b = MyDataset(x=1, y=1)
print(data_1a == data_1b)
data_2 = MyDataset(x=1, y=2)
print(data_1a == data_2)
```

Output:
```python
True
True
```

### Sorting datasets

We can add a custom sort_index attribute. Which we can also hide with [repr=False](https://docs.python.org/3/library/dataclasses.html#dataclasses.field):

```python
from dataclasses import dataclass


@dataclass(order=True)
class MyDataset:
    sort_index: int = field(init=False, repr=False)
    x: int
    y: int

    def __post_init__(self):
        self.sort_index = self.x + self.y * 10


data_0 = MyDataset(x=2, y=2)
data_1 = MyDataset(x=1, y=1)
data_2 = MyDataset(x=1, y=2)
data_3 = MyDataset(x=1, y=2)

print([data_0, data_1, data_2, data_3])
print("")
print(sorted([data_0, data_1, data_2, data_3]))
```

Output:

```python
[MyDataset(x=2, y=2), MyDataset(x=1, y=1), MyDataset(x=1, y=2), MyDataset(x=1, y=2)]

[MyDataset(x=1, y=1), MyDataset(x=1, y=2), MyDataset(x=1, y=2), MyDataset(x=2, y=2)]
```

## Slots (Python >= 3.10)

{: .topic-optional}
This is an optional topic!


What? Slots? 

[3.3.2.4. \_\_slots\_\_](https://docs.python.org/3/reference/datamodel.html#slots)
> The space saved over using \_\_dict\_\_ can be significant. Attribute lookup speed can be significantly improved as well.

Normally: 

```python
from dataclasses import dataclass


@dataclass
class MyDataset:
    x: int
    y: int


data_0 = MyDataset(x=2, y=2)
print(data_0.__dict__)
data_0.a = 1
print(data_0.__dict__)
```

Output:
```python
{'x': 2, 'y': 2}
{'x': 2, 'y': 2, 'a': 1}
```

With slots=True:

```python
from dataclasses import dataclass


@dataclass(slots=True)
class MyDataset:
    x: int
    y: int


data_0 = MyDataset(x=2, y=2)
print(data_0.__dict__)  # -> AttributeError: 'MyDataset' object has no attribute '__dict__'
data_0.a = 1  # -> AttributeError: 'MyDataset' object has no attribute 'a'
```

## Convert to tuple / dictionary
We can easily convert a dataclass object and convert it into a tuple or dictionary:

```python:
from dataclasses import dataclass, astuple, asdict


@dataclass
class MyDataset:
    x: int
    y: int


data_0 = MyDataset(x=2, y=2)
data_tuple = astuple(data_0)
data_dict = asdict(data_0)
print(data_tuple)
print(data_dict)
```

Output:
```python
(2, 2)
{'x': 2, 'y': 2}
```

## dataclasses_json

If this third party package is missing:

```shell
pip install dataclasses-json
```

### JSON
```python
from dataclasses import dataclass, field
import dataclasses_json


@dataclasses_json.dataclass_json
@dataclass(frozen=True)
class TestClassA:
    name: str
    number_of_electrodes: int
    dt: float = field(init=False)
    sample_rate_in_hz: float = 1000.0

    def __post_init__(self) -> None:
        object.__setattr__(self, "dt", 1.0 / self.sample_rate_in_hz)


data_1 = TestClassA("Dataset A", 100, 500)
print(data_1)
print("")

print("as JSON:")
string_json = data_1.to_json()
print(string_json)

print("")

data_2 = TestClassA.from_json(string_json)
print(data_2)
```

Output:

```python
TestClassA(name='Dataset A', number_of_electrodes=100, dt=0.002, sample_rate_in_hz=500)

as JSON:
{"name": "Dataset A", "number_of_electrodes": 100, "dt": 0.002, "sample_rate_in_hz": 500}

TestClassA(name='Dataset A', number_of_electrodes=100, dt=0.002, sample_rate_in_hz=500)
```


### Dict

```python
from dataclasses import dataclass, field
import dataclasses_json


@dataclasses_json.dataclass_json
@dataclass(frozen=True)
class TestClassA:
    name: str
    number_of_electrodes: int
    dt: float = field(init=False)
    sample_rate_in_hz: float = 1000.0

    def __post_init__(self) -> None:
        object.__setattr__(self, "dt", 1.0 / self.sample_rate_in_hz)


data_1 = TestClassA("Dataset A", 100, 500)
print(data_1)
print("")

print("as dict:")
string_dict = data_1.to_dict()
print(string_dict)

print("")

data_2 = TestClassA.from_dict(string_dict)
print(data_2)
```

Output: 
```python
TestClassA(name='Dataset A', number_of_electrodes=100, dt=0.002, sample_rate_in_hz=500)

as dict:
{'name': 'Dataset A', 'number_of_electrodes': 100, 'dt': 0.002, 'sample_rate_in_hz': 500}

TestClassA(name='Dataset A', number_of_electrodes=100, dt=0.002, sample_rate_in_hz=500)
```

### Pickle (deals with numpy ndarray)

While JSON doesn't like numpy ndarrays, pickle has no problem with it. But we loose the human readability. An example:

```python
from dataclasses import dataclass
import numpy as np
import pickle


@dataclass
class TestClassA:
    name: str
    measured_data: np.ndarray


rng = np.random.default_rng()
data_1 = TestClassA(name="Recording X", measured_data=rng.random((3, 6)))
print(data_1)
print("")


print("as pickle string:")
string_pickle = pickle.dumps(data_1)
print(string_pickle)

print("")

data_2 = pickle.loads(string_pickle)
print(data_2)
```

Output
```python
TestClassA(name='Recording X', measured_data=array([[0.03041124, 0.90241323, 0.06146134, 0.0207697 , 0.03924572,
        0.62343829],
       [0.03930966, 0.34830424, 0.53869473, 0.76964259, 0.64897337,
        0.76441662],
       [0.40438748, 0.95079476, 0.44350839, 0.17806159, 0.31114876,
        0.59675174]]))

as pickle string:
b'\x80\x04\x95a\x01\x00\x00\x00\x00\x00\x00\x8c\x08__main__\x94\x8c\nTestClassA\x94\x93\x94)\x81\x94}\x94(\x8c\x04name\x94\x8c\x0bRecording X\x94\x8c\rmeasured_data\x94\x8c\x15numpy.core.multiarray\x94\x8c\x0c_reconstruct\x94\x93\x94\x8c\x05numpy\x94\x8c\x07ndarray\x94\x93\x94K\x00\x85\x94C\x01b\x94\x87\x94R\x94(K\x01K\x03K\x06\x86\x94h\x0b\x8c\x05dtype\x94\x93\x94\x8c\x02f8\x94\x89\x88\x87\x94R\x94(K\x03\x8c\x01<\x94NNNJ\xff\xff\xff\xffJ\xff\xff\xff\xffK\x00t\x94b\x89C\x90\xe0\xd1r\xb1\x1f$\x9f?\xbe\xa8\xb8\xb5\x91\xe0\xec?\xc0i\xf35\xdcw\xaf?\x00NT)\xa7D\x95?\xe0\xca\x9e\xdc\x03\x18\xa4?\xc0\x12&\xdb4\xf3\xe3?\xe0.\xd2Xe \xa4?\x16\xb4\xbc\xde\x9dJ\xd6?\x95\x00\x03\xbc\xfc<\xe1?5\xb3U\x80\xe9\xa0\xe8?-\r\x8d\xccc\xc4\xe4?4\x1e8\xd7\x19v\xe8?\\c\xb3\t|\xe1\xd9?\xcf\xaf\xbb#\xe9l\xee?R/5\x07qb\xdc?\xecr\xdd\xe3\xb8\xca\xc6?\x10\x12R~\xdc\xe9\xd3?\xcfz;\x1d\x97\x18\xe3?\x94t\x94bub.'

TestClassA(name='Recording X', measured_data=array([[0.03041124, 0.90241323, 0.06146134, 0.0207697 , 0.03924572,
        0.62343829],
       [0.03930966, 0.34830424, 0.53869473, 0.76964259, 0.64897337,
        0.76441662],
       [0.40438748, 0.95079476, 0.44350839, 0.17806159, 0.31114876,
        0.59675174]]))
```
