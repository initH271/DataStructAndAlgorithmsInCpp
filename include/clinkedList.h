/**
 * @file clinkedList.h
 * @brief: 循环单链表的声明
 * @version: 1.0
 * @author: inith271
 * @email: oy.zf@qq.com
 * @date: 22/11/29 15:54
 *
 **/

#ifndef CLINKEDLIST_H
#define CLINKEDLIST _H

typedef int ElementType;

typedef struct CLNode {
    ElementType m_data;
    struct CLNode *m_prior, *m_next;
    explicit CLNode()=default;
    explicit CLNode(ElementType &data,struct CLNode*prior= nullptr,struct CLNode*next= nullptr):
            m_data(data),m_next(next),m_prior(prior){}
} CLinkedListNode, *pCLinkedListNode,
        CLinkedList, *pCLinkedList;

void initList(pCLinkedList &L); // 初始化一个循环单链表

void createListFront(pCLinkedList &L, ElementType *arr, int n); // 从元素数组创建循环单链表，头插法
void createListRear(pCLinkedList &L, ElementType *arr, int n); // 从元素数组创建循环单链表，尾插法

void destroyList(pCLinkedList &L); // 销毁一个循环单链表

bool listEmpty(pCLinkedList &L); // 判断循环单链表是否为空

int listLength(pCLinkedList &L); // 获取循环单链表长度

void displayList(pCLinkedList &L); // 打印循环单链表

void listInsert(pCLinkedList &L, int index, ElementType &elementType); // 将元素插入循环单链表

void listDelete(pCLinkedList &L, int index); // 删除循环单链表中的元素

pCLinkedListNode getElement(pCLinkedList &L, int index); // 根据索引获取元素节点

int locateElement(pCLinkedListNode, ElementType &element); // 获取元素索引

#endif //CLINKEDLIST_H
