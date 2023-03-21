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

option(PDSTRUT_CHAR_CHAR "Build with default char/uchar char type" TRUE)
option(PDSTRUT_CHAR_WCHAR "Build with wchar char type" TRUE)
option(PDSTRUT_CHAR_U16CHAR "Build with u16char char type" TRUE)
option(PDSTRUT_CHAR_U32CHAR "Build with u32char char type" TRUE)

add_library(common INTERFACE)
add_library(PDSTRUT::common ALIAS common)
target_compile_options(common
    INTERFACE
    $<$<CXX_COMPILER_ID:MSVC>:/Wall>
    $<$<CXX_COMPILER_ID:GNU,Clang>:-Wall -Wextra>
    )
if(PDSTRUT_CHAR_CHAR)
    target_compile_definitions(common INTERFACE PDSTRUT_CHAR_CHAR=1)
endif()
if(PDSTRUT_CHAR_WCHAR)
    target_compile_definitions(common INTERFACE PDSTRUT_CHAR_WCHAR=1)
endif()
if(PDSTRUT_CHAR_U16CHAR)
    target_compile_definitions(common INTERFACE PDSTRUT_CHAR_U16CHAR=1)
endif()
if(PDSTRUT_CHAR_U32CHAR)
    target_compile_definitions(common INTERFACE PDSTRUT_CHAR_U32CHAR=1)
endif()

add_subdirectory(dependencies)
add_subdirectory(sources)
