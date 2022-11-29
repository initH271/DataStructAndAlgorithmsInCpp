# 双向链表

## Declaration and Definition

### 声明

[dlinkedList.h](../include/dlinkedList.h)

```c++
typedef int ElementType;

typedef struct DNode {
    ElementType m_data;
    struct DNode *m_prior, *m_next; // 双向指针
    explicit DNode() = default;

    explicit DNode(ElementType &data, struct DNode *prior = nullptr, struct DNode *next = nullptr)
            : m_data(data), m_prior(prior), m_next(next) {}
} DLinkedNode, *pDLinkedNode, DLinkedList, *pDLinkedList;

void createListFront(pDLinkedList &L, ElementType *arr, int n); // 头插法创建双向链表
void createListRear(pDLinkedList &L, ElementType *arr, int n); // 尾插法创建双向链表

void initList(pDLinkedList &L); // 初始化一个空双向链表
void destroyList(pDLinkedList &L); // 销毁一个双向链表
bool listEmpty(pDLinkedList &L); // 双向链表是否为空
int listLength(pDLinkedList &L); // 获取双向链表长度
void displayList(pDLinkedList &L); // 打印双向链表
void listInsert(pDLinkedList &L, int index, ElementType &element); // 向双向链表索引处插入元素
void listDelete(pDLinkedList &L, int index); // 从双向链表中删除索引处节点

pDLinkedNode getElement(pDLinkedList &L, int index); // 获取双向链表中指定索引的元素
int locateElement(pDLinkedList &L, ElementType &element); // 查找元素在双向链表中的索引
```

### 定义

[dlinkedList.cpp](../dlinkedList.cpp)

```c++
void initList(pDLinkedList &L) {
    L = new DLinkedList();
    L->m_prior = L->m_next = nullptr;
}

void createListFront(pDLinkedList &L, ElementType *arr, int n) {
    initList(L);
    for (int i = 0; i < n; ++i) { // 以循环链表的方式创建
        pDLinkedNode node = new DLinkedNode(arr[i], L, L->m_next); // 构造新节点，前接头结点，后接首节点
        L->m_next = node;
    }
}

void createListRear(pDLinkedList &L, ElementType *arr, int n) {
    initList(L);
    pDLinkedNode p = L;
    for (int i = 0; i < n; ++i) { // 以循环链表的方式创建
        pDLinkedNode node = new DLinkedNode(arr[i], p, p->m_next); // 构造新节点
        p->m_next = node;
        p = p->m_next;
    }
}

void destroyList(pDLinkedList &L) {
    pDLinkedNode node = L->m_next;
    while (node) {
        L = node->m_next;
        delete node;
        node = L;
    }
}

bool listEmpty(pDLinkedList &L) {
    return L->m_next == nullptr;
}

int listLength(pDLinkedList &L) {
    pDLinkedNode node = L->m_next;
    int index = 0;
    while (node) {
        node = node->m_next;
        index++;
    }
    return index;
}

void displayList(pDLinkedList &L) {
    printf("DLinkedList:[ ");
    int count = 0;
    for (pDLinkedNode node = L->m_next; node; node = node->m_next, count++)
        printf("%d ", node->m_data);
    printf("], size=%d\n", count);
}

void listInsert(pDLinkedList &L, int index, ElementType &element) {
    pDLinkedNode node = L;
    int i;
    for (i = 0; i < index && node; ++i) {
        node = node->m_next;
    }
    if (i != index || !node) return;
    pDLinkedNode p = new DLinkedNode(element, node, node->m_next);
    node->m_next = p;
}

void listDelete(pDLinkedList &L, int index) {
    pDLinkedNode node = L;
    int i;
    for (i = 0; i < index && node; ++i) {
        node = node->m_next;
    }
    if (i != index || !node) return;
    pDLinkedNode p = node->m_next;
    p->m_next->m_prior = node;
    node->m_next = p->m_next;
    delete p;
}

pDLinkedNode getElement(pDLinkedList &L, int index) {
    pDLinkedNode node = L;
    int i;
    for (i = 0; i < index && node; ++i) {
        node = node->m_next;
    }
    if (i != index) return nullptr;
    return node;
}

int locateElement(pDLinkedList &L, ElementType &element) {
    int index = -1;
    pDLinkedNode node = L->m_next;
    for (int i = 0; node; node = node->m_next, i++) {
        if (node->m_data == element) index = i;
    }
    return index;
}
```



## Algorithms

### 倒置双向链表的元素

[algorithm2-9](../algorithm2-9.cpp)

- algorithm 1: 取出原有头结点，使用头插法插入原有节点

  ```c++
  void reverseList(pDLinkedList &L) {
      pDLinkedNode p = L->m_next, q;
      L->m_next = nullptr;
      while (p) {
          q = p->m_next; // 记住下一节点
  
          p->m_next = L->m_next; // 头插法插入节点
          p->m_prior = L;
          L->m_next = p;
  
          p = q;
      }
  }
  ```

  

### 递增排序双向链表

[algorithm2-10](./algorithm2-10.cpp)

- algorithm 1：用原链表构造一个单节点链表，遍历剩下的节点，比较后插入对应位置

  ```c++
  void sortList(pDLinkedList &L) {
      pDLinkedNode p = L->m_next->m_next, q, pre;
      L->m_next->m_next = nullptr; // 构造单节点链表
      while (p) {
          q = p->m_next; // 记住下一节点的位置
  
          pre = L;
          while (pre->m_next && pre->m_next->m_data < p->m_data) // 找到不小于p的节点
              pre = pre->m_next;
          p->m_prior = pre; // 插入节点
          p->m_next = pre->m_next;
          if (pre->m_next) // 如果找到的节点不是尾节点
              pre->m_next->m_prior = p;
          pre->m_next = p;
          p = q;
      }
  }
  ```

  