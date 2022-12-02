# 循环链表

## 循环单链表

### Declaration and Definition

#### 声明

[clinkedlist.h](../include/clinkedList.h)

```c++
typedef int ElementType;

typedef struct CLNode {
    ElementType m_data;
    struct CLNode *m_next;
    explicit CLNode()=default;
    explicit CLNode(ElementType &data,struct CLNode*next= nullptr):
            m_data(data),m_next(next){}
} CLinkedListNode, *pCLinkedListNode,
        CLinkedList, *pCLinkedList;

void initList(pCLinkedList &L); // 初始化一个循环单链表

void createListFront(pCLinkedList &L, ElementType *arr, int n); // 从元素数组创建循环单链表，头插法
void createListRear(pCLinkedList &L, ElementType *arr, int n); // 从元素数组创建循环单链表，尾插法

void destroyList(pCLinkedList &L); // 销毁一个循环单链表

bool listEmpty(pCLinkedList &L); // 判断循环单链表是否为空

int listLength(pCLinkedList &L); // 获取循环单链表长度

void displayList(pCLinkedList &L); // 打印循环单链表

void listInsert(pCLinkedList &L, int index, ElementType &elementType); // 将元素插入循环单链表

void listDelete(pCLinkedList &L, int index); // 删除循环单链表中的元素

pCLinkedListNode getElement(pCLinkedList &L, int index); // 根据索引获取元素节点

int locateElement(pCLinkedListNode &L, ElementType &element); // 获取元素索引
```



#### 定义

[clinkedList.cpp](../clinkedList.cpp)

```c++
#include <cstdio>
#include "clinkedList.h"

void createListRear(pCLinkedList &L, ElementType *arr, int n) {
    initList(L);
    pCLinkedListNode p = L;
    for (int i = 0; i < n; ++i) {
        pCLinkedListNode node = new CLinkedListNode(arr[i], L); // 构建新节点, 后接头结点
        p->m_next = node; // 作为尾节点插入
        p = p->m_next;
    }
}

void initList(pCLinkedList &L) {
    L = new CLinkedList();
    L->m_next = L;
}

void destroyList(pCLinkedList &L) {
    pCLinkedListNode p = L->m_next;
    while (p != L) {
        L->m_next = p->m_next;
        delete p;
        p = L->m_next;
    }
    delete L;
}

void displayList(pCLinkedList &L) {
    pCLinkedListNode p = L->m_next;
    int count = 0;
    printf("CLinkedList:[ ");
    while (p != L) {
        printf("%d ", p->m_data);
        p = p->m_next;
        count++;
    }
    printf("], size=%d\n", count);
}
```



### Algorithms

#### 统计循环单链表中指定值域为x的节点个数

[algorithm2-11](../algorithm2-11.cpp) T(O(n)) / S(O(1))

- algorithm 1：遍历单链表，并加上计数条件

  ```c++
  int countX(pCLinkedList &L, ElementType &x) {
      pCLinkedListNode p = L->m_next;
      int count = 0;
      while (p != L) {
          if (p->m_data == x) count++;
          p = p->m_next;
      }
      return count;
  }
  ```

- test:

  ```c++
  int main(int argc, char const *argv[]) {
      pCLinkedList L;
      ElementType arr[] = {1, 2, 2, 4, 2, 3, 5, 2, 1, 4};
      ElementType x = 2;
      createListRear(L, arr, 10);
      displayList(L);
      printf("对循环单链表L中的%d进行计数为%d.\n", x, countX(L, x));
      destroyList(L);
      return 0;
  }
  ```

- result:

  <img src="https://cdn.jsdelivr.net/gh/initH271/resource-public/img/20221202134517.png" alt="image-20221202134517217" style="zoom:50%;" align=left />

## 循环双向链表

### Declaration and Definition

#### 声明

[cdLinkedList.h](../include/cdLinkedList.h)

```c++
typedef int ElementType;

typedef struct CDLNode {
    ElementType m_data;
    struct CDLNode *m_prior, *m_next;

    explicit CDLNode() = default;

    explicit CDLNode(ElementType &data, struct CDLNode *prior = nullptr, struct CDLNode *next = nullptr) :
            m_data(data), m_prior(prior), m_next(next) {}

} CDLinkedListNode, *pCDLinkedListNode,
        CDLinkedList, *pCDLinkedList;



void initList(pCDLinkedList &L); // 初始化一个循环单链表

void createListFront(pCDLinkedList &L, ElementType *arr, int n); // 从元素数组创建循环单链表，头插法
void createListRear(pCDLinkedList &L, ElementType *arr, int n); // 从元素数组创建循环单链表，尾插法

void destroyList(pCDLinkedList &L); // 销毁一个循环单链表

bool listEmpty(pCDLinkedList &L); // 判断循环单链表是否为空

int listLength(pCDLinkedList &L); // 获取循环单链表长度

void displayList(pCDLinkedList &L); // 打印循环单链表

void listInsert(pCDLinkedList &L, int index, ElementType &elementType); // 将元素插入循环单链表

void listDelete(pCDLinkedList &L, int index); // 删除循环单链表中的元素

pCDLinkedListNode getElement(pCDLinkedList &L, int index); // 根据索引获取元素节点

int locateElement(pCDLinkedListNode &L, ElementType &element); // 获取元素索引
```

#### 定义

[cdLinkedList.cpp](../cdLinkedList.cpp)

```C++
#include <cstdio>
#include "cdLinkedList.h"

void createListRear(pCDLinkedList &L, ElementType *arr, int n) {
    initList(L);
    pCDLinkedListNode p = L;
    for (int i = 0; i < n; ++i) {
        pCDLinkedListNode node = new CDLinkedListNode(arr[i], L->m_prior, L); // 构建节点，前接尾节点，后接头结点
        L->m_prior->m_next = node; // 作为尾节点插入
        L->m_prior = node;
    }
}

void initList(pCDLinkedList &L) {
    L = new CDLinkedList();
    L->m_prior = L->m_next = L; // 头结点前继后继指向自身

}

void displayList(pCDLinkedList &L) {
    pCDLinkedListNode p = L->m_next;
    int count = 0;
    printf("CDLinkedList:[ ");
    while (p != L) {
        printf("%d ", p->m_data);
        p = p->m_next;
        count++;
    }
    printf("], size=%d\n", count);
}

void destroyList(pCDLinkedList &L) {
    pCDLinkedListNode p = L->m_next;
    while (p != L) {
        L->m_next = p->m_next;
        delete p;
        p = L->m_next;
    }
    delete L;
}
```



### Algorithms

#### 删除循环双向链表中第一个值域为X的结点

[algorithm2-12](../algorithm2-12.cpp) T(O(n)) / S(O(1))

- algorithm 1: 遍历到目标结点，利用双向链表的特点将其删除

  ```c++
  void deleteFirstX(pCDLinkedList &L, ElementType &x) {
      pCDLinkedListNode p = L->m_next;
      while (p != L) {
          if (x == p->m_data)
              break;
          p = p->m_next;
      }
      auto pre = p->m_prior;
      auto succ = p->m_next;
      pre->m_next = succ;
      succ->m_prior = pre;
      delete p;
  }
  ```

- test:

  ```c++
  int main(int argc, char const *argv[]) {
      ElementType arr[] = {1, 2, 2, 4, 2, 3, 5, 2, 1, 4};
      ElementType x = 1;
      pCDLinkedList L;
      createListRear(L, arr, 10);
      displayList(L);
      printf("删除第一个数据域为 %d 的节点\n", x);
      deleteFirstX(L, x);
      displayList(L);
      destroyList(L);
      return 0;
  }
  ```

- result

  <img src="https://cdn.jsdelivr.net/gh/initH271/resource-public/img/20221202134658.png" alt="image-20221202134658000" style="zoom:50%;" align=left />



#### 判断双向链表的节点是否对称

[algorithm2-13](../algorithm2-13) T(O(n)) / S(O(1))

- algorithm 1: 使用两个指针分别从前往后和从后往前扫描双向链表，比对值域是否相同

  ```c++
  bool listSymmetry(pCDLinkedList &L) {
      auto p = L->m_next, q = L->m_prior;
      bool result = true;
      while (p != q && p->m_next!=q) {
          if (p->m_data != q->m_data) {
              result = false;
              break;
          }
          p = p->m_next;
          q = q->m_prior;
      }
      return result;
  }
  ```

- test:

  ```c++
  int main(int argc, char const *argv[]) {
      ElementType arr[] = {1, 2,1, 2, 1};
      pCDLinkedList L;
      createListRear(L, arr, 5);
      displayList(L);
      printf("判断循环双链表是否对称：");
      if (listSymmetry(L))
          printf("\t对称");
      else
          printf("\t不对称");
      destroyList(L);
      return 0;
  }
  ```

- result:

  <img src="https://cdn.jsdelivr.net/gh/initH271/resource-public/img/20221202134750.png" alt="image-20221202134750605" style="zoom:50%;" align=left />