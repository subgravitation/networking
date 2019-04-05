cmake_minimum_required(VERSION 3.10.2)

add_library(
    common
    STATIC
     ./assertion.cpp
     ./socket_guard.cpp
)

target_include_directories(common PUBLIC ~/programing/networking/common)

set_target_properties(common PROPERTIES LINKER_LANGUAGE CXX)

