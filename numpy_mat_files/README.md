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

### MATLAB <= 7.2 format mat files

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
