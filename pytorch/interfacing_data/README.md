# Interfacing data
{:.no_toc}

<nav markdown="1" class="toc-class">
* TOC
{:toc}
</nav>

## The goal

We need to handle our data and make it accessible for PyTorch.

Questions to [David Rotermund](mailto:davrot@uni-bremen.de)

There are options to interface your data. 

## [torch.utils.data.TensorDataset](https://pytorch.org/docs/stable/data.html#torch.utils.data.TensorDataset)

```python
CLASS torch.utils.data.TensorDataset(*tensors)
```

> Dataset wrapping tensors.
> 
> Each sample will be retrieved by indexing tensors along the first dimension.
> 
> **\*tensors** : (Tensor) – tensors that have the same size of the first dimension.


## [torch.utils.data.Dataset](https://pytorch.org/docs/stable/data.html#torch.utils.data.Dataset)

In the case we might not be able to load the fully dataset into memory, the **torch.utils.data.Dataset** is very helpful. 

```python
CLASS torch.utils.data.Dataset(*args, **kwds)
```

> An abstract class representing a Dataset.
> 
> All datasets that represent a map from keys to data samples should subclass it. All subclasses should overwrite **\_\_getitem\_\_()**, supporting fetching a data sample for a given key. Subclasses could also optionally overwrite **\_\_len\_\_()**, which is expected to return the size of the dataset by many Sampler implementations and the default options of DataLoader. Subclasses could also optionally implement **\_\_getitems\_\_()**, for speedup batched samples loading. This method accepts list of indices of samples of batch and returns list of samples.


We need to create a new class which is derived from **torch.utils.data.Dataset**. We can do what every we want in this class as long as we service the functions
* **\_\_len\_\_()** :  gives us the number of pattern in the dataset
* **\_\_getitem\_\_(index)** :  gives us the information about ONE pattern at position index in the data set. In the following example, I return the image as 3d torch.Tensor and the corresponding class for that pattern (for which I use int). 

We have a lot of freedom for our own design. e.g.:
* The argument **train:bool** of the contructor was introduced by me. 
* The **\_\_getitem\_\_(index)** doesn't need to give back the data for that pattern in exactly this way (means: order of variables, types of variables, number of variables). 

We assume that the data is in the four following files: 
* train_pattern_storage.npy
* train_label_storage.npy
* test_pattern_storage.npy
* test_label_storage.npy
  

```python
import numpy as np
import torch


class MyDataset(torch.utils.data.Dataset):

    # Initialize
    def __init__(self, train: bool = False) -> None:
        super(MyDataset, self).__init__()

        if train is True:
            self.pattern_storage: np.ndarray = np.load("train_pattern_storage.npy")
            self.label_storage: np.ndarray = np.load("train_label_storage.npy")
        else:
            self.pattern_storage = np.load("test_pattern_storage.npy")
            self.label_storage = np.load("test_label_storage.npy")

        self.pattern_storage = self.pattern_storage.astype(np.float32)
        self.pattern_storage /= np.max(self.pattern_storage)

        # How many pattern are there?
        self.number_of_pattern: int = self.label_storage.shape[0]

    def __len__(self) -> int:
        return self.number_of_pattern

    # Get one pattern at position index
    def __getitem__(self, index: int) -> tuple[torch.Tensor, int]:

        image = torch.tensor(self.pattern_storage[index, np.newaxis, :, :])
        target = int(self.label_storage[index])

        return image, target


if __name__ == "__main__":
    pass

```
