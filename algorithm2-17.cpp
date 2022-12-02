/**
 * @file algorithm2-17.cpp
 * @brief: 【例2-17】求出两个有序顺序表中所有元素的中位数
 * @version: 1.0
 * @author: inith271
 * @email: oy.zf@qq.com
 * @date: 22/12/02 8:28
 *
 **/

#include "sqOrderList.h"
#include <cstdio>

ElementType findMedian(pSqList &L1, pSqList &L2) {
    int total = L1->m_length + L2->m_length;
    int midIndex = total % 2 == 0 ? total / 2 - 1 : total / 2; // 计算中位数所在序号
    int q = 0; // L1 指针
    int p = 0; // L2 指针
    while (q + p < midIndex) {
        if (q < L1->m_length && L1->m_data[q] <= L2->m_data[p]) // 扫描L1表
            q++;
        else if (p < L2->m_length && L2->m_data[p] <= L1->m_data[q]) // 扫描L2表
            p++;
    }
    return L1->m_data[q] <= L2->m_data[p] ? L1->m_data[q] : L2->m_data[p];
}

int main(int argc, char const *argv[]) {
    ElementType arr[] = {1, 2, 3, 4, 6, 7, 8, 9,
                         10, 9, 11, 5, 3, 1, 44, 66, 77,
                         3, 1, 5, 34, 55, 57, 12};
    pSqList L1, L2, L3;
    createList(L1, arr, 3);
    createList(L2, &arr[3], 21);
    createList(L3, arr, 24);
    displayList(L1);
    displayList(L2);
    printf("两有序表的中位数是%d\n", findMedian(L1, L2));
    displayList(L3); // 验证
    int mid = L3->m_length % 2 == 0 ? (L3->m_length / 2 - 1) : (L3->m_length / 2);
    printf("正确的中位数=%d\n", L3->m_data[mid]);
    destroyList(L1);
    destroyList(L2);
    return 0;
}