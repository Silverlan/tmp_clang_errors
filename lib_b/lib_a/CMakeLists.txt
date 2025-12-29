cmake_minimum_required(VERSION 3.3)

set(CMAKE_EXPERIMENTAL_CXX_IMPORT_STD "d0edc3af-4c50-42ea-a356-e2862fe7a444")
set(CMAKE_CXX_STANDARD 23)
# set(CMAKE_CXX_MODULE_STD 1)

project(lib_b LANGUAGES CXX)

add_library(lib_b SHARED)

target_sources(lib_b PRIVATE FILE_SET cxx_modules TYPE CXX_MODULES FILES b.cppm)
