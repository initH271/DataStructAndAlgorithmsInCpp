/**
 * @file algorithm2-11.cpp
 * @brief: 【例2-11】统计循环单链表中数据域为x的节点个数
 * @version: 1.0
 * @author: inith271
 * @email: oy.zf@qq.com
 * @date: 22/11/29 16:05
 *
 **/

#include "clinkedList.h"
#include <cstdio>

int countX(pCLinkedList &L, ElementType &x) {
    pCLinkedListNode p = L->m_next;
    int count = 0;
    while (p != L) {
        if (p->m_data == x) count++;
        p = p->m_next;
    }
    return count;
}

int main(int argc, char const *argv[]) {
    pCLinkedList L;
    ElementType arr[] = {1, 2, 2, 4, 2, 3, 5, 2, 1, 4};
    ElementType x = 2;
    createListRear(L, arr, 10);
    displayList(L);
    printf("对循环单链表L中的%d进行计数为%d.\n", x, countX(L, x));
    destroyList(L);
    return 0;
}