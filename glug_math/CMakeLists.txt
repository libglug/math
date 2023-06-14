cmake_minimum_required(VERSION 3.7)
include(CMakePackageConfigHelpers)

include(cmake/version.cmake)

include(cmake/detect_os.cmake)
include(cmake/set_compilation_props.cmake)
include(cmake/link_libs.cmake)
include(cmake/set_export_defs.cmake)

parse_git_tag_version(VER_MAJOR VER_MINOR VER_PATCH VER_META VER_REV VER_HASH VER_FULL)
set(FULL_VERSION ${VER_MAJOR}.${VER_MINOR}.${VER_PATCH}-${VER_META})

project(
    glug_math
    LANGUAGES
        C
    VERSION
        ${VER_MAJOR}.${VER_MINOR}.${VER_PATCH}
)

option(BUILD_STATIC "Build as a static library instead of shared?" OFF)

detect_os(IS_WIN IS_OSX IS_LIN IS_BSD)

# configure files
set(CONFIGURED_OUT_ROOT ${CMAKE_CURRENT_BINARY_DIR}/configured)
configure_file(include/glug/math/version.h.in ${CONFIGURED_OUT_ROOT}/include/glug/math/version.h)

include(common_src.cmake)

# set the library type
set(LIB_TYPE SHARED)
if (BUILD_STATIC)
    set(LIB_TYPE STATIC)
endif()

if (${IS_LIN})
    set(PLATFORM_LIBS
        bsd)
endif()

add_library(
    glug_math
    SHARED
    ${COMMON_SOURCE}
#    ${BINDINGS}
)

add_library(glug::math ALIAS glug_math)

link_libs(glug_math "${PLATFORM_LIBS}")
set_export_defs(glug_math ${BUILD_STATIC} ${IS_WIN})

target_compile_definitions(
    glug_math
    PRIVATE
        _WIN32_WINNT=0x0601
)

target_include_directories(
    glug_math
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<BUILD_INTERFACE:${CONFIGURED_OUT_ROOT}/include> # because "version.h" is a configured file
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/common_headers/include>
    PRIVATE
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>
    INTERFACE
        $<INSTALL_INTERFACE:include>
)

set(PROJECT_CONFIG_FILE glug_math-config.cmake)
configure_package_config_file(
    cmake/config.cmake.in
    ${PROJECT_CONFIG_FILE}
    INSTALL_DESTINATION
        cmake
)

# install the lib's headers
install(
    DIRECTORY
        include/
    DESTINATION
        include
    FILES_MATCHING
        PATTERN "*"
        PATTERN "*.in" EXCLUDE
)

# install the lib's configured version file
install(
    FILES
        ${CONFIGURED_OUT_ROOT}/include/glug/math/version.h
    DESTINATION
        include/glug/math
)

# install the common_headers
install(
    DIRECTORY
        common_headers/include/
    DESTINATION
        include
    FILES_MATCHING
        PATTERN "*"
        PATTERN "*.in$" EXCLUDE
)

# install the library and its exports
install(
    TARGETS
        glug_math
    EXPORT
        glug_math-targets
    RUNTIME DESTINATION
        lib
    LIBRARY DESTINATION
        lib
    ARCHIVE DESTINATION
        lib
)

# export the package to be included in other projects
install(
    EXPORT
        glug_math-targets
    FILE
        glug_math-targets.cmake
    NAMESPACE
        glug::
    DESTINATION
        cmake
)
export(
    EXPORT
        glug_math-targets
    FILE
        glug_math-config.cmake
    NAMESPACE
        glug::
)

export(PACKAGE glug_math)

enable_testing()
add_subdirectory(tests)
