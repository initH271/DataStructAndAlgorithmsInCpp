/**
 * @file orderLinkedList.h
 * @brief: 有序表的单链表结构声明
 * @version: 1.0
 * @author: inith271
 * @email: oy.zf@qq.com
 * @date: 22/11/30 17:20
 *
 **/

#ifndef ORDERLINKEDLIST_H
#define ORDERLINKEDLIST_H

typedef int ElementType;

typedef struct OLNode {
    ElementType m_data;
    struct OLNode *m_next;

    explicit OLNode() : m_next(nullptr) {}

    explicit OLNode(ElementType &data, struct OLNode *next = nullptr) : m_data(data), m_next(next) {}
} *pOrderLinkedList, OrderLinkedList,
        *pOrderListNode, OrderListNode;

void createList(pOrderLinkedList &L, ElementType *arr, int n);

void initList(pOrderLinkedList &L);

void destroyList(pOrderLinkedList &L);

bool listEmpty(pOrderLinkedList &L);

int listLength(pOrderLinkedList &L);

void displayList(pOrderLinkedList &L);

pOrderListNode getElement(pOrderLinkedList &L, int index);

int locateElement(pOrderLinkedList &L, ElementType &element);

void listInsert(pOrderLinkedList &L, ElementType &element);

void listDelete(pOrderLinkedList &L, int index);

#endif //ORDERLINKEDLIST_H
