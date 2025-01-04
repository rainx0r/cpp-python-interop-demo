#include <pybind11/pybind11.h>
#include "custom_module.cpp"

namespace py = pybind11;

PYBIND11_MODULE(cpp_python_interop, m) {
    m.def("my_function", &my_function, "Process mjData");
}
