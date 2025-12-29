cmake_minimum_required(VERSION 3.3)

set(CMAKE_EXPERIMENTAL_CXX_IMPORT_STD "d0edc3af-4c50-42ea-a356-e2862fe7a444")
set(CMAKE_CXX_STANDARD 23)

project(lib_b LANGUAGES CXX)

add_subdirectory(lib_a)

add_executable(lib_b main.cpp)

target_link_libraries(lib_b PUBLIC lib_a)
