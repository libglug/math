add_subdirectory(cunit/CUnit)

add_executable(
    UnitTests
    main.c
    suites/vec2.c
    suites/vec3.c
)

find_package(glug_math REQUIRED)

add_custom_command(
    OUTPUT
        ${CMAKE_CURRENT_BINARY_DIR}/CUnit
    COMMAND
        ${CMAKE_COMMAND} -E copy $<TARGET_FILE:CUnit> ${CMAKE_CURRENT_BINARY_DIR}
    DEPENDS
        CUnit
)

add_custom_target(
    copy_cunit
    ALL
    DEPENDS
        ${CMAKE_CURRENT_BINARY_DIR}/CUnit
)

target_link_libraries(
    UnitTests
    CUnit
    glug_math
)
