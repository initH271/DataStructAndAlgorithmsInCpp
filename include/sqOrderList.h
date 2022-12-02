/**
 * @file sqOrderList.h
 * @brief: 有序表的顺序存储声明
 * @version: 1.0
 * @author: inith271
 * @email: oy.zf@qq.com
 * @date: 22/11/30 16:02
 *
 **/

#ifndef SQORDERLIST_H
#define SQORDERLIST_H

typedef int ElementType;

typedef struct LNode {
    ElementType *m_data;
    int m_length;
    int m_maxSize;
    explicit LNode():m_data(nullptr),m_length(0),m_maxSize(0){}
} *pSqList, SqList;

void createList(pSqList &L, ElementType *arr, int n); // 从数组创建有序表
void initList(pSqList &L, int size = 10); // 初始化一个有序表
void destroyList(pSqList &L); // 销毁一个有序表
void displayList(pSqList &L); // 打印一个有序表
bool listEmpty(pSqList &L); // 有序表是否为空
ElementType getElement(pSqList &L, int index); // 获取索引所在元素
int locateElement(pSqList &L, ElementType &element); // 获取元素索引
void listInsert(pSqList &L, ElementType &element); // 将元素插入
void listDelete(pSqList &L, int index); // 删除索引出元素

#endif //SQORDERLIST_H
