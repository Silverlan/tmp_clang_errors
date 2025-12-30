@echo off
setlocal

clang++.exe -std=c++20 test_module\test_module.cppm --precompile -o test_module\test_module.pcm
clang++.exe -std=c++20 test_module\test_module.pcm -c -o test_module\test_module.o
clang++.exe -shared -o test_module\test_module.dll test_module\test_module.o -Wl,/IMPLIB:test_module\test_module.lib
clang++.exe -std=c++20 main.cpp -fprebuilt-module-path=test_module -c -o main.o -DTEST_CASE=%1
clang++.exe main.o test_module\test_module.lib -o app.exe
.\app.exe

endlocal
