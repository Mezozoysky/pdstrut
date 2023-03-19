if(PDSTRUT_BUILD_UT)
    add_subdirectory(Catch2)
    set(CMAKE_MODULE_PATH "${CMAKE_MODULE_PATH}" PARENT_SCOPE)
    include(CTest)
    include(Catch)
endif()

