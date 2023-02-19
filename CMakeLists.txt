cmake_minimum_required(VERSION 3.23)
project(LibrarySystemC_)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(LibrarySystemC_
        class.h
        main.cpp)
