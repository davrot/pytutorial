# Organizing parameters -- dataclasses and [dataconf](https://github.com/zifeo/dataconf)
{:.no_toc}

<nav markdown="1" class="toc-class">
* TOC
{:toc}
</nav>

## The goal

In data science we have a lot of parameters in our simulations. Often the parameters are distributed over the whole source code. The combination of dataclass and dataconf allows it very easily to put the parameters in to a config file. dataconf supports many different config types. Among those are json and yaml.

Questions to [David Rotermund](mailto:davrot@uni-bremen.de)

```shell
pip install dataconf
```

## Defining the shape of the config

First we define the shape of our configuration data with data classes. We need to have one dataclass Config (or however you want to call it) which is the root of the config. 

The root contains variables but also can contain sub-dataclasses which can also contain variables and sub-sub-dataclasses... and so on... 

Here an example:  

```python
from dataclasses import dataclass

@dataclass
class Date:
    day: int
    month: int
    year: int

    hour: int
    minute: int
    second: int


@dataclass
class MetaData:
    channels: int
    scale: float
    name: str


@dataclass
class Config:
    id: int
    date: Date
    meta_data: MetaData
    events: list[int]
```

If you are not sure that all parameters are included in the config file then you can set the default values or default_factory with the field element in the dataclass. see [dataclass](https://davrot.github.io/pytutorial/python_basics/dataclass/) for details.

## The JSON config file

Here an example JSON file tailored for our dataclass Config:

```json
{
    "id": 1,
    "events": [
        1,
        2,
        3,
        4,
        5,
        6,
        7
    ],
    "date": {
        "day": 22,
        "month": 7,
        "year": 1983,
        "hour": 1,
        "minute": 37,
        "second": 12
    },
    "meta_data": {
        "channels": 5555,
        "scale": 0.00001,
        "name": "Experiment IV"
    }
}
```

## Loading in the config file

Now we can load the config file into memory:

```python
import dataconf

cfg = dataconf.file("config.json", Config)
print(cfg)
print("")
print(cfg.id)
print("")
print(cfg.meta_data.name)
```

Output:

```python
Config(id=1, date=Date(day=22, month=7, year=1983, hour=1, minute=37, second=12), meta_data=MetaData(channels=5555, scale=1e-05, name='Experiment IV'), events=[1, 2, 3, 4, 5, 6, 7])

1

Experiment IV
```

I have not tested the other properties of [dataconf](https://github.com/zifeo/dataconf).

It is told that it can also use config information from different sources:

```python
conf = dataconf.string('{ name: Test }', Config)
conf = dataconf.env('PREFIX_', Config)
conf = dataconf.dict({'name': 'Test'}, Config)
conf = dataconf.url('https://raw.githubusercontent.com/zifeo/dataconf/master/confs/test.hocon', Config)
conf = dataconf.file('confs/test.{hocon,json,yaml,properties}', Config)
```

and write the config from memory to a file (with dump) or string (with dumps)

```python
dataconf.dump('confs/test.hocon', conf, out='hocon')
dataconf.dump('confs/test.json', conf, out='json')
dataconf.dump('confs/test.yaml', conf, out='yaml')
dataconf.dump('confs/test.properties', conf, out='properties')
```

## Alternative: [Hydra](https://hydra.cc/)

If you need more features then you may want to look into [hydra](https://hydra.cc/): 

* Hierarchical configuration composable from multiple sources
* Configuration can be specified or overridden from the command line
* Dynamic command line tab completion
* **Run your application locally or launch it to run remotely**
* **Run multiple jobs with different arguments with a single command**

"Hydra is an open-source Python framework that simplifies the development of research and other complex applications. The key feature is the ability to dynamically create a hierarchical configuration by composition and override it through config files and the command line. The name Hydra comes from its ability to run multiple similar jobs - much like a Hydra with multiple heads."


