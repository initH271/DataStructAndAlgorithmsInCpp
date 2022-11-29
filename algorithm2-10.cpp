/**
 * @file algorithm2-10.cpp
 * @brief: 【例2-10】将双向链表（至少拥有一个节点）递增排序
 * @version: 1.0
 * @author: inith271
 * @email: oy.zf@qq.com
 * @date: 22/11/29 11:14
 *
 **/


#include "dlinkedlist.h"
#include <cstdio>

void sortList(pDLinkedList &L) {
    pDLinkedNode p = L->m_next->m_next, q, pre;
    L->m_next->m_next = nullptr; // 构造单节点链表
    while (p) {
        q = p->m_next; // 记住下一节点的位置

        pre = L;
        while (pre->m_next && pre->m_next->m_data < p->m_data) // 找到不小于p的节点
            pre = pre->m_next;
        p->m_prior = pre; // 插入节点
        p->m_next = pre->m_next;
        if (pre->m_next) // 如果找到的节点不是尾节点
            pre->m_next->m_prior = p;
        pre->m_next = p;
        p = q;
    }
}

int main(int argc, char const *argv[]) {
    ElementType arr[] = {1, 8, 0, 4, 9, 7, 5, 2, 3, 6};
    pDLinkedList L;
    createListRear(L, arr, 10);
    listInsert(L, 10, arr[3]);
    displayList(L);
    printf("递增排序双向链表L\n");
    sortList(L);
    displayList(L);
    destroyList(L);
    return 0;
}