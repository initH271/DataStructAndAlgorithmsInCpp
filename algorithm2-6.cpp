/**
 * @file algorithm2-6.cpp
 * @brief: 【例2-6】将带头结点的单链表L拆分为两个带头结点的单链表L1、L2，其中L1使用L的头结点。
 *  L = [a1,b1,a2,b2,...,an,bn]
 *  L1 = [a1,a2,...,an]
 *  L2 = [bn,bn-1,...,b1]
 * @version: 1.0
 * @author: inith271
 * @email: oy.zf@qq.com
 * @date: 22/11/28 19:19
 *
 **/

#include <cstdio>
#include "linkedList.h"

void splitList(pLinkedList &L, pLinkedList &L1, pLinkedList &L2) {
    L1 = L; // L1 使用L的头结点
    initList(L2);
    pLinkedNode node = L->m_head;
    while (node && node->m_next) {
        node = node->m_next; // an
        pLinkedNode p = node->m_next; // 取出 bn
        node->m_next = p->m_next;
        L->m_length--;

        p->m_next = L2->m_head->m_next; // 头插法，插入bn
        L2->m_head->m_next = p;
        L2->m_length++;
        if (listEmpty(L2)) // L2空表时，记得更新尾节点
            L->m_last = p;
    }
}

int main() {
    pLinkedList L = nullptr, L1 = nullptr, L2 = nullptr;
    int n = 10;
    ElementType arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    createListRear(L, arr, n);
    printf("L:");
    displayList(L);

    printf("L->L1,L2\n");
    splitList(L, L1, L2);

    printf("L1:");
    displayList(L1);
    printf("L2:");
    displayList(L2);

    destroyList(L1);
    destroyList(L2);
    return 0;
}