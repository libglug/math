project(glug_math_tests VERSION 1.0)
add_subdirectory(cunit/CUnit)

add_executable(
    ${PROJECT_NAME}
    main.c
    suites/box.c
    suites/circle.c
    suites/line2.c
    suites/line3.c
    suites/plane.c
    suites/rect.c
    suites/sphere.c
    suites/vec2.c
    suites/vec3.c
    suites/vec4.c
)

# copy the executable to this build directory (MSVC likes to hide it in Debug/Release folders)
add_custom_command(
    TARGET
        ${PROJECT_NAME} POST_BUILD
    COMMAND
        ${CMAKE_COMMAND} -E copy_if_different
            $<TARGET_FILE:${PROJECT_NAME}> ${CMAKE_CURRENT_BINARY_DIR}
)

# copy the CUnit library to the same directory
add_custom_command(
    TARGET
        ${PROJECT_NAME} POST_BUILD
    COMMAND
        ${CMAKE_COMMAND} -E copy
            $<TARGET_FILE:CUnit> ${CMAKE_CURRENT_BINARY_DIR}
)

# also copy the math library to the same directory
add_custom_command(
    TARGET
        ${PROJECT_NAME} POST_BUILD
    COMMAND
        ${CMAKE_COMMAND} -E copy
            $<TARGET_FILE:glug_math> ${CMAKE_CURRENT_BINARY_DIR}
)

find_package(glug_math REQUIRED)

target_link_libraries(
    ${PROJECT_NAME}
    CUnit
    glug_math
)

find_library(CMATH m)
if (CMATH)
    target_link_libraries(
        ${PROJECT_NAME}
        ${CMATH}
    )
endif()
