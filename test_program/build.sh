#!/bin/bash

set -e
clang++ -std=c++20 test_module/test_module.cppm --precompile -o test_module/test_module.pcm
clang++ -std=c++20 test_module/test_module.pcm -c -o test_module/test_module.o
clang++ -shared -o test_module/libtest_module.so test_module/test_module.o
clang++ -std=c++20 main.cpp -fprebuilt-module-path=test_module -c -o main.o -DTEST_CASE="$1"
clang++ main.o test_module/libtest_module.so -o app
