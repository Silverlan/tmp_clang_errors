#include <iostream>

import test_module;

int main() {
    test_func();
    std::cout<<"test_func address (main): "<<((void*)&test_func)<<std::endl;
    return 0;
}
