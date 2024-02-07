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

## Test and train data 

```python
import numpy as np

rng = np.random.default_rng(1)

a_x: np.ndarray = rng.normal(1.5, 1.0, size=(1000))[:, np.newaxis]
a_y: np.ndarray = rng.normal(3.0, 1.0, size=(1000))[:, np.newaxis]
data_train_0: np.ndarray = np.concatenate((a_x, a_y), axis=-1)
class_train_0: np.ndarray = np.full((data_train_0.shape[0],), -1)

a_x = rng.normal(1.5, 1.0, size=(1000))[:, np.newaxis]
a_y = rng.normal(3.0, 1.0, size=(1000))[:, np.newaxis]
data_test_0: np.ndarray = np.concatenate((a_x, a_y), axis=-1)
class_test_0: np.ndarray = np.full((data_test_0.shape[0],), -1)
del a_x
del a_y

a_x = rng.normal(0.0, 1.0, size=(1000))[:, np.newaxis]
a_y = rng.normal(0.0, 1.0, size=(1000))[:, np.newaxis]
data_train_1: np.ndarray = np.concatenate((a_x, a_y), axis=-1)
class_train_1: np.ndarray = np.full((data_train_0.shape[0],), +1)

a_x = rng.normal(0.0, 1.0, size=(1000))[:, np.newaxis]
a_y = rng.normal(0.0, 1.0, size=(1000))[:, np.newaxis]
data_test_1: np.ndarray = np.concatenate((a_x, a_y), axis=-1)
class_test_1: np.ndarray = np.full((data_test_0.shape[0],), +1)
del a_x
del a_y

data_train: np.ndarray = np.concatenate((data_train_0, data_train_1), axis=0)
data_test: np.ndarray = np.concatenate((data_test_0, data_test_1), axis=0)
label_train: np.ndarray = np.concatenate((class_train_0, class_train_1), axis=0)
label_test: np.ndarray = np.concatenate((class_test_0, class_test_1), axis=0)

np.save("data_train.npy", data_train)
np.save("data_test.npy", data_test)
np.save("label_train.npy", label_train)
np.save("label_test.npy", label_test)
```

## Train and test 

```python
import numpy as np
import sklearn.svm  # type:ignore

data_train = np.load("data_train.npy")
data_test = np.load("data_test.npy")
label_train = np.load("label_train.npy")
label_test = np.load("label_test.npy")

svm = sklearn.svm.SVC()

svm.fit(X=data_train, y=label_train)
prediction = svm.predict(X=data_test)

performance = 100.0 * (prediction == label_test).sum() / prediction.shape[0]

print(f"Performance correct: {performance}%") # -> Performance correct: 95.4%
```

Sometimes it is useful to scale the value range of the individual features to the same range: 

```pythonv
import numpy as np
import sklearn.svm  # type:ignore

data_train = np.load("data_train.npy")
data_test = np.load("data_test.npy")
label_train = np.load("label_train.npy")
label_test = np.load("label_test.npy")

svm = sklearn.svm.SVC()

min_value = data_train.min(axis=0, keepdims=True)
data_train -= min_value
data_test -= min_value

min_value = data_train.max(axis=0, keepdims=True)
data_train /= min_value
data_test /= min_value

svm.fit(X=data_train, y=label_train)
prediction = svm.predict(X=data_test)

performance = 100.0 * (prediction == label_test).sum() / prediction.shape[0]

print(f"Performance correct: {performance}%")
```
