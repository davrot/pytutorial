# Numpy: Dealing with Matlab files
{:.no_toc}

<nav markdown="1" class="toc-class">
* TOC
{:toc}
</nav>

## The goal
We want to read and write Matlab files under Python.

Questions to [David Rotermund](mailto:davrot@uni-bremen.de)

Reminder: Learning Python as Matlab user
Please read [NumPy for MATLAB users](https://numpy.org/doc/stable/user/numpy-for-matlab-users.html)

## Mat files under Python

### MATLAB < 7.3 format mat files

This is a job for [scipy.io](https://docs.scipy.org/doc/scipy/reference/io.html#module-scipy.io)

| | |
| ------------- |-------------|
|[loadmat](https://docs.scipy.org/doc/scipy/reference/generated/scipy.io.loadmat.html#scipy.io.loadmat)(file_name[, mdict, appendmat])|	Load MATLAB file. |
|[savemat](https://docs.scipy.org/doc/scipy/reference/generated/scipy.io.savemat.html#scipy.io.savemat)(file_name, mdict[, appendmat, …])|	Save a dictionary of names and arrays into a MATLAB-style .mat file. |
|[whosmat](https://docs.scipy.org/doc/scipy/reference/generated/scipy.io.whosmat.html#scipy.io.whosmat)(file_name[, appendmat])|	List variables inside a MATLAB file. |

#### Read
Under Matlab we create a test file

```matlab
>> A = rand(10,100);
>> save -v7 Test_1.mat A
```

Under Python we look into the file for information:
```python
import scipy.io as sio

Info = sio.whosmat("Test_1.mat")
print(Info) # --> [('A', (10, 100), 'double')]
```

And we can read the data: 

```python
import numpy as np
import scipy.io as sio

mat_data = sio.loadmat("Test_1.mat")

print(
    mat_data.keys()
)  # -> dict_keys(['__header__', '__version__', '__globals__', 'A'])

a = mat_data["A"]
print(type(a))  # --> <class 'numpy.ndarray'>
print(a.dtype)  # --> float64
print(a.shape)  # --> (10, 100)
```

#### Write

Under Python we generate a .mat file:

```python
import numpy as np
import scipy.io as sio

myrng = np.random.default_rng()

A: np.ndarray = myrng.random((10, 100), dtype=np.float64)
B: str = "Hellp world!"
mdic = {"A": A, "ImportantMessage": B}
sio.savemat("Test_2.mat", mdic)
```

And read it in under Matlab:

```matlab
>> load Test_2.mat
>> whos
  Name                   Size             Bytes  Class     Attributes

  A                     10x100             8000  double              
  ImportantMessage       1x12                24  char                

>> ImportantMessage

ImportantMessage =

    'Hellp world!'
```

### MATLAB == 7.3 format mat files (for very big files)

#### Read
Under Matlab we create another test file

```matlab
>> A = rand(10,100);
>> B = rand(5, 10,100);
>> save -v7.3 Test_3.mat A B
```

And we can read the data under Python. But be aware that the matrix is in reversed order now. 10x100 -> 100x10 and 5x10x100 -> 100x10x5

```python
import numpy as np
import h5py

file_handle = h5py.File("Test_3.mat", "r")

print(file_handle.keys())  # --> <KeysViewHDF5 ['A']>

hdf5_a = file_handle["A"]
print(hdf5_a)  # --> <HDF5 dataset "A": shape (100, 10), type "<f8">
a = np.array(hdf5_a)
print(type(a))  # --> <class 'numpy.ndarray'>
print(a.dtype)  # --> float64
print(a.shape)  # --> (100, 10)

hdf5_b = file_handle["B"]
print(hdf5_b)  # --> <HDF5 dataset "B": shape (100, 10), type "<f8">
b = np.array(hdf5_b)
print(type(b))  # --> <class 'numpy.ndarray'>
print(b.dtype)  # --> float64
print(b.shape)  # --> (100, 10, 5)

file_handle.close() #  optional
```

Note: If you -- in a real world example -- see a HDF5 group (e.g. <HDF5 group "/#refs#" (16 members)> ) instead of a HDF5 dataset then the variable is a container again (very similar to file_handle in the example). It will have keys and you can go down the tree until you find the HDF5 datasets. Especially in the case of Matlab structures you might need to go deeper. 

#### Write

Under Python we generate a .hd5 file:

```python
import numpy as np
import h5py

myrng = np.random.default_rng()

a: np.ndarray = myrng.random((10, 100), dtype=np.float64)
b: np.ndarray = myrng.random((2, 20, 200), dtype=np.float64)

file_handle = h5py.File("Test_4.hd5", "w")

dataset_a = file_handle.create_dataset("A", data=a)
dataset_b = file_handle.create_dataset("B", data=b)
file_handle.close() # optional
```

Under Matlab we now can extract information about the hd5 file:

```matlab
>> info = h5info('Test_4.hd5');
>> length(info.Datasets)

ans =

     2

>> info.Datasets(1)

ans = 

  struct with fields:

          Name: 'A'
      Datatype: [1x1 struct]
     Dataspace: [1x1 struct]
     ChunkSize: []
     FillValue: 0
       Filters: []
    Attributes: []

>> info.Datasets(2)

ans = 

  struct with fields:

          Name: 'B'
      Datatype: [1x1 struct]
     Dataspace: [1x1 struct]
     ChunkSize: []
     FillValue: 0
       Filters: []
    Attributes: []
```

And now we read it in under Matlab:

```matlab
>> h5disp('Test_4.hd5')
HDF5 Test_4.hd5 
Group '/' 
    Dataset 'A' 
        Size:  100x10
        MaxSize:  100x10
        Datatype:   H5T_IEEE_F64LE (double)
        ChunkSize:  []
        Filters:  none
        FillValue:  0.000000
    Dataset 'B' 
        Size:  200x20x2
        MaxSize:  200x20x2
        Datatype:   H5T_IEEE_F64LE (double)
        ChunkSize:  []
        Filters:  none
        FillValue:  0.000000
```

Now we know that the databases are at '/A' and '/B'. With information we can read the matrices. But be aware that the matrices are in reversed order!

```matlab
>> a = h5read('Test_4.hd5','/A');
>> b = h5read('Test_4.hd5','/B');
>> whos
  Name        Size              Bytes  Class     Attributes

  a         100x10               8000  double              
  b         200x20x2            64000  double
```
