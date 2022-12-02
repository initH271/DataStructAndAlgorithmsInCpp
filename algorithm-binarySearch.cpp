/**
 * @file algorithm-binarySearch.cpp
 * @brief: 有序表顺序结构的二分查找
 * @version: 1.0
 * @author: inith271
 * @email: oy.zf@qq.com
 * @date: 22/12/01 14:50
 *
 **/

#include "sqOrderList.h"
#include <cstdio>

int binarySearch(pSqList &L, int x, int low, int high) {
    int count = 0;
    while (low < high) {
        int mid = (low + high) >> 1;
        x < L->m_data[mid] ? high = mid : low = mid + 1;
        count++;
    }
    printf("比较次数为 %d\n", count);
    return low - 1;
}

int main(int argc, char const *argv[]) {
    ElementType arr[11] = {13, 18, 24, 35, 47, 50, 62, 83, 90, 115, 134};
    pSqList L;
    createList(L, arr, 11);
    displayList(L);
    ElementType x = 90;
    printf("二分查找 %d = %d", x, binarySearch(L, x, 0, 10));
    return 0;
}