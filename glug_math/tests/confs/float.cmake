set(TEST_TARGET "float")

set(TEST_SOURCE suites/float.c)

list(
    APPEND
    TEST_LIB_SOURCE
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
