/**
 * @file linkedStack.h
 * @brief: 链式栈的声明
 * @version: 1.0
 * @author: inith271
 * @email: oy.zf@qq.com
 * @date: 22/11/29 13:38
 *
 **/

#ifndef LINKEDSTACK_H
#define LINKEDSTACK_H

typedef int ElementType;

typedef struct LSNode {
    ElementType m_data;
    struct LSNode *m_next;
    explicit LSNode() =default;
    explicit LSNode(ElementType &element, struct LSNode* next= nullptr):
            m_data(element),m_next(next){}
} LinkedStackNode, *pLinkedStackNode, LinkedStack, *pLinkedStack;

void initStack(pLinkedStack &S);

void destroyStack(pLinkedStack &S);

bool stackEmpty(pLinkedStack &S);

void pushStack(pLinkedStack &S, ElementType &element);

pLinkedStackNode popStack(pLinkedStack &S);

ElementType &stackTop(pLinkedStack &S);


#endif //LINKEDSTACK_H
