/**
 * @file sqOrderList.cpp
 * @brief: 有序表的顺序存储定义
 * @version: 1.0
 * @author: inith271
 * @email: oy.zf@qq.com
 * @date: 22/11/30 16:02
 *
 **/

#include <cstdio>
#include "sqOrderList.h"
#include "utils/dsexception.h"

void createList(pSqList &L, ElementType *arr, int n) {
    initList(L, n);
    for (int i = 0; i < n; ++i) {
        listInsert(L, arr[i]);
    }
}

void initList(pSqList &L, int size) {
    L = new SqList();
    L->m_data = new ElementType[L->m_maxSize = size];
}

void listInsert(pSqList &L, ElementType &element) {
    if (listEmpty(L)) { // 表空
        L->m_data[L->m_length++] = element;
        return;
    }
    if (L->m_maxSize == L->m_length) return; // 表满
    int i = 0;
    for (; i < L->m_length; ++i) { // 找到插入位置
        if (element < L->m_data[i]) break;
    }
    for (int j = L->m_length; j > i; --j) { // 移动后方元素
        L->m_data[j] = L->m_data[j - 1];
    }
    L->m_data[i] = element; // 插入元素
    L->m_length++;
}

void destroyList(pSqList &L) {
    delete[]L->m_data;
    delete L;
}

void displayList(pSqList &L) {
    printf("OrderList:{ ");
    for (int i = 0; i < L->m_length; ++i) {
        printf("%d, ", L->m_data[i]);
    }
    printf("}, size=%d\n", L->m_length);
}

ElementType getElement(pSqList &L, int index) {
    if (index < 0 || index >= L->m_length)
        throw DsException(THEINDEXOUTOFRANGE);
    return L->m_data[index];
}

int locateElement(pSqList &L, ElementType &element) {
    int index = -1;
    for (int i = 0; i < L->m_length; ++i) {
        if (L->m_data[i] == element) {
            index = i;
            break;
        }
    }
    return index;
}

void listDelete(pSqList &L, int index) {
    if (listEmpty(L) || index < 0 || index >= L->m_length) return;
    for (int i = index; i < L->m_length - 1; i++)
        L->m_data[i] = L->m_data[i + 1];
    L->m_length--;
}

bool listEmpty(pSqList &L) {
    return L->m_length == 0;
}

/*
// 测试函数
int main(int argc, char const *argv[]) {
    pSqList L;
    ElementType arr[] = {2, 1, 5, 7, 3, 9, 1, 0, 12, 55, 13, 45};
    createList(L, arr, 12);
    displayList(L);
    destroyList(L);
    return 0;
}
*/
