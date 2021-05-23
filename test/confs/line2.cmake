set(TEST_TARGET "line2")

set(TEST_SOURCE suites/line2.c)

list(
    APPEND
    TEST_LIB_SOURCE
    line2.c
    vec2.c
)

list(
    APPEND
    TEST_DEFS
    GLUG_EXTERN_START=
    GLUG_EXTERN_END=
)
