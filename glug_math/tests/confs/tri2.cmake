set(TEST_TARGET "tri2")

set(TEST_SOURCE suites/tri2.c)

list(
    APPEND
    TEST_LIB_SOURCE
    triangle2.c
    vec2.c
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
