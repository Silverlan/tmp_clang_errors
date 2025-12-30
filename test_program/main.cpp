#include <iostream>

import test_module;

// Test Case 0: Access member of constexpr vector from module test_module
// Result: Build successful
#if TEST_CASE == 0

int main() {
    std::cout<<test::cexpr_test_vector.x<<std::endl;
    return 0;
}

#endif

// Test Case 1: Call test_function from module test_module with constexpr vector
// Result: lld-link: error: undefined symbol: struct TestVector const test::cexpr_test_vector
#if TEST_CASE == 1

int main() {
    test::test_function(test::cexpr_test_vector);
    return 0;
}

#endif

// Test Case 2: Same as Test Case 1, but with locally created vector
// Result: Build successful
#if TEST_CASE == 2

int main() {
    test::test_function(TestVector {1.f, 2.f, 3.4});
    return 0;
}

#endif

// Test Case 3: Calling a locally defined function with constexpr vector as argument
// Result: Build successful
#if TEST_CASE == 3

static void print_vec(const TestVector v)
{
    std::cout<<v.x<<","<<v.y<<","<<v.z<<std::endl;
}

int main() {
    print_vec(test::cexpr_test_vector);
    return 0;
}

#endif

// Test Case 4: Same as Test Case 3, but with optimization turned off
// Result: lld-link: error: undefined symbol: struct TestVector const test::cexpr_test_vector
#if TEST_CASE == 4

#pragma clang optimize off
static void print_vec(const TestVector v)
{
    std::cout<<v.x<<","<<v.y<<","<<v.z<<std::endl;
}

int main() {
    print_vec(test::cexpr_test_vector);
    return 0;
}
#pragma clang optimize on

#endif

// Test Case 5: Same as Test Case 0, but using dllexported vector instead of constexpr
// Result: lld-link: error: undefined symbol: struct TestVector test::dllexp_test_vector
#if TEST_CASE == 5

int main() {
    std::cout<<test::dllexp_test_vector.x<<std::endl;
    return 0;
}

#endif

// Test Case 6: Same as Test Case 0, but using dllexported getter-function for vector instead of constexpr
// Result: Build successful
#if TEST_CASE == 6

int main() {
    std::cout<<test::dllexp_get_test_vector().x<<std::endl;
    return 0;
}

#endif
