cmake_minimum_required(VERSION 3.20)

set(EXE_NAME tracey)

project(${EXE_NAME})

set(CMAKE_C_STANDARD 99)
# set(CMAKE_C_FLAGS "-Wall")

set(SOURCE_FILES main.c
    src/io/image.c
    src/io/io.c
    src/math/vec.c
    src/math/ray.c
    src/graphics/color.c)

add_executable(${EXE_NAME} ${SOURCE_FILES})

target_include_directories(${EXE_NAME} PUBLIC
    include)

# Add debug mode macro
if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    add_compile_definitions(__DEBUG__)
endif()