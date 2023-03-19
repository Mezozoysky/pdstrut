cmake_minimum_required(VERSION 3.13)

project(PDSTRUT
    LANGUAGES CXX
    VERSION 0.1.0
)

set(PDSTRUT_VERSION ${PROJECT_VERSION})

list(PREPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake/modules")

set(PDSTRUT_BUILD_SHARED_DEFAULT ${BUILD_SHARED_LIBS})
set(PDSTRUT_BUILD_UT_DEFAULT TRUE)

option(PDSTRUT_BUILD_SHARED "Build shared libraries" ${PDSTRUT_BUILD_SHARED_DEFAULT})
option(PDSTRUT_BUILD_UT "Build unit tests" ${PDSTRUT_BUILD_UT_DEFAULT})

add_library(common INTERFACE)
add_library(PDSTRUT::common ALIAS common)
target_compile_options(common
    INTERFACE
    $<$<CXX_COMPILER_ID:MSVC>:/Wall>
    $<$<CXX_COMPILER_ID:GNU,Clang>:-Wall -Wextra>
    )

add_subdirectory(dependencies)
add_subdirectory(sources)
