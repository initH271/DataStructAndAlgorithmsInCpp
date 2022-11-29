/**
 * @file algorithm2-13.cpp
 * @brief: 【例2-13】判断循环双链表的数据节点是否对称
 * @version: 1.0
 * @author: inith271
 * @email: oy.zf@qq.com
 * @date: 22/11/29 17:10
 *
 **/

#include "cdLinkedList.h"
#include <cstdio>

bool listSymmetry(pCDLinkedList &L) {
    auto p = L->m_next, q = L->m_prior;
    bool result = true;
    while (p != q && p->m_next!=q) {
        if (p->m_data != q->m_data) {
            result = false;
            break;
        }
        p = p->m_next;
        q = q->m_prior;
    }
    return result;
}

int main(int argc, char const *argv[]) {
    ElementType arr[] = {1, 2,1, 2, 1};
    pCDLinkedList L;
    createListRear(L, arr, 5);
    displayList(L);
    printf("判断循环双链表是否对称：");
    if (listSymmetry(L))
        printf("\t对称");
    else
        printf("\t不对称");
    destroyList(L);
    return 0;
}