cmake_minimum_required(VERSION 3.10.2)

enable_language(CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(./common)
add_subdirectory(./udp_simple/client)
add_subdirectory(./udp_simple/server)
