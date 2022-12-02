/**
 * @file tableList.h
 * @brief: 存储表的数据结构声明，以顺序结构存储列数据，链式结构存储行数据
 * @version: 1.0
 * @author: inith271
 * @email: oy.zf@qq.com
 * @date: 22/11/30 8:12
 *
 **/

#ifndef TABLELIST_H
#define TABLELIST_H


typedef int ElementType;

typedef struct RNode { // 行节点，存储一行数据
    ElementType *cols;
    struct RNode *next;

    explicit RNode() : next(nullptr), cols(nullptr) {}
} *pRow, Row;

typedef struct TableNode { // 表节点，表头
    int m_row, m_col;
    pRow next;

    explicit TableNode() : next(nullptr), m_col(0), m_row(0) {}
} Table, *pTable;


void createTable(pTable &T); // 从用户输入创建一个表
void destroyTable(pTable &T); // 销毁一个表
void displayTable(pTable &T); // 输出一个表
void linkTable(pTable &s1, pTable &s2, pTable &T); // 由源表s1,s2连接的结果存储到表T

#endif //TABLELIST_H
