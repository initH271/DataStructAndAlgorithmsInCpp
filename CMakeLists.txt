cmake_minimum_required(VERSION 3.23)
project(dsaincpp)

set(CMAKE_CXX_STANDARD 11)

add_subdirectory(googletest)
include_directories(googletest/include googletest)
add_executable(test linkedlist_unittest.cpp)

target_link_libraries(test gtest gtest_main)

add_executable(dsaincpp main.cpp)

# binary tree
add_executable(binTreeTest binaryTree_unittest.cpp)

# huffman tree
add_executable(huffmantree huffmantree.cpp)

# 顺序表
add_executable(sqList sqList.cpp)

# algorithm2-3
add_executable(algorithm2-3 algorithm2-3.cpp sqList.cpp)
# algorithm2-4
add_executable(algorithm2-4 algorithm2-4.cpp sqList.cpp)