/**
 * @file algorithm2-15.cpp
 * @brief: 【例2-15】已知3个有序单链表，单个表中元素互异，但是3个表中可能存在元素相同的节点。
 *                      将存在相同元素的节点存储在第一个单链表中，同时删除其他无用节点。
 * @version: 1.0
 * @author: inith271
 * @email: oy.zf@qq.com
 * @date: 22/11/30 19:05
 *
 **/

#include <cstdio>
#include "orderLinkedList.h"


void solution(pOrderLinkedList &L1, pOrderLinkedList &L2, pOrderLinkedList &L3) {
    pOrderListNode p = L1->m_next, q = L2->m_next, m = L3->m_next; // 三个表指针
    L1->m_next = nullptr; // 构造L1为空表
    pOrderListNode n = L1, r;
    while (p && q && m) {
        while (q && q->m_data < p->m_data) // 移动表指针，对齐表使所指节点不小于目标
            q = q->m_next;
        while (m && m->m_data < p->m_data)
            m = m->m_next;

        if (q && m && p->m_data == q->m_data && p->m_data == m->m_data) { // 如是交集元素，则插入
            r = p;
            p = p->m_next;

            r->m_next = n->m_next;
            n->m_next = r;
            n = n->m_next;
        } else { // 否则释放
            r = p;
            p = p->m_next;

            delete r;
        }
    }
}

int main(int argc, char const *argv[]) {
    ElementType arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9,
                         10, 9, 7, 5, 3, 1, 44, 66, 77,
                         3, 1, 5, 34, 57, 12};
    pOrderLinkedList L1, L2, L3;
    createList(L1, arr, 9);
    createList(L2, &arr[9], 9);
    createList(L3, &arr[18], 6);

    displayList(L1);
    displayList(L2);
    displayList(L3);
    printf("求L1,L2,L3的交集:\n");
    solution(L1, L2, L3);
    displayList(L1);
    destroyList(L1);
    destroyList(L2);
    destroyList(L3);
    return 0;
}