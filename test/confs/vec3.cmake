set(TEST_TARGET "vec3")

set(TEST_SOURCE suites/vec3.c)

list(
    APPEND
    TEST_LIB_SOURCE
    vec3.c
)

list(
    APPEND
    TEST_DEFS
    GLUG_EXTERN_START=
    GLUG_EXTERN_END=
)
