cmake_minimum_required(VERSION 3.10.2)

add_executable(server server.cpp)

target_include_directories(server PRIVATE ~/programing/networking)
target_link_libraries(server common)
