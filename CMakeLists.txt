cmake_minimum_required (VERSION 2.6)
project (Lem-in)

include_directories(includes/)
file(GLOB SOURCES *.c printf_src/*.c)
add_executable(lem-in ${SOURCES})