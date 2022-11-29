/**
 * @file dlinkedlist.cpp
 * @brief: 双向链表的定义
 * @version: 1.0
 * @author: inith271
 * @email: oy.zf@qq.com
 * @date: 22/11/29 8:48
 *
 **/

#include <cstdio>
#include "dlinkedlist.h"

void initList(pDLinkedList &L) {
    L = new DLinkedList();
    L->m_prior = L->m_next = nullptr;
}

void createListFront(pDLinkedList &L, ElementType *arr, int n) {
    initList(L);
    for (int i = 0; i < n; ++i) { // 以循环链表的方式创建
        pDLinkedNode node = new DLinkedNode(arr[i], L, L->m_next); // 构造新节点，前接头结点，后接首节点
        L->m_next = node;
    }
}

void createListRear(pDLinkedList &L, ElementType *arr, int n) {
    initList(L);
    pDLinkedNode p = L;
    for (int i = 0; i < n; ++i) { // 以循环链表的方式创建
        pDLinkedNode node = new DLinkedNode(arr[i], p, p->m_next); // 构造新节点
        p->m_next = node;
        p = p->m_next;
    }
}

void destroyList(pDLinkedList &L) {
    pDLinkedNode node = L->m_next;
    while (node) {
        L = node->m_next;
        delete node;
        node = L;
    }
}

bool listEmpty(pDLinkedList &L) {
    return L->m_next == nullptr;
}

int listLength(pDLinkedList &L) {
    pDLinkedNode node = L->m_next;
    int index = 0;
    while (node) {
        node = node->m_next;
        index++;
    }
    return index;
}

void displayList(pDLinkedList &L) {
    printf("DLinkedList:[ ");
    int count = 0;
    for (pDLinkedNode node = L->m_next; node; node = node->m_next, count++)
        printf("%d ", node->m_data);
    printf("], size=%d\n", count);
}

void listInsert(pDLinkedList &L, int index, ElementType &element) {
    pDLinkedNode node = L;
    int i;
    for (i = 0; i < index && node; ++i) {
        node = node->m_next;
    }
    if (i != index || !node) return;
    pDLinkedNode p = new DLinkedNode(element, node, node->m_next);
    node->m_next = p;
}

void listDelete(pDLinkedList &L, int index) {
    pDLinkedNode node = L;
    int i;
    for (i = 0; i < index && node; ++i) {
        node = node->m_next;
    }
    if (i != index || !node) return;
    pDLinkedNode p = node->m_next;
    p->m_next->m_prior = node;
    node->m_next = p->m_next;
    delete p;
}

pDLinkedNode getElement(pDLinkedList &L, int index) {
    pDLinkedNode node = L;
    int i;
    for (i = 0; i < index && node; ++i) {
        node = node->m_next;
    }
    if (i != index) return nullptr;
    return node;
}

int locateElement(pDLinkedList &L, ElementType &element) {
    int index = -1;
    pDLinkedNode node = L->m_next;
    for (int i = 0; node; node = node->m_next, i++) {
        if (node->m_data == element) index = i;
    }
    return index;
}

