set(TEST_TARGET "sphere")

set(TEST_SOURCE suites/sphere.c)

list(
    APPEND
    TEST_LIB_SOURCE
    sphere.c
    vec3.c
    float.c
)

list(
    APPEND
    TEST_MOCK_SOURCE
    mocks/glug/bool_t.h
    mocks/glug/import.h
)


list(
    APPEND
    TEST_DEFS
    GLUG_EXTERN_START=
    GLUG_EXTERN_END=
)
