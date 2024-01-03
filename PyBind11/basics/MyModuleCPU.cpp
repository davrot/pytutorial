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