get_filename_component(CMAKE_CURRENT_PARENT_DIR ${CMAKE_CURRENT_SOURCE_DIR} DIRECTORY)
message(STATUS "Checking source files:")

# Coverage setup function (better approach)
function(enable_coverage_for_target target_name)
    if(ENABLE_COVERAGE AND CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
        message(STATUS "Enabling coverage for target: ${target_name}")
        target_compile_options(${target_name} PRIVATE --coverage -fprofile-arcs -ftest-coverage)
        target_link_options(${target_name} PRIVATE --coverage)
    endif()
endfunction()

file(GLOB_RECURSE SRC_FILES "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")
message(STATUS "Creating library with files: ${SRC_FILES}")

# Only create library if there are source files
if(SRC_FILES)
    add_library(src_lib ${SRC_FILES})
   
    # FIXED: Properly link to basic_lib instead of including it as directory
    target_link_libraries(src_lib PUBLIC basic_lib)
    
    # Include directories (basic_lib already provides most of what we need)
    target_include_directories(src_lib PUBLIC
        ${CMAKE_CURRENT_PARENT_DIR}/include
    )
    
    # FIXED: Apply coverage per target, not globally
    enable_coverage_for_target(src_lib)
       
    message(STATUS "src_lib created successfully")
else()
    message(STATUS "No source files found for src_lib, creating interface library")
    add_library(src_lib INTERFACE)
   
    # FIXED: Link to basic_lib for interface library too
    target_link_libraries(src_lib INTERFACE basic_lib)
    
    target_include_directories(src_lib INTERFACE
        ${CMAKE_CURRENT_PARENT_DIR}/include
    )
endif()

# Create window executable
if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/window.cpp")
    message(STATUS "Creating window executable")
    add_executable(window window.cpp)
    target_link_libraries(window PRIVATE src_lib)
    enable_coverage_for_target(window)
else()
    message(STATUS "window.cpp not found, skipping window executable")
endif()

# Function to create executable from any cpp file
function(create_executable cpp_file)
    get_filename_component(exec_name ${cpp_file} NAME_WE)
    if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/${cpp_file}")
        add_executable(${exec_name} ${cpp_file})
        target_link_libraries(${exec_name} PRIVATE src_lib)
        enable_coverage_for_target(${exec_name})
        message(STATUS "Created executable: ${exec_name}")
    else()
        message(WARNING "File ${cpp_file} not found")
    endif()
endfunction()

# Handle dynamic target creation if TARGET_FILE is defined
if(DEFINED TARGET_FILE)
    get_filename_component(target_filename ${TARGET_FILE} NAME)
    create_executable(${target_filename})
endif()