cmake_minimum_required(VERSION 3.23)
project(dsaincpp)

set(CMAKE_CXX_STANDARD 11)

# add googletest framework
#add_subdirectory(googletest)
#include_directories(googletest/include googletest)
#target_link_libraries(gtest gtest_main)

include_directories(include)

# test demo
add_executable(test_demo test_demo.cpp)

# =========顺序表 及其算法=================================
add_executable(sqList sqList.cpp)

# algorithm2-3
add_executable(algorithm2-3 algorithm2-3.cpp sqList.cpp)
# algorithm2-4
add_executable(algorithm2-4 algorithm2-4.cpp sqList.cpp)
# algorithm2-5
add_executable(algorithm2-5 algorithm2-5.cpp sqList.cpp)


# =========单链表 及其算法==================================

add_executable(linkedList linkedList.cpp)

# algorithm2-6
add_executable(algorithm2-6 algorithm2-6.cpp linkedList.cpp)
# algorithm2-7
add_executable(algorithm2-7 algorithm2-7.cpp linkedList.cpp)
# algorithm2-8
add_executable(algorithm2-8 algorithm2-8.cpp linkedList.cpp)

# =========双向链表 及其算法================================

add_executable(dlinkedlist dlinkedlist.cpp)

# algorithm2-9
add_executable(algorithm2-9 algorithm2-9.cpp dlinkedlist.cpp)
# algorithm2-10
add_executable(algorithm2-10 algorithm2-10.cpp dlinkedlist.cpp)

# =========循环单链表 及其算法==============================

add_executable(clinkedList clinkedList.cpp)

# algorithm2-11
add_executable(algorithm2-11 algorithm2-11.cpp clinkedList.cpp)

# =========循环双向链表 及其算法============================

add_executable(cdlinkedList cdLinkedList.cpp)

# algorithm2-12
add_executable(algorithm2-12 algorithm2-12.cpp cdLinkedList.cpp)

# algorithm2-13
add_executable(algorithm2-13 algorithm2-13.cpp cdLinkedList.cpp)

# ========线性表应用======================================

add_executable(tableList tableList.cpp)

# 笛卡尔积算法
add_executable(tablelink tableList.cpp algorithm-tablelink.cpp)

# ========有序表的顺序结构 及其算法==========================

add_executable(sqOrderList sqOrderList.cpp)

# algorithm2-14
add_executable(algorithm2-14 algorithm2-14.cpp sqOrderList.cpp)

# binary search
add_executable(algorithm-binarySearch algorithm-binarySearch.cpp sqOrderList.cpp)

#algorithm2-17
add_executable(algorithm2-17 algorithm2-17.cpp sqOrderList.cpp)

# ========有序表的链式结构 及其算法==========================

add_executable(orderLinkedList orderLinkedList.cpp)

# algorithm2-15
add_executable(algorithm2-15 orderLinkedList.cpp algorithm2-15.cpp)

# algorithm2-16
add_executable(algorithm2-16 algorithm2-16.cpp orderLinkedList.cpp)
# =========顺序栈 及其算法==================================

add_executable(sqStack sqStack.cpp)

# =========链式栈 及其算法==================================

add_executable(linkedStack linkedStack.cpp)

# =========顺序队列 及其算法================================

add_executable(sqQueue sqQueue.cpp)

# =========