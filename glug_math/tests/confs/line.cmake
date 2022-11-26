set(TEST_TARGET "line")

set(TEST_SOURCE suites/line.c)

list(
    APPEND
    TEST_LIB_SOURCE
    line.c
    vec3.c
    mat2.c
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
