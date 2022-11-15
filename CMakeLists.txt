cmake_minimum_required(VERSION 3.23)
project(dsaincpp)

set(CMAKE_CXX_STANDARD 11)

add_subdirectory(googletest)
include_directories(googletest/include googletest)
add_executable(test linkedlist_unittest.cpp)

target_link_libraries(test gtest gtest_main)

add_executable(dsaincpp main.cpp)
