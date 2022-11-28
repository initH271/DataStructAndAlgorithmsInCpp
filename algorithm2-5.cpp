/**
 * @file algorithm2-5.cpp
 * @brief: 【例2-5】将所有奇数移动到偶数前面，时间复杂度O(n)，空间复杂度O(1)
 * @version: 1.0
 * @author: inith271
 * @email: oy.zf@qq.com
 * @date: 22/11/28 10:38
 *
 **/
#include "sqList.h"
#include <cstdio>
#include "utils/util.h"

// partition算法实现
int move1(pSqList &L){
    int left=0,right = L->m_length-1;
    while (left<right){
        while (left<right && L->m_data[right]%2==0)
            --right;
        while (left<right && L->m_data[left]%2!=0)
            ++left;
        if(left<right)
            swap(L->m_data[left],L->m_data[right]);
    }

    return left;
}
// 令[0,i]为奇数区，从左至右扫描，将奇数放置奇数区
int move2(pSqList &L){
    int i = -1;
    for(int j=0;j<L->m_length;j++){
        if(L->m_data[j]%2==1){ // 找到奇数
            i++;
            if(i!=j) // 放置于奇数区
                swap(L->m_data[i],L->m_data[j]);
        }
    }
    return i;
}



int main(int argc, char const *argv[])
{
    int arr[] = {3, 8, 2, 7, 1, 5, 3, 4, 6, 0};
    pSqList L = new SqList;
    createList(L, arr, 10);
    displayList(L);
    printf("移动奇数到偶数的前面，");
    printf("分界 = %d\n", move2(L));
    displayList(L);
    destroyList(L);
    return 0;
}