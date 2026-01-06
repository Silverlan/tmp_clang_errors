
module;

#include <iostream>

export module test_module;

#ifdef _WIN32
#define API __declspec(dllexport)
#else
#define API __attribute__((visibility("default")))
#endif

export {
    API void test_func() {
        std::cout<<"test_func address (test_module): "<<((void*)&test_func)<<std::endl;
    }
}
