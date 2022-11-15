/**
 * @file arraylist_unittest.cpp
 * @brief: 测试线性表的顺序结构
 * @version: 1.0
 * @author: initial271
 * @date: 2022-11-13 16:22:49
 *
 **/

#include "arraylist.h"
#include "gtest/gtest.h"
#include <iostream>

// to use test fixture, derive a class from testing::Test.
class ArrayListTest: public testing::Test {
protected:
    arraylist<int> a1_, a2_, *a3_=nullptr;

    // virtual void SetUp() will be called before each test is run.
    // define it if you need to initialize the variables.
    // otherwise, this can be skipped.
    void SetUp()override {
        a1_.insert(11, 0);
        a1_.insert(12, 1);
        a1_.insert(13, 2);
        int *arr = new int[]{222,444,666};
        a3_ = new arraylist<int>(arr,3);
        delete[] arr;
    }
    void TearDown()override{
    }
};

TEST_F(ArrayListTest, DefaultContructor) {
    ASSERT_EQ(0, a2_.length());
//	EXPECT_TRUE(true) << "My warning message";
}

TEST_F(ArrayListTest, ContructFromArray) {

    EXPECT_FALSE(a3_->empty());
    EXPECT_NO_THROW(a3_->output(std::cout));
    EXPECT_EQ(3, a3_->length()) << "the a3_ should has 3 elements.";
//	EXPECT_TRUE(true) << "My warning message";
}

TEST_F(ArrayListTest,InsertAnElement){
    EXPECT_NO_THROW(a1_.output(std::cout));
    EXPECT_EQ(3,a1_.length()) << "the a1_ should has 3 elements.";
}

TEST_F(ArrayListTest, Output) {
    EXPECT_NO_THROW(a2_.output(std::cout));
//	EXPECT_TRUE(true) << "My warning message";
}