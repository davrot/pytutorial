# Expanding Python with C++ modules
{:.no_toc}

<nav markdown="1" class="toc-class">
* TOC
{:toc}
</nav>

## Top

A minimal introduction in how to use PyBind11. PyBind11 allows you to extend Python with C++ modules which are written in C++11 or newer.

Questions to [David Rotermund](mailto:davrot@uni-bremen.de)

## A very simple example

What do we need in the most minimal scenario?

* [Makefile](Makefile) plus a .env file
* Module wrapper ([PyMyModuleCPU.cpp](PyMyModuleCPU.cpp))
* The module ([MyModuleCPU.cpp](MyModuleCPU.cpp) and [MyModuleCPU.h](MyModuleCPU.h))
* Some test code [test.py](test.py)


## [Makefile](Makefile)

If you are programming in C++ and don't know how to use a Makefile then you really should [look it up](https://www.gnu.org/software/make/manual/html_node/Simple-Makefile.html). 

I am working under Linux and my Makefile looks like [this](Makefile)... MyModuleCPU.cpp and PyMyModuleCPU.cpp are compiled in .o files and then linked into PyMyModuleCPU. However, Python needs a special filename ending which depends on the Python version. Thus there is this additional copy command dealing with this issue. 

## The wrapper file ([PyMyModuleCPU.cpp](PyMyModuleCPU.cpp))

The wrapper file is the connection point between Python and C++. It tells Python what to call. In this example we have three functions we export into the Python space:

* PutStuffIn , which is connected to MyModule::PutStuffIn
* DoStuff  , which is connected to MyModule::DoStuff
* GetStuffOut , which is connected to MyModule::GetStuffOut
  
These methods of the class MyModule are defined in MyModuleCPU.h and do what their names suggest they will do...

## The class definition of MyModule ([MyModuleCPU.h](MyModuleCPU.h))

The exported methods are public. The rest are a collection of methods to handle the data exchange between C++ and Python in a safe way.  

The exported methods do the following:

* PutStuffIn : An Numpy array arrives. GetShape extracts the shape of the numpy.ndarray and stored it into std::vector<size_t> Data_Shape;. Then it puts the numpy.ndarray into Converter and makes std::vector<double> Data_Data; out of it.
* DoStuff: Python gives double Factor to the method. The method multiplies this number with the data Data_Data from the numpy.ndarray. This is done in SIMD (single instruction multiple data) fashion using openmp. 
* GetStuffOut : It takes Data_Data and Data_Shape and makes a Python numpy.ndarray out of it and gives it to Python.

```cpp
int MyModule::PutStuffIn(py::array & Arg_Input){

        if (GetShape(Arg_Input, Data_Shape) == false){
                return false;
        }

        if (MyModule::Converter(Arg_Input, Data_Data) == false){
                return false;
        }

        return true;
}

int MyModule::DoStuff(double Factor){

        size_t Counter; 

        #pragma omp simd
        for (Counter = 0; Counter < Data_Data.size(); Counter++){
            Data_Data[Counter] *= Factor;
        }

        return true;
}

py::array MyModule::GetStuffOut(void){

        return Converter(Data_Data, Data_Shape);

}
```

## The test program ([test.py](test.py))

I think that the mathematical operation that the test code does, need no additional explanation. (A random matrix is multiplied by 5.0)


## Source code 

### .env file

**Change the directories and parameters according you system.**

```Makefile
PYBIN=~/P3.11/bin/
CC=/usr/lib64/ccache/clang++
NVCC=/usr/local/cuda-12/bin/nvcc -allow-unsupported-compiler 

PARAMETERS_O_CPU = -O3 -std=c++14 -fPIC -Wall -fopenmp=libomp
PARAMETERS_Linker_CPU = -shared -lm -lomp -lstdc++ -Wall

PARAMETERS_O_GPU= -O3 -std=c++14 -ccbin=$(CC) \
    -Xcompiler "-fPIC -Wall -fopenmp=libomp"   
PARAMETERS_Linker_GPU=-Xcompiler "-shared -lm -lomp -lstdc++ -Wall"

O_DIRS = o/
```

### Makefile

[Makefile](Makefile)

```Makefile
include .env
export

name = MyModule
type = CPU

PYPOSTFIX := $(shell $(PYBIN)python3-config --extension-suffix)
PYBIND11INCLUDE := $(shell $(PYBIN)python3 -m pybind11 --includes)
PARAMETERS_O = $(PARAMETERS_O_CPU) $(PYBIND11INCLUDE) 
PARAMETERS_Linker = $(PARAMETERS_Linker_CPU)

so_file = Py$(name)$(type)$(PYPOSTFIX)
pyi_file = Py$(name)$(type).pyi
all: $(so_file)

$(O_DIRS)$(name)$(type).o: $(name)$(type).h $(name)$(type).cpp
	mkdir -p $(O_DIRS) 
	$(CC) $(PARAMETERS_O) -c $(name)$(type).cpp -o $(O_DIRS)$(name)$(type).o

$(O_DIRS)Py$(name)$(type).o: $(name)$(type).h Py$(name)$(type).cpp 
	mkdir -p $(O_DIRS)
	$(CC) $(PARAMETERS_O) -c Py$(name)$(type).cpp -o $(O_DIRS)Py$(name)$(type).o

$(so_file): $(O_DIRS)$(name)$(type).o $(O_DIRS)Py$(name)$(type).o
	$(CC) $(PARAMETERS_Linker) -o $(so_file) $(O_DIRS)$(name)$(type).o $(O_DIRS)Py$(name)$(type).o


#######################
clean:
	rm -rf $(O_DIRS)
	rm -f $(so_file)
	rm -f $(pyi_file)
```

### PyMyModuleCPU.cpp

[PyMyModuleCPU.cpp](PyMyModuleCPU.cpp)

```cpp
#include <pybind11/pybind11.h>
#include "MyModuleCPU.h"

namespace py = pybind11;

PYBIND11_MODULE(PyMyModuleCPU, m)
{
    m.doc() = "Example Module";
    py::class_<MyModule>(m, "MyModule")
        .def(py::init<>())
        .def("PutStuffIn", &MyModule::PutStuffIn)
        .def("DoStuff", &MyModule::DoStuff)
        .def("GetStuffOut", &MyModule::GetStuffOut);
}
```

### MyModuleCPU.h

[MyModuleCPU.h](MyModuleCPU.h)

```cpp
#ifndef MYMODULECPU
#define MYMODULECPU

#include <pybind11/pybind11.h>
#include <pybind11/numpy.h>
#include <vector>

namespace py = pybind11;

class MyModule
{

    public:
    MyModule();
    ~MyModule();

    // The functionality of the module
    int PutStuffIn(py::array& Arg_Input);
    int DoStuff(double Factor);
    py::array GetStuffOut(void);

    private:
    // Example data:
    std::vector<double> Data_Data;
    std::vector<size_t> Data_Shape;

    // Private functions:
    // ==================

    // Put vector of vector<> in and get a py::list out
    py::list MakeList(std::vector<std::vector<double>>& Arg_Data,
        std::vector<std::vector<size_t>>& Arg_Shape);

    // Put vector<> in and get py::array out
    py::array Converter(std::vector<double>& Arg_Data,
        std::vector<size_t>& Arg_Shape);

    // Put a value in and get a py:array out
    py::array Converter(double& Arg_Data);

    // Put py::array in and get vector<> out
    bool Converter(py::array& Arg_In, std::vector<double>& Arg_Data);

    // Put py::list in and get vector<vector<>> out
    bool ConvertList(py::list& Arg_List,
        std::vector<std::vector<double>>& Arg_Data,
        std::vector<std::vector<size_t>>& Arg_Shape);

    // Put a py::array in and get a vector<> with the dimensions out
    bool GetShape(py::array& Arg_Input, std::vector<size_t>& Arg_Shape);

    // Put a py::list in and get a vector<vector<>> with the dimensions out
    int GetShape(py::list& Arg_List, std::vector<std::vector<size_t>>& Arg_Shape);

    // Put a py::list in and get a vector<vector<>> of the data out out
    int CopyData(py::list& Arg_List, std::vector<std::vector<double>>& Arg_Data,
        std::vector<std::vector<size_t>>& Arg_Shape);

    // Check the properties of a list
    // 0: single
    // 1: double
    // 2: uint32_t
    // 3: uint64_t
    bool CheckList(py::list& Arg_List, int Check_NumberOfDimensions,
        size_t dType);
};

#endif /* MYMODULECPU */
```
### MyModuleCPU.cpp

[MyModuleCPU.cpp](MyModuleCPU.cpp)

```cpp
#include "MyModuleCPU.h"

#include <iostream>
#include <unistd.h>
#include <cctype>

MyModule::MyModule() {};

MyModule::~MyModule() {};

int MyModule::PutStuffIn(py::array& Arg_Input)
{

    if (GetShape(Arg_Input, Data_Shape) == false)
    {
        return false;
    }

    if (MyModule::Converter(Arg_Input, Data_Data) == false)
    {
        return false;
    }

    return true;
}

int MyModule::DoStuff(double Factor)
{

    size_t Counter;

#pragma omp simd
    for (Counter = 0; Counter < Data_Data.size(); Counter++)
    {
        Data_Data[Counter] *= Factor;
    }

    return true;
}

py::array MyModule::GetStuffOut(void)
{

    return Converter(Data_Data, Data_Shape);
}

// ------------------------------------------------

py::list MyModule::MakeList(std::vector<std::vector<double>>& Arg_Data,
    std::vector<std::vector<size_t>>& Arg_Shape)
{

    py::list ReturnValue;

    if (Arg_Data.size() != Arg_Shape.size())
    {
        std::cout << "MyModule::MakeList => The sizes of the two vectors are different.\n";
        return ReturnValue;
    }

    size_t List_Pos = 0;
    for (List_Pos = 0; List_Pos < Arg_Shape.size(); List_Pos++)
    {
        std::vector<ptrdiff_t> ShapeVector;
        ShapeVector.resize(Arg_Shape[List_Pos].size());

        size_t Counter = 0;
        for (Counter = 0; Counter < Arg_Shape[List_Pos].size(); Counter++)
        {
            ShapeVector[Counter] = Arg_Shape[List_Pos].at(Counter);
        }

        auto Temp = py::array_t<double>(ShapeVector, Arg_Data[List_Pos].data());
        ReturnValue.append(Temp);
    }

    return ReturnValue;
}

py::array MyModule::Converter(std::vector<double>& Arg_Data,
    std::vector<size_t>& Arg_Shape)
{

    py::array ReturnValue;

    std::vector<ptrdiff_t> ShapeVector;
    ShapeVector.resize(Arg_Shape.size());

    size_t Counter = 0;

    for (Counter = 0; Counter < Arg_Shape.size(); Counter++)
    {
        ShapeVector[Counter] = Arg_Shape.at(Counter);
    }

    auto Temp = py::array_t<double>(ShapeVector, Arg_Data.data());

    return Temp;
}

bool MyModule::Converter(py::array& Arg_In, std::vector<double>& Arg_Data)
{

    if ((Arg_In.flags() & pybind11::detail::npy_api::NPY_ARRAY_C_CONTIGUOUS_) != pybind11::detail::npy_api::NPY_ARRAY_C_CONTIGUOUS_)
    {
        std::cout << "MyModule::Converter => Array is not c_style.\n";
        return false;
    }

    size_t Size = Arg_In.nbytes();

    if (Size == 0)
    {
        std::cout << "MyModule::Converter => Array is empty.\n";
        return false;
    }

    auto Temp_Array = Arg_In.request();
    if (py::isinstance<py::array_t<double>>(Arg_In) == false)
    {
        std::cout << "MyModule::Converter => Wrong type.\n";
        return false;
    }

    double* MyPtr = (double*)Temp_Array.ptr;
    if (MyPtr == nullptr)
    {
        std::cout << "MyModule::Converter => Pointer is null.\n";
        return false;
    }

    Arg_Data.resize(Size / sizeof(double));
    memcpy(Arg_Data.data(), MyPtr, Size);

    return true;
}

bool MyModule::ConvertList(py::list& Arg_List, std::vector<std::vector<double>>& Arg_Data,
    std::vector<std::vector<size_t>>& Arg_Shape)
{

    Arg_Data.resize(0);
    Arg_Shape.resize(0);

    // Get the shapes of all the matrices
    if (GetShape(Arg_List, Arg_Shape) != 0)
    {
        return false;
    }

    // Get the data from the list
    if (CopyData(Arg_List, Arg_Data, Arg_Shape) != 0)
    {
        return false;
    }

    return true;
}

int MyModule::GetShape(py::list& Arg_List, std::vector<std::vector<size_t>>& Arg_Shape)
{

    Arg_Shape.resize(0);

    size_t List_Length = Arg_List.size();
    Arg_Shape.resize(List_Length);

    size_t Counter_List;
    size_t Counter_Dims;

    py::array Temp_Array;
    for (Counter_List = 0; Counter_List < List_Length; Counter_List++)
    {
        Arg_Shape[Counter_List].resize(0);
        Temp_Array = Arg_List[Counter_List];

        Arg_Shape[Counter_List].resize(Temp_Array.ndim());
        for (Counter_Dims = 0; Counter_Dims < Temp_Array.ndim(); Counter_Dims++)
        {
            Arg_Shape[Counter_List][Counter_Dims] = Temp_Array.shape(Counter_Dims);
        }
    }

    return 0;
}

bool MyModule::GetShape(py::array& Arg_Input, std::vector<size_t>& Arg_Shape)
{

    Arg_Shape.resize(Arg_Input.ndim());

    size_t Counter_Dims;
    for (Counter_Dims = 0; Counter_Dims < Arg_Input.ndim(); Counter_Dims++)
    {
        Arg_Shape[Counter_Dims] = Arg_Input.shape(Counter_Dims);
    }

    return true;
}

int MyModule::CopyData(py::list& Arg_List, std::vector<std::vector<double>>& Arg_Data,
    std::vector<std::vector<size_t>>& Arg_Shape)
{

    Arg_Data.resize(0);
    size_t List_Length = Arg_List.size();
    size_t List_Pos = List_Length;

    double* MyPtr = nullptr;
    py::array Temp_Array;

    Arg_Data.resize(List_Length);

    for (List_Pos = 0; List_Pos < List_Length; List_Pos++)
    {
        MyPtr = nullptr;
        Temp_Array = Arg_List[List_Pos];

        size_t Counter = 0;
        size_t ElementsOfArray = 0;
        for (Counter = 0; Counter < Arg_Shape[List_Pos].size(); Counter++)
        {
            if (Counter == 0)
            {
                ElementsOfArray = Arg_Shape[List_Pos][Counter];
            }
            else
            {
                ElementsOfArray *= Arg_Shape[List_Pos][Counter];
            }
        }
        size_t SizeOfArray_Bytes = ElementsOfArray * sizeof(double);
        if (SizeOfArray_Bytes != Temp_Array.nbytes())
        {
            std::cout << "MyModule::CopyData => "
                << "Liste element: "
                << Counter << " is not the right amount of data.\n";
            return -1;
        }

        auto Temp_Array_f = Temp_Array.request();

        MyPtr = (double*)Temp_Array_f.ptr;

        if (MyPtr == nullptr)
        {
            std::cout << "MyModule::CopyData => "
                << "Pointer is null.\n";
            return -1;
        }

        Arg_Data[List_Pos].resize(ElementsOfArray);

        memcpy((void*)Arg_Data[List_Pos].data(), (void*)MyPtr, SizeOfArray_Bytes);
    }

    return 0;
}

py::array MyModule::Converter(double& Arg_Data)
{

    std::vector<ptrdiff_t> ShapeVector;
    ShapeVector.resize(1);
    ShapeVector[0] = 1;

    return py::array_t<double>(ShapeVector, &Arg_Data);
}

bool MyModule::CheckList(py::list& Arg_List, int Check_NumberOfDimensions,
    size_t dType)
{

    // Is it a list?
    py::handle type = Arg_List.get_type();
    py::object type_name = type.attr("__name__");
    std::string Correct_List = std::string("list");
    if (Correct_List.compare(py::cast<std::string>(type_name)) != 0)
    {
        std::cout << "MyModule => Not a list.\n";
        return false;
    }

    // Is there something in the list?
    size_t List_Length = Arg_List.size();
    if (List_Length <= 0)
    {
        std::cout << "MyModule => List is empty.\n";
        return false;
    }

    // Are the list elements numpy arrays?
    size_t Counter = 0;
    std::string Correct_NDArray = std::string("ndarray");
    for (Counter = 0; Counter < List_Length; Counter++)
    {
        type = Arg_List[Counter].get_type();
        type_name = type.attr("__name__");
        if (Correct_NDArray.compare(py::cast<std::string>(type_name)) != 0)
        {
            std::cout << "MyModule => Liste element: " << Counter << " not a numpy array .\n";
            return false;
        }
    }

    // Has every array the right dimension?
    py::array Temp_Array;
    for (Counter = 0; Counter < List_Length; Counter++)
    {
        Temp_Array = Arg_List[Counter];
        if (Temp_Array.ndim() != Check_NumberOfDimensions)
        {
            std::cout << " MyModule => Liste element: " << Counter
                << " has not the necessary "
                << Check_NumberOfDimensions << " dimensions (found: " << Temp_Array.ndim() << ").\n";
            return false;
        }
    }

    // Are all the numpy arrays c_style?
    for (Counter = 0; Counter < List_Length; Counter++)
    {
        Temp_Array = Arg_List[Counter];
        if ((Temp_Array.flags() & pybind11::detail::npy_api::NPY_ARRAY_C_CONTIGUOUS_) != pybind11::detail::npy_api::NPY_ARRAY_C_CONTIGUOUS_)
        {
            std::cout << "MyModule => Liste element: " << Counter << " is not c_style.\n";
            return false;
        }
    }

    // 0: single
    // 1: double
    // 2: uint32_t
    // 3: uint64_t
    for (Counter = 0; Counter < List_Length; Counter++)
    {
        Temp_Array = Arg_List[Counter];

        // Float
        if (dType == 0)
        {
            if (py::isinstance<py::array_t<float>>(Temp_Array) == false)
            {
                std::cout << "MyModule => Liste element: " << Counter << " is not a float.\n";
                return -1;
            }
        }

        // Double
        if (dType == 1)
        {
            if (py::isinstance<py::array_t<double>>(Temp_Array) == false)
            {
                std::cout << "MyModule => Liste element: " << Counter << " is not a double.\n";
                return false;
            }
        }

        // uint32_t
        if (dType == 2)
        {
            if (py::isinstance<py::array_t<uint32_t>>(Temp_Array) == false)
            {
                std::cout << "MyModule => Liste element: " << Counter << " is not a uint32.\n";
                return false;
            }
        }

        // uint64_t
        if (dType == 3)
        {
            if (py::isinstance<py::array_t<uint64_t>>(Temp_Array) == false)
            {
                std::cout << "MyModule => Liste element: " << Counter << " is not a uint64.\n";
                return false;
            }
        }
    }
    return true;
}
```

### test.py

[test.py](test.py)

```python
from PyMyModuleCPU import MyModule
import numpy as np

MyCExtension = MyModule()

X = np.random.random((5, 6))

print("X")
print(X)

if MyCExtension.PutStuffIn(X) is False:
    print("Error (1)\n")
    exit()

Y = MyCExtension.GetStuffOut()

print("X-Y:")
print(X - Y)

if MyCExtension.DoStuff(5.0) is False:
    print("Error (2)\n")
    exit()

Z = MyCExtension.GetStuffOut()

print("X*5-Z:")
print(X * 5.0 - Z)

```


## Reference 

* [PyBind11](https://pybind11.readthedocs.io/en/stable/)

