/**
 * @file util.h
 * @brief: 
 * @version: 1.0
 * @author: inith271
 * @email: oy.zf@qq.com
 * @date: 22/11/28 10:43
 *
 **/

#ifndef UTIL_H
#define UTIL_H

template<typename T>
void swap(T &a, T &b) {
    T temp = a;
    a = b;
    b = temp;
}

// 复制源数组source[0, slen) 到 target[start, start=slen)
template<typename T>
void copyArray(T *source, T *target, int start, int slen) {
    for (int i = 0; i < slen; ++i) {
        target[start++] = source[i];
    }
}

#endif //UTIL_H
