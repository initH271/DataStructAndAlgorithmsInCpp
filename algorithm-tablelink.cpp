/**
 * @file algorithm-tablelink.cpp
 * @brief: 2.5 线性表的应用 - 表的笛卡尔积连接实现
 * @version: 1.0
 * @author: inith271
 * @email: oy.zf@qq.com
 * @date: 22/11/30 8:40
 *
 **/

#include "tableList.h"
#include <cstdio>


// 使用clion配置了重定向输入，输入文件路径: input/tablelink_input.txt
int main(int argc, char const *argv[]) {
    pTable T1, T2, T3;
    printf("创建表1:\n");
    createTable(T1);
    displayTable(T1);
    printf("创建表2:\n");
    createTable(T2);
    displayTable(T2);
    printf("连接表1、2为表3:\n");
    linkTable(T1, T2, T3); // 链接表1、2到表3
    displayTable(T3);

    destroyTable(T1);
    destroyTable(T2);
    destroyTable(T3);
    return 0;
}