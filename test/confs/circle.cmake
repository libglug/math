set(TEST_TARGET "circle")

set(TEST_SOURCE suites/circle.c)

list(
    APPEND
    TEST_LIB_SOURCE
    circle.c
    vec2.c
)

list(
    APPEND
    TEST_DEFS
    GLUG_EXTERN_START=
    GLUG_EXTERN_END=
)
