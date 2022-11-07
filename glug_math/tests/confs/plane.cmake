set(TEST_TARGET "plane")

set(TEST_SOURCE suites/plane.c)

list(
    APPEND
    TEST_LIB_SOURCE
    plane.c
    vec3.c
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
