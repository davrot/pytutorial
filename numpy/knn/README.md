# K Nearest Neighbour
{:.no_toc}

<nav markdown="1" class="toc-class">
* TOC
{:toc}
</nav>

## Top

Questions to [David Rotermund](mailto:davrot@uni-bremen.de)

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

k: int = 3

data_train = np.load("data_train.npy")
data_test = np.load("data_test.npy")
label_train = np.load("label_train.npy")
label_test = np.load("label_test.npy")

prediction = np.zeros((data_test.shape[0]), dtype=np.int8)

for id in range(0, label_test.shape[0]):
    distance = ((data_train - data_test[id, :][np.newaxis, :]) ** 2).sum(axis=-1)

    recall = label_train[np.argsort(distance)[:k]]
    if (recall == -1).sum() > (recall == 1).sum():
        prediction[id] = -1
    else:
        prediction[id] = +1

performance = 100.0 * (prediction == label_test).sum() / prediction.shape[0]

print(f"Performance correct: {performance}%") # -> Performance correct: 95.1%
```


