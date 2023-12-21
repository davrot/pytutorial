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






