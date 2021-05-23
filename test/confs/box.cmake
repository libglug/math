set(TEST_TARGET "box")

set(TEST_SOURCE suites/box.c)

list(
    APPEND
    TEST_LIB_SOURCE
    box.c
    vec3.c
)

list(
    APPEND
    TEST_DEFS
    GLUG_EXTERN_START=
    GLUG_EXTERN_END=
)
