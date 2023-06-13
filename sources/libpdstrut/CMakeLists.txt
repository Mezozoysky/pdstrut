cmake_minimum_required(VERSION 3.13)

project(libpdstrut
    LANGUAGES CXX
    VERSION ${PDSTRUT_VERSION}
    )

add_library(${PROJECT_NAME} STATIC)
add_library(PDSTRUT::${PROJECT_NAME} ALIAS ${PROJECT_NAME})

set_target_properties(${PROJECT_NAME}
    PROPERTIES
    LINKER_LANGUAGE CXX
    CXX_STANDARD 20
    CXX_STANDARD_REQUIRED ON
    OUTPUT_NAME pdstrut
    )
target_link_libraries(${PROJECT_NAME}
    PUBLIC
    PDSTRUT::common
    )
target_include_directories(${PROJECT_NAME}
    PUBLIC
    "${CMAKE_CURRENT_LIST_DIR}/include"
    )

set(HEADER_FILES
    include/pd/strut/char_type.hpp
    include/pd/strut/convert.hpp
    include/pd/strut/strut.hpp
    )
set(SOURCE_FILES
    src/pd/strut/char_type.cpp
    src/pd/strut/convert.cpp
    # src/pd/strut/strut.cpp
    )

target_sources(${PROJECT_NAME}
    PRIVATE ${SOURCE_FILES}
    PUBLIC ${HEADER_FILES}
    )

if(PDSTRUT_BUILD_UT)
    add_subdirectory(ut)
endif()
