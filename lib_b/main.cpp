#include <iostream>

import test_module;

int main() {
    std::cout<<"VecA: "<<test::A.x<<","<<test::A.y<<","<<test::A.z<<std::endl;
    std::cout<<"VecB: "<<test::B.x<<","<<test::B.y<<","<<test::B.z<<std::endl;
    std::cout << "Hello World from Clang " << __clang_version__ << "!" << std::endl;
    return 0;
}