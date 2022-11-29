/**
 * @file cdLinkedList.cpp
 * @brief: 循环双链表的定义
 * @version: 1.0
 * @author: inith271
 * @email: oy.zf@qq.com
 * @date: 22/11/29 16:32
 *
 **/

#include <cstdio>
#include "cdLinkedList.h"

void createListRear(pCDLinkedList &L, ElementType *arr, int n) {
    initList(L);
    pCDLinkedListNode p = L;
    for (int i = 0; i < n; ++i) {
        pCDLinkedListNode node = new CDLinkedListNode(arr[i], L->m_prior, L); // 构建节点，前接尾节点，后接头结点
        L->m_prior->m_next = node; // 作为尾节点插入
        L->m_prior = node;
    }
}

void initList(pCDLinkedList &L) {
    L = new CDLinkedList();
    L->m_prior = L->m_next = L; // 头结点前继后继指向自身

}

void displayList(pCDLinkedList &L) {
    pCDLinkedListNode p = L->m_next;
    int count = 0;
    printf("CDLinkedList:[ ");
    while (p != L) {
        printf("%d ", p->m_data);
        p = p->m_next;
        count++;
    }
    printf("], size=%d\n", count);
}

void destroyList(pCDLinkedList &L) {
    pCDLinkedListNode p = L->m_next;
    while (p != L) {
        L->m_next = p->m_next;
        delete p;
        p = L->m_next;
    }
    delete L;
}
