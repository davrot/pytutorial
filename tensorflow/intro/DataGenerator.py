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
