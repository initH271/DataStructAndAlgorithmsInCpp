/**
 * @file linkedStack.cpp
 * @brief: 链式栈的定义
 * @version: 1.0
 * @author: inith271
 * @email: oy.zf@qq.com
 * @date: 22/11/29 13:38
 *
 **/

#include "linkedStack.h"

void initStack(pLinkedStack &S) {
    S = new LinkedStack();
    S->m_next = nullptr;
}

void destroyStack(pLinkedStack &S) {
    pLinkedStackNode node = S->m_next, p;
    while (node) {
        p = node;
        node = node->m_next;
        delete p;
    }
    delete S;
}

bool stackEmpty(pLinkedStack &S) {
    return S->m_next == nullptr;
}

void pushStack(pLinkedStack &S, ElementType &element) {
    pLinkedStackNode node = new LinkedStackNode(element, S->m_next);
    S->m_next = node;
}

pLinkedStackNode popStack(pLinkedStack &S) {
    pLinkedStackNode p = S->m_next; // 取出栈顶节点
    S->m_next = p->m_next;
    return p;
}

ElementType &stackTop(pLinkedStack &S) {
    return S->m_next->m_data;
}
