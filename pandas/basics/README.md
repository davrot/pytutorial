# [Pandas](https://pandas.pydata.org/)
{:.no_toc}

<nav markdown="1" class="toc-class">
* TOC
{:toc}
</nav>

## The goal



Questions to [David Rotermund](mailto:davrot@uni-bremen.de)

```shell
pip install pandas
```

## [Pandas](https://pandas.pydata.org/)


The two most important data types of Pandas are:​
* Series​
* Data Frames

> “Pandas is a fast, powerful, flexible and easy to use open source data analysis and manipulation tool, built on top of the Python programming language.”​

It is the basis for:
* [scipy.stats​](https://docs.scipy.org/doc/scipy/reference/stats.html)
> This module contains a large number of probability distributions, summary and frequency statistics, correlation functions and statistical tests, masked statistics, kernel density estimation, quasi-Monte Carlo functionality, and more. 
* [Pingouin](https://pingouin-stats.org/build/html/index.html)
> Pingouin is an open-source statistical package written in Python 3 and based mostly on Pandas and NumPy. 
* [rPy2](https://rpy2.github.io/)
> rpy2 is an interface to R running embedded in a Python process.

## [Pandas.Series​](https://pandas.pydata.org/pandas-docs/stable/reference/api/pandas.Series.html#pandas-series)

```python
class pandas.Series(data=None, index=None, dtype=None, name=None, copy=None, fastpath=False)
```

> One-dimensional ndarray with axis labels (including time series).
>
> Labels need not be unique but must be a hashable type. The object supports both integer- and label-based indexing and provides a host of methods for performing operations involving the index. Statistical methods from ndarray have been overridden to automatically exclude missing data (currently represented as NaN).
> 
> Operations between Series (+, -, /, *, **) align values based on their associated index values– they need not be the same length. The result index will be the sorted union of the two indexes.

Example 1:

```python
import pandas as pd

example = pd.Series(["Bambu", "Tree", "Sleep"])
print(example)
```

Output:

```python
0    Bambu
1     Tree
2    Sleep
dtype: object
```
Example 2:

```python
import numpy as np
import pandas as pd

example = pd.Series([99, 88, 32])
print(example)
```

Output:

```python
0    99
1    88
2    32
dtype: int64
```
Example 3:

```python
import numpy as np
import pandas as pd

rng = np.random.default_rng()
a = rng.random((5))

example = pd.Series(a)
print(example)
```

Output:

```python
0    0.305920
1    0.633360
2    0.219094
3    0.005722
4    0.006673
dtype: float64
```

Example 4:

```python
import pandas as pd

example = pd.Series(["Bambu", 3, "Sleep"])
print(example)
```

Output:

```python
0    Bambu
1        3
2    Sleep
dtype: object
```

### index and values

```python
import pandas as pd

example = pd.Series(["Bambu", "Tree", "Sleep"])
print(example.index)
print()
print(example.values)
```

Output: 

```python
RangeIndex(start=0, stop=3, step=1)

['Bambu' 'Tree' 'Sleep']
```

## [DataFrame](https://pandas.pydata.org/pandas-docs/stable/reference/api/pandas.DataFrame.html#pandas.DataFrame)

```python
class pandas.DataFrame(data=None, index=None, columns=None, dtype=None, copy=None)
```

> Two-dimensional, size-mutable, potentially heterogeneous tabular data.
> 
> Data structure also contains labeled axes (rows and columns). Arithmetic operations align on both row and column labels. Can be thought of as a dict-like container for Series objects. The primary pandas data structure.


## [pandas.concat](https://pandas.pydata.org/pandas-docs/stable/reference/api/pandas.concat.html)

```python
pandas.concat(objs, *, axis=0, join='outer', ignore_index=False, keys=None, levels=None, names=None, verify_integrity=False, sort=False, copy=None)
```

> Concatenate pandas objects along a particular axis.
> 
> Allows optional set logic along the other axes.
>
> Can also add a layer of hierarchical indexing on the concatenation axis, which may be useful if the labels are the same (or overlapping) on the passed axis number.



## [I/O operations​](https://pandas.pydata.org/pandas-docs/stable/reference/io.html#input-output)

||
|---|
|[Pickling](https://pandas.pydata.org/pandas-docs/stable/reference/io.html#pickling)|
|[Flat file](https://pandas.pydata.org/pandas-docs/stable/reference/io.html#flat-file)|
|[Clipboard](https://pandas.pydata.org/pandas-docs/stable/reference/io.html#clipboard)|
|[Excel](https://pandas.pydata.org/pandas-docs/stable/reference/io.html#excel)|
|[JSON](https://pandas.pydata.org/pandas-docs/stable/reference/io.html#json)|
|[HTML](https://pandas.pydata.org/pandas-docs/stable/reference/io.html#html)|
|[XML](https://pandas.pydata.org/pandas-docs/stable/reference/io.html#xml)|
|[Latex](https://pandas.pydata.org/pandas-docs/stable/reference/io.html#latex)|
|[HDFStore: PyTables (HDF5)](https://pandas.pydata.org/pandas-docs/stable/reference/io.html#hdfstore-pytables-hdf5)|
|[Feather](https://pandas.pydata.org/pandas-docs/stable/reference/io.html#feather)|
|[Parquet](https://pandas.pydata.org/pandas-docs/stable/reference/io.html#parquet)|
|[ORC](https://pandas.pydata.org/pandas-docs/stable/reference/io.html#orc)|
|[SAS](https://pandas.pydata.org/pandas-docs/stable/reference/io.html#sas)|
|[SPSS](https://pandas.pydata.org/pandas-docs/stable/reference/io.html#spss)|
|[SQL](https://pandas.pydata.org/pandas-docs/stable/reference/io.html#sql)|
|[Google BigQuery](https://pandas.pydata.org/pandas-docs/stable/reference/io.html#google-bigquery)|
|[STATA](https://pandas.pydata.org/pandas-docs/stable/reference/io.html#stata)|


### csv (“comma” separated values file)​

#### [read](https://pandas.pydata.org/pandas-docs/stable/reference/api/pandas.read_csv.html#pandas.read_csv)

```python
pandas.read_csv(filepath_or_buffer, *, sep=_NoDefault.no_default, delimiter=None, header='infer', names=_NoDefault.no_default, index_col=None, usecols=None, dtype=None, engine=None, converters=None, true_values=None, false_values=None, skipinitialspace=False, skiprows=None, skipfooter=0, nrows=None, na_values=None, keep_default_na=True, na_filter=True, verbose=False, skip_blank_lines=True, parse_dates=None, infer_datetime_format=_NoDefault.no_default, keep_date_col=False, date_parser=_NoDefault.no_default, date_format=None, dayfirst=False, cache_dates=True, iterator=False, chunksize=None, compression='infer', thousands=None, decimal='.', lineterminator=None, quotechar='"', quoting=0, doublequote=True, escapechar=None, comment=None, encoding=None, encoding_errors='strict', dialect=None, on_bad_lines='error', delim_whitespace=False, low_memory=True, memory_map=False, float_precision=None, storage_options=None, dtype_backend=_NoDefault.no_default)
```
> Read a comma-separated values (csv) file into DataFrame.

#### [write](https://pandas.pydata.org/pandas-docs/stable/reference/api/pandas.read_csv.html#pandas.read_csv)

```python
DataFrame.to_csv(path_or_buf=None, sep=',', na_rep='', float_format=None, columns=None, header=True, index=True, index_label=None, mode='w', encoding=None, compression='infer', quoting=None, quotechar='"', lineterminator=None, chunksize=None, date_format=None, doublequote=True, escapechar=None, decimal='.', errors='strict', storage_options=None)
```

> Write object to a comma-separated values (csv) file.

### Excel​

## JSON
