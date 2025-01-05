#include "custom_module.cpp"
#include <mujoco/mujoco.h>
#include <nanobind/nanobind.h>

namespace nb = nanobind;

NB_MODULE(cpp_python_interop, m) {
  m.def(
      "my_function",
      [](nb::object d) {
        std::uintptr_t ptr = nb::cast<std::uintptr_t>(d.attr("_address"));
        mjData *d_cpp_ = reinterpret_cast<mjData *>(ptr);
        my_function(d_cpp_);
      },
      "Process mjData");
}
