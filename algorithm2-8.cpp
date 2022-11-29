/**
 * @file algorithm2-8.cpp
 * @brief: 【例2-8】使带头结点的链表递增有序排列
 * @version: 1.0
 * @author: inith271
 * @email: oy.zf@qq.com
 * @date: 22/11/28 20:50
 *
 **/

#include <cstdio>
#include "linkedList.h"

void sort(pLinkedList &L) {
    pLinkedNode p = L->m_head->m_next->m_next; // 指向第二个节点
    pLinkedNode q;
    pLinkedNode pre; // p的前缀指针
    L->m_head->m_next->m_next = nullptr; // 构造单节点的链表
    while (p) {
        q = p->m_next; // 存储p的下一个节点位置

        pre = L->m_head; // 操作链表，比较大小找到插入p的位置
        while (pre->m_next && pre->m_next->m_data < p->m_data)
            pre = pre->m_next;
        p->m_next = pre->m_next; // 插入p节点
        pre->m_next = p;

        p = q; // 步进下一节点
    }
}


int main(int argc, char const *argv[]) {
    pLinkedList L;
    ElementType arr[] = {1, 3, 2, 9, 0, 4, 7, 6, 5, 8};
    createListRear(L, arr, 10);
    displayList(L);
    printf("对链表进行递增排序\n");
    sort(L);
    displayList(L);
    destroyList(L);
    return 0;
}