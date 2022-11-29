/**
 * @file cdLinkedList.h
 * @brief: 循环双链表的声明
 * @version: 1.0
 * @author: inith271
 * @email: oy.zf@qq.com
 * @date: 22/11/29 16:32
 *
 **/

#ifndef CDLINKEDLIST_H
#define CDLINKEDLIST_H

typedef int ElementType;

typedef struct CDLNode {
    ElementType m_data;
    struct CDLNode *m_prior, *m_next;

    explicit CDLNode() = default;

    explicit CDLNode(ElementType &data, struct CDLNode *prior = nullptr, struct CDLNode *next = nullptr) :
            m_data(data), m_prior(prior), m_next(next) {}

} CDLinkedListNode, *pCDLinkedListNode,
        CDLinkedList, *pCDLinkedList;



void initList(pCDLinkedList &L); // 初始化一个循环单链表

void createListFront(pCDLinkedList &L, ElementType *arr, int n); // 从元素数组创建循环单链表，头插法
void createListRear(pCDLinkedList &L, ElementType *arr, int n); // 从元素数组创建循环单链表，尾插法

void destroyList(pCDLinkedList &L); // 销毁一个循环单链表

bool listEmpty(pCDLinkedList &L); // 判断循环单链表是否为空

int listLength(pCDLinkedList &L); // 获取循环单链表长度

void displayList(pCDLinkedList &L); // 打印循环单链表

void listInsert(pCDLinkedList &L, int index, ElementType &elementType); // 将元素插入循环单链表

void listDelete(pCDLinkedList &L, int index); // 删除循环单链表中的元素

pCDLinkedListNode getElement(pCDLinkedList &L, int index); // 根据索引获取元素节点

int locateElement(pCDLinkedListNode &L, ElementType &element); // 获取元素索引


#endif //CDLINKEDLIST_H
