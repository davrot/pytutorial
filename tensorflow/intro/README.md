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

[DataGenerator_no_dataugmentation.py](DataGenerator_no_dataugmentation.py)

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

[DataGenerator.py](DataGenerator.py)

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

|||
|---|---|
|[padding](https://www.tensorflow.org/api_docs/python/tf/keras/layers/Conv1D) | "One of "valid", "same" or "causal" (case-insensitive). "valid" means no padding. "same" results in padding with zeros evenly to the left/right or up/down of the input such that output has the same height/width dimension as the input. "causal" results in causal (dilated) convolutions, e.g. output[t] does not depend on input[t+1:]. "|
|[use_bias](https://www.tensorflow.org/api_docs/python/tf/keras/layers/Conv1D)| "Boolean, whether the layer uses a bias vector."|
|[activation](https://www.tensorflow.org/api_docs/python/tf/keras/layers/Conv1D)| "Activation function to use. If you don't specify anything, no activation is applied (see [keras.activations](https://www.tensorflow.org/api_docs/python/tf/keras/activations))."|
[data_format](https://www.tensorflow.org/api_docs/python/tf/keras/layers/Conv1D)| " A string, one of channels_last (default) or channels_first."|

[keras_learn.py](keras_learn.py)

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

|||
|---|---|
|[tf.keras.models.load_model](https://www.tensorflow.org/api_docs/python/tf/keras/saving/load_model) | "Loads a model saved via model.save()."|
|[network.evaluate()](https://www.tensorflow.org/api_docs/python/tf/keras/Sequential#evaluate) | "Returns the loss value & metrics values for the model in test mode."|

[keras_test.py](keras_test.py)

```python
from tensorflow import keras
from DataGenerator import DataGenerator

number_of_classes: int = 10
size_of_batch_test: int = 100
model_id: int = 49

test_data = DataGenerator(
    train=False,
    size_of_batch=size_of_batch_test,
    number_of_classes=number_of_classes,
    do_shuffle=False,
)

keras.backend.clear_session()

network = keras.models.load_model("./Model_" + str(model_id) + ".h5")

test_loss, test_acc = network.evaluate(x=test_data)

print(f"Correct: {test_acc * 100.0:.2f}%")
```
## How to extract the activities from the network

```python
from tensorflow import keras
from DataGenerator import DataGenerator
import numpy as np

number_of_classes: int = 10
size_of_batch_test: int = 100
model_id: int = 49
pattern_batch_id: int = 0
pattern_id: int = 42

test_data = DataGenerator(
    train=False,
    size_of_batch=size_of_batch_test,
    number_of_classes=number_of_classes,
    do_shuffle=False,
)

keras.backend.clear_session()

network = keras.models.load_model("./Model_" + str(model_id) + ".h5")

image, target = test_data.__getitem__(pattern_batch_id)
the_target = target[pattern_id]

print("Layer 1 (Conv1)")
input_0 = image[pattern_id : pattern_id + 1, :, :, :]
output_0 = network.layers[0](input_0)

print("Input Shape:")
print(input_0.shape)
print("Output Shape:")
print(output_0.numpy().shape)
print("")

print("Layer 2 (Pool1)")
input_1 = output_0
output_1 = network.layers[1](input_1)

print("Input Shape:")
print(input_1.numpy().shape)
print("Output Shape:")
print(output_1.numpy().shape)
print("")

print("Layer 3 (Conv2)")
input_2 = output_1
output_2 = network.layers[2](input_2)

print("Input Shape:")
print(input_2.numpy().shape)
print("Output Shape:")
print(output_2.numpy().shape)
print("")

print("Layer 4 (Pool2)")
input_3 = output_2
output_3 = network.layers[3](input_3)

print("Input Shape:")
print(input_3.numpy().shape)
print("Output Shape:")
print(output_3.numpy().shape)
print("")

print("Layer 5 (Flatten)")
input_4 = output_3
output_4 = network.layers[4](input_4)

print("Input Shape:")
print(input_4.numpy().shape)
print("Output Shape:")
print(output_4.numpy().shape)
print("")

print("Layer 6 (Full)")
input_5 = output_4
output_5 = network.layers[5](input_5)

print("Input Shape:")
print(input_5.numpy().shape)
print("Output Shape:")
print(output_5.numpy().shape)
print("")

print("Layer 7 (Output)")
input_6 = output_5
output_6 = network.layers[6](input_6)

print("Input Shape:")
print(input_6.numpy().shape)
print("Output Shape:")
print(output_6.numpy().shape)
print("")

print("\nEstimation")
print(np.round(output_6.numpy(), 4))
print("Strongest reponse is at " + str(np.argmax(output_6.numpy())))
print("Correct output is " + str(np.argmax(the_target)))
```

## Extracting weight and bias

Here is one way to extract the weights and bias of the whole network. Alternatively you can use [get_weights](https://www.tensorflow.org/api_docs/python/tf/keras/layers/Layer#get_weights) from [tf.keras.layers.Layer](https://www.tensorflow.org/api_docs/python/tf/keras/layers/Layer) in combination with [get_layer](https://www.tensorflow.org/api_docs/python/tf/keras/Sequential#get_layer) of [tf.keras.Sequential](https://www.tensorflow.org/api_docs/python/tf/keras/Sequential).

```python
from tensorflow import keras
from DataGenerator import DataGenerator

number_of_classes: int = 10
size_of_batch_test: int = 100
model_id: int = 49
pattern_batch_id: int = 0
pattern_id: int = 42

test_data = DataGenerator(
    train=False,
    size_of_batch=size_of_batch_test,
    number_of_classes=number_of_classes,
    do_shuffle=False,
)

keras.backend.clear_session()

network = keras.models.load_model("./Model_" + str(model_id) + ".h5")

weights_bias = network.get_weights()

counter_layer: int = 0
for i in range(0, len(weights_bias), 2):
    print("Layer " + str(counter_layer) + " weights_bias position: " + str(i) + " =>")
    print(weights_bias[i].shape)
    counter_layer += 1

print("")

counter_layer = 0
for i in range(1, len(weights_bias), 2):
    print("Bias " + str(counter_layer) + " weights_bias position: " + str(i) + " =>")
    print(weights_bias[i].shape)
    counter_layer += 1
```

## [Type of layers](https://www.tensorflow.org/api_docs/python/tf/keras/layers#classes_2)

Reduced list with the most relevant network layers

|||
|---|---|
|[Activation](https://www.tensorflow.org/api_docs/python/tf/keras/layers/Activation)|	Applies an activation function to an output.|
|[AveragePooling1D](https://www.tensorflow.org/api_docs/python/tf/keras/layers/AveragePooling1D)|	Average pooling for temporal data.|
|[AveragePooling2D](https://www.tensorflow.org/api_docs/python/tf/keras/layers/AveragePooling2D)|	Average pooling operation for spatial data.|
|[AveragePooling3D](https://www.tensorflow.org/api_docs/python/tf/keras/layers/AveragePooling3D)	|Average pooling operation for 3D data (spatial or spatio-temporal).|
|[BatchNormalization](https://www.tensorflow.org/api_docs/python/tf/keras/layers/BatchNormalization)|	Layer that normalizes its inputs.|
|[Conv1D](https://www.tensorflow.org/api_docs/python/tf/keras/layers/Conv1D)|	1D convolution layer (e.g. temporal convolution).|
|[Conv2D](https://www.tensorflow.org/api_docs/python/tf/keras/layers/Conv2D)	|2D convolution layer (e.g. spatial convolution over images).|
|[Conv3D](https://www.tensorflow.org/api_docs/python/tf/keras/layers/Conv3D)|	3D convolution layer (e.g. spatial convolution over volumes).|
|[Dense](https://www.tensorflow.org/api_docs/python/tf/keras/layers/Dense)|	Just your regular densely-connected NN layer.|
|[Dropout](https://www.tensorflow.org/api_docs/python/tf/keras/layers/Dropout)	|Applies Dropout to the input.|
|[Flatten](https://www.tensorflow.org/api_docs/python/tf/keras/layers/Flatten)	|Flattens the input. Does not affect the batch size.|
|[MaxPooling1D](https://www.tensorflow.org/api_docs/python/tf/keras/layers/MaxPooling1D)|	Max pooling operation for 1D temporal data.|
|[MaxPooling2D](https://www.tensorflow.org/api_docs/python/tf/keras/layers/MaxPooling2D)	|Max pooling operation for 2D spatial data.|
|[MaxPooling3D](https://www.tensorflow.org/api_docs/python/tf/keras/layers/MaxPooling3D)	|Max pooling operation for 3D data (spatial or spatio-temporal).|
|[SpatialDropout1D](https://www.tensorflow.org/api_docs/python/tf/keras/layers/SpatialDropout1D)	|Spatial 1D version of Dropout.|
|[SpatialDropout2D](https://www.tensorflow.org/api_docs/python/tf/keras/layers/SpatialDropout2D)	|Spatial 2D version of Dropout.|
|[SpatialDropout3D](https://www.tensorflow.org/api_docs/python/tf/keras/layers/SpatialDropout3D)	|Spatial 3D version of Dropout.|
|[ZeroPadding1D](https://www.tensorflow.org/api_docs/python/tf/keras/layers/ZeroPadding1D)	|Zero-padding layer for 1D input (e.g. temporal sequence).|
|[ZeroPadding2D](https://www.tensorflow.org/api_docs/python/tf/keras/layers/ZeroPadding2D)	|Zero-padding layer for 2D input (e.g. picture).|
|[ZeroPadding3D](https://www.tensorflow.org/api_docs/python/tf/keras/layers/ZeroPadding3D)	|Zero-padding layer for 3D data (spatial or spatio-temporal).|
 

## [Preprocessing layers](https://www.tensorflow.org/api_docs/python/tf/keras/layers#classes_2) 

Reduced list with the most relevant preprocessing layers

|||
|---|---|
|[CenterCrop](https://www.tensorflow.org/api_docs/python/tf/keras/layers/CenterCrop)	|A preprocessing layer which crops images.|
|[RandomContrast](https://www.tensorflow.org/api_docs/python/tf/keras/layers/RandomContrast)	|A preprocessing layer which randomly adjusts contrast during training.|
|[RandomCrop](https://www.tensorflow.org/api_docs/python/tf/keras/layers/RandomCrop)	|A preprocessing layer which randomly crops images during training.|
|[RandomFlip](https://www.tensorflow.org/api_docs/python/tf/keras/layers/RandomFlip)	|A preprocessing layer which randomly flips images during training.|
|[RandomHeight](https://www.tensorflow.org/api_docs/python/tf/keras/layers/RandomHeight)|	A preprocessing layer which randomly varies image height during training.|
|[RandomRotation](https://www.tensorflow.org/api_docs/python/tf/keras/layers/RandomRotation)	|A preprocessing layer which randomly rotates images during training.|
|[RandomTranslation](https://www.tensorflow.org/api_docs/python/tf/keras/layers/RandomTranslation)	|A preprocessing layer which randomly translates images during training.|
|[RandomWidth](https://www.tensorflow.org/api_docs/python/tf/keras/layers/RandomWidth)	|A preprocessing layer which randomly varies image width during training.|
|[RandomZoom](https://www.tensorflow.org/api_docs/python/tf/keras/layers/RandomZoom)	|A preprocessing layer which randomly zooms images during training.|
|[Rescaling](https://www.tensorflow.org/api_docs/python/tf/keras/layers/Rescaling)	|A preprocessing layer which rescales input values to a new range.|
|[Resizing](https://www.tensorflow.org/api_docs/python/tf/keras/layers/Resizing)	|A preprocessing layer which resizes images.|
 

## [Activation functions](https://www.tensorflow.org/api_docs/python/tf/keras/activations)

Reduced list with the most relevant activation functions
|||
|---|---|
|[hard_sigmoid(...)](https://www.tensorflow.org/api_docs/python/tf/keras/activations/hard_sigmoid)|	Hard sigmoid activation function.|
|[relu(...)](https://www.tensorflow.org/api_docs/python/tf/keras/activations/relu)	|Applies the rectified linear unit activation function.|
|[sigmoid(...)](https://www.tensorflow.org/api_docs/python/tf/keras/activations/sigmoid)	|Sigmoid activation function, sigmoid(x) = 1 / (1 + exp(-x)).|
|[softmax(...)](https://www.tensorflow.org/api_docs/python/tf/keras/activations/softmax)	|Softmax converts a vector of values to a probability distribution.|
|[softplus(...)](https://www.tensorflow.org/api_docs/python/tf/keras/activations/softplus)	|Softplus activation function, softplus(x) = log(exp(x) + 1).|
|[softsign(...)](https://www.tensorflow.org/api_docs/python/tf/keras/activations/softsign)	|Softsign activation function, softsign(x) = x / (abs(x) + 1).|
|[tanh(...)](https://www.tensorflow.org/api_docs/python/tf/keras/activations/tanh)	|Hyperbolic tangent activation function.|
 

## [Loss-functions](https://www.tensorflow.org/api_docs/python/tf/keras/losses)

Reduced list with the most relevant loss functions

|||
|---|---|
|[BinaryCrossentropy](https://www.tensorflow.org/api_docs/python/tf/keras/losses/BinaryCrossentropy)	|Computes the cross-entropy loss between true labels and predicted labels.|
|[CategoricalCrossentropy](https://www.tensorflow.org/api_docs/python/tf/keras/losses/CategoricalCrossentropy)	|Computes the crossentropy loss between the labels and predictions.|
|[KLDivergence](https://www.tensorflow.org/api_docs/python/tf/keras/losses/KLDivergence)	|Computes Kullback-Leibler divergence loss between y_true and y_pred.|
|[MeanAbsoluteError](https://www.tensorflow.org/api_docs/python/tf/keras/losses/MeanAbsoluteError)	|Computes the mean of absolute difference between labels and predictions.|
|[MeanSquaredError](https://www.tensorflow.org/api_docs/python/tf/keras/losses/MeanSquaredError)	|Computes the mean of squares of errors between labels and predictions.|
|[Poisson](https://www.tensorflow.org/api_docs/python/tf/keras/losses/Poisson)	|Computes the Poisson loss between y_true and y_pred.|
|[SparseCategoricalCrossentropy](https://www.tensorflow.org/api_docs/python/tf/keras/losses/SparseCategoricalCrossentropy)	|Computes the crossentropy loss between the labels and predictions.|
 

## [Optimizer](https://www.tensorflow.org/api_docs/python/tf/keras/optimizers) 

Reduced list with the most relevant optimizer

|||
|---|---|
|[Adagrad](https://www.tensorflow.org/api_docs/python/tf/keras/optimizers/experimental/Adagrad)	|Optimizer that implements the Adagrad algorithm.|
|[Adam](https://www.tensorflow.org/api_docs/python/tf/keras/optimizers/Adam)	|Optimizer that implements the Adam algorithm.|
|[RMSprop](https://www.tensorflow.org/api_docs/python/tf/keras/optimizers/experimental/RMSprop)	|Optimizer that implements the RMSprop algorithm.|
|[SGD](https://www.tensorflow.org/api_docs/python/tf/keras/optimizers/experimental/SGD)	|Gradient descent (with momentum) optimizer.|
 

## [Metrics](https://www.tensorflow.org/api_docs/python/tf/keras/metrics) 
A very reduced list with the most relevant metrics

|||
|---|---|
|[Accuracy](https://www.tensorflow.org/api_docs/python/tf/keras/metrics/Accuracy)	| Calculates how often predictions equal labels.|
|[BinaryAccuracy](https://www.tensorflow.org/api_docs/python/tf/keras/metrics/BinaryAccuracy)	| Calculates how often predictions match binary labels.|
|[BinaryCrossentropy](https://www.tensorflow.org/api_docs/python/tf/keras/metrics/BinaryCrossentropy)	| Computes the crossentropy metric between the labels and predictions.|
|[CategoricalAccuracy](https://www.tensorflow.org/api_docs/python/tf/keras/metrics/CategoricalAccuracy)	| Calculates how often predictions match one-hot labels.|
|[CategoricalCrossentropy](https://www.tensorflow.org/api_docs/python/tf/keras/metrics/CategoricalCrossentropy)	| Computes the crossentropy metric between the labels and predictions.|
|[KLDivergence](https://www.tensorflow.org/api_docs/python/tf/keras/metrics/KLDivergence)	| Computes Kullback-Leibler divergence metric between y_true and y_pred.|
|[Mean](https://www.tensorflow.org/api_docs/python/tf/keras/metrics/Mean)	| Computes the (weighted) mean of the given values.|
|[MeanAbsoluteError](https://www.tensorflow.org/api_docs/python/tf/keras/metrics/MeanAbsoluteError)	| Computes the mean absolute error between the labels and predictions.|
|[MeanSquaredError](https://www.tensorflow.org/api_docs/python/tf/keras/metrics/MeanSquaredError)	| Computes the mean squared error between y_true and y_pred.|
|[Poisson](https://www.tensorflow.org/api_docs/python/tf/keras/metrics/Poisson)	| Computes the Poisson metric between y_true and y_pred.|
|[Precision](https://www.tensorflow.org/api_docs/python/tf/keras/metrics/Precision)	| Computes the precision of the predictions with respect to the labels.|
|[RootMeanSquaredError](https://www.tensorflow.org/api_docs/python/tf/keras/metrics/RootMeanSquaredError)	| Computes root mean squared error metric between y_true and y_pred.|
|[SparseCategoricalAccuracy](https://www.tensorflow.org/api_docs/python/tf/keras/metrics/SparseCategoricalAccuracy)	| Calculates how often predictions match integer labels.|
|[SparseCategoricalCrossentropy](https://www.tensorflow.org/api_docs/python/tf/keras/metrics/SparseCategoricalCrossentropy)	| Computes the crossentropy metric between the labels and predictions.|
|[SparseTopKCategoricalAccuracy](https://www.tensorflow.org/api_docs/python/tf/keras/metrics/SparseTopKCategoricalAccuracy)	 | Computes how often integer targets are in the top K predictions.|
|[Sum](https://www.tensorflow.org/api_docs/python/tf/keras/metrics/Sum)	| Computes the (weighted) sum of the given values.|
|[TopKCategoricalAccuracy](https://www.tensorflow.org/api_docs/python/tf/keras/metrics/TopKCategoricalAccuracy)|	Computes how often targets are in the top K predictions.|




