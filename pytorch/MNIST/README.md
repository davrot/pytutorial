# Class
{:.no_toc}

<nav markdown="1" class="toc-class">
* TOC
{:toc}
</nav>

## The goal

Class has a very important job as a core container type in Python. It is really hard to find a good overview how to use them in a good practice manner.

Questions to [David Rotermund](mailto:davrot@uni-bremen.de)

**I will use Linux. You will need a replacement for gzip under Windows.**

## Download the files

We need to download the MNIST database files 

t10k-images-idx3-ubyte.gz
t10k-labels-idx1-ubyte.gz
train-images-idx3-ubyte.gz
train-labels-idx1-ubyte.gz
A source for that is for example [https://deepai.org/dataset/mnist](https://deepai.org/dataset/mnist)

## Unpack the gz files

In a terminal:

```shell
gzip -d *.gz
```

## Convert the data into numpy files

### [numpy.dtype.newbyteorder](https://numpy.org/doc/stable/reference/generated/numpy.dtype.newbyteorder.html)

```python
type.newbyteorder(new_order='S', /)
```

> Return a new dtype with a different byte order.
> 
> Changes are also made in all fields and sub-arrays of the data type.
> 
> **new_order** : string, optional
> 
> Byte order to force; a value from the byte order specifications below. The default value (‘S’) results in swapping the current byte order. new_order codes can be any of:
> 
>  ‘S’ - swap dtype from current to opposite endian
> 
> {‘<’, ‘little’} - little endian
> 
> {‘>’, ‘big’} - big endian
> 
> {‘=’, ‘native’} - native order
> 
> {‘\|’, ‘I’} - ignore (no change to byte order)
> 

### Label file structure

> [offset] [type]          [value]          [description]
> 
> 0000     32 bit integer  0x00000801(2049) magic number (MSB first)
> 
> 0004     32 bit integer  60000            number of items
> 
> 0008     unsigned byte   ??               label
> 
> 0009     unsigned byte   ??               label
> 
> ........
> 
> xxxx     unsigned byte   ??               label

The labels values are 0 to 9.

### Pattern file structure

> [offset] [type]          [value]          [description]
> 
> 0000     32 bit integer  0x00000803(2051) magic number
> 
> 0004     32 bit integer  60000            number of images
> 
> 0008     32 bit integer  28               number of rows
> 
> 0012     32 bit integer  28               number of columns
> 
> 0016     unsigned byte   ??               pixel
> 
> 0017     unsigned byte   ??               pixel
> 
> ........
> 
> xxxx     unsigned byte   ??               pixel

Pixels are organized row-wise.

Pixel values are 0 to 255. 0 means background (white),

255 means foreground (black).

## Converting the dataset to numpy

My source code for that task: convert.py

```python
import numpy as np

# [offset] [type]          [value]          [description]
# 0000     32 bit integer  0x00000801(2049) magic number (MSB first)
# 0004     32 bit integer  60000            number of items
# 0008     unsigned byte   ??               label
# 0009     unsigned byte   ??               label
# ........
# xxxx     unsigned byte   ??               label
# The labels values are 0 to 9.


class ReadLabel:
    """Class for reading the labels from an MNIST label file"""

    def __init__(self, filename: str) -> None:
        self.filename: str = filename
        self.data = self.read_from_file(filename)

    def read_from_file(self, filename: str) -> np.ndarray:

        int_32bit_data = np.dtype(np.uint32)
        int_32bit_data = int_32bit_data.newbyteorder(">")

        with open(filename, "rb") as file:

            magic_flag: np.uint32 = np.frombuffer(file.read(4), int_32bit_data)[0]

            if magic_flag != 2049:
                data: np.ndarray = np.zeros(0)
                number_of_elements: int = 0
            else:
                number_of_elements = np.frombuffer(file.read(4), int_32bit_data)[0]

            if number_of_elements < 1:
                data = np.zeros(0)
            else:
                data = np.frombuffer(file.read(number_of_elements), dtype=np.uint8)

        return data


# [offset] [type]          [value]          [description]
# 0000     32 bit integer  0x00000803(2051) magic number
# 0004     32 bit integer  60000            number of images
# 0008     32 bit integer  28               number of rows
# 0012     32 bit integer  28               number of columns
# 0016     unsigned byte   ??               pixel
# 0017     unsigned byte   ??               pixel
# ........
# xxxx     unsigned byte   ??               pixel
# Pixels are organized row-wise.
# Pixel values are 0 to 255. 0 means background (white),
# 255 means foreground (black).


class ReadPicture:
    """Class for reading the images from an MNIST image file"""

    def __init__(self, filename: str) -> None:
        self.filename: str = filename
        self.Data = self.read_from_file(filename)

    def read_from_file(self, filename: str) -> np.ndarray:

        int_32bit_data = np.dtype(np.uint32)
        int_32bit_data = int_32bit_data.newbyteorder(">")

        with open(filename, "rb") as file:

            magic_flag = np.frombuffer(file.read(4), int_32bit_data)[0]

            if magic_flag != 2051:
                data = np.zeros(0)
                number_of_elements: int = 0
            else:
                number_of_elements = np.frombuffer(file.read(4), int_32bit_data)[0]

            if number_of_elements < 1:
                data = np.zeros(0)
                number_of_rows: int = 0
            else:
                number_of_rows = np.frombuffer(file.read(4), int_32bit_data)[0]

            if number_of_rows != 28:
                data = np.zeros(0)
                number_of_columns: int = 0
            else:
                number_of_columns = np.frombuffer(file.read(4), int_32bit_data)[0]

            if number_of_columns != 28:
                data = np.zeros(0)
            else:
                data = np.frombuffer(
                    file.read(number_of_elements * number_of_rows * number_of_columns),
                    dtype=np.uint8,
                )
                data = data.reshape(
                    number_of_elements, number_of_columns, number_of_rows
                )

        return data


def proprocess_dataset(testdata_mode: bool) -> None:

    if testdata_mode is True:
        filename_out_pattern: str = "test_pattern_storage.npy"
        filename_out_label: str = "test_label_storage.npy"
        filename_in_image: str = "t10k-images-idx3-ubyte"
        filename_in_label: str = "t10k-labels-idx1-ubyte"
    else:
        filename_out_pattern = "train_pattern_storage.npy"
        filename_out_label = "train_label_storage.npy"
        filename_in_image = "train-images-idx3-ubyte"
        filename_in_label = "train-labels-idx1-ubyte"

    pictures = ReadPicture(filename_in_image)
    labels = ReadLabel(filename_in_label)

    # Down to 0 ... 1.0
    max_value = np.max(pictures.Data.astype(np.float32))
    pattern_storage = np.float32(pictures.Data.astype(np.float32) / max_value).astype(
        np.float32
    )

    label_storage = np.uint64(labels.data)

    np.save(filename_out_pattern, pattern_storage)
    np.save(filename_out_label, label_storage)


proprocess_dataset(testdata_mode=True)
proprocess_dataset(testdata_mode=False)
``` 

Now we have the files:

* test_label_storage.npy
* test_pattern_storage.npy
* train_label_storage.npy
* train_pattern_storage.npy
