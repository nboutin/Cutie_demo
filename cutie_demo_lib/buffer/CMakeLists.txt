cmake_minimum_required(VERSION 3.14)
project(buffer LANGUAGES C)

add_library(${PROJECT_NAME} STATIC
    source/buffer.c
)

target_include_directories(${PROJECT_NAME} PUBLIC
    include
)

if (BUILD_TESTING AND BUFFER_TEST)
    add_subdirectory(test)
endif()
