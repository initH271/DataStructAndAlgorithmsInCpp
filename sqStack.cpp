/**
 * @file sqStack.cpp
 * @brief: 顺序栈的定义
 * @version: 1.0
 * @author: inith271
 * @email: oy.zf@qq.com
 * @date: 22/11/29 13:15
 *
 **/

#include "sqStack.h"
#include "utils/dsexception.h"

void initStack(pStack &S, int size) {
    S = new Stack();
    S->m_data = new ElementType[S->m_maxSize = size];
    S->m_top = -1;
}

void destroyStack(pStack &S) {
    delete[]S->m_data;
    delete S;
}

bool stackEmpty(pStack &S) {
    return S->m_top == -1;
}

ElementType &stackTop(pStack &S) {
    return S->m_data[S->m_top];
}

void pushStack(pStack &S, ElementType &element) {
    if (S->m_top == S->m_maxSize)
        throw DsException(THEINDEXOUTOFRANGE);
    S->m_data[++S->m_top] = element;
}

bool popStack(pStack &S, ElementType &element) {
    if (stackEmpty(S))
        return false;
    element = S->m_data[S->m_top--];
    return true;
}
