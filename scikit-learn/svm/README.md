# Supprt Vector Machine
{:.no_toc}

<nav markdown="1" class="toc-class">
* TOC
{:toc}
</nav>

## Top

Questions to [David Rotermund](mailto:davrot@uni-bremen.de)


## [sklearn.svm.SVC](https://scikit-learn.org/stable/modules/generated/sklearn.svm.SVC.html)

```python
sklearn.svm.SVC(*, C=1.0, kernel='rbf', degree=3, gamma='scale', coef0=0.0, shrinking=True, probability=False, tol=0.001, cache_size=200, class_weight=None, verbose=False, max_iter=-1, decision_function_shape='ovr', break_ties=False, random_state=None)
```

> **kernel** : {‘linear’, ‘poly’, ‘rbf’, ‘sigmoid’, ‘precomputed’} or callable, default=’rbf’
> 
> Specifies the kernel type to be used in the algorithm. If none is given, ‘rbf’ will be used. If a callable is given it is used to pre-compute the kernel matrix from data matrices; that matrix should be an array of shape (n_samples, n_samples).

### [fit](https://scikit-learn.org/stable/modules/generated/sklearn.svm.SVC.html#sklearn.svm.SVC.fit)

```python
fit(X, y, sample_weight=None)
```

> Fit the SVM model according to the given training data.
>
> **X** : {array-like, sparse matrix} of shape (n_samples, n_features) or (n_samples, n_samples)
> 
> Training vectors, where n_samples is the number of samples and n_features is the number of features. For kernel=”precomputed”, the expected shape of X is (n_samples, n_samples).
>
> **y** : array-like of shape (n_samples,)
> 
> Target values (class labels in classification, real numbers in regression).

### [predict](https://scikit-learn.org/stable/modules/generated/sklearn.svm.SVC.html#sklearn.svm.SVC.predict)

```python
predict(X)
```
> For an one-class model, +1 or -1 is returned.
>
> Parameters:
> 
> **X** : {array-like, sparse matrix} of shape (n_samples, n_features) or (n_samples_test, n_samples_train)
>
> Returns:
> 
> **y_pred** : ndarray of shape (n_samples,)
> 
> Class labels for samples in X.

```python
```


```shell
```
