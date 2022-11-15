/**
 * @file linkedlist_unittest.cpp
 * @brief: 测试线性表的链式结构
 * @version: 1.0
 * @author: initial271
 * @date: 2022-11-15 12:58:56
 *
 **/

#include "linkedlist.h"
#include "gtest/gtest.h"
#include <iostream>
class LinkedListTest: public testing::Test {
    typedef LinkedList<int>* pLinkedList;
protected:
    pLinkedList l1_, l2_, l3_;

    void SetUp() override {
        int* arr = new int[] {222, 444, 666, 888};
        l1_ = new LinkedList<int>(arr, 4, 'F'); // by header-insert
        l2_ = new LinkedList<int>(arr, 4); // by rear-insert
        l3_ = new LinkedList<int>();
    }

    void TearDown() override {
        delete l1_;
        delete l2_;
        delete l3_;
    }
};


TEST_F(LinkedListTest, CreateListF) {
    EXPECT_EQ(4u, l1_->size());
    EXPECT_FALSE(l1_->empty());
    EXPECT_NO_THROW(l1_->output(std::cout));
}

TEST_F(LinkedListTest, CreateListR) {
    EXPECT_EQ(4u, l2_->size());
    EXPECT_FALSE(l2_->empty());
    EXPECT_NO_THROW(l2_->output(std::cout));
}