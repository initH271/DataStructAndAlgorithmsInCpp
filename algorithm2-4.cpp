/**
 * @file algorithm2-4.cpp
 * @brief: 【例2.4】以顺序表第一个元素为基准线，将所有小于它的元素移动到它的前面
 *          来自剑指offer的经典partition算法
 * @version: 1.0
 * @author: inith271
 * @email: oy.zf@qq.com
 * @date: 22/11/23 19:58
 *
 **/

#include "sqList.h"
#include <cstdio>

void swap(ElementType &a, ElementType &b) {
    ElementType temp = a;
    a = b;
    b = temp;
}

/**
 * Defined the first element as based-element,
 * Firstly find a element less than it from right to left,
 * Then find a element greater than and equal to it from left to right,
 * than swap them.
 * 时间复杂度为O(n), 空间复杂度为O(1)
 * @param L
 */
void partition1(pSqList &L) {
    ElementType base = L->m_data[0];
    int left = 0, right = L->m_length - 1;
    while (left < right) {
        // Importance: firstly finding from right to left.
        // 先从右向左扫描保证left指针移动时超过base的位置。
        while (L->m_data[right] > base && left < right)
            --right; // 从右向左找到小于base的元素
        while (L->m_data[left] <= base && left < right)
            ++left; // 从左向右找到大于等于base的元素
        if (left < right)
            swap(L->m_data[left], L->m_data[right]); // 交换位置
        printf("left= %d, right= %d, ", left, right);
        displayList(L);
    }
    swap(L->m_data[left], L->m_data[0]);
}

int main(int argc, char const *argv[]) {

    int arr[] = {3, 8, 2, 7, 1, 5, 3, 4, 6, 0};
    pSqList L = new SqList;
    createList(L, arr, 10);
    displayList(L);
    printf("以第一个元素%d为基准，小于它的在它前面\n", L->m_data[0]);
    partition1(L);
    displayList(L);
    destroyList(L);
    return 0;
}