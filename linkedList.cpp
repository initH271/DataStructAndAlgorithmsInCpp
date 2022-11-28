/**
 * @file linkedlist.cpp
 * @brief: 
 * @version: 1.0
 * @author: inith271
 * @email: oy.zf@qq.com
 * @date: 22/11/28 17:09
 *
 **/


#include <cstdio>
#include "linkedList.h"
#include "utils/dsexception.h"
#include "exceptionMessage.h"

void insertNodeAfter(pLinkedNode &node, pLinkedNode &x) { // 在node后插入节点
    x->m_next = node->m_next;
    node->m_next = x;
}

void removeNodeAfter(pLinkedNode &node) { // 移除node的直接后继节点
    pLinkedNode oldNode = node->m_next;
    node->m_next = oldNode->m_next;
    delete oldNode;
}

pLinkedNode removeNodeAfterAndReturn(pLinkedNode &node) { // 移除node的直接后继节点并返回
    pLinkedNode oldNode = node->m_next;
    node->m_next = oldNode->m_next;
    return oldNode;
}

void createListFront(pLinkedList &L, ElementType *arr, int n) {
    initList(L);
    for (int i = 0; i < n; ++i) {
        pLinkedNode node = new LinkedNode(arr[i]);
        insertNodeAfter(L->m_head, node); // 在头结点之后插入节点
        if (listEmpty(L)) // 链表为空
            L->m_last = node; // 更新尾节点
        ++L->m_length; // 更新长度
    }
}

void createListRear(pLinkedList &L, ElementType *arr, int n) {
    initList(L);
    for (int i = 0; i < n; ++i) {
        pLinkedNode node = new LinkedNode(arr[i]);
        if (listEmpty(L)) // 链表为空
            L->m_last = L->m_head->m_next = node;
        else {
            L->m_last->m_next = node;
            L->m_last = node;
        }
        ++L->m_length;
    }

}

void initList(pLinkedList &L) {
    L = new LinkedList();
}

void destroyList(pLinkedList &L) {
    if(!L)return;
    pLinkedNode node = L->m_head->m_next, removed;
    while (node) {
        removed = node;
        node = node->m_next;
        delete removed;
    }
    L->m_length = 0;
}

bool listEmpty(pLinkedList &L) {
    return L->m_length == 0 && !L->m_head->m_next;
}

int listLength(pLinkedList &L) {
    return L->m_length;
}

void displayList(pLinkedList &L) {
    if(!L) return;
    printf("LinkedList:[ ");
    for (pLinkedNode p = L->m_head->m_next; p; p = p->m_next) {
        printf("%d ", p->m_data);
    }
    printf("], size=%d\n", L->m_length);
}

pLinkedNode getElement(pLinkedList &L, int index) {
    if (!checkIndexOnList(L, index)) return nullptr;
    int count = 0;
    pLinkedNode p;
    for (p = L->m_head->m_next; p; p = p->m_next, ++count) {
        if (count == index)
            break;
    }
    return p;
}

int locateElement(pLinkedList &L, ElementType &element) {
    int index = -1;
    pLinkedNode node = L->m_head->m_next;
    for (int i = 0; i < L->m_length; ++i) {
        if (node->m_data == element) index = i;
        node = node->m_next;
    }
    return index;
}

void listInsert(pLinkedList &L, int index, ElementType &element) {
    if (!checkIndexOnList(L, index)) throw DsException(THEINDEXOUTOFRANGE);
    pLinkedNode p = L->m_head->m_next;
    for (int i = 0; i < L->m_length; ++i) {
        if(index==i) break;
        p = p->m_next;
    }
    pLinkedNode newNode = new LinkedNode(element);
    insertNodeAfter(p,newNode);
    ++L->m_length;
}

bool checkIndexOnList(pLinkedList &L, int index) {
    return !(index < 0 || index >= L->m_length);
}

void listDelete(pLinkedList &L, int index) {
    if(!checkIndexOnList(L,index)) throw DsException(THEINDEXOUTOFRANGE);
    pLinkedNode node = L->m_head;
    for (int i = -1; i < L->m_length; ++i) {
        if(index-1==i) break;
        node = node->m_next;
    }
    removeNodeAfter(node);
}



