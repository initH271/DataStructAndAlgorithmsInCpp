
// 【例2.3】 删除线性表中所有值为x的元素，要求算法的时间复杂度为O(n), 空间复杂度为O(1)
#include "sqList.h"
#include <cstdio>

/**
 * 原地删除算法，借用原有空间进行依次进行原地移动
 *
 * @param L - 顺序表
 * @param x - 待删除元素
 */
void deleteX1(pSqList &L, ElementType &x) {
    // 优化
    int k = 0;
    for (int i = 0; i < L->m_length; ++i) {
        if (L->m_data[i] != x) {
            L->m_data[k] = L->m_data[i];
            k++;
        } // 匹配到元素，则跳过
    }
    L->m_length = k;
}

void deleteX2(pSqList &L, ElementType &x) {
    int k = 0, i = 0;
    while (i < L->m_length) {
        if (L->m_data[i] == x)
            k++; // 匹配到元素的个数
        else
            L->m_data[i - k] = L->m_data[i]; // 元素向前移动k个位置
        i++;
    }
    L->m_length -= k;
}


int main(int argc, char const *argv[]) {
    int arr[] = {1, 3, 6, 7, 15, 4, 8, 7, 19, 17, 7, 13, 9, 4, 10, 11, 8, 22, 6, 20, 19, 1};
    pSqList L = new SqList;
    createList(L, arr, 22);
    displayList(L);
    int x = 8;
    deleteX1(L, x);
    printf("\n删除x=%d的元素后\n", x);
    displayList(L);
    x = 1;
    deleteX1(L, x);
    printf("\n删除x=%d的元素后\n", x);
    displayList(L);
    x = 7;
    deleteX2(L, x);
    printf("\n删除x=%d的元素后\n", x);
    displayList(L);
    destroyList(L);
    return 0;
}