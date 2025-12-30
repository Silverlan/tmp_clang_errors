
export module test_module;

#ifdef _WIN32
#define API __declspec(dllexport)
#else
#define API __attribute__((visibility("default")))
#endif

export {
    struct API TestVector {
        float x;
        float y;
        float z;
    };
}

export namespace test {
    constexpr TestVector test_vector = TestVector{1.f,2.f,3.f};
    API void test_function(const TestVector &v)
    {
    }
}
