
export module test_module;

export import glm;

#ifdef _WIN32
#define API __declspec(dllexport)
#else
#define API __attribute__((visibility("default")))
#endif

export namespace test {
    constexpr API extern glm::vec3 test_vector = glm::vec3{1.f,2.f,3.f};
    API void test_function(const glm::vec3 &v)
    {
    }
}
