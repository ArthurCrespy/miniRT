cmake_minimum_required(VERSION 3.26)
project(miniRT C)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_C_STANDARD 23)

include_directories(files/includes)
include_directories(files/srcs)

include_directories(/usr/X11/include)
link_directories(/usr/X11/lib)

add_executable(miniRT
        files/srcs/main.c)