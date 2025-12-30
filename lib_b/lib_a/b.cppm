
export module test_module;

export import glm;

export namespace test {
    constexpr glm::vec3 test_vector = glm::vec3{1.f,2.f,3.f};
    __declspec(dllexport) void test_function(const glm::vec3 &v)
    {
    }
}
