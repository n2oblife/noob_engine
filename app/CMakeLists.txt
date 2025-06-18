get_filename_component(CMAKE_CURRENT_PARENT_DIR ${CMAKE_CURRENT_SOURCE_DIR} DIRECTORY)

message(STATUS "Checking source files:")

if(ENABLE_COVERAGE)
    if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
        message(STATUS "Enabling coverage build...")

        # Add necessary compiler and linker flags for coverage
        add_compile_options(--coverage -fprofile-arcs -ftest-coverage)
        add_link_options(--coverage)

        # Ensure CMake does not optimize or strip debugging info
        set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} --coverage")
        set(CMAKE_EXE_LINKER_FLAGS_DEBUG "${CMAKE_EXE_LINKER_FLAGS_DEBUG} --coverage")

    else()
        message(WARNING "Code coverage is only supported with GCC or Clang.")
    endif()
endif()

file(GLOB_RECURSE SRC_FILES "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")

message(STATUS "Linked binary")
add_executable(app
    app.cpp
)

target_link_libraries(app PRIVATE app_lib)