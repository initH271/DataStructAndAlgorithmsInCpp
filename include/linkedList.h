/**
 * @file linkedList.h
 * @brief: 单链表的结构声明
 * @version: 1.0
 * @author: inith271
 * @email: oy.zf@qq.com
 * @date: 22/11/28 17:09
 *
 **/

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef int ElementType; // 元素类型

typedef struct LNode { // 元素节点
    ElementType m_data;
    struct LNode *m_next; // 后继节点
    explicit LNode(ElementType data, struct LNode* next= nullptr)
            :m_data(data),m_next(next){}
} LinkedNode, *pLinkedNode;

typedef struct LinkedList{ // 链表
    pLinkedNode m_head; // 头结点
    pLinkedNode m_last; // 尾节点
    int m_length; // 链表长度
    explicit LinkedList(): m_head(new LinkedNode(0)), m_last(new LinkedNode(0)),m_length(0){}
}*pLinkedList;


void insertNodeAfter(pLinkedNode &node, pLinkedNode &x); // 插入直接后继节点
void removeNodeAfter(pLinkedNode &node); // 移除后继节点

pLinkedNode &removeNodeAfterAndReturn(pLinkedNode &node); // 移除直接后续节点并返回
bool checkIndexOnList(pLinkedList &L,int index); // 检查索引是否有效
void createListFront(pLinkedList &L, ElementType *&arr, int n); // 从元素数组创建一个链表，使用头插法
void createListRear(pLinkedList &L, ElementType *&arr, int n); // 从元素数组创建一个链表，使用尾插法
void initList(pLinkedList &L); // 初始化一个链表
void destroyList(pLinkedList &L); // 销毁一个链表
bool listEmpty(pLinkedList &L); // 判断链表是否为空
int listLength(pLinkedList &L); // 获得链表长度
void displayList(pLinkedList &L); // 打印链表
pLinkedNode getElement(pLinkedList &L, int index); // 获得索引为index处的元素
int locateElement(pLinkedList &L, ElementType &element); // 获取匹配元素的索引
void listInsert(pLinkedList &L, int index, ElementType & element); // 向链表中插入元素
void listDelete(pLinkedList &L, int index); // 删除链表中的元素
#endif //LINKEDLIST_H
