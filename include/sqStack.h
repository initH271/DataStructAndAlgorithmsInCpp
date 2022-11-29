/**
 * @file sqStack.h
 * @brief: 顺序栈的声明
 * @version: 1.0
 * @author: inith271
 * @email: oy.zf@qq.com
 * @date: 22/11/29 13:15
 *
 **/

#ifndef SQSTACK_H
#define SQSTACK_H

typedef int ElementType;
typedef struct {
    ElementType *m_data; // 栈域
    int m_top; // 栈顶指针
    int m_maxSize; // 最大栈空间
} Stack, *pStack;

void initStack(pStack &S, int size = 10); // 初始化栈
void destroyStack(pStack &S); // 销毁栈
bool stackEmpty(pStack &S); // 判断栈空
void pushStack(pStack &S, ElementType &element);

bool popStack(pStack &S, ElementType &element);

ElementType &stackTop(pStack &S);

#endif //SQSTACK_H
