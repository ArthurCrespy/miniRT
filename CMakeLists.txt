cmake_minimum_required(VERSION 3.24)
project(miniRT C)

set(CMAKE_C_STANDARD 23)

#add_compile_options(-Wall -Wextra -Werror)

#miniRT
file(GLOB SOURCES
    files/srcs/main.c
    files/srcs/**/*.c)
file(GLOB_RECURSE EXCLUDE_TESTS
    files/srcs/tests/*.c)
list(REMOVE_ITEM SOURCES ${EXCLUDE_TESTS})
add_executable(miniRT ${SOURCES})

target_include_directories(miniRT PRIVATE
    files/includes
    files/libft
    files/minilibx-linux)

target_link_libraries(miniRT PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/files/minilibx-linux/libmlx.a
    ${CMAKE_CURRENT_SOURCE_DIR}/files/libft/libft.a)

if(APPLE)
    target_include_directories(miniRT PRIVATE
        /usr/X11/lib
        /usr/local/include
        /usr/local/Cellar/libx11/1.8.7/include/X11/)
    target_link_libraries(miniRT PRIVATE
        /usr/X11/lib/libX11.dylib
        /usr/X11/lib/libXext.dylib
        /usr/local/Cellar/libx11/1.8.7/lib/libX11-xcb.1.dylib)
    target_include_directories(miniRT PRIVATE
        /usr/X11/include)
endif()

#miniRT_test
file(GLOB SOURCES_TEST
    files/srcs/main_tests.c
    files/srcs/**/*.c)
add_executable(miniRT_test ${SOURCES_TEST})

target_include_directories(miniRT_test PRIVATE
    files/includes
    files/libft
    files/minilibx-linux)

target_link_libraries(miniRT_test PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/files/minilibx-linux/libmlx.a
    ${CMAKE_CURRENT_SOURCE_DIR}/files/libft/libft.a)

if(APPLE)
    target_include_directories(miniRT_test PRIVATE
        /usr/X11/lib
        /usr/local/include
        /usr/local/Cellar/libx11/1.8.7/include/X11/
        /usr/local/Cellar/cunit/2.1-3/include)
    target_link_libraries(miniRT_test PRIVATE
        /usr/X11/lib/libX11.dylib
        /usr/X11/lib/libXext.dylib
        /usr/local/Cellar/libx11/1.8.7/lib/libX11-xcb.1.dylib
        /usr/local/Cellar/cunit/2.1-3/lib/libcunit.1.dylib)
    target_include_directories(miniRT_test PRIVATE
        /usr/X11/include
        /usr/local/Cellar/cunit/2.1-3/include)
endif()
