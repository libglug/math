add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/cunit/CUnit EXCLUDE_FROM_ALL)

find_package(glug_math REQUIRED)

set(LIB_SRC_ROOT ${CMAKE_SOURCE_DIR}/glug_math/src)
set(LIB_INC_ROOT ${CMAKE_SOURCE_DIR}/glug_math/include)

function(add_test_by_conf TEST_ROOT TEST_CONF)
    include(${TEST_ROOT}/${TEST_CONF})
    set(TEST_TARGET "test-${TEST_TARGET}")

    list(
        TRANSFORM
            TEST_SOURCE
        PREPEND
            ${TEST_ROOT}/
    )

    list(
        TRANSFORM
            TEST_LIB_SOURCE
        PREPEND
            ${LIB_SRC_ROOT}/
    )

    list(
        TRANSFORM
            TEST_MOCK_SOURCE
        PREPEND
            ${TEST_ROOT}/utils/
    )

    add_executable(
        ${TEST_TARGET}
        EXCLUDE_FROM_ALL
        ${TEST_SOURCE}
        ${TEST_LIB_SOURCE}
        ${TEST_MOCK_SOURCE}
        ${TEST_ROOT}/utils/suites/create_suite.h
        ${TEST_ROOT}/utils/suites/create_suite.c
        ${TEST_ROOT}/utils/asserts/asserts.h
        ${TEST_ROOT}/utils/asserts/asserts.c
    )

    target_include_directories(
        ${TEST_TARGET}
        PRIVATE
            ${TEST_ROOT}/utils
            ${TEST_ROOT}/utils/mocks
            ${LIB_SRC_ROOT}
            ${LIB_INC_ROOT}
            ${TEST_INCLUDE_DIRS}
    )

    target_link_libraries(
        ${TEST_TARGET}
        CUnit
    )

    find_library(CMATH m)
    if (CMATH)
        target_link_libraries(
            ${TEST_TARGET}
            ${CMATH}
        )
    endif()

    target_compile_definitions(
        ${TEST_TARGET}
        PRIVATE
            GLUG_LIB_LOCAL=
            GLUG_LIB_API=
    )

    foreach(DEF IN LISTS TEST_DEFS)
        target_compile_definitions(
            ${TEST_TARGET}
            PRIVATE
                ${DEF}
        )
    endforeach()

    foreach(MOCK IN LISTS TEST_MOCKS)
        target_compile_definitions(
            ${TEST_TARGET}
            PRIVATE
                ${MOCK}=${MOCK}_mocked
        )
    endforeach()

    list(
        APPEND
        TEST_TARGETS
        ${TEST_TARGET}
    )

    add_test(${TEST_TARGET} ${TEST_TARGET})
    set(TEST_TARGETS ${TEST_TARGETS} PARENT_SCOPE)

endfunction()

# unit tests
list(
    APPEND
    TEST_TARGETS
)

add_test_by_conf(${CMAKE_CURRENT_LIST_DIR} confs/box.cmake)
add_test_by_conf(${CMAKE_CURRENT_LIST_DIR} confs/circle.cmake)
add_test_by_conf(${CMAKE_CURRENT_LIST_DIR} confs/line2.cmake)
add_test_by_conf(${CMAKE_CURRENT_LIST_DIR} confs/line3.cmake)
add_test_by_conf(${CMAKE_CURRENT_LIST_DIR} confs/mat2.cmake)
add_test_by_conf(${CMAKE_CURRENT_LIST_DIR} confs/plane.cmake)
add_test_by_conf(${CMAKE_CURRENT_LIST_DIR} confs/rect.cmake)
add_test_by_conf(${CMAKE_CURRENT_LIST_DIR} confs/sphere.cmake)
add_test_by_conf(${CMAKE_CURRENT_LIST_DIR} confs/tri2.cmake)
add_test_by_conf(${CMAKE_CURRENT_LIST_DIR} confs/tri3.cmake)
add_test_by_conf(${CMAKE_CURRENT_LIST_DIR} confs/vec2.cmake)
add_test_by_conf(${CMAKE_CURRENT_LIST_DIR} confs/vec3.cmake)
add_test_by_conf(${CMAKE_CURRENT_LIST_DIR} confs/vec4.cmake)

foreach(TEST_TARGET IN LISTS TEST_TARGETS)
    add_custom_command(
        TARGET
            ${TEST_TARGET} POST_BUILD
        # copy the CUnit library to the same directory as the test binaries
        COMMAND
            ${CMAKE_COMMAND} -E copy_if_different
                $<TARGET_FILE:CUnit> $<TARGET_FILE_DIR:${TEST_TARGET}>
    )
endforeach()

# add the "check" target to build all tests
add_custom_target(
    check
    DEPENDS
        ${TEST_TARGETS}
)
