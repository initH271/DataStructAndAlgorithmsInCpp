/**
 * @file algorithm2-9.cpp
 * @brief: 【例2-9】将双向链表所有元素倒置，首节点变尾节点，尾节点变为首节点
 * @version: 1.0
 * @author: inith271
 * @email: oy.zf@qq.com
 * @date: 22/11/29 10:51
 *
 **/

#include "dlinkedlist.h"
#include <cstdio>

void reverseList(pDLinkedList &L){
    pDLinkedNode p = L->m_next,q;
    L->m_next = nullptr;
    while (p){
        q = p->m_next;
        p->m_next = L->m_next;
        p->m_prior = L;
        L->m_next = p;
        p = q;
    }
}

int main(int argc, char const *argv[]) {
    ElementType arr[] = {1, 8, 0, 4, 9, 7, 5, 2, 3, 6};
    pDLinkedList L;
    createListRear(L, arr, 10);
    displayList(L);
    printf("逆转双向链表L\n");
    reverseList(L);
    displayList(L);
    destroyList(L);
    return 0;
}