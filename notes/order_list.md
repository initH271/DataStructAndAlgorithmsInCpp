# 线性表的应用 - 有序表

## Declaration and Definition

### 顺序结构的声明

[sqOrderList.h](../include/sqOrderList.h)

```c++
typedef int ElementType;

typedef struct LNode {
    ElementType *m_data;
    int m_length;
    int m_maxSize;
    explicit LNode():m_data(nullptr),m_length(0),m_maxSize(0){}
} *pSqList, SqList;

void createList(pSqList &L, ElementType *arr, int n); // 从数组创建有序表
void initList(pSqList &L, int size = 10); // 初始化一个有序表
void destroyList(pSqList &L); // 销毁一个有序表
void displayList(pSqList &L); // 打印一个有序表
bool listEmpty(pSqList &L); // 有序表是否为空
ElementType getElement(pSqList &L, int index); // 获取索引所在元素
int locateElement(pSqList &L, ElementType &element); // 获取元素索引
void listInsert(pSqList &L, ElementType &element); // 将元素插入
void listDelete(pSqList &L, int index); // 删除索引出元素
```



### 顺序结构的定义

[sqOrderList.cpp](../sqOrderList.cpp)

```c++
#include <cstdio>
#include "sqOrderList.h"
#include "utils/dsexception.h"

void createList(pSqList &L, ElementType *arr, int n) {
    initList(L, n);
    for (int i = 0; i < n; ++i) {
        listInsert(L, arr[i]);
    }
}

void initList(pSqList &L, int size) {
    L = new SqList();
    L->m_data = new ElementType[L->m_maxSize = size];
}

void listInsert(pSqList &L, ElementType &element) {
    if (listEmpty(L)) { // 表空
        L->m_data[L->m_length++] = element;
        return;
    }
    if (L->m_maxSize == L->m_length) return; // 表满
    int i = 0;
    for (; i < L->m_length; ++i) { // 找到插入位置
        if (element < L->m_data[i]) break;
    }
    for (int j = L->m_length; j > i; --j) { // 移动后方元素
        L->m_data[j] = L->m_data[j - 1];
    }
    L->m_data[i] = element; // 插入元素
    L->m_length++;
}

void destroyList(pSqList &L) {
    delete[]L->m_data;
    delete L;
}

void displayList(pSqList &L) {
    printf("OrderList:{ ");
    for (int i = 0; i < L->m_length; ++i) {
        printf("%d, ", L->m_data[i]);
    }
    printf("}, size=%d\n", L->m_length);
}

ElementType getElement(pSqList &L, int index) {
    if (index < 0 || index >= L->m_length)
        throw DsException(THEINDEXOUTOFRANGE);
    return L->m_data[index];
}

int locateElement(pSqList &L, ElementType &element) {
    int index = -1;
    for (int i = 0; i < L->m_length; ++i) {
        if (L->m_data[i] == element) {
            index = i;
            break;
        }
    }
    return index;
}

void listDelete(pSqList &L, int index) {
    if (listEmpty(L) || index < 0 || index >= L->m_length) return;
    for (int i = index; i < L->m_length - 1; i++)
        L->m_data[i] = L->m_data[i + 1];
    L->m_length--;
}

bool listEmpty(pSqList &L) {
    return L->m_length == 0;
}
```



### 链式结构的声明

```c++
typedef int ElementType;

typedef struct OLNode {
    ElementType m_data;
    struct OLNode *m_next;

    explicit OLNode() : m_next(nullptr) {}

    explicit OLNode(ElementType &data, struct OLNode *next = nullptr) : m_data(data), m_next(next) {}
} *pOrderLinkedList, OrderLinkedList,
        *pOrderListNode, OrderListNode;

void createList(pOrderLinkedList &L, ElementType *arr, int n);

void initList(pOrderLinkedList &L);

void destroyList(pOrderLinkedList &L);

bool listEmpty(pOrderLinkedList &L);

int listLength(pOrderLinkedList &L);

void displayList(pOrderLinkedList &L);

pOrderListNode getElement(pOrderLinkedList &L, int index);

int locateElement(pOrderLinkedList &L, ElementType &element);

void listInsert(pOrderLinkedList &L, ElementType &element);

void listDelete(pOrderLinkedList &L, int index);
```



### 链式结构的定义

```c++
#include <cstdio>
#include "orderLinkedList.h"

void initList(pOrderLinkedList &L) {
    L = new OrderLinkedList();
}

void createList(pOrderLinkedList &L, ElementType *arr, int n) {
    initList(L);
    for (int i = 0; i < n; ++i) {
        listInsert(L, arr[i]);
    }
}

bool listEmpty(pOrderLinkedList &L) {
    return L->m_next == nullptr;
}

int listLength(pOrderLinkedList &L) {
    int count = 0;
    pOrderListNode p = L->m_next;
    while (p && ++count)
        p = p->m_next;
    return count;
}

void listInsert(pOrderLinkedList &L, ElementType &element) {
    pOrderListNode node = new OrderListNode(element);
    pOrderListNode p = L;
    while (p && p->m_next) {
        if (element < p->m_next->m_data)
            break;
         p = p->m_next;
    }
    node->m_next = p->m_next;
    p->m_next = node;
}

void destroyList(pOrderLinkedList &L) {
    pOrderListNode p = L->m_next;
    while (p) {
        L->m_next = p->m_next;
        delete p;
        p = L->m_next;
    }
    delete L;
}

void displayList(pOrderLinkedList &L) {
    printf("OrderLinkedList:[ ");
    pOrderListNode p = L->m_next;
    int count = 0;
    while (p && ++count) {
        printf("%d ", p->m_data);
        p = p->m_next;
    }
    printf("], size=%d\n", count);
}

pOrderListNode getElement(pOrderLinkedList &L, int index) {
    pOrderListNode p = L->m_next;
    int i = 0;
    while (p && i++ < index)
        p = p->m_next;
    return p;
}

int locateElement(pOrderLinkedList &L, ElementType &element) {
    pOrderListNode p = L->m_next;
    int index = -1, i = 0;
    while (p) {
        if (p->m_data == element) {
            index = i;
            break;
        }
        p = p->m_next;
        i++;
    }
    return index;
}

void listDelete(pOrderLinkedList &L, int index) {
    pOrderListNode p = L, q;
    while (p->m_next && 0 < index)
        p = p->m_next, index--;
    q = p->m_next;
    p->m_next = q->m_next;
    delete q;
}
```





## Algorithms

### [顺序结构] 将两个有序表归并为一个有序表

[algorithm2-14](../algorithm2-14.cpp) T(O(n)) / S(O(1))

- algorithm 1: 两表各用一个指针，从最左端开始相互比较，若指针所指值小于等于另一指针，则取出元素插入合并表，而后指针步进，继续比较并执行前一步骤。

  ```c++
  void unionList(pSqList &S1, pSqList &S2, pSqList &T) {
      initList(T, S1->m_length + S2->m_length);
      int i = 0, j = 0;
      while (i < S1->m_length && j < S2->m_length) { // 表1和表2元素依次比较插入
          if (S1->m_data[i] < S2->m_data[j])
              listInsert(T, S1->m_data[i++]);
          else
              listInsert(T, S2->m_data[j++]);
      }
      // 剩下的一段直接插入
      while (i < S1->m_length)
          listInsert(T, S1->m_data[i++]);
      while (j < S1->m_length)
          listInsert(T, S2->m_data[j++]);
  }
  ```

- test:

  ```c++
  int main(int argc, char const *argv[]) {
      pSqList L1, L2, L3;
      ElementType arr[] = {55, 66, 44, 77, 33, 88, 22, 99, 11, 0};
      createList(L1, arr, 5);
      createList(L2, &arr[5], 5);
      displayList(L1);
      displayList(L2);
  
      printf("合并有序表L1和L2:\n");
      unionList(L1, L2, L3);
      displayList(L3);
      destroyList(L1);
      destroyList(L2);
      destroyList(L3);
      return 0;
  }
  ```

- result:

  ![image-20221202141907949](https://cdn.jsdelivr.net/gh/initH271/resource-public/img/20221202141908.png)

  

### [顺序结构]求两个有序表中所有元素的中位数

  [algorithm2-17](../algorithm2-17.cpp)

  - algorithm 1: 对长度为n的有序表中位数（如n为偶数，中位数取中间两位前一位）

    ```c++
    ElementType findMedian(pSqList &L1, pSqList &L2) {
        int q = 0; // L1 指针
        int p = 0; // L2 指针
        int count = 0;
        while (q < L1->m_length && p < L2->m_length) {
            count++;
            if (L1->m_data[q] <= L2->m_data[p]) // 扫描L1表
                if (count == L1->m_length)
                    return L1->m_data[q];
                else {
                    q++;
                }
            else // 扫描L2表
            if (count == L2->m_length)
                return L2->m_data[p];
            else
                p++;
        }
        return count == L1->m_length ? L1->m_data[q] : L2->m_data[p];
    }
    ```

  - test:

    ```c++
    int main(int argc, char const *argv[]) {
        ElementType arr[] = {1, 2, 3, 4, 6, 7, 8, 9,
                             10, 9, 11, 5, 3, 1, 44, 66, 77,
                             3, 1, 5, 34, 55, 57, 34};
        pSqList L1, L2, L3;
        createList(L1, arr, 12);
        createList(L2, &arr[12], 12);
        createList(L3, arr, 24);
        displayList(L1);
        displayList(L2);
        printf("两有序表的中位数是%d\n", findMedian(L1, L2));
        displayList(L3); // 验证
        int mid = L3->m_length / 2 - 1;
        printf("正确的中位数=%d, 索引为%d\n", L3->m_data[mid], mid);
        destroyList(L1);
        destroyList(L2);
        return 0;
    }
    ```

    

  - result:

    <img src="https://cdn.jsdelivr.net/gh/initH271/resource-public/img/20221202161238.png" alt="image-20221202161238716" style="zoom:50%;" align=left />

  

### [顺序结构] 二分查找

  [algorithm-binarySearch](../algorithm-binarySearch.cpp) T(O(logn)) / S(O(1))

  - algorithm 1: 将有序表[low, high] 进行折半拆分得到[low, mid], [mid+1, high]两个有序表，此时与mid处元素进行比较就可以缩小一半的查找范围，对缩小后的有序表部分继续折半查找比较，知道找到匹配元素或者不存在。

    ```c++
    int binarySearch(pSqList &L, int x, int low, int high) {
        int count = 0;
        while (low < high) {
            int mid = (low + high) >> 1;
            x < L->m_data[mid] ? high = mid : low = mid + 1;
            count++;
        }
        printf("比较次数为 %d\n", count);
        return low - 1;
    }
    ```

  - test:

    ```c++
    int main(int argc, char const *argv[]) {
        ElementType arr[11] = {13, 18, 24, 35, 47, 50, 62, 83, 90, 115, 134};
        pSqList L;
        createList(L, arr, 11);
        displayList(L);
        ElementType x = 90;
        printf("二分查找 %d = %d", x, binarySearch(L, x, 0, 10));
        return 0;
    }
    ```

  - result:

    <img src="https://cdn.jsdelivr.net/gh/initH271/resource-public/img/20221202145616.png" alt="image-20221202145616500" style="zoom:50%;" align=left />

### [链式结构] 求3个有序表的并集

[algorithm2-15](../algorithm2-15.cpp) T(O(n)) / S(O(1))

- algorithm 1: 各表使用一个指针，遍历表一，同时将另外两个表遍历，移动指针使之与表一指针对齐，当三个指针所指元素相等时插入并集表。

  ```c++
  void solution(pOrderLinkedList &L1, pOrderLinkedList &L2, pOrderLinkedList &L3) {
      pOrderListNode p = L1->m_next, q = L2->m_next, m = L3->m_next; // 三个表指针
      L1->m_next = nullptr; // 构造L1为空表
      pOrderListNode n = L1, r;
      while (p && q && m) {
          while (q && q->m_data < p->m_data) // 移动表指针，对齐表使所指节点不小于目标
              q = q->m_next;
          while (m && m->m_data < p->m_data)
              m = m->m_next;
  
          if (q && m && p->m_data == q->m_data && p->m_data == m->m_data) { // 如是交集元素，则插入
              r = p;
              p = p->m_next;
  
              r->m_next = n->m_next;
              n->m_next = r;
              n = n->m_next;
          } else { // 否则释放
              r = p;
              p = p->m_next;
  
              delete r;
          }
      }
  }
  ```

- test:

  ```c++
  int main(int argc, char const *argv[]) {
      ElementType arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9,
                           10, 9, 7, 5, 3, 1, 44, 66, 77,
                           3, 1, 5, 34, 57, 12};
      pOrderLinkedList L1, L2, L3;
      createList(L1, arr, 9);
      createList(L2, &arr[9], 9);
      createList(L3, &arr[18], 6);
  
      displayList(L1);
      displayList(L2);
      displayList(L3);
      printf("求L1,L2,L3的交集:\n");
      solution(L1, L2, L3);
      displayList(L1);
      destroyList(L1);
      destroyList(L2);
      destroyList(L3);
      return 0;
  }
  ```

- result:

  <img src="https://cdn.jsdelivr.net/gh/initH271/resource-public/img/20221202150548.png" alt="image-20221202150548821" style="zoom:50%;" align=left />



### [链式结构] 唯一化有序表

[algorithm2-16](../algorithm2-16.cpp) T(O(n)) / S(O(1))

- algorithm 1: 有序表中相同元素必相邻，因此，遍历有序表，删除与当前元素相同的节点即可。

  ```c++
  void uniqueList(pOrderLinkedList &L) {
      pOrderListNode p = L->m_next, q;
      while (p && p->m_next) {
          if (p->m_data == p->m_next->m_data) {
              q = p->m_next; // 取出重复节点并删除
              p->m_next = q->m_next;
              delete q;
          } else {
              p = p->m_next;
          }
      }
  }
  ```

- test:

  ```c++
  int main(int argc, char const *argv[]) {
      pOrderLinkedList L;
      ElementType arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9,
                           10, 9, 7, 5, 3, 1, 44, 66, 77,
                           3, 1, 5, 34, 57, 12};
      createList(L, arr, 24);
      displayList(L);
      printf("唯一化有序表之后：\n");
      uniqueList(L);
      displayList(L);
  
      destroyList(L);
      return 0;
  }
  ```

- result:

  <img src="https://cdn.jsdelivr.net/gh/initH271/resource-public/img/20221202150926.png" alt="image-20221202150926190" style="zoom:50%;" align=left />