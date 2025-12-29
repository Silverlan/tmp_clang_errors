#include <iostream>

import test_module;

int main() {
    std::cout<<"Vec: "<<test::A.x<<","<<test::A.y<<","<<test::A.z<<std::endl;
    std::cout << "Hello World from Clang " << __clang_version__ << "!" << std::endl;
    return 0;
}