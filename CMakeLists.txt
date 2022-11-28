cmake_minimum_required(VERSION 3.23)
project(dsaincpp)

set(CMAKE_CXX_STANDARD 11)

# add googletest framework
add_subdirectory(googletest)
include_directories(googletest/include googletest)
target_link_libraries(gtest gtest_main)

include_directories(include)

# =========顺序表 及其算法=================================
add_executable(sqList sqList.cpp)

# algorithm2-3
add_executable(algorithm2-3 algorithm2-3.cpp sqList.cpp include/utils/util.h)
# algorithm2-4
add_executable(algorithm2-4 algorithm2-4.cpp sqList.cpp include/utils/util.h)
# algorithm2-5
add_executable(algorithm2-5 algorithm2-5.cpp sqList.cpp include/utils/util.h)

# =========链表 及其算法==================================

add_executable(linkedList linkedList.cpp)

# algorithm2-6
add_executable(algorithm2-6 algorithm2-6.cpp linkedList.cpp)