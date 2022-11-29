/**
 * @file clinkedList.cpp
 * @brief: 
 * @version: 1.0
 * @author: inith271
 * @email: oy.zf@qq.com
 * @date: 22/11/29 15:54
 *
 **/

#include "clinkedList.h"
#include <cstdio>

void createListRear(pCLinkedList &L, ElementType *arr, int n) {
    initList(L);
    for (int i = 0; i < n; ++i) {
        pCLinkedListNode node = new CLinkedListNode(arr[i], L->m_prior, L); // 构建新节点，前接尾节点，后接头结点
        L->m_prior->m_next = node; // 作为尾节点插入
        L->m_prior = node;
    }
}

void initList(pCLinkedList &L) {
    L = new CLinkedList();
    L->m_prior = L;
    L->m_next = L;
}

void destroyList(pCLinkedList &L) {
    pCLinkedListNode p = L->m_next;
    while (p != L) {
        L->m_next = p->m_next;
        delete p;
        p = L->m_next;
    }
    delete L;
}

void displayList(pCLinkedList &L) {
    pCLinkedListNode p = L->m_next;
    int count = 0;
    printf("CLinkedList:[ ");
    while (p != L) {
        printf("%d ", p->m_data);
        p = p->m_next;
        count++;
    }
    printf("], size=%d\n", count);
}
