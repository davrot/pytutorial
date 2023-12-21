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

