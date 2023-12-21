# Matlab is also just a Python package
{:.no_toc}

<nav markdown="1" class="toc-class">
* TOC
{:toc}
</nav>

## The goal

Remote controlling Matlab from Python using the Matlab engine package. (Note: A similar approach can be used with C/C++ instead of Python.) 

Questions to [David Rotermund](mailto:davrot@uni-bremen.de)

## Installing Matlab under Python

[Versions of Python Compatible with MATLAB Products by Release](https://de.mathworks.com/support/requirements/python-compatibility.html)

Obviously you need a working Matlab and Python installation first. Then... 

### Linux

Open a terminal and do this (please adapt to your Matlab and Python version / installation path). And make sure that you use the correct Python installation for this operation, otherwise you will be confused why it will not work.  


```shell
cd /tools/matlab2023b/extern/engines/python/
/data_1/davrot/P3.11/bin/python3 ./setup.py install
```

You get something like this as a response: 

```shell
running install
running bdist_egg
running egg_info
creating dist/matlabengine.egg-info
writing dist/matlabengine.egg-info/PKG-INFO
writing dependency_links to dist/matlabengine.egg-info/dependency_links.txt
writing top-level names to dist/matlabengine.egg-info/top_level.txt
writing manifest file 'dist/matlabengine.egg-info/SOURCES.txt'
/data_1/davrot/P3.11/lib/python3.11/site-packages/setuptools/command/egg_info.py:643: SetuptoolsDeprecationWarning: Custom 'build_py' does not implement 'get_data_files_without_manifest'.
Please extend command classes from setuptools instead of distutils.
  warnings.warn(
reading manifest file 'dist/matlabengine.egg-info/SOURCES.txt'
writing manifest file 'dist/matlabengine.egg-info/SOURCES.txt'
installing library code to build/bdist.linux-x86_64/egg
running install_lib
running build_py
creating build
creating build/lib
creating build/lib/matlab
copying dist/matlab/__init__.py -> build/lib/matlab
creating build/lib/matlab/engine
copying dist/matlab/engine/matlabengine.py -> build/lib/matlab/engine
copying dist/matlab/engine/basefuture.py -> build/lib/matlab/engine
copying dist/matlab/engine/fevalfuture.py -> build/lib/matlab/engine
copying dist/matlab/engine/__init__.py -> build/lib/matlab/engine
copying dist/matlab/engine/engineerror.py -> build/lib/matlab/engine
copying dist/matlab/engine/enginehelper.py -> build/lib/matlab/engine
copying dist/matlab/engine/matlabfuture.py -> build/lib/matlab/engine
copying dist/matlab/engine/futureresult.py -> build/lib/matlab/engine
copying dist/matlab/engine/enginesession.py -> build/lib/matlab/engine
creating build/bdist.linux-x86_64
creating build/bdist.linux-x86_64/egg
creating build/bdist.linux-x86_64/egg/matlab
creating build/bdist.linux-x86_64/egg/matlab/engine
copying build/lib/matlab/engine/matlabengine.py -> build/bdist.linux-x86_64/egg/matlab/engine
copying build/lib/matlab/engine/basefuture.py -> build/bdist.linux-x86_64/egg/matlab/engine
copying build/lib/matlab/engine/fevalfuture.py -> build/bdist.linux-x86_64/egg/matlab/engine
copying build/lib/matlab/engine/__init__.py -> build/bdist.linux-x86_64/egg/matlab/engine
copying build/lib/matlab/engine/engineerror.py -> build/bdist.linux-x86_64/egg/matlab/engine
copying build/lib/matlab/engine/_arch.txt -> build/bdist.linux-x86_64/egg/matlab/engine
copying build/lib/matlab/engine/enginehelper.py -> build/bdist.linux-x86_64/egg/matlab/engine
copying build/lib/matlab/engine/matlabfuture.py -> build/bdist.linux-x86_64/egg/matlab/engine
copying build/lib/matlab/engine/futureresult.py -> build/bdist.linux-x86_64/egg/matlab/engine
copying build/lib/matlab/engine/enginesession.py -> build/bdist.linux-x86_64/egg/matlab/engine
copying build/lib/matlab/__init__.py -> build/bdist.linux-x86_64/egg/matlab
byte-compiling build/bdist.linux-x86_64/egg/matlab/engine/matlabengine.py to matlabengine.cpython-311.pyc
byte-compiling build/bdist.linux-x86_64/egg/matlab/engine/basefuture.py to basefuture.cpython-311.pyc
byte-compiling build/bdist.linux-x86_64/egg/matlab/engine/fevalfuture.py to fevalfuture.cpython-311.pyc
byte-compiling build/bdist.linux-x86_64/egg/matlab/engine/__init__.py to __init__.cpython-311.pyc
byte-compiling build/bdist.linux-x86_64/egg/matlab/engine/engineerror.py to engineerror.cpython-311.pyc
byte-compiling build/bdist.linux-x86_64/egg/matlab/engine/enginehelper.py to enginehelper.cpython-311.pyc
byte-compiling build/bdist.linux-x86_64/egg/matlab/engine/matlabfuture.py to matlabfuture.cpython-311.pyc
byte-compiling build/bdist.linux-x86_64/egg/matlab/engine/futureresult.py to futureresult.cpython-311.pyc
byte-compiling build/bdist.linux-x86_64/egg/matlab/engine/enginesession.py to enginesession.cpython-311.pyc
byte-compiling build/bdist.linux-x86_64/egg/matlab/__init__.py to __init__.cpython-311.pyc
creating build/bdist.linux-x86_64/egg/EGG-INFO
copying dist/matlabengine.egg-info/PKG-INFO -> build/bdist.linux-x86_64/egg/EGG-INFO
copying dist/matlabengine.egg-info/SOURCES.txt -> build/bdist.linux-x86_64/egg/EGG-INFO
copying dist/matlabengine.egg-info/dependency_links.txt -> build/bdist.linux-x86_64/egg/EGG-INFO
copying dist/matlabengine.egg-info/top_level.txt -> build/bdist.linux-x86_64/egg/EGG-INFO
zip_safe flag not set; analyzing archive contents...
matlab.__pycache__.__init__.cpython-311: module references __file__
matlab.__pycache__.__init__.cpython-311: module references __path__
matlab.engine.__pycache__.__init__.cpython-311: module references __file__
creating 'dist/matlabengine-23.2-py3.11.egg' and adding 'build/bdist.linux-x86_64/egg' to it
removing 'build/bdist.linux-x86_64/egg' (and everything under it)
Processing matlabengine-23.2-py3.11.egg
creating /data_1/davrot/P3.11/lib/python3.11/site-packages/matlabengine-23.2-py3.11.egg
Extracting matlabengine-23.2-py3.11.egg to /data_1/davrot/P3.11/lib/python3.11/site-packages
Adding matlabengine 23.2 to easy-install.pth file

Installed /data_1/davrot/P3.11/lib/python3.11/site-packages/matlabengine-23.2-py3.11.egg
Processing dependencies for matlabengine==23.2
Finished processing dependencies for matlabengine==23.2
```

### Windows 

Open a Power Shell as administrator under Windows and do this: 

```shell
cd "C:\Program Files\MATLAB\R2023b\extern\engines\python"
python.exe .\setup.py install
```

## Start the engine

Under Python we now can connect to Matlab:

```python
import matlab.engine

eng = matlab.engine.start_matlab()
```

## First test

```python
import numpy as np
import matlab.engine

eng = matlab.engine.start_matlab()

a = eng.rand(100, 10)
print(type(a))  # --> <class 'mlarray.double'>
a_np = np.array(a)
print(type(a_np)) # --> <class 'numpy.ndarray'>
print(a_np.shape) # --> (100, 10)
print(a_np.dtype) # --> float64
```

You may want to read additional information about the whole ordeal: 

* [MATLAB Arrays as Python Variables](https://de.mathworks.com/help/matlab/matlab_external/matlab-arrays-as-python-variables.html)
* [Use MATLAB Arrays in Python](https://de.mathworks.com/help/matlab/matlab_external/use-matlab-arrays-in-python.html)
* [Pass Data to MATLAB from Python](https://de.mathworks.com/help/matlab/matlab_external/pass-data-to-matlab-from-python.html)
* [Handle Data Returned from MATLAB to Python](https://de.mathworks.com/help/matlab/matlab_external/handle-data-returned-from-matlab-to-python.html)

## Eval

```python
import matlab.engine

eng = matlab.engine.start_matlab()

eng.eval("clear all", nargout=0)
eng.eval("a = rand(100,10);", nargout=0)
eng.eval("whos", nargout=0)
eng.eval("figure(1);", nargout=0)
eng.eval("plot(a)", nargout=0)

input("Press enter to continue")
```

And you get this result if you use the Power Shell:

PS C:\Users\admin\Documents\MATLAB> python.exe .\matlab1.py
  Name        Size            Bytes  Class     Attributes

  a         100x10             8000  double

Press enter to continue

If you use VS Code in cell mode, you will get a cold stare instead of the text output.

 

## Getting data from the Matlab workspace 

```python
import matlab.engine
import numpy as np

eng = matlab.engine.start_matlab()

eng.eval("clear all", nargout=0)
eng.eval("a = rand(100,10);", nargout=0)
data_mat = eng.workspace["a"]
print(type(data_mat)) # --> import numpy as np
a = np.array(data_mat)
print(type(a)) # --> <class 'numpy.ndarray'>
print(a.shape) # --> (100, 10)
print(a.dtype) # --> float64
```

An alternative is:

```python
import matlab.engine

eng = matlab.engine.start_matlab()

Output = eng.eval("A = 1", nargout=1)  # Error!!!

eng.eval("A = 1;", nargout=0)
Output = eng.eval("A", nargout=1)
print(Output) # --> 1.0
```

## Exchanging data with Matlab bi-directionally 

```python
# %%
import matlab.engine
import matlab
import numpy as np

eng = matlab.engine.start_matlab()

myrng = np.random.default_rng()

a = myrng.random((100, 10))
b = myrng.random((100, 10))
c_py = a * b

a_mat = matlab.double(a.tolist())
b_mat = matlab.double(b.tolist())

eng.eval("clear all", nargout=0)
eng.workspace["a"] = a_mat
eng.workspace["b"] = b_mat

eng.eval("c = a .* b;", nargout=0)

c_mat = np.array(eng.workspace["c"])

print(np.sum(np.abs(c_py - c_mat))) # --> 0.0
```



