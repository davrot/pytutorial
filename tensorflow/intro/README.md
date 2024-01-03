# Tensorflow / Keras -- A fast non-introduction 
{:.no_toc}

<nav markdown="1" class="toc-class">
* TOC
{:toc}
</nav>

## Top

This is a fast overview how to get an MNIST example running under TF Keras 

If you just want to start with Tensorflow / Keras (especially if it is a scientific project), then you want to reconsider using Keras. In this case please check (& use) PyTorch. 

Questions to [David Rotermund](mailto:davrot@uni-bremen.de)


## Data loader / Data generator 

|||
|---|---|
| [keras.utils.Sequence](https://www.tensorflow.org/api_docs/python/tf/keras/utils/Sequence) | "Base object for fitting to a sequence of data, such as a dataset."|
| [tf.keras.utils.to_categorical](https://www.tensorflow.org/api_docs/python/tf/keras/utils/to_categorical) | "Converts a class vector (integers) to binary class matrix."|


## Basic

```python
from tensorflow import keras
import numpy as np


class DataGenerator(keras.utils.Sequence):
    def __init__(
        self,
        train: bool = True,
        size_of_batch: int = 32,
        number_of_classes: int = 10,
        do_shuffle: bool = True,
    ) -> None:
        super(DataGenerator, self).__init__()

        if train is True:
            self.pattern_storage: np.ndarray = np.load("./train_pattern_storage.npy")
            self.label_storage: np.ndarray = np.load("./train_label_storage.npy")
        else:
            self.pattern_storage = np.load("./test_pattern_storage.npy")
            self.label_storage = np.load("./test_label_storage.npy")

        self.pattern_storage = self.pattern_storage.astype(np.float32)
        self.pattern_storage /= np.max(self.pattern_storage)

        self.dimensions: tuple[int, int] = (
            self.pattern_storage.shape[1],
            self.pattern_storage.shape[2],
        )

        # How many pattern are there?
        self.number_of_pattern: int = self.label_storage.shape[0]

        self.size_of_batch: int = size_of_batch

        self.number_of_classes: int = number_of_classes
        self.do_shuffle: bool = do_shuffle

        if self.pattern_storage.ndim == 3:
            self.number_of_channel: int = 1
        else:
            self.number_of_channel = self.pattern_storage.shape[3]

        self.available_indices: np.ndarray = np.arange(self.number_of_pattern)

        self.on_epoch_end()

    def on_epoch_end(self) -> None:
        self.available_indices = np.arange(self.number_of_pattern)

        if self.do_shuffle is True:
            np.random.shuffle(self.available_indices)

    def __getitem__(self, index: int) -> tuple[np.ndarray, np.ndarray]:
        selected_indices: np.ndarray = self.available_indices[
            index * self.size_of_batch : (index + 1) * self.size_of_batch
        ]
        image, target = self.__data_generation(selected_indices)
        return image, target

    def __data_generation(
        self, list_of_indice: np.ndarray
    ) -> tuple[np.ndarray, np.ndarray]:
        image = np.empty(
            (self.size_of_batch, *self.dimensions, self.number_of_channel),
            dtype=np.float32,
        )
        target = np.empty((self.size_of_batch), dtype=int)

        for i in range(0, len(list_of_indice)):

            if self.pattern_storage.ndim == 3:
                image[i, :, :, 0] = self.pattern_storage[
                    self.available_indices[list_of_indice[i]], :, :
                ]
            else:
                image[i, :, :, :] = self.pattern_storage[
                    self.available_indices[list_of_indice[i]], :, :, :
                ]

            target[i] = self.label_storage[self.available_indices[list_of_indice[i]]]

        return image, keras.utils.to_categorical(
            target, num_classes=self.number_of_classes
        )

    def __len__(self):
        return int(np.floor(self.number_of_pattern / self.size_of_batch))


if __name__ == "__main__":
    pass
```

## With data augmentation

To the pre-processing chain **self.data_augmentation** you can add other preprocessing layers which are then applied to the input before given to the network.

```python
from tensorflow import keras
import numpy as np


class DataGenerator(keras.utils.Sequence):
    def __init__(
        self,
        train: bool = True,
        size_of_batch: int = 32,
        number_of_classes: int = 10,
        do_shuffle: bool = True,
    ) -> None:
        super(DataGenerator, self).__init__()

        if train is True:
            self.pattern_storage: np.ndarray = np.load("./train_pattern_storage.npy")
            self.label_storage: np.ndarray = np.load("./train_label_storage.npy")
        else:
            self.pattern_storage = np.load("./test_pattern_storage.npy")
            self.label_storage = np.load("./test_label_storage.npy")

        self.pattern_storage = self.pattern_storage.astype(np.float32)
        self.pattern_storage /= np.max(self.pattern_storage)

        self.dimensions: tuple[int, int] = (
            self.pattern_storage.shape[1],
            self.pattern_storage.shape[2],
        )
        reduction: tuple[int, int] = (4, 4)

        if train is True:
            self.data_augmentation = keras.Sequential(
                [
                    keras.layers.RandomCrop(
                        height=self.dimensions[0] - reduction[0],
                        width=self.dimensions[1] - reduction[1],
                    ),
                ]
            )
        else:
            self.data_augmentation = keras.Sequential(
                [
                    keras.layers.CenterCrop(
                        height=self.dimensions[0] - reduction[0],
                        width=self.dimensions[1] - reduction[1],
                    ),
                ]
            )

        # How many pattern are there?
        self.number_of_pattern: int = self.label_storage.shape[0]

        self.size_of_batch: int = size_of_batch

        self.number_of_classes: int = number_of_classes
        self.do_shuffle: bool = do_shuffle

        if self.pattern_storage.ndim == 3:
            self.number_of_channel: int = 1
        else:
            self.number_of_channel = self.pattern_storage.shape[3]

        self.available_indices: np.ndarray = np.arange(self.number_of_pattern)

        self.on_epoch_end()

    def on_epoch_end(self) -> None:
        self.available_indices = np.arange(self.number_of_pattern)

        if self.do_shuffle is True:
            np.random.shuffle(self.available_indices)

    def __getitem__(self, index: int) -> tuple[np.ndarray, np.ndarray]:
        selected_indices: np.ndarray = self.available_indices[
            index * self.size_of_batch : (index + 1) * self.size_of_batch
        ]
        image, target = self.__data_generation(selected_indices)
        return image, target

    def __data_generation(
        self, list_of_indice: np.ndarray
    ) -> tuple[np.ndarray, np.ndarray]:
        image = np.empty(
            (self.size_of_batch, *self.dimensions, self.number_of_channel),
            dtype=np.float32,
        )
        target = np.empty((self.size_of_batch), dtype=int)

        for i in range(0, len(list_of_indice)):

            if self.pattern_storage.ndim == 3:
                image[i, :, :, 0] = self.pattern_storage[
                    self.available_indices[list_of_indice[i]], :, :
                ]
            else:
                image[i, :, :, :] = self.pattern_storage[
                    self.available_indices[list_of_indice[i]], :, :, :
                ]

            target[i] = self.label_storage[self.available_indices[list_of_indice[i]]]

        image = self.data_augmentation(image)
        return image, keras.utils.to_categorical(
            target, num_classes=self.number_of_classes
        )

    def __len__(self):
        return int(np.floor(self.number_of_pattern / self.size_of_batch))


if __name__ == "__main__":
    pass
```

## Train an example MNIST network

|||
|---|---|
|[tf.keras.backend.clear_session](https://www.tensorflow.org/api_docs/python/tf/keras/backend/clear_session) | "Resets all state generated by Keras."|
|[tf.keras.Sequential](https://www.tensorflow.org/api_docs/python/tf/keras/Sequential) | "Sequential groups a linear stack of layers into a tf.keras.Model."|
|[network.add()](https://www.tensorflow.org/api_docs/python/tf/keras/Sequential#add) | "Adds a layer instance on top of the layer stack." |
|[tf.keras.layers.Conv2D](https://www.tensorflow.org/api_docs/python/tf/keras/layers/Conv2D) | "2D convolution layer (e.g. spatial convolution over images)."|
|[tf.keras.layers.MaxPool2D](https://www.tensorflow.org/api_docs/python/tf/keras/layers/MaxPooling2D) | "Max pooling operation for 2D spatial data."|
|[tf.keras.layers.Flatten](https://www.tensorflow.org/api_docs/python/tf/keras/layers/Flatten) | "Flattens the input. Does not affect the batch size."|
|[tf.keras.layers.Dense](https://www.tensorflow.org/api_docs/python/tf/keras/layers/Dense) | "Just your regular densely-connected NN layer."|
|[network.compile()](https://www.tensorflow.org/api_docs/python/tf/keras/Sequential#compile) | "Configures the model for training."|
|[tf.keras.metrics.categorical_crossentropy](https://www.tensorflow.org/api_docs/python/tf/keras/metrics/categorical_crossentropy) | "Computes the categorical crossentropy loss."|
|[tf.keras.optimizers.Adam](https://www.tensorflow.org/api_docs/python/tf/keras/optimizers/Adam) | "Optimizer that implements the Adam algorithm."|
|[network.fit() ](https://www.tensorflow.org/api_docs/python/tf/keras/Sequential#fit) | Trains the model for a fixed number of epochs (iterations on a dataset).|
|[network.summary()](https://www.tensorflow.org/api_docs/python/tf/keras/Sequential#summary) | "Prints a string summary of the network."|
|[network.save()](https://www.tensorflow.org/api_docs/python/tf/keras/Sequential#save) | "Saves the model to Tensorflow SavedModel or a single HDF5 file."|

Parameters for the layers: 

[padding](https://www.tensorflow.org/api_docs/python/tf/keras/layers/Conv1D): "One of "valid", "same" or "causal" (case-insensitive). "valid" means no padding. "same" results in padding with zeros evenly to the left/right or up/down of the input such that output has the same height/width dimension as the input. "causal" results in causal (dilated) convolutions, e.g. output[t] does not depend on input[t+1:]. "
[use_bias](https://www.tensorflow.org/api_docs/python/tf/keras/layers/Conv1D): "Boolean, whether the layer uses a bias vector."
[activation](https://www.tensorflow.org/api_docs/python/tf/keras/layers/Conv1D): "Activation function to use. If you don't specify anything, no activation is applied (see [keras.activations](https://www.tensorflow.org/api_docs/python/tf/keras/activations))."
[data_format](https://www.tensorflow.org/api_docs/python/tf/keras/layers/Conv1D): " A string, one of channels_last (default) or channels_first."

```python
from tensorflow import keras
from DataGenerator import DataGenerator

epoch_max: int = 50
number_of_classes: int = 10
size_of_batch_train: int = 100

train_data = DataGenerator(
    train=True,
    size_of_batch=size_of_batch_train,
    number_of_classes=number_of_classes,
    do_shuffle=True,
)

number_of_channels: int = train_data.number_of_channel
input_dimensions = train_data.dimensions
number_of_pattern_train = train_data.number_of_pattern

number_of_output_channels_conv1: int = 32
number_of_output_channels_conv2: int = 64
number_of_neurons_flatten1: int = 1024

kernel_size_conv1: tuple[int, int] = (5, 5)
kernel_size_pool1: tuple[int, int] = (2, 2)
kernel_size_conv2: tuple[int, int] = (5, 5)
kernel_size_pool2: tuple[int, int] = (2, 2)

stride_conv1: tuple[int, int] = (1, 1)
stride_pool1: tuple[int, int] = (2, 2)
stride_conv2: tuple[int, int] = (1, 1)
stride_pool2: tuple[int, int] = (2, 2)


keras.backend.clear_session()

network = keras.Sequential()

# Conv 1
network.add(
    keras.layers.Conv2D(
        number_of_output_channels_conv1,
        kernel_size=kernel_size_conv1,
        activation="relu",
        input_shape=(input_dimensions[0], input_dimensions[1], number_of_channels),
        padding="valid",
        strides=stride_conv1,
        data_format="channels_last",
        use_bias=True,
    )
)

# Pool 1
network.add(
    keras.layers.MaxPooling2D(
        pool_size=kernel_size_pool1,
        padding="valid",
        strides=stride_pool1,
        data_format="channels_last",
    )
)

# Conv 2
network.add(
    keras.layers.Conv2D(
        number_of_output_channels_conv2,
        kernel_size=kernel_size_conv2,
        activation="relu",
        padding="valid",
        strides=stride_conv2,
        data_format="channels_last",
        use_bias=True,
    )
)

# Pool 2
network.add(
    keras.layers.MaxPooling2D(
        pool_size=kernel_size_pool2,
        padding="valid",
        strides=stride_pool2,
        data_format="channels_last",
    )
)

# Flatten
network.add(keras.layers.Flatten(data_format="channels_last"))

# Full layer
network.add(
    keras.layers.Dense(number_of_neurons_flatten1, activation="relu", use_bias=True)
)

# Output layer
network.add(keras.layers.Dense(number_of_classes, activation="softmax"))

network.compile(
    loss=keras.losses.categorical_crossentropy,
    optimizer=keras.optimizers.Adam(),
    metrics=["accuracy"],
)

for epoch_id in range(0, epoch_max):
    print(f"Epoch: {epoch_id} of {epoch_max - 1}")
    network.fit(x=train_data)

    network.summary()
    network.save("Model_" + str(epoch_id) + ".h5")
```

## Test the example network performance



```python
```

