cmake_minimum_required(VERSION 3.23)
project(final)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(final
        main.cpp
        programa.h
        user.h
        library.h)
