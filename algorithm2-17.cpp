/**
 * @file algorithm2-17.cpp
 * @brief: 【例2-17】求出两个有序顺序表（长度相等）中所有元素的中位数
 * @version: 1.0
 * @author: inith271
 * @email: oy.zf@qq.com
 * @date: 22/12/02 8:28
 *
 **/

#include "sqOrderList.h"
#include <cstdio>

ElementType findMedian(pSqList &L1, pSqList &L2) {
    int q = 0; // L1 指针
    int p = 0; // L2 指针
    int count = 0;
    while (q < L1->m_length && p < L2->m_length) {
        count++;
        if (L1->m_data[q] <= L2->m_data[p]) // 扫描L1表
            if (count == L1->m_length)
                return L1->m_data[q];
            else {
                q++;
            }
        else // 扫描L2表
        if (count == L2->m_length)
            return L2->m_data[p];
        else
            p++;
    }
    return count == L1->m_length ? L1->m_data[q] : L2->m_data[p];
}

int main(int argc, char const *argv[]) {
    ElementType arr[] = {1, 2, 3, 4, 6, 7, 8, 9,
                         10, 9, 11, 5, 3, 1, 44, 66, 77,
                         3, 1, 5, 34, 55, 57, 34};
    pSqList L1, L2, L3;
    createList(L1, arr, 12);
    createList(L2, &arr[12], 12);
    createList(L3, arr, 24);
    displayList(L1);
    displayList(L2);
    printf("两有序表的中位数是%d\n", findMedian(L1, L2));
    displayList(L3); // 验证
    int mid = L3->m_length / 2 - 1;
    printf("正确的中位数=%d, 索引为%d\n", L3->m_data[mid], mid);
    destroyList(L1);
    destroyList(L2);
    return 0;
}