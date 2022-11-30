/**
 * @file tableList.cpp
 * @brief: 表的数据结构实现
 * @version: 1.0
 * @author: inith271
 * @email: oy.zf@qq.com
 * @date: 22/11/30 8:12
 *
 **/

#include <cstdio>
#include "tableList.h"
#include "utils/util.h"

void createTable(pTable &T) {
    T = new Table();
    scanf("%d %d", &T->m_row, &T->m_col); // 得到表的行数, 列数
    pRow p;
    for (int i = 0; i < T->m_row; ++i) {
        pRow row = new Row(); // 新建一行
        row->cols = new ElementType[T->m_col];
        for (int j = 0; j < T->m_col; ++j) { // 填充列数据
            scanf("%d", &row->cols[j]);
        }
        if (!T->next)
            T->next = p = row; // 接上表头
        else
            p = p->next = row; // 接上表尾
    }
}

void destroyTable(pTable &T) {
    pRow p = T->next;
    while (p) {
        T->next = p->next;
        delete[]p->cols;
        delete p;
        p = T->next;
    }
    delete T;
}

void displayTable(pTable &T) {
    pRow p = T->next;
    printf("Table:[\n");
    while (p) {
        printf("\t[ ");
        for (int i = 0; i < T->m_col; ++i) {
            printf("%d ", p->cols[i]);
        }
        printf("]\n");
        p = p->next; // 换行
    }
    printf("], shape = [%d, %d]\n", T->m_row, T->m_col);
}

void linkTable(pTable &s1, pTable &s2, pTable &T) {
    int c1, c2; // 分别为源表1、2的列数，链接条件为c1=c2
    scanf("%d %d", &c1, &c2);
    T = new Table();
    T->m_col = s1->m_col + s2->m_col;
    pRow p = s1->next; // 扫描源表1
    pRow q;
    pRow m;
    while (p) {
        q = s2->next; // 扫描源表2
        while (q) {
            if (p->cols[c1 - 1] == q->cols[c2 - 1]) { // 比较链接条件是否成立, 注意列数-1为索引
                pRow row = new Row();
                row->cols = new ElementType[T->m_col];
                copyArray(p->cols, row->cols, 0, s1->m_col); // 复制表1的行
                copyArray(q->cols, row->cols, s1->m_col, s2->m_col); // 复制表2的行
                if (!T->next) // 接入表
                    T->next = m = row;
                else
                    m = m->next = row;
                T->m_row++; // 目标表函数增加
            }
            q = q->next;
        }
        p = p->next;
    }
}

