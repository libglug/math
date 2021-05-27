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
    TEST_MOCK_SOURCE
    mocks/glug/bool_t.h
    mocks/glug/import.h
)


list(
    APPEND
    TEST_DEFS
    GLUG_EXTERN_START=
    GLUG_EXTERN_END=
)
