cmake_minimum_required(VERSION 3.14)
project(EstudoDirigido)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(tests)

add_executable(EstudoDirigido ./src/main.cpp ./src/project.cpp)