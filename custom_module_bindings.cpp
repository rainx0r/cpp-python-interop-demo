#include <pybind11/pybind11.h>
#include <mujoco/mujoco.h>
#include "custom_module.cpp"

namespace py = pybind11;

PYBIND11_MODULE(cpp_python_interop, m) {
    m.def("my_function", [](py::object d) {
        std::uintptr_t d_raw = d.attr("_address").cast<std::uintptr_t>();
        mjData* d_cpp_ = reinterpret_cast<mjData*>(d_raw);
        my_function(d_cpp_);
    }, "Process mjData");
}
