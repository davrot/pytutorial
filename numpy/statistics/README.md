# [Statistics](https://numpy.org/doc/stable/reference/routines.statistics.html#statistics)
{:.no_toc}

<nav markdown="1" class="toc-class">
* TOC
{:toc}
</nav>

## The goal

There are other (more extensive) statistics packages like​
* [scipy.stats​](https://docs.scipy.org/doc/scipy/reference/stats.html)
* [pingouin](https://pingouin-stats.org/build/html/index.html)
* [statsmodels](https://www.statsmodels.org/stable/index.html)
  

Questions to [David Rotermund](mailto:davrot@uni-bremen.de)

## [Fisher Exact Test](https://docs.scipy.org/doc/scipy/reference/generated/scipy.stats.fisher_exact.html#scipy.stats.fisher_exact)

The [Fisher Exact Test](https://docs.scipy.org/doc/scipy/reference/generated/scipy.stats.fisher_exact.html#scipy.stats.fisher_exact) is not part of the numpy package. But we need it in machine learning. 

```python
scipy.stats.fisher_exact(table, alternative='two-sided')
```

> Perform a Fisher exact test on a 2x2 contingency table.


## [Order statistics](https://numpy.org/doc/stable/reference/routines.statistics.html#order-statistics)

|||
|---|---|
|[ptp](https://numpy.org/doc/stable/reference/generated/numpy.ptp.html#numpy.ptp)(a[, axis, out, keepdims]) |Range of values (maximum - minimum) along an axis.|
|[percentile](https://numpy.org/doc/stable/reference/generated/numpy.percentile.html#numpy.percentile)(a, q[, axis, out, ...]) |Compute the q-th percentile of the data along the specified axis.|
|[nanpercentile](https://numpy.org/doc/stable/reference/generated/numpy.nanpercentile.html#numpy.nanpercentile)(a, q[, axis, out, ...]) |Compute the qth percentile of the data along the specified axis, while ignoring nan values.|
|[quantile](https://numpy.org/doc/stable/reference/generated/numpy.quantile.html#numpy.quantile)(a, q[, axis, out, overwrite_input, ...]) |Compute the q-th quantile of the data along the specified axis.|
|[nanquantile](https://numpy.org/doc/stable/reference/generated/numpy.nanquantile.html#numpy.nanquantile)(a, q[, axis, out, ...]) |Compute the qth quantile of the data along the specified axis, while ignoring nan values.|

## [Averages and variances](https://numpy.org/doc/stable/reference/routines.statistics.html#averages-and-variances)

|||
|---|---|
|[median](https://numpy.org/doc/stable/reference/generated/numpy.median.html#numpy.median)(a[, axis, out, overwrite_input, keepdims])|Compute the median along the specified axis.|
|[average](https://numpy.org/doc/stable/reference/generated/numpy.average.html#numpy.average)(a[, axis, weights, returned, keepdims])|Compute the weighted average along the specified axis.|
|[mean](https://numpy.org/doc/stable/reference/generated/numpy.mean.html#numpy.mean)(a[, axis, dtype, out, keepdims, where])|Compute the arithmetic mean along the specified axis.|
|[std](https://numpy.org/doc/stable/reference/generated/numpy.std.html#numpy.std)(a[, axis, dtype, out, ddof, keepdims, where])|Compute the standard deviation along the specified axis.|
|[var](https://numpy.org/doc/stable/reference/generated/numpy.var.html#numpy.var)(a[, axis, dtype, out, ddof, keepdims, where])|Compute the variance along the specified axis.|
|[nanmedian](https://numpy.org/doc/stable/reference/generated/numpy.nanmedian.html#numpy.nanmedian)(a[, axis, out, overwrite_input, ...])|Compute the median along the specified axis, while ignoring NaNs.|
|[nanmean](https://numpy.org/doc/stable/reference/generated/numpy.nanmean.html#numpy.nanmean)(a[, axis, dtype, out, keepdims, where])|Compute the arithmetic mean along the specified axis, ignoring NaNs.|
|[nanstd](https://numpy.org/doc/stable/reference/generated/numpy.nanstd.html#numpy.nanstd)(a[, axis, dtype, out, ddof, ...])|Compute the standard deviation along the specified axis, while ignoring NaNs.|
|[nanvar](https://numpy.org/doc/stable/reference/generated/numpy.nanvar.html#numpy.nanvar)(a[, axis, dtype, out, ddof, ...]) |Compute the variance along the specified axis, while ignoring NaNs.|

## [Correlating](https://numpy.org/doc/stable/reference/routines.statistics.html#correlating)

|||
|---|---|
|[corrcoef](https://numpy.org/doc/stable/reference/generated/numpy.corrcoef.html#numpy.corrcoef)(x[, y, rowvar, bias, ddof, dtype])|Return Pearson product-moment correlation coefficients.|
|[correlate](https://numpy.org/doc/stable/reference/generated/numpy.correlate.html#numpy.correlate)(a, v[, mode])|Cross-correlation of two 1-dimensional sequences.|
|[cov](https://numpy.org/doc/stable/reference/generated/numpy.cov.html#numpy.cov)(m[, y, rowvar, bias, ddof, fweights, ...])|Estimate a covariance matrix, given data and weights.|

## [Histograms](https://numpy.org/doc/stable/reference/routines.statistics.html#histograms)

|||
|---|---|
|[histogram](https://numpy.org/doc/stable/reference/generated/numpy.histogram.html#numpy.histogram)(a[, bins, range, density, weights])|Compute the histogram of a dataset.|
|[histogram2d](https://numpy.org/doc/stable/reference/generated/numpy.histogram2d.html#numpy.histogram2d)(x, y[, bins, range, density, ...])|Compute the bi-dimensional histogram of two data samples.|
|[histogramdd](https://numpy.org/doc/stable/reference/generated/numpy.histogramdd.html#numpy.histogramdd)(sample[, bins, range, density, ...])|Compute the multidimensional histogram of some data.|
|[bincount](https://numpy.org/doc/stable/reference/generated/numpy.bincount.html#numpy.bincount)(x, /[, weights, minlength])|Count number of occurrences of each value in array of non-negative ints.|
|[histogram_bin_edges](https://numpy.org/doc/stable/reference/generated/numpy.histogram_bin_edges.html#numpy.histogram_bin_edges)(a[, bins, range, weights])|Function to calculate only the edges of the bins used by the histogram function.|
|[digitize](https://numpy.org/doc/stable/reference/generated/numpy.digitize.html#numpy.digitize)(x, bins[, right])|Return the indices of the bins to which each value in input array belongs.|
