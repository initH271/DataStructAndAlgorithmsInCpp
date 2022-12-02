/**
 * @file algorithm2-16.cpp
 * @brief: 【例2-16】删除一个有序单链表中值域重复的节点
 * @version: 1.0
 * @author: inith271
 * @email: oy.zf@qq.com
 * @date: 22/12/02 8:17
 *
 **/

#include "orderLinkedList.h"
#include <cstdio>

void uniqueList(pOrderLinkedList &L) {
    pOrderListNode p = L->m_next, q;
    while (p && p->m_next) {
        if (p->m_data == p->m_next->m_data) {
            q = p->m_next; // 取出重复节点并删除
            p->m_next = q->m_next;
            delete q;
        } else {
            p = p->m_next;
        }
    }
}

int main(int argc, char const *argv[]) {
    pOrderLinkedList L;
    ElementType arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9,
                         10, 9, 7, 5, 3, 1, 44, 66, 77,
                         3, 1, 5, 34, 57, 12};
    createList(L, arr, 24);
    displayList(L);
    printf("唯一化有序表之后：\n");
    uniqueList(L);
    displayList(L);

    destroyList(L);
    return 0;
}