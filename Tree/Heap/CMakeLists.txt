cmake_minimum_required(VERSION 3.13)

project(main)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

add_executable(main src/main.cpp src/test.cpp src/test.h)

if (MSVC)
    # warning level 4 and all warnings as errors
    add_compile_options(/W4 /WX)
else()
    # lots of warnings and all warnings as errors
    add_compile_options(-Wall -Wextra -pedantic -Werror -std=c++1y)
endif()