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

More complex indexing and re-indexing is possible:​

```python
import pandas as pd

index_1 = pd.Series(["Food", "HappyPlace", "Favorite"])
data_1 = pd.Series(["Bambu", "Tree", "Sleep"], index=index_1)
print(data_1)
print()

index_2 = pd.Series(["Food", "ShoeSize", "Favorite"])
data_2 = pd.Series(data_1, index=index_2)

print(data_2)
```

Output:
```python
Food          Bambu
HappyPlace     Tree
Favorite      Sleep
dtype: object

Food        Bambu
ShoeSize      NaN
Favorite    Sleep
dtype: object
```

### [pandas.Series.iloc](https://pandas.pydata.org/docs/reference/api/pandas.Series.iloc.html)

```python
property Series.iloc
```

> Purely integer-location based indexing for selection by position.
> 
> .iloc[] is primarily integer position based (from 0 to length-1 of the axis), but may also be used with a boolean array.
> .iloc will raise IndexError if a requested indexer is out-of-bounds, except slice indexers which allow out-of-bounds indexing (this conforms with python/numpy slice semantics).
> * An integer, e.g. 5.
> * A list or array of integers, e.g. [4, 3, 0].
> * A slice object with ints, e.g. 1:7.
> * A boolean array.
> * A callable function with one argument (the calling Series or DataFrame) and that returns valid output for indexing (one of the above). This is useful in method chains, when you don’t have a reference to the calling object, but would like to base your selection on some value.
> * A tuple of row and column indexes. The tuple elements consist of one of the above inputs, e.g. (0, 1).

```python
import pandas as pd

index_1 = pd.Series(["Food", "HappyPlace", "Favorite"])
data_1 = pd.Series(["Bambu", "Tree", "Sleep"], index=index_1)
print(data_1.iloc[0])
print(data_1["Food"])
```

### Converting a dictionary

```python
import pandas as pd

data_1 = pd.Series({"A": 34, "B": 54, "C": "Blub"})
print(data_1)
```

Output:

```python
A      34
B      54
C    Blub
dtype: object
```



### Operations on Series

#### Example: Math on one series

```python
import pandas as pd
import numpy as np

index_1 = pd.Series(["A", "B", "C", "D", "E"])
rng = np.random.default_rng()
np_data = rng.random((5))
data_1 = pd.Series(np_data, index=index_1)

print(data_1)
print()
print(data_1 > 0.5)
print()
print(data_1[data_1 > 0.5])
print()
print(sum(data_1))
```

Output:
```python
A    0.772007
B    0.143811
C    0.524829
D    0.413733
E    0.100003
dtype: float64

A     True
B    False
C     True
D    False
E    False
dtype: bool

A    0.772007
C    0.524829
dtype: float64

1.9543834923707668
```

#### Example: Math with two series

```python
import pandas as pd
import numpy as np

index_1 = pd.Series(["A", "B", "C", "D", "E"])
rng = np.random.default_rng()
np_data_1 = rng.random((5))
data_1 = pd.Series(np_data_1, index=index_1)

index_2 = pd.Series(["D", "E", "F", "G", "H"])
rng = np.random.default_rng()
np_data_2 = rng.random((5))
data_2 = pd.Series(np_data_2, index=index_2)


print(data_1)
print()
print(data_2)
print()
print((data_1 + data_2))
print()
print((data_1 + data_2) * 3 + 10)
```

Output:
```python
A    0.702998
B    0.032210
C    0.534611
D    0.839864
E    0.118698
dtype: float64

D    0.321691
E    0.024475
F    0.168798
G    0.232925
H    0.782430
dtype: float64

A         NaN
B         NaN
C         NaN
D    1.161555
E    0.143173
F         NaN
G         NaN
H         NaN
dtype: float64

A          NaN
B          NaN
C          NaN
D    13.484666
E    10.429519
F          NaN
G          NaN
H          NaN
dtype: float64
```

#### Example: Applying functions ([pandas.Series.apply](https://pandas.pydata.org/docs/reference/api/pandas.Series.apply.html))

```python
Series.apply(func, convert_dtype=_NoDefault.no_default, args=(), *, by_row='compat', **kwargs)
```

> Invoke function on values of Series.
> 
> Can be ufunc (a NumPy function that applies to the entire Series) or a Python function that only works on single values.

```python
import pandas as pd
import numpy as np

index_1 = pd.Series(["A", "B", "C", "D", "E"])
rng = np.random.default_rng()
np_data_1 = rng.random((5))
data_1 = pd.Series(np_data_1, index=index_1)

print(data_1)
print()
print(data_1[["A", "D"]])
print()

data_2 = data_1.apply(np.log)
print(data_2)
print()

data_3 = data_1.apply(lambda x: x if x > 0.5 else 0)
print(data_3)
print()
```

Output:
```python
A    0.803968
B    0.234188
C    0.511411
D    0.858326
E    0.374570
dtype: float64

A    0.803968
D    0.858326
dtype: float64

A   -0.218195
B   -1.451633
C   -0.670581
D   -0.152771
E   -0.981978
dtype: float64

A    0.803968
B    0.000000
C    0.511411
D    0.858326
E    0.000000
dtype: float64
```

## [pandas.Series.isnull](https://pandas.pydata.org/docs/reference/api/pandas.Series.isnull.html) and [pandas.Series.notnull](https://pandas.pydata.org/docs/reference/api/pandas.Series.notnull.html)

**Note: A value set to NONE will lead to a NaN.​**

```python
Series.isnull()
```

> Series.isnull is an alias for Series.isna.
>
> Detect missing values.
>
> Return a boolean same-sized object indicating if the values are NA. NA values, such as None or numpy.NaN, gets mapped to True values. Everything else gets mapped to False values. Characters such as empty strings '' or numpy.inf are not considered NA values (unless you set pandas.options.mode.use_inf_as_na = True).

```python
Series.notnull()
```
> Series.notnull is an alias for Series.notna.
> 
> Detect existing (non-missing) values.
> 
> Return a boolean same-sized object indicating if the values are not NA. Non-missing values get mapped to True. Characters such as empty strings '' or numpy.inf are not considered NA values (unless you set pandas.options.mode.use_inf_as_na = True). NA values, such as None or numpy.NaN, get mapped to False values.


```python
import pandas as pd
import numpy as np

index_1 = pd.Series(["A", "B", "C", "D", "E"])
rng = np.random.default_rng()
np_data_1 = rng.random((5))
data_1 = pd.Series(np_data_1, index=index_1)

index_2 = pd.Series(["D", "E", "F", "G", "H"])
rng = np.random.default_rng()
np_data_2 = rng.random((5))
data_2 = pd.Series(np_data_2, index=index_2)

data_3 = data_1 + data_2

print(data_3)
print()
print(data_3.isnull())
print()
print(data_3[data_3.isnull()])
print()
print(data_3.notnull())
print()
print(data_3[data_3.notnull()])
```

Output 

```python
A         NaN
B         NaN
C         NaN
D    0.970744
E    0.425544
F         NaN
G         NaN
H         NaN
dtype: float64

A     True
B     True
C     True
D    False
E    False
F     True
G     True
H     True
dtype: bool

A   NaN
B   NaN
C   NaN
F   NaN
G   NaN
H   NaN
dtype: float64

A    False
B    False
C    False
D     True
E     True
F    False
G    False
H    False
dtype: bool

D    0.970744
E    0.425544
dtype: float64
```

### [pandas.Series.dropna](https://pandas.pydata.org/docs/reference/api/pandas.Series.dropna.html) or [pandas.Series.fillna](https://pandas.pydata.org/docs/reference/api/pandas.Series.fillna.html)

```python
Series.dropna(*, axis=0, inplace=False, how=None, ignore_index=False)
```

> Return a new Series with missing values removed.

```python
Series.fillna(value=None, *, method=None, axis=None, inplace=False, limit=None, downcast=_NoDefault.no_default)
```

> Fill NA/NaN values using the specified method.

```python
import pandas as pd
import numpy as np

index_1 = pd.Series(["A", "B", "C", "D", "E"])
rng = np.random.default_rng()
np_data_1 = rng.random((5))
data_1 = pd.Series(np_data_1, index=index_1)

index_2 = pd.Series(["D", "E", "F", "G", "H"])
rng = np.random.default_rng()
np_data_2 = rng.random((5))
data_2 = pd.Series(np_data_2, index=index_2)

data_3 = data_1 + data_2

print(data_3)
print()
print(data_3.dropna())
print()
print(data_3.fillna(0.0))  # 0.0 => Value for filling
print()
print()
print(data_3.fillna(3.3))  # 3.3 => Value for filling
print()
```

Output:
```python
A         NaN
B         NaN
C         NaN
D    0.660655
E    0.256244
F         NaN
G         NaN
H         NaN
dtype: float64

D    0.660655
E    0.256244
dtype: float64

A    0.000000
B    0.000000
C    0.000000
D    0.660655
E    0.256244
F    0.000000
G    0.000000
H    0.000000
dtype: float64


A    3.300000
B    3.300000
C    3.300000
D    0.660655
E    0.256244
F    3.300000
G    3.300000
H    3.300000
dtype: float64
```

### [pandas.concat](https://pandas.pydata.org/pandas-docs/stable/reference/api/pandas.concat.html) and [pandas.Series.sort_index](https://pandas.pydata.org/docs/reference/api/pandas.Series.sort_index.html) and [pandas.Series.sort_values](https://pandas.pydata.org/docs/reference/api/pandas.Series.sort_values.html)

```python
pandas.concat(objs, *, axis=0, join='outer', ignore_index=False, keys=None, levels=None, names=None, verify_integrity=False, sort=False, copy=None)
```

> Concatenate pandas objects along a particular axis.
> 
> Allows optional set logic along the other axes.
>
> Can also add a layer of hierarchical indexing on the concatenation axis, which may be useful if the labels are the same (or overlapping) on the passed axis number.

```python
Series.sort_index(*, axis=0, level=None, ascending=True, inplace=False, kind='quicksort', na_position='last', sort_remaining=True, ignore_index=False, key=None)
```

> Sort Series by index labels.
> 
> Returns a new Series sorted by label if inplace argument is False, otherwise updates the original series and returns None.

```python
Series.sort_values(*, axis=0, ascending=True, inplace=False, kind='quicksort', na_position='last', ignore_index=False, key=None)
```
> Sort by the values.
> 
> Sort a Series in ascending or descending order by some criterion.


```python
import pandas as pd
import numpy as np

index_1 = pd.Series(["A", "B", "C", "D", "E"])
rng = np.random.default_rng()
np_data_1 = rng.random((5))
data_1 = pd.Series(np_data_1, index=index_1)

index_2 = pd.Series(["D", "E", "F", "G", "H"])
rng = np.random.default_rng()
np_data_2 = rng.random((5))
data_2 = pd.Series(np_data_2, index=index_2)

data_3 = pd.concat([data_1, data_2])
print(data_3)
print()
print(data_3.sort_index())
print()
print(data_3.sort_values())
print()
```

Output:

```python
A    0.480872
B    0.830495
C    0.420633
D    0.824773
E    0.580569
D    0.224508
E    0.250787
F    0.056334
G    0.880224
H    0.552785
dtype: float64

A    0.480872
B    0.830495
C    0.420633
D    0.824773
D    0.224508
E    0.580569
E    0.250787
F    0.056334
G    0.880224
H    0.552785
dtype: float64

F    0.056334
D    0.224508
E    0.250787
C    0.420633
A    0.480872
H    0.552785
E    0.580569
D    0.824773
B    0.830495
G    0.880224
dtype: float64
```

## [DataFrame](https://pandas.pydata.org/pandas-docs/stable/reference/api/pandas.DataFrame.html#pandas.DataFrame)

```python
class pandas.DataFrame(data=None, index=None, columns=None, dtype=None, copy=None)
```

> Two-dimensional, size-mutable, potentially heterogeneous tabular data.
> 
> Data structure also contains labeled axes (rows and columns). Arithmetic operations align on both row and column labels. Can be thought of as a dict-like container for Series objects. The primary pandas data structure.


### Combining two series into one dataframe

```python
import pandas as pd
import numpy as np

index = pd.Series(["A", "B", "C", "D", "E"])

rng = np.random.default_rng()

np_data_1 = rng.random((5))
data_1 = pd.Series(np_data_1, index=index)

np_data_2 = rng.random((5))
data_2 = pd.Series(np_data_2, index=index)

data_3 = pd.concat([data_1, data_2], axis=1)

print(type(data_1))  # -> <class 'pandas.core.series.Series'>
print(type(data_2))  # -> <class 'pandas.core.series.Series'>
print(type(data_3))  # -> <class 'pandas.core.frame.DataFrame'>

print(data_3)
print()
print(data_3.columns)  # -> RangeIndex(start=0, stop=2, step=1)
print(data_3.columns.values)  # -> [0 1]
```

```python
          0         1
A  0.942032  0.213441
B  0.379446  0.937325
C  0.645035  0.799521
D  0.546175  0.656740
E  0.564155  0.546581
```

### Renaming the columns

```python
data_3.columns = ["Alpha", "Beta"]

print(data_3)
print()
print(data_3.columns) # -> Index(['Alpha', 'Beta'], dtype='object')
print()
print(data_3[ "Beta"])
```

Output:

```python
      Alpha      Beta
A  0.942032  0.213441
B  0.379446  0.937325
C  0.645035  0.799521
D  0.546175  0.656740
E  0.564155  0.546581

A    0.213441
B    0.937325
C    0.799521
D    0.656740
E    0.546581
Name: Beta, dtype: float64
```

## Saving (pandas.DataFrame.to_pickle) / loading (pandas.read_pickle) data ‘natively’​ 

Save: 

```python
import pandas as pd
original_df = pd.DataFrame(
    {"foo": range(5), "bar": range(5, 10)}
   )  
print(original_df)

pd.to_pickle(original_df, "./dummy.pkl")
```

Output:

```python
   foo  bar
0    0    5
1    1    6
2    2    7
3    3    8
4    4    9
```

Load: 

```python
import pandas as pd
unpickled_df = pd.read_pickle("./dummy.pkl")  
print(unpickled_df)
```

Output:

```python
   foo  bar
0    0    5
1    1    6
2    2    7
3    3    8
4    4    9
```

#### [read](https://pandas.pydata.org/pandas-docs/stable/reference/api/pandas.read_pickle.html#pandas.read_pickle)

```python
pandas.read_pickle(filepath_or_buffer, compression='infer', storage_options=None)
```

> Load pickled pandas object (or any object) from file.

#### [write](https://pandas.pydata.org/pandas-docs/stable/reference/api/pandas.DataFrame.to_pickle.html#pandas.DataFrame.to_pickle)

```python
DataFrame.to_pickle(path, compression='infer', protocol=5, storage_options=None)
```

> Pickle (serialize) object to file.

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

#### [read](https://pandas.pydata.org/pandas-docs/stable/reference/api/pandas.read_excel.html#pandas.read_excel)

```python
pandas.read_excel(io, sheet_name=0, *, header=0, names=None, index_col=None, usecols=None, dtype=None, engine=None, converters=None, true_values=None, false_values=None, skiprows=None, nrows=None, na_values=None, keep_default_na=True, na_filter=True, verbose=False, parse_dates=False, date_parser=_NoDefault.no_default, date_format=None, thousands=None, decimal='.', comment=None, skipfooter=0, storage_options=None, dtype_backend=_NoDefault.no_default, engine_kwargs=None)
```

> Read an Excel file into a pandas DataFrame.
> 
> Supports xls, xlsx, xlsm, xlsb, odf, ods and odt file extensions read from a local filesystem or URL. Supports an option to read a single sheet or a list of sheets.

#### [write](https://pandas.pydata.org/pandas-docs/stable/reference/api/pandas.DataFrame.to_excel.html#pandas.DataFrame.to_excel)

```python
DataFrame.to_excel(excel_writer, sheet_name='Sheet1', na_rep='', float_format=None, columns=None, header=True, index=True, index_label=None, startrow=0, startcol=0, engine=None, merge_cells=True, inf_rep='inf', freeze_panes=None, storage_options=None, engine_kwargs=None)
```

> Write object to an Excel sheet.
> 
> To write a single object to an Excel .xlsx file it is only necessary to specify a target file name. To write to multiple sheets it is necessary to create an ExcelWriter object with a target file name, and specify a sheet in the file to write to.
> 
> Multiple sheets may be written to by specifying unique sheet_name. With all data written to the file it is necessary to save the changes. Note that creating an ExcelWriter object with a file name that already exists will result in the contents of the existing file being erased.

### JSON

#### [read](https://pandas.pydata.org/pandas-docs/stable/reference/api/pandas.read_json.html#pandas.read_json)

```python
pandas.read_json(path_or_buf, *, orient=None, typ='frame', dtype=None, convert_axes=None, convert_dates=True, keep_default_dates=True, precise_float=False, date_unit=None, encoding=None, encoding_errors='strict', lines=False, chunksize=None, compression='infer', nrows=None, storage_options=None, dtype_backend=_NoDefault.no_default, engine='ujson')
```

> Convert a JSON string to pandas object.

#### [write](https://pandas.pydata.org/pandas-docs/stable/reference/api/pandas.DataFrame.to_json.html#pandas.DataFrame.to_json)

```python
DataFrame.to_json(path_or_buf=None, orient=None, date_format=None, double_precision=10, force_ascii=True, date_unit='ms', default_handler=None, lines=False, compression='infer', index=None, indent=None, storage_options=None, mode='w')
```

> Convert the object to a JSON string.
> 
> Note NaN’s and None will be converted to null and datetime objects will be converted to UNIX timestamps.






