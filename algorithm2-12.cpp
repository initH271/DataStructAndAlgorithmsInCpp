/**
 * @file algorithm2-12.cpp
 * @brief: 【例2-12】删除循环双向链表中第一个数据域为x的节点
 * @version: 1.0
 * @author: inith271
 * @email: oy.zf@qq.com
 * @date: 22/11/29 16:30
 *
 **/

#include <cstdio>
#include "cdLinkedList.h"

void deleteFirstX(pCDLinkedList &L, ElementType &x) {
    pCDLinkedListNode p = L->m_next;
    while (p != L) {
        if (x == p->m_data)
            break;
        p = p->m_next;
    }
    auto pre = p->m_prior;
    auto succ = p->m_next;
    pre->m_next = succ;
    succ->m_prior = pre;
    delete p;
}

int main(int argc, char const *argv[]) {
    ElementType arr[] = {1, 2, 2, 4, 2, 3, 5, 2, 1, 4};
    ElementType x = 1;
    pCDLinkedList L;
    createListRear(L, arr, 10);
    displayList(L);
    printf("删除第一个数据域为 %d 的节点\n", x);
    deleteFirstX(L, x);
    displayList(L);
    destroyList(L);
    return 0;
}