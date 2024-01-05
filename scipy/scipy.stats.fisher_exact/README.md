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


> **alternative** : {‘two-sided’, ‘less’, ‘greater’}, optional
> Defines the alternative hypothesis. The following options are available (default is ‘two-sided’):
> 
> * ‘two-sided’: the odds ratio of the underlying population is not one
> * ‘less’: the odds ratio of the underlying population is less than one
> * ‘greater’: the odds ratio of the underlying population is greater than one

See the Notes for more details.
