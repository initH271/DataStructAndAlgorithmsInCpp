/**
 * @file algorithm2-14.cpp
 * @brief: 【例2-14】有序表的归并算法，将两个有序表合并为一个有序表（有序表中的元素不重复）
 * @version: 1.0
 * @author: inith271
 * @email: oy.zf@qq.com
 * @date: 22/11/30 16:56
 *
 **/

#include <cstdio>
#include "sqOrderList.h"

void unionList(pSqList &S1, pSqList &S2, pSqList &T) {
    initList(T, S1->m_length + S2->m_length);
    int i = 0, j = 0;
    while (i < S1->m_length && j < S2->m_length) { // 表1和表2元素依次比较插入
        if (S1->m_data[i] < S2->m_data[j])
            listInsert(T, S1->m_data[i++]);
        else
            listInsert(T, S2->m_data[j++]);
    }
    // 剩下的一段直接插入
    while (i < S1->m_length)
        listInsert(T, S1->m_data[i++]);
    while (j < S1->m_length)
        listInsert(T, S2->m_data[j++]);
}

int main(int argc, char const *argv[]) {
    pSqList L1, L2, L3;
    ElementType arr[] = {55, 66, 44, 77, 33, 88, 22, 99, 11, 0};
    createList(L1, arr, 5);
    createList(L2, &arr[5], 5);
    displayList(L1);
    displayList(L2);

    printf("合并有序表L1和L2:\n");
    unionList(L1, L2, L3);
    displayList(L3);
    destroyList(L1);
    destroyList(L2);
    destroyList(L3);
    return 0;
}