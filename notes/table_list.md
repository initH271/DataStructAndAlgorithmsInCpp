# 线性表的应用 - table list

## Declaration and Definition



### 声明

```c++
typedef int ElementType;

typedef struct RNode { // 行节点，存储一行数据
    ElementType *cols;
    struct RNode *next;

    explicit RNode() : next(nullptr), cols(nullptr) {}
} *pRow, Row;

typedef struct TableNode { // 表节点，表头
    int m_row, m_col;
    pRow next;

    explicit TableNode() : next(nullptr), m_col(0), m_row(0) {}
} Table, *pTable;


void createTable(pTable &T); // 从用户输入创建一个表
void destroyTable(pTable &T); // 销毁一个表
void displayTable(pTable &T); // 输出一个表
void linkTable(pTable &s1, pTable &s2, pTable &T); // 由源表s1,s2笛卡尔积的结果存储到表T
```



### 定义

```c++
#include <cstdio>
#include "tableList.h"
#include "utils/util.h"

void createTable(pTable &T) {
    T = new Table();
    scanf("%d %d", &T->m_row, &T->m_col); // 得到表的行数, 列数
    pRow p;
    for (int i = 0; i < T->m_row; ++i) {
        pRow row = new Row(); // 新建一行
        row->cols = new ElementType[T->m_col];
        for (int j = 0; j < T->m_col; ++j) { // 填充列数据
            scanf("%d", &row->cols[j]);
        }
        if (!T->next)
            T->next = p = row; // 接上表头
        else
            p = p->next = row; // 接上表尾
    }
}

void destroyTable(pTable &T) {
    pRow p = T->next;
    while (p) {
        T->next = p->next;
        delete[]p->cols;
        delete p;
        p = T->next;
    }
    delete T;
}

void displayTable(pTable &T) {
    pRow p = T->next;
    printf("Table:[\n");
    while (p) {
        printf("\t[ ");
        for (int i = 0; i < T->m_col; ++i) {
            printf("%d ", p->cols[i]);
        }
        printf("]\n");
        p = p->next; // 换行
    }
    printf("], shape = [%d, %d]\n", T->m_row, T->m_col);
}
```

## Algorithms



### 实现两个table的自然连接

[algorithm-tablelink.cpp](../algorithm-tablelink.cpp) T(O($n^2$)) / S(O(1))

- algorithm 1: 

  ```c++
  void linkTable(pTable &s1, pTable &s2, pTable &T) {
      int c1, c2; // 分别为源表1、2的列数，链接条件为c1=c2
      scanf("%d %d", &c1, &c2);
      T = new Table();
      T->m_col = s1->m_col + s2->m_col;
      pRow p = s1->next; // 扫描源表1
      pRow q;
      pRow m;
      while (p) {
          q = s2->next; // 扫描源表2
          while (q) {
              if (p->cols[c1 - 1] == q->cols[c2 - 1]) { // 比较链接条件是否成立, 注意列数-1为索引
                  pRow row = new Row();
                  row->cols = new ElementType[T->m_col];
                  copyArray(p->cols, row->cols, 0, s1->m_col); // 复制表1的行
                  copyArray(q->cols, row->cols, s1->m_col, s2->m_col); // 复制表2的行
                  if (!T->next) // 接入表
                      T->next = m = row;
                  else
                      m = m->next = row;
                  T->m_row++; // 目标表函数增加
              }
              q = q->next;
          }
          p = p->next;
      }
  }
  ```

- test:

  ```c++
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
  ```

  [tablelink_input.txt](../input/tablelink_input.txt) 给定了以下输入

  ```txt
  3 3
  1 2 3
  2 3 3
  1 1 1
  3 2
  3 5
  1 6
  3 4
  3 1
  ```

- result：

  <img src="https://cdn.jsdelivr.net/gh/initH271/resource-public/img/20221202140657.png" alt="image-20221202140657540" style="zoom:50%;" align=left />