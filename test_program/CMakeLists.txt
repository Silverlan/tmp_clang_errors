cmake_minimum_required(VERSION 3.3)

message(STATUS "CMake version: ${CMAKE_VERSION}")

set(CMAKE_CXX_STANDARD 23)

set(TEST_CASE 0 CACHE STRING "Test Case")

project(test_program LANGUAGES CXX)

add_subdirectory(test_library)

add_executable(test_program main.cpp)

target_compile_definitions(test_program PRIVATE "-DTEST_CASE=${TEST_CASE}")

target_link_libraries(test_program PUBLIC test_library)

if(UNIX)
    set_target_properties(test_program PROPERTIES INSTALL_RPATH "\$ORIGIN")
endif()

install(TARGETS test_program test_library DESTINATION .)
