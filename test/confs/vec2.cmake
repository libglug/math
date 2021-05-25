set(TEST_TARGET "vec2")

set(TEST_SOURCE suites/vec2.c)

list(
    APPEND
    TEST_LIB_SOURCE
    vec2.c
)

list(
    APPEND
    TEST_DEFS
    GLUG_EXTERN_START=
    GLUG_EXTERN_END=
)
