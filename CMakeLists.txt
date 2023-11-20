cmake_minimum_required(VERSION 3.24)
project(miniRT C)

set(CMAKE_C_STANDARD 23)

include_directories(files/mlx, files/includes)
file(GLOB SOURCES
        files/mlx/*.c
        files/srcs/*.c
        files/srcs/**/*.c)

add_executable(miniRT ${SOURCES})

if(APPLE)
    include_directories(/usr/X11/include)
    link_directories(/usr/X11/lib)
endif()