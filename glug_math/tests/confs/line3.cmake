set(TEST_TARGET "line3")

set(TEST_SOURCE suites/line3.c)

list(
    APPEND
    TEST_LIB_SOURCE
    line3.c
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
