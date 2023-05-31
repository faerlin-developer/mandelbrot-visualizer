cmake_minimum_required(VERSION 3.24)

project(mandelbrot-visualizer)

set(LOCAL_LIBRARY library)
set(EXECUTABLE mandelbrot-visualizer)

find_package(SDL2 REQUIRED)
include_directories(include)
include_directories(${SDL2_INCLUDE_DIRS})

add_subdirectory(lib)

add_executable(${EXECUTABLE} "main.cpp")
target_link_libraries(${EXECUTABLE} ${SDL2_LIBRARIES} ${LOCAL_LIBRARY})