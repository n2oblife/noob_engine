#TODO: handle better the dependencies to avoid installing everything on the computer
message(STATUS "======= COMPILATION PIPELINE CHECKS ======")
cmake_minimum_required(VERSION 3.14)

project(App
    VERSION 1.0.0
    DESCRIPTION "This repository ..."
    LANGUAGES CXX
    HOMEPAGE_URL ...
    )

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(TARGET ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/app)
set(TARGET_TESTS ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/tests/app_tests)
set(CMAKE_APP_DIR ${CMAKE_CURRENT_SOURCE_DIR}/app)
set(CMAKE_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(CMAKE_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)
set(CMAKE_TEST_DIR ${CMAKE_CURRENT_SOURCE_DIR}/tests)
set(README_FILE "${CMAKE_CURRENT_SOURCE_DIR}/README.md")

set(CMAKE_POSITION_INDEPENDENT_CODE ON)


if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release CACHE STRING "Build type" FORCE)
elseif("${CMAKE_BUILD_TYPE}" STREQUAL "debug")
    set(CMAKE_BUILD_TYPE Debug CACHE STRING "Build type" FORCE)
elseif("${CMAKE_BUILD_TYPE}" STREQUAL "minsizerel")
    set(CMAKE_BUILD_TYPE MinSizeRel CACHE STRING "Build type" FORCE)
endif()

if("${CMAKE_BUILD_TYPE}" STREQUAL "Debug")
    set(ENABLE_TESTS ON CACHE BOOL "Enable Tests" FORCE)
    set(ENABLE_COVERAGE ON CACHE BOOL "Enable code coverage analysis" FORCE)
    # Enable STATUSs for debug
    if (CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
        add_compile_options(-Wall -Wextra -Wpedantic -o0 -g)
    elseif (MSVC)
        add_compile_options(/W4 /WX)
    endif()
else()
    set(ENABLE_COVERAGE OFF CACHE BOOL "Enable code coverage analysis" FORCE)
endif()


message(STATUS "======= FETCHING DEPENDENCIES ======")

# Include FetchContent for libraries that need to be fetched
include(FetchContent)
include(ExternalProject)
find_package(Threads REQUIRED)

# TODO adapt this for a specific library
find_package(PkgConfig)
if(PKG_CONFIG_FOUND)
    pkg_check_modules(LIB lib)
endif()
if(LIB_FOUND)
    message(STATUS "Found LIB via pkg-config")
    # No need to set LIB_TARGET as we'll use variables provided by pkg-config
else()
    message(STATUS "System LIB not found. Fetch from source...")
    
    # If LIB is not found, download and fetch it
    FetchContent_Declare(
        LIB
        GIT_REPOSITORY ...
        GIT_TAG release-...
    )
    FetchContent_MakeAvailable(LIB)
    # Set LIB include and lib vars manually
    set(LIB_INCLUDE_DIRS "${LIB_SOURCE_DIR}/include" "${LIB_BINARY_DIR}/include")
    set(LIB_LIBRARIES LIB-static)
    message(STATUS "LIB Libraries fetched: ${LIB_LIBRARIES}")
endif()


find_package(Doxygen QUIET)
if(NOT DOXYGEN_FOUND)
    message(STATUS "Doxygen not found. Fetching from source...")
    
    FetchContent_Declare(
        doxygen
        GIT_REPOSITORY https://github.com/doxygen/doxygen.git
        GIT_TAG Release_1_10_0 # Use the latest stable release tag
    )
    
    FetchContent_MakeAvailable(doxygen)
    
    # Set the newly built Doxygen as the executable
    set(DOXYGEN_EXECUTABLE ${CMAKE_BINARY_DIR}/_deps/doxygen-build/bin/doxygen)
    
    if(EXISTS ${DOXYGEN_EXECUTABLE})
        message(STATUS "Doxygen successfully built: ${DOXYGEN_EXECUTABLE}")
    else()
        message(FATAL_ERROR "Failed to build Doxygen. Documentation won't be generated.")
    endif()
endif()

if(DOXYGEN_EXECUTABLE)
    message(STATUS "Doxygen executable: ${DOXYGEN_EXECUTABLE}")

    set(DOXYGEN_INPUT_DIR "${CMAKE_INCLUDE_DIR} ${CMAKE_SOURCE_DIR}")
    set(DOXYGEN_OUTPUT_DIR ${CMAKE_BINARY_DIR}/docs)
    set(DOXYGEN_CONFIG_FILE ${CMAKE_BINARY_DIR}/docs/Doxyfile.in)
    
    configure_file(${CMAKE_CURRENT_SOURCE_DIR}/docs/Doxyfile.in ${DOXYGEN_CONFIG_FILE} @ONLY)

    add_custom_target(doc
        COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYGEN_CONFIG_FILE}
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/docs
        COMMENT "Generating API documentation with Doxygen"
        VERBATIM
    )
endif()


message(STATUS "====== LINKING PROJECT ======")
add_subdirectory(${CMAKE_SOURCE_DIR})
add_subdirectory(${CMAKE_APP_DIR})


if(ENABLE_TESTS)
    message(STATUS "====== LINKING TESTS ======")
    add_subdirectory(${CMAKE_TEST_DIR})
endif()

# Installation (Optional)
# install(TARGETS app DESTINATION bin)