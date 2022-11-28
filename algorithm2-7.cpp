/**
 * @file algorithm2-7.cpp
 * @brief: 【例2-7】删除链表中元素值最大的节点（假设该节点唯一）
 * @version: 1.0
 * @author: inith271
 * @email: oy.zf@qq.com
 * @date: 22/11/28 20:33
 *
 **/

#include "linkedList.h"
#include <cstdio>

void deleteMaxNode(pLinkedList &L) {
    if(listEmpty(L)) return;
    pLinkedNode p = L->m_head, max = p;
    while (p && p->m_next) {
        if (p->m_next->m_data > max->m_next->m_data) // 比较下一节点是否比当前最大值节点大
            max = p;
        p = p->m_next;
    }
    removeNodeAfter(max);
    L->m_length--;
}

int main(int argc, char const *argv[]) {
    pLinkedList L;
    int n = 10;
    ElementType arr[] = {1, 3, 2, 9, 0, 4, 7, 6, 5, 8};
    createListRear(L, arr, n);
    displayList(L);
    printf("删除元素最大的节点\n");
    deleteMaxNode(L);
    displayList(L);
    printf("删除元素最大的节点\n");
    deleteMaxNode(L);
    displayList(L);
    printf("删除元素最大的节点\n");
    deleteMaxNode(L);
    displayList(L);
    printf("删除元素最大的节点\n");
    deleteMaxNode(L);
    displayList(L);
    printf("删除元素最大的节点\n");
    deleteMaxNode(L);
    displayList(L);
    printf("删除元素最大的节点\n");
    deleteMaxNode(L);
    displayList(L);
    printf("删除元素最大的节点\n");
    deleteMaxNode(L);
    displayList(L);
    printf("删除元素最大的节点\n");
    deleteMaxNode(L);
    displayList(L);
    printf("删除元素最大的节点\n");
    deleteMaxNode(L);
    displayList(L);
    printf("删除元素最大的节点\n");
    deleteMaxNode(L);
    displayList(L);
    printf("删除元素最大的节点\n");
    deleteMaxNode(L);
    displayList(L);
    destroyList(L);
    return 0;
}