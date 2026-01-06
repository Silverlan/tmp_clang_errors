
module;

#include <iostream>

export module test_module;

export {
    __declspec(dllexport) void test_func() {
        std::cout<<"test_func address (test_module): "<<((void*)&test_func)<<std::endl;
    }
}
