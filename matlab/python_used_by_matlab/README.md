# Running Python remotely from Matlab
{:.no_toc}

<nav markdown="1" class="toc-class">
* TOC
{:toc}
</nav>

## The goal

We want to integrate Python files and code into our Matlab workflow.  

Questions to [David Rotermund](mailto:davrot@uni-bremen.de)

## Check if you are ready

[Versions of Python Compatible with MATLAB Products by Release](https://de.mathworks.com/support/requirements/python-compatibility.html)

You need to ask yourself or better Matlab if it is using the correct Python. You can check this via:

```matlab
>> pyenv

ans = 

  PythonEnvironment with properties:

          Version: "3.11"
       Executable: "/data_1/davrot/P3.11/bin/python3"
          Library: "libpython3.11.so.1.0"
             Home: "/data_1/davrot/P3.11"
           Status: NotLoaded
    ExecutionMode: InProcess

```

If this is wrong (which it isn't in my case) then you can change it (temporarily?) with

```matlab
>> pyenv('Version','/data_1/davrot/P3.11/bin/python3')

ans = 

  PythonEnvironment with properties:

          Version: "3.11"
       Executable: "/data_1/davrot/P3.11/bin/python3"
          Library: "libpython3.11.so.1.0"
             Home: "/data_1/davrot/P3.11"
           Status: NotLoaded
    ExecutionMode: InProcess
```

**Obviously you need to use your location for your Python installation.**

## Python help

```matlab
>> py.help('int')
Help on class int in module builtins:

class int(object)
 |  int([x]) -> integer
 |  int(x, base=10) -> integer
[...]
```

## Tuple and random number example

We can crate a python tuple like this:

```matlab
>> py_dim = py.tuple({py.int(10), py.int(100)})

py_dim = 

  Python tuple with values:

    (10, 100)

    Use string, double or cell function to convert to a MATLAB array.
```

Now we can use numpy to generate random numbers:

```matlab
>> py_dim = py.tuple({py.int(10), py.int(100)})
>> rng = py.numpy.random.default_rng();
>> a = rng.random(py_dim);
>> py.print(py.type(a))
<class 'numpy.ndarray'>
>> py.print(a.shape)
(10, 100)
>> py.print(a.dtype)
float64
>> whos
>> whos
  Name        Size            Bytes  Class                                   Attributes

  a           1x1                 8  py.numpy.ndarray                                  
  ans         1x1                 8  matlab.pyclient.PythonEnvironment                 
  py_dim      1x2                 8  py.tuple                                          
  rng         1x1                 8  py.numpy.random._generator.Generator    
```

Alternatively this is also possible:

```matlab
>> b = rng.random(cell({int32(10),int32(100)}));
```

## User defined Python modules

Our very own Python function in the file **mtest_1.py**:

```python
import numpy as np

def mysquared(input:np.ndarray) -> np.ndarray:
    output = input**2
    return output
```

Now Matlab allows us to do this:

```matlab
>> x = (1:1:10);
>> x_np = py.numpy.array(x);
>> y_np = py.mtest_1.mysquared(x_np);
>> y = double(x_np).^2;
>> sum(sum(abs(y-double(y_np))))

ans =

     0
```

If you change the py file, then you need to clean it from the memory via

```matlab
>> clear classes
```

## Save a numpy file with Matlab

In Matlab we save data into numpy file:

```matlab
>> a = rand(100,10);
>> a_np = py.numpy.array(a);
>> py.numpy.save("test_1.npy",a_np);
```

Now we can load it into Python: 

```python
import numpy as np

a = np.load("test_1.npy")

print(type(a)) # --> <class 'numpy.ndarray'>
print(a.shape) # --> (100, 10)
print(a.dtype) # --> float64
```

## Loading a numpy file with Matlab

Under Python we generate a file:

```python
import numpy as np

myrng = np.random.default_rng()

a = myrng.random((100, 10))
np.save("test_2.npy", a)
```

And under Matlab we load it:

>> a_np = py.numpy.load("test_2.npy");
>> a = double(a_np);
>> whos
  Name        Size            Bytes  Class               Attributes

  a         100x10             8000  double                        
  a_np        1x1                 8  py.numpy.ndarray     

## References 
* [Access Python Modules from MATLAB - Getting Started](https://de.mathworks.com/help/matlab/matlab_external/create-object-from-python-class.html)
* [Use Python str Variables in MATLAB](https://de.mathworks.com/help/matlab/matlab_external/pythonstrvariables.html)
* [Use Python list Variables in MATLAB](https://de.mathworks.com/help/matlab/matlab_external/pythonlistvariables.html)
* [Use Python tuple Variables in MATLAB](https://de.mathworks.com/help/matlab/matlab_external/pythontuplevariables.html)
* [Use Python dict Variables in MATLAB](https://de.mathworks.com/help/matlab/matlab_external/python-dict-variables.html)
* [Call User-Defined Python Module](https://de.mathworks.com/help/matlab/matlab_external/call-user-defined-custom-module.html)

 




