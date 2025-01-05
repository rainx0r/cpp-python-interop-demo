#include <nanobind/nanobind.h>
#include <mujoco/mujoco.h>
#include "custom_module.cpp"

namespace nb = nanobind;

NB_MODULE(cpp_python_interop, m) {
    m.def("my_function", [](nb::object d) {
        std::uintptr_t ptr = nb::cast<std::uintptr_t>(d.attr("_address"));
        /*std::uintptr_t d_raw = d.attr("_address").cast<std::uintptr_t>();*/
        mjData* d_cpp_ = reinterpret_cast<mjData*>(ptr);
        my_function(d_cpp_);
    }, "Process mjData");
}
