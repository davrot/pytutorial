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
# With data augmentation (okay this should be fixed in DataGenerator.py :-( )
input_dimensions = (train_data.dimensions[0] - 4, train_data.dimensions[0] - 4)
# Without data augmentation
# input_dimensions = train_data.dimensions
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
