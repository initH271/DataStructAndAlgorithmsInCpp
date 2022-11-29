/**
 * @file sqQueue.cpp
 * @brief: 
 * @version: 1.0
 * @author: inith271
 * @email: oy.zf@qq.com
 * @date: 22/11/29 15:00
 *
 **/

#include "sqQueue.h"

void initQueue(pSqQueue &Q, int size) {
    Q = new SqQueue();
    Q->m_data = new ElementType[Q->m_maxSize = size];
    Q->m_front = Q->m_rear = -1;
}

void destroyQueue(pSqQueue &Q) {
    delete[]Q->m_data;
    delete Q;
}

bool queueEmpty(pSqQueue &Q) {
    return Q->m_front == Q->m_rear;
}

void enQueue(pSqQueue &Q, ElementType &element) {
    if (Q->m_rear == Q->m_maxSize - 1) return;
    Q->m_data[Q->m_rear++] = element;
}

void deQueue(pSqQueue &Q, ElementType &element) {
    if (queueEmpty(Q)) return;
    element = Q->m_data[Q->m_front++];
}
