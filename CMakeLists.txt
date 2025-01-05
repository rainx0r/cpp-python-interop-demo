if(NOT DEFINED MUJOCO_HEADER_DIR)
    message(FATAL_ERROR "MUJOCO_HEADER_DIR must be provided. Use -DMUJOCO_HEADER_DIR=/path/to/mujoco to set it.")
endif()

cmake_minimum_required(VERSION 3.15...3.27)
project(cpp_interop_demo)

if (CMAKE_VERSION VERSION_LESS 3.18)
  set(DEV_MODULE Development)
else()
  set(DEV_MODULE Development.Module)
endif()

find_package(Python 3.8 COMPONENTS Interpreter ${DEV_MODULE} REQUIRED)

if (NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
  set(CMAKE_BUILD_TYPE Release CACHE STRING "Choose the type of build." FORCE)
  set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS "Debug" "Release" "MinSizeRel" "RelWithDebInfo")
endif()

execute_process(
  COMMAND "${Python_EXECUTABLE}" -m nanobind --cmake_dir
  OUTPUT_STRIP_TRAILING_WHITESPACE OUTPUT_VARIABLE nanobind_ROOT)
find_package(nanobind CONFIG REQUIRED)

nanobind_add_module(cpp_interop_demo custom_module_bindings.cpp)
target_include_directories(cpp_interop_demo PRIVATE ${MUJOCO_HEADER_DIR})
