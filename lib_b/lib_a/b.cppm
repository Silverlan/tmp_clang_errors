
export module test_module;

struct Vector3 {
    float x;
    float y;
    float z;
}

export namespace test {
    constexpr Vector3 A = Vector3 {1.f,2.f,3.f};
}
