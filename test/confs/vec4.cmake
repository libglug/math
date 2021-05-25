set(TEST_TARGET "vec4")

set(TEST_SOURCE suites/vec4.c)

list(
    APPEND
    TEST_LIB_SOURCE
    vec4.c
)

list(
    APPEND
    TEST_DEFS
    GLUG_EXTERN_START=
    GLUG_EXTERN_END=
)
