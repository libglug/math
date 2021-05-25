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
    TEST_DEFS
    GLUG_EXTERN_START=
    GLUG_EXTERN_END=
)
