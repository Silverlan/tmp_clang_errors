cmake_minimum_required(VERSION 4.0)

set(CMAKE_EXPERIMENTAL_CXX_IMPORT_STD "d0edc3af-4c50-42ea-a356-e2862fe7a444")
set(CMAKE_CXX_STANDARD 23)
# set(CMAKE_CXX_MODULE_STD 1)

project(lib_a LANGUAGES CXX)

add_subdirectory(glm_cxxmodule)

add_library(lib_a SHARED)

target_link_libraries(lib_a PUBLIC glm_module)

# glm/glm/glm.cppm

target_sources(lib_a PUBLIC FILE_SET cxx_modules TYPE CXX_MODULES FILES b.cppm)
