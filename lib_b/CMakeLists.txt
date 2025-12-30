cmake_minimum_required(VERSION 4.0)

message(STATUS "CMake version: ${CMAKE_VERSION}")

set(CMAKE_CXX_STANDARD 23)

set(TEST_CASE 0 CACHE STRING "Test Case")

project(lib_b LANGUAGES CXX)

add_subdirectory(lib_a)

add_executable(lib_b main.cpp)

target_compile_definitions(lib_b PRIVATE "-DTEST_CASE=${TEST_CASE}")

target_link_libraries(lib_b PUBLIC lib_a)

install(TARGETS lib_b lib_a DESTINATION .)
