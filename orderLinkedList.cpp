/**
 * @file orderLinkedList.cpp
 * @brief: 有序表的单链表结构定义
 * @version: 1.0
 * @author: inith271
 * @email: oy.zf@qq.com
 * @date: 22/11/30 17:20
 *
 **/

#include <cstdio>
#include "orderLinkedList.h"

void initList(pOrderLinkedList &L) {
    L = new OrderLinkedList();
}

void createList(pOrderLinkedList &L, ElementType *arr, int n) {
    initList(L);
    for (int i = 0; i < n; ++i) {
        listInsert(L, arr[i]);
    }
}

bool listEmpty(pOrderLinkedList &L) {
    return L->m_next == nullptr;
}

int listLength(pOrderLinkedList &L) {
    int count = 0;
    pOrderListNode p = L->m_next;
    while (p && ++count)
        p = p->m_next;
    return count;
}

void listInsert(pOrderLinkedList &L, ElementType &element) {
    pOrderListNode node = new OrderListNode(element);
    pOrderListNode p = L;
    while (p && p->m_next) {
        if (element < p->m_next->m_data)
            break;
         p = p->m_next;
    }
    node->m_next = p->m_next;
    p->m_next = node;
}

void destroyList(pOrderLinkedList &L) {
    pOrderListNode p = L->m_next;
    while (p) {
        L->m_next = p->m_next;
        delete p;
        p = L->m_next;
    }
    delete L;
}

void displayList(pOrderLinkedList &L) {
    printf("OrderLinkedList:[ ");
    pOrderListNode p = L->m_next;
    int count = 0;
    while (p && ++count) {
        printf("%d ", p->m_data);
        p = p->m_next;
    }
    printf("], size=%d\n", count);
}

pOrderListNode getElement(pOrderLinkedList &L, int index) {
    pOrderListNode p = L->m_next;
    int i = 0;
    while (p && i++ < index)
        p = p->m_next;
    return p;
}

int locateElement(pOrderLinkedList &L, ElementType &element) {
    pOrderListNode p = L->m_next;
    int index = -1, i = 0;
    while (p) {
        if (p->m_data == element) {
            index = i;
            break;
        }
        p = p->m_next;
        i++;
    }
    return index;
}

void listDelete(pOrderLinkedList &L, int index) {
    pOrderListNode p = L, q;
    while (p->m_next && 0 < index)
        p = p->m_next, index--;
    q = p->m_next;
    p->m_next = q->m_next;
    delete q;
}

