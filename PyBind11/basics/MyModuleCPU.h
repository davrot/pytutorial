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
