# Fisher Exact Test
{:.no_toc}

<nav markdown="1" class="toc-class">
* TOC
{:toc}
</nav>

## Top


Questions to [David Rotermund](mailto:davrot@uni-bremen.de)


## [scipy.stats.fisher_exact](https://docs.scipy.org/doc/scipy/reference/generated/scipy.stats.fisher_exact.html)

```python
scipy.stats.fisher_exact(table, alternative='two-sided')
```

> Perform a Fisher exact test on a 2x2 contingency table.
> 
> The null hypothesis is that the true odds ratio of the populations underlying the observations is one, and the observations were sampled from these populations under a condition: the marginals of the resulting table must equal those of the observed table. The statistic returned is the unconditional maximum likelihood estimate of the odds ratio, and the p-value is the probability under the null hypothesis of obtaining a table at least as extreme as the one that was actually observed. There are other possible choices of statistic and two-sided p-value definition associated with Fisher’s exact test; please see the Notes for more information.

> Parameters:
>
> **alternative** : {‘two-sided’, ‘less’, ‘greater’}, optional
> Defines the alternative hypothesis. The following options are available (default is ‘two-sided’):
> 
> * ‘two-sided’: the odds ratio of the underlying population is not one
> * ‘less’: the odds ratio of the underlying population is less than one
> * ‘greater’: the odds ratio of the underlying population is greater than one

> Returns:
> 
> **res** : SignificanceResult
> 
> An object containing attributes:
> 
> **statistic** : float
> 
> This is the prior odds ratio, not a posterior estimate.
> 
> **pvalue** : float
> 
> The probability under the null hypothesis of obtaining a table at least as extreme as the one that was actually observed.

The input table is [[a, b], [c, d]]. 

|||
|---|---|
|a| b |
|c|d|

Where $N_A = a + c$ for the elements in group A (performance values of network A with $N_A$ as number of test pattern) and $N_B = b + d$ for the elements in group B (performance values of network B with $N_B$ as number of test pattern). 

|||
|---|---|
|$N_A - c$| $N_B-d$ |
|c|d|


If network architectures are tested, typically, the same data set is used in both conditions and such $N = N_A = N_B$. 

|||
|---|---|
|$N - c$| $N - d$ |
|c|d|


## [Example](https://docs.scipy.org/doc/scipy/reference/generated/scipy.stats.fisher_exact.html)

||Group A|Group B|
|---|---|---|
|Yes| 7 | 17 |
|No| 15| 5|

This translates in to the table: [[7, 17], [15, 5]]


```python
from scipy.stats import fisher_exact

res = fisher_exact([[7, 17], [15, 5]], alternative="less")
print(res.statistic) # -> 0.13725490196078433
print(res.pvalue) # -> 0.0028841933752349743
```



