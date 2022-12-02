# 单链表

## Declaration and Definition

### 声明

[linkedList.h](../include/linkedList.h)

```c++
typedef int ElementType; // 元素类型

typedef struct LNode { // 元素节点
    ElementType m_data;
    struct LNode *m_next; // 后继节点
    explicit LNode(ElementType data, struct LNode* next= nullptr)
            :m_data(data),m_next(next){}
} LinkedNode, *pLinkedNode;

typedef struct LinkedList{ // 链表
    pLinkedNode m_head; // 头结点
    pLinkedNode m_last; // 尾节点
    int m_length; // 链表长度
    explicit LinkedList(): m_head(new LinkedNode(0)), m_last(new LinkedNode(0)),m_length(0){}
}*pLinkedList;


void insertNodeAfter(pLinkedNode &node, pLinkedNode &x); // 插入直接后继节点
void removeNodeAfter(pLinkedNode &node); // 移除后继节点

pLinkedNode removeNodeAfterAndReturn(pLinkedNode &node); // 移除直接后续节点并返回
bool checkIndexOnList(pLinkedList &L,int index); // 检查索引是否有效
void createListFront(pLinkedList &L, ElementType *&arr, int n); // 从元素数组创建一个链表，使用头插法
void createListRear(pLinkedList &L, int *arr, int n); // 从元素数组创建一个链表，使用尾插法
void initList(pLinkedList &L); // 初始化一个链表
void destroyList(pLinkedList &L); // 销毁一个链表
bool listEmpty(pLinkedList &L); // 判断链表是否为空
int listLength(pLinkedList &L); // 获得链表长度
void displayList(pLinkedList &L); // 打印链表
pLinkedNode getElement(pLinkedList &L, int index); // 获得索引为index处的元素
int locateElement(pLinkedList &L, ElementType &element); // 获取匹配元素的索引
void listInsert(pLinkedList &L, int index, ElementType & element); // 向链表中插入元素
void listDelete(pLinkedList &L, int index); // 删除链表中的元素
```



### 定义

[linkedList.cpp](../linkedList.cpp)

```c++
#include <cstdio>
#include "linkedList.h"
#include "utils/dsexception.h"

void insertNodeAfter(pLinkedNode &node, pLinkedNode &x) { // 在node后插入节点
    x->m_next = node->m_next;
    node->m_next = x;
}

void removeNodeAfter(pLinkedNode &node) { // 移除node的直接后继节点
    pLinkedNode oldNode = node->m_next;
    node->m_next = oldNode->m_next;
    delete oldNode;
}

pLinkedNode removeNodeAfterAndReturn(pLinkedNode &node) { // 移除node的直接后继节点并返回
    pLinkedNode oldNode = node->m_next;
    node->m_next = oldNode->m_next;
    return oldNode;
}

void createListFront(pLinkedList &L, ElementType *arr, int n) {
    initList(L);
    for (int i = 0; i < n; ++i) {
        pLinkedNode node = new LinkedNode(arr[i]);
        insertNodeAfter(L->m_head, node); // 在头结点之后插入节点
        if (listEmpty(L)) // 链表为空
            L->m_last = node; // 更新尾节点
        ++L->m_length; // 更新长度
    }
}

void createListRear(pLinkedList &L, ElementType *arr, int n) {
    initList(L);
    for (int i = 0; i < n; ++i) {
        pLinkedNode node = new LinkedNode(arr[i]);
        if (listEmpty(L)) // 链表为空
            L->m_last = L->m_head->m_next = node;
        else {
            L->m_last->m_next = node;
            L->m_last = node;
        }
        ++L->m_length;
    }

}

void initList(pLinkedList &L) {
    L = new LinkedList();
}

void destroyList(pLinkedList &L) {
    if(!L)return;
    pLinkedNode node = L->m_head->m_next, removed;
    while (node) {
        removed = node;
        node = node->m_next;
        delete removed;
    }
    L->m_length = 0;
}

bool listEmpty(pLinkedList &L) {
    return L->m_length == 0 && !L->m_head->m_next;
}

int listLength(pLinkedList &L) {
    return L->m_length;
}

void displayList(pLinkedList &L) {
    if(!L) return;
    printf("LinkedList:[ ");
    for (pLinkedNode p = L->m_head->m_next; p; p = p->m_next) {
        printf("%d ", p->m_data);
    }
    printf("], size=%d\n", L->m_length);
}

pLinkedNode getElement(pLinkedList &L, int index) {
    if (!checkIndexOnList(L, index)) return nullptr;
    int count = 0;
    pLinkedNode p;
    for (p = L->m_head->m_next; p; p = p->m_next, ++count) {
        if (count == index)
            break;
    }
    return p;
}

int locateElement(pLinkedList &L, ElementType &element) {
    int index = -1;
    pLinkedNode node = L->m_head->m_next;
    for (int i = 0; i < L->m_length; ++i) {
        if (node->m_data == element) index = i;
        node = node->m_next;
    }
    return index;
}

void listInsert(pLinkedList &L, int index, ElementType &element) {
    if (!checkIndexOnList(L, index)) throw DsException(THEINDEXOUTOFRANGE);
    pLinkedNode p = L->m_head->m_next;
    for (int i = 0; i < L->m_length; ++i) {
        if(index==i) break;
        p = p->m_next;
    }
    pLinkedNode newNode = new LinkedNode(element);
    insertNodeAfter(p,newNode);
    ++L->m_length;
}

bool checkIndexOnList(pLinkedList &L, int index) {
    return !(index < 0 || index >= L->m_length);
}

void listDelete(pLinkedList &L, int index) {
    if(!checkIndexOnList(L,index)) throw DsException(THEINDEXOUTOFRANGE);
    pLinkedNode node = L->m_head;
    for (int i = -1; i < L->m_length; ++i) {
        if(index-1==i) break;
        node = node->m_next;
    }
    removeNodeAfter(node);
}
```



## Algorithms



### 拆分带头结点的单链表

> 将带头结点的单链表L拆分为两个带头结点的单链表L1,L2，其中$L = [a_1,b_1,a_2,b_2,...,a_n,b_n], L1 = [a_1,a_2,...,a_n],L2=[b_n,b_{n-1},...,b_1]$，L1使用L的头结点。

[algorithm2-6](../algorithm2-6.cpp) T-O(n)/S-O(1) 

- algorithm 1：遍历链表L，取出bn使用头插法拆入L2。

  ```c++
  void splitList(pLinkedList &L, pLinkedList &L1, pLinkedList &L2) {
      L1 = L; // L1 使用L的头结点
      initList(L2);
      pLinkedNode node = L->m_head;
      while (node && node->m_next) {
          node = node->m_next; // an
          pLinkedNode p = node->m_next; // 取出 bn
          node->m_next = p->m_next;
          L->m_length--;
  
          p->m_next = L2->m_head->m_next; // 头插法，插入bn
          L2->m_head->m_next = p;
          L2->m_length++;
          if (listEmpty(L2)) // L2空表时，记得更新尾节点
              L->m_last = p;
      }
  }
  ```
  
- test:

  ```c++
  int main() {
      pLinkedList L = nullptr, L1 = nullptr, L2 = nullptr;
      int n = 10;
      ElementType arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  
      createListRear(L, arr, n);
      printf("L:");
      displayList(L);
  
      printf("L->L1,L2\n");
      splitList(L, L1, L2);
  
      printf("L1:");
      displayList(L1);
      printf("L2:");
      displayList(L2);
  
      destroyList(L1);
      destroyList(L2);
      return 0;
  }
  ```

- result:

  <img src="https://cdn.jsdelivr.net/gh/initH271/resource-public/img/20221202133446.png" alt="image-20221202133446134" style="zoom:50%;" align=left />

### 删除链表中的元素值最大的节点

  [algorithm2-7](../algorithm2-7.cpp) T(O(n)) / S(O(1))

  - algorithm 1: 由头结点开始，比较其后继节点的元素，存储当前最大元素节点的直接前继。

    ```c++
    void deleteMaxNode(pLinkedList &L) {
        if(listEmpty(L)) return;
        pLinkedNode p = L->m_head, max = p; // 头结点开始，比较的是其后继元素
        while (p && p->m_next) {
            if (p->m_next->m_data > max->m_next->m_data) // 比较下一节点是否比当前最大值节点大
                max = p;
            p = p->m_next;
        }
        removeNodeAfter(max);
        L->m_length--;
    }
    ```
    
- test:

  ```c++
  int main(int argc, char const *argv[]) {
      pLinkedList L;
      int n = 10;
      ElementType arr[] = {1, 3, 2, 9, 0, 4, 7, 6, 5, 8};
      createListRear(L, arr, n);
      displayList(L);
      printf("删除元素最大的节点\n");
      deleteMaxNode(L);
      displayList(L);
      printf("删除元素最大的节点\n");
      deleteMaxNode(L);
      displayList(L);
      printf("删除元素最大的节点\n");
      deleteMaxNode(L);
      displayList(L);
      printf("删除元素最大的节点\n");
      deleteMaxNode(L);
      displayList(L);
      printf("删除元素最大的节点\n");
      deleteMaxNode(L);
      displayList(L);
      printf("删除元素最大的节点\n");
      deleteMaxNode(L);
      displayList(L);
      printf("删除元素最大的节点\n");
      deleteMaxNode(L);
      displayList(L);
      printf("删除元素最大的节点\n");
      deleteMaxNode(L);
      displayList(L);
      printf("删除元素最大的节点\n");
      deleteMaxNode(L);
      displayList(L);
      printf("删除元素最大的节点\n");
      deleteMaxNode(L);
      displayList(L);
      destroyList(L);
      return 0;
  }
  ```

- result:

  <img src="https://cdn.jsdelivr.net/gh/initH271/resource-public/img/20221202133702.png" alt="image-20221202133702569" style="zoom:50%;" align=left />

### 对带头结点的链表进行递增排序

  [algorithm2-8](../algorithm2-8.cpp) T(O(n)) / S(O(1))

  - algorithm 1：用原链表的空间构建一个单节点的链表，从原链表的第二个节点开始与单链表中的节点比较，插入在大于其的节点之前。

    ```c++
    void sort(pLinkedList &L) {
        pLinkedNode p = L->m_head->m_next->m_next; // 指向第二个节点
        pLinkedNode q;
        pLinkedNode pre; // p的前缀指针
        L->m_head->m_next->m_next = nullptr; // 构造单节点的链表
        while (p) {
            q = p->m_next; // 存储p的下一个节点位置
    
            pre = L->m_head; // 操作链表，比较大小找到插入p的位置
            while (pre->m_next && pre->m_next->m_data < p->m_data)
                pre = pre->m_next;
            p->m_next = pre->m_next; // 插入p节点
            pre->m_next = p;
    
            p = q; // 步进下一节点
        }
    }
    ```

- test:

  ```c++
  int main(int argc, char const *argv[]) {
      pLinkedList L;
      ElementType arr[] = {1, 3, 2, 9, 0, 4, 7, 6, 5, 8};
      createListRear(L, arr, 10);
      displayList(L);
      printf("对链表进行递增排序\n");
      sort(L);
      displayList(L);
      destroyList(L);
      return 0;
  }
  ```

- result:

  <img src="https://cdn.jsdelivr.net/gh/initH271/resource-public/img/20221202133817.png" alt="image-20221202133817057" style="zoom:50%;" align=left />

  