set(TEST_TARGET "sphere")

set(TEST_SOURCE suites/sphere.c)

list(
    APPEND
    TEST_LIB_SOURCE
    sphere.c
    vec3.c
)

list(
    APPEND
    TEST_DEFS
    GLUG_EXTERN_START=
    GLUG_EXTERN_END=
)
