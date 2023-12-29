# Numpy <-> JSON over Pandas
{:.no_toc}

<nav markdown="1" class="toc-class">
* TOC
{:toc}
</nav>

## The goal

Normally we can not use JSON with Numpy. However, if we use [Pandas](https://pandas.pydata.org/) as an intermediary then we can do it. 

Questions to [David Rotermund](mailto:davrot@uni-bremen.de)

**Note: Pandas can also be used for many other formats beside JSON.**

## Writing JSON [pandas.DataFrame.to_json](https://pandas.pydata.org/docs/reference/api/pandas.DataFrame.to_json.html#pandas-dataframe-to-json)

```python
DataFrame.to_json(path_or_buf=None, orient=None, date_format=None, double_precision=10, force_ascii=True, date_unit='ms', default_handler=None, lines=False, compression='infer', index=None, indent=None, storage_options=None, mode='w')[source]
```

> Convert the object to a JSON string.
> 
> Note NaN’s and None will be converted to null and datetime objects will be converted to UNIX timestamps.

```python
import numpy as np
import pandas as pd

rng = np.random.default_rng()

some_data = rng.random((11, 3))

df = pd.DataFrame(some_data)
# As file
filename = "mynumpydata.json"
df.to_json(filename, orient="index")

# As string
output = df.to_json(orient="index")
print(output)
```

Output (reformated):

```python
{
    "0": {
        "0": 0.3145859169,
        "1": 0.2517001569,
        "2": 0.6685086575
    },
    "1": {
        "0": 0.7324177066,
        "1": 0.6750562092,
        "2": 0.0086333192
    },
    "2": {
        "0": 0.7529914827,
        "1": 0.3597052352,
        "2": 0.2780062722
    },
    "3": {
        "0": 0.2847410336,
        "1": 0.5572451873,
        "2": 0.5591149362
    },
    "4": {
        "0": 0.4507115703,
        "1": 0.9623511422,
        "2": 0.7180796014
    },
    "5": {
        "0": 0.5406601852,
        "1": 0.9315847158,
        "2": 0.2456480951
    },
    "6": {
        "0": 0.3441382077,
        "1": 0.4714817658,
        "2": 0.1777388975
    },
    "7": {
        "0": 0.6994839505,
        "1": 0.6520935819,
        "2": 0.9870686976
    },
    "8": {
        "0": 0.187576403,
        "1": 0.7466669157,
        "2": 0.2952841542
    },
    "9": {
        "0": 0.9140410582,
        "1": 0.6828387334,
        "2": 0.165762789
    },
    "10": {
        "0": 0.644055269,
        "1": 0.6122094952,
        "2": 0.9695111468
    }
}
```

## Read JSON [pandas.read_json](https://pandas.pydata.org/docs/reference/api/pandas.read_json.html#pandas-read-json)

```python
pandas.read_json(path_or_buf, *, orient=None, typ='frame', dtype=None, convert_axes=None, convert_dates=True, keep_default_dates=True, precise_float=False, date_unit=None, encoding=None, encoding_errors='strict', lines=False, chunksize=None, compression='infer', nrows=None, storage_options=None, dtype_backend=_NoDefault.no_default, engine='ujson')[source]
```

> Convert a JSON string to pandas object.

```python
import numpy as np
import pandas as pd

filename = "mynumpydata.json"
df = pd.read_json(filename, orient="index")
output_np = df.to_numpy()
print(type(output_np)) # -> <class 'numpy.ndarray'>
print(output_np)
```

Output:

```python
[[0.31458592 0.25170016 0.66850866]
 [0.73241771 0.67505621 0.00863332]
 [0.75299148 0.35970524 0.27800627]
 [0.28474103 0.55724519 0.55911494]
 [0.45071157 0.96235114 0.7180796 ]
 [0.54066019 0.93158472 0.2456481 ]
 [0.34413821 0.47148177 0.1777389 ]
 [0.69948395 0.65209358 0.9870687 ]
 [0.1875764  0.74666692 0.29528415]
 [0.91404106 0.68283873 0.16576279]
 [0.64405527 0.6122095  0.96951115]]
```

