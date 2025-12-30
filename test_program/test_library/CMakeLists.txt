cmake_minimum_required(VERSION 3.3)

set(CMAKE_CXX_STANDARD 23)

project(test_library LANGUAGES CXX)

add_library(test_library SHARED)

target_sources(test_library PUBLIC FILE_SET cxx_modules TYPE CXX_MODULES FILES test_module.cppm glm/glm/glm.cppm)
