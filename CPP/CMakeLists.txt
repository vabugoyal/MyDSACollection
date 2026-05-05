cmake_minimum_required(VERSION 3.16)

project(main_project LANGUAGES CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Set compiler
set(CMAKE_CXX_COMPILER clang++)

# Set C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Compiler flags
add_compile_options(
    -fcolor-diagnostics
    -fansi-escape-codes
    -g
    --save-temps
    -O1
)

# Source files
set(SRC main.cpp)

# Create executable
add_executable(main ${SRC})

# Custom target: clean (optional, CMake already provides this)
add_custom_target(clean_all
    COMMAND ${CMAKE_COMMAND} -E rm -f main *.o
)

# Custom target: run
add_custom_target(run
    COMMAND main
    DEPENDS main
    WORKING_DIRECTORY ${CMAKE_PROJECT_DIR}
)