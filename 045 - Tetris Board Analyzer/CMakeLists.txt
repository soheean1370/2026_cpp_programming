cmake_minimum_required(VERSION 3.16)
project(tetris_board LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(tetris_board main.cpp board_util.cpp)