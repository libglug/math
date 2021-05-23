set(TEST_TARGET "rect")

set(TEST_SOURCE suites/rect.c)

list(
    APPEND
    TEST_LIB_SOURCE
    rect.c
    vec2.c
)

list(
    APPEND
    TEST_DEFS
    GLUG_EXTERN_START=
    GLUG_EXTERN_END=
)
