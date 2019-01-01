include(${PROJECT_SOURCE_DIR}/cmake/macros/add_gluglib.cmake)

set(SRC_ROOT src)
set(INC_ROOT include/glug)

list(
    APPEND
    COMMON_SOURCE
    ${INC_ROOT}/math.h
    ${INC_ROOT}/math/box_t.h
    ${INC_ROOT}/math/box.h
    ${SRC_ROOT}/box.c
    ${INC_ROOT}/math/circle_t.h
    ${INC_ROOT}/math/circle.h
    ${SRC_ROOT}/circle.c
    ${INC_ROOT}/math/rect_t.h
    ${INC_ROOT}/math/rect.h
    ${SRC_ROOT}/rect.c
    ${INC_ROOT}/math/sphere_t.h
    ${INC_ROOT}/math/sphere.h
    ${SRC_ROOT}/sphere.c
    ${INC_ROOT}/math/vec2_t.h
    ${INC_ROOT}/math/vec2.h
    ${SRC_ROOT}/vec2.c
    ${INC_ROOT}/math/vec3_t.h
    ${INC_ROOT}/math/vec3.h
    ${SRC_ROOT}/vec3.c
    ${INC_ROOT}/math/vec4_t.h
    ${INC_ROOT}/math/vec4.h
    ${SRC_ROOT}/vec4.c
)

list(
    APPEND
    WIN32_SOURCE
    ${COMMON_SOURCE}
    # add win32 specific source files
)

list(
    APPEND
    MACOS_SOURCE
    ${COMMON_SOURCE}
    # add macos specific source files
)

list(
    APPEND
    LINUX_SOURCE
    ${COMMON_SOURCE}
    # add linux specific source files
)

set(GLUG_TARGET_NAME ${CMAKE_PROJECT_NAME})

add_gluglib(
    TARGET_NAME ${GLUG_TARGET_NAME}
    WIN32_SOURCE ${WIN32_SOURCE}
    MACOS_SOURCE ${MACOS_SOURCE}
    LINUX_SOURCE ${LINUX_SOURCE}
)

# install the library
install(
    TARGETS ${GLUG_TARGET_NAME}
    DESTINATION ${GLUG_DIST_LIBR_DIR}
)

install(
    TARGETS ${GLUG_TARGET_NAME}
    DESTINATION ${GLUG_DIST_XMPL_DIR}
)
