set(TEST_TARGET "tri3")

set(TEST_SOURCE suites/tri3.c)

list(
    APPEND
    TEST_LIB_SOURCE
    triangle3.c
    vec3.c
)

list(
    APPEND
    TEST_DEFS
    GLUG_EXTERN_START=
    GLUG_EXTERN_END=
)
