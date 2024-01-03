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
