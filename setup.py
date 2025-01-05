import pathlib

import mujoco
from pybind11.setup_helpers import Pybind11Extension, build_ext
from setuptools import setup

ext_modules = [
    Pybind11Extension(
        "cpp_python_interop",
        ["custom_module_bindings.cpp"],
        include_dirs=[pathlib.Path(mujoco.HEADERS_DIR).parent],
    ),
]

setup(
    name="cpp_python_interop",
    ext_modules=ext_modules,
    cmdclass={"build_ext": build_ext},
)
