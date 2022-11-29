/**
 * @file dlinkedlist.h
 * @brief: 双向链表的声明
 * @version: 1.0
 * @author: inith271
 * @email: oy.zf@qq.com
 * @date: 22/11/29 8:48
 *
 **/

#ifndef DLINKEDLIST_H
#define DLINKEDLIST_H

typedef int ElementType;

typedef struct DNode {
    ElementType m_data;
    struct DNode *m_prior, *m_next; // 双向指针
    explicit DNode() = default;

    explicit DNode(ElementType &data, struct DNode *prior = nullptr, struct DNode *next = nullptr)
            : m_data(data), m_prior(prior), m_next(next) {}
} DLinkedNode, *pDLinkedNode, DLinkedList, *pDLinkedList;

void createListFront(pDLinkedList &L, ElementType *arr, int n); // 头插法创建双向链表
void createListRear(pDLinkedList &L, ElementType *arr, int n); // 尾插法创建双向链表

void initList(pDLinkedList &L); // 初始化一个空双向链表
void destroyList(pDLinkedList &L); // 销毁一个双向链表
bool listEmpty(pDLinkedList &L); // 双向链表是否为空
int listLength(pDLinkedList &L); // 获取双向链表长度
void displayList(pDLinkedList &L); // 打印双向链表
void listInsert(pDLinkedList &L, int index, ElementType &element); // 向双向链表索引处插入元素
void listDelete(pDLinkedList &L, int index); // 从双向链表中删除索引处节点

pDLinkedNode getElement(pDLinkedList &L, int index); // 获取双向链表中指定索引的元素
int locateElement(pDLinkedList &L, ElementType &element); // 查找元素在双向链表中的索引



#endif //DLINKEDLIST_H
