cmake_minimum_required(VERSION 3.14)
project(EstudoDirigido)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS_DEBUG "-g -O0 -Wall -Wextra -Wpedantic")
enable_testing()
add_subdirectory(tests)

add_executable(EstudoDirigido ./src/main.cpp ./src/project.cpp)