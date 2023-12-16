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

