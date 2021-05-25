set(TEST_TARGET "mat2")

set(TEST_SOURCE suites/mat2.c)

list(
    APPEND
    TEST_LIB_SOURCE
    mat2.c
    float.c
)

list(
    APPEND
    TEST_DEFS
    GLUG_EXTERN_START=
    GLUG_EXTERN_END=
)
