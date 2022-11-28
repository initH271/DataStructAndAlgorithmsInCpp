/**
 * @file sqlList.h
 * @brief: 顺序表的声明定义
 * @version: 1.0
 * @author: ${USR}
 * @email: oy.zf@qq.com
 * @date: 22/11/23 8:23
 *
 **/

#ifndef SQLLIST_H
#define SQLLIST_H

typedef int ElementType; // 元素类型
const int MAXSIZE =  10;

typedef struct { // 顺序表结构
    ElementType *m_data;
    int m_length;
} SqList, *pSqList;

void createList(pSqList &L, ElementType arr[], int n); // 从数组中建立顺序表

void initList(pSqList &L, int size=MAXSIZE); // 初始化一个空顺序表

void destroyList(pSqList &L); // 销毁顺序表

bool listEmpty(pSqList &L); // 顺序表是否为空

int ListLength(pSqList &L); // 顺序表长度

void displayList(pSqList &L); // 打印顺序表

ElementType& getElement(pSqList &L, int index); // 获取索引为index的元素

int locateElement(pSqList &L, ElementType &element); // 获取元素element在顺序表中的索引，如果存在

ElementType listDelete(pSqList &L, int index); // 删除索引为index的元素并返回

#endif //SQLLIST_H
