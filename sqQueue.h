/**
 * @file sqQueue.h
 * @brief: 顺序队列的声明
 * @version: 1.0
 * @author: inith271
 * @email: oy.zf@qq.com
 * @date: 22/11/29 15:00
 *
 **/

#ifndef SQQUEUE_H
#define SQQUEUE_H

typedef int ElementType;

typedef struct {
    ElementType *m_data;
    int m_front, m_rear; // 对头与队尾
    int m_maxSize;
} SqQueue, *pSqQueue;

void initQueue(pSqQueue &Q, int size = 10); // 初始化一个队列
void destroyQueue(pSqQueue &Q); // 销毁一个队列
bool queueEmpty(pSqQueue &Q); // 判断队列为空
void enQueue(pSqQueue &Q, ElementType &element); // 将元素入队
void deQueue(pSqQueue &Q, ElementType &element); // 元素出队

#endif //SQQUEUE_H
