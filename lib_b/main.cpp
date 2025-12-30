#include <iostream>

import test_module;

#if TEST_CASE == 4
#pragma clang optimize off
#endif

#if TEST_CASE == 3 || TEST_CASE == 4
static void print_vec(const glm::vec3 v)
{
    std::cout<<v.x<<","<<v.y<<","<<v.z<<std::endl;
}
#endif

int main() {
#if TEST_CASE == 0
    // Build successful
    std::cout<<test::test_vector.x<<std::endl;
#elif TEST_CASE == 1
    // lld-link: error: undefined symbol: struct glm::vec<3, float, 0> const test::test_vector
    std::cout<<test::test_vector<<std::endl;
#elif TEST_CASE == 2
    // lld-link: error: undefined symbol: struct glm::vec<3, float, 0> const test::test_vector
    test::test_function(test::test_vector);
#else
    // TEST_CASE == 3: Build successful
    // TEST_CASE == 4: lld-link: error: undefined symbol: struct glm::vec<3, float, 0> const test::test_vector
    print_vec(test::test_vector);
#endif
    return 0;
}
#if TEST_CASE == 4
#pragma clang optimize on
#endif
