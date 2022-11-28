/**
 * @file sqList.cpp
 * @brief: 
 * @version: 1.0
 * @author: ${USR}
 * @email: oy.zf@qq.com
 * @date: 22/11/23 8:45
 *
 **/

#include "utils/dsexception.h"
#include "sqList.h"
#include <cstdio>
#include "exceptionMessage.h"

void initList(pSqList &L, int size) {
    L->m_data = new ElementType[size];
    L->m_length = 0;
}

void destroyList(pSqList &L) {
    delete[] L->m_data;
    L->m_length = 0;
}

bool listEmpty(pSqList &L) {
    return L->m_length == 0;
}

void createList(pSqList &L, int *arr, int n) {
    initList(L, n);
    for (int i = 0; i < n; i++)
        L->m_data[i] = arr[i];
    L->m_length = n;
}

int ListLength(pSqList &L) {
    return L->m_length;
}

void displayList(pSqList &L) {
    printf("SqList[");
    for (int i = 0; i < L->m_length; ++i) {
        printf("%2d ", *(L->m_data + i));
    }
    printf("], m_length = %d\n", L->m_length);
}

ElementType &getElement(pSqList &L, int index) {
    if (index < 0 || index >= L->m_length) {
        throw DsException(THEINDEXOUTOFRANGE);
    }
    return L->m_data[index];
}

int locateElement(pSqList &L, int &element) {
    int index = -1;
    for (int i = 0; i < L->m_length; ++i) {
        if (L->m_data[i] == element) index = i;
    }
    return index;
}

ElementType listDelete(pSqList &L, int index) {
    ElementType oldElement = 0;
    if (index >= 0 && index < L->m_length) {
        oldElement = L->m_data[index];
        for (int i = index; i < L->m_length-1; ++i) {
            L->m_data[i] = L->m_data[i+1];
        }
    }
    return oldElement;
}
