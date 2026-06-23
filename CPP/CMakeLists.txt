cmake_minimum_required(VERSION 3.16)

project(main_project LANGUAGES CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
endif()

find_package(Boost REQUIRED)

add_executable(main main.cpp)

target_include_directories(main PRIVATE
    ${Boost_INCLUDE_DIRS}
)

target_compile_options(main PRIVATE
    -g
    -O3
    -fno-omit-frame-pointer
    -fsanitize=address,undefined
)

target_link_options(main PRIVATE
    -fsanitize=address,undefined
)

add_custom_target(run
    COMMAND ./main
    DEPENDS main
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
)