cmake_minimum_required(VERSION 3.10.2)

add_executable(client client.cpp)

target_include_directories(client PRIVATE ~/programing/networking)
target_link_libraries(client common)
