cmake_minimum_required(VERSION 3.20)
project(pyembeed C)
include_directories(F://conda//include)
link_directories(F://conda//libs)

set(CMAKE_C_STANDARD 11)

add_library(loguru SHARED src/module.c src/loguru.c)
target_link_libraries(loguru python38)

add_executable(main src/main.c)
target_link_libraries(main loguru)
