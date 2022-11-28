# 顺序表 sequence list

## Declaration and Definition

### 声明

```c++
typedef int ElementType; // 元素类型
const int MAXSIZE =  10;

typedef struct { // 顺序表结构
    ElementType *m_data;
    int m_length;
} SqList, *pSqList;

void createList(pSqList &L, ElementType arr[], int n); // 从数组中建立顺序表

void initList(pSqList &L, int size=MAXSIZE); // 初始化一个空顺序表

void destroyList(pSqList &L); // 销毁顺序表

bool listEmpty(pSqList &L); // 顺序表是否为空

int ListLength(pSqList &L); // 顺序表长度

void displayList(pSqList &L); // 打印顺序表

ElementType& getElement(pSqList &L, int index); // 获取索引为index的元素

int locateElement(pSqList &L, ElementType &element); // 获取元素element在顺序表中的索引，如果存在

ElementType listDelete(pSqList &L, int index); // 删除索引为index的元素并返回
```

### 定义

```c++
const char *THEINDEXOUTOFRANGE = "the index out of range";

void initList(pSqList &L, int size) {
    L->m_data = new ElementType[size];
    L->m_length = 0;
}

void destroyList(pSqList &L) {
    delete[] L->m_data;
    L->m_length = 0;
}

bool listEmpty(pSqList &L) {
    return L->m_length == 0;
}

void createList(pSqList &L, int *arr, int n) {
    initList(L, n);
    for (int i = 0; i < n; i++)
        L->m_data[i] = arr[i];
    L->m_length = n;
}

int ListLength(pSqList &L) {
    return L->m_length;
}

void displayList(pSqList &L) {
    printf("SqList[");
    for (int i = 0; i < L->m_length; ++i) {
        printf("%2d ", *(L->m_data + i));
    }
    printf("], length = %d\n", L->m_length);
}

ElementType &getElement(pSqList &L, int index) {
    if (index < 0 || index >= L->m_length) {
        throw DsException(THEINDEXOUTOFRANGE);
    }
    return L->m_data[index];
}

int locateElement(pSqList &L, int &element) {
    int index = -1;
    for (int i = 0; i < L->m_length; ++i) {
        if (L->m_data[i] == element) index = i;
    }
    return index;
}

ElementType listDelete(pSqList &L, int index) {
    ElementType oldElement = 0;
    if (index >= 0 && index < L->m_length) {
        oldElement = L->m_data[index];
        for (int i = index; i < L->m_length-1; ++i) {
            L->m_data[i] = L->m_data[i+1];
        }
    }
    return oldElement;
}
```

## Algorithms



### 从顺序表中删除一个元素

[algorithm2-3](../algorithm2-3.cpp) 时间复杂度O(n) / 空间复杂度O(1)

- algorithm 1：使用原有空间进行移动操作，覆盖待删除元素 `x`

  ```c++
  void deleteX1(pSqList &L, ElementType &x) {
      // 优化
      int k = 0; // 覆盖的目标位置指针
      for (int i = 0; i < L->m_length; ++i) {
          if (L->m_data[i] != x) {
              L->m_data[k] = L->m_data[i];
              k++;
          } // 匹配到元素，则跳过
      }
      L->m_length = k; // 修改长度
  }
  ```

- algorithm 2：algorithm 1的另一视角，考虑匹配到的待删除元素个数

  ```C++
  void deleteX2(pSqList &L, ElementType &x) {
      int k = 0, i = 0;
      while (i < L->m_length) {
          if (L->m_data[i] == x)
              k++; // 匹配到元素的个数
          else
              L->m_data[i - k] = L->m_data[i]; // 元素向前移动k个位置
          i++;
      }
      L->m_length -= k; // 修改长度
  }
  ```

  

  ### 以首元素为基准，小于等于它的放其前面

  [algorithm2-4](../algorithm2-3.cpp) 时间复杂度O(n)/空间复杂度O(1)

  - algorithm 1: 运用partition算法，使用两个指针，右指针从右向左扫描，寻找不大于基准的元素；左指针从左向右扫描，寻找大于基准的元素，找到后将其交换位置。

    - tips：先执行右指针扫描，使得后序左指针的结束位置落于不大于基准元素的最后一个位置。

    ```C++
    int partition1(pSqList &L) {
        ElementType base = L->m_data[0];
        int left = 0, right = L->m_length - 1;
        while (left < right) {
            // Importance: firstly finding from right to left.
            // 先从右向左扫描保证left指针移动时超过base的位置。
            while (L->m_data[right] > base && left < right)
                --right; // 从右向左找到小于base的元素
            while (L->m_data[left] <= base && left < right)
                ++left; // 从左向右找到大于等于base的元素
            if (left < right)
                swap(L->m_data[left], L->m_data[right]); // 交换位置
            printf("left= %d, right= %d, ", left, right);
        }
        swap(L->m_data[left], L->m_data[0]); // 此时left=right=所指小于等于base的最后一个元素
        return left;
    }
    ```

  - algorithm 2: 优化算法1，放弃使用临时变量交换元素，使用原有空闲空间进行位置交换。

    - tips：从基准位置开始，左指针与右指针所指位置会依次置于空闲状态。

    ```C++
    int partition2(pSqList &L){
        ElementType base = L->m_data[0]; // 基准暂存处，此时left=0处空闲
        int left = 0, right = L->m_length-1;
        while (left<right){
            while (left<right&&L->m_data[right]>base) // 从右向左扫描
                --right;
            L->m_data[left] = L->m_data[right]; // 找到小于base的元素放置left处，此后right处空置
            while (left<right && L->m_data[left]<=base) // 从左向右扫描
                ++left;
            L->m_data[right] = L->m_data[left]; // 找到>=base的元素放置right处，此后left处空置
        }
        L->m_data[left] = base; // 扫描完毕，基准值放入空置的left处
        return left;
    }
    ```

  ### 将所有奇数移动到偶数前面

  [algorithm2-5](../algorithm2-5.cpp) 时间复杂度O(n)/空间复杂度O(1)

  - algorithm 1：partition算法，使用左右两个指针从两个方向开始扫描后，匹配到的元素进行交换

    ```C++
    int move1(pSqList &L){
        int left=0,right = L->m_length-1;
        while (left<right){
            while (left<right && L->m_data[right]%2==0)
                --right; // 从右扫描奇数
            while (left<right && L->m_data[left]%2!=0)
                ++left; // 从左扫描偶数
            if(left<right)
                swap(L->m_data[left],L->m_data[right]); // 交换位置
        }
        return left;
    }
    ```

  - algorithm 2：将表[0, i]区域划为奇数区，`i`表示最后一个奇数的位置。左指针从左向右扫描，将奇数放置于奇数区域。

    ```C++
    int move2(pSqList &L) {
        int i = -1; // 奇数区起点
        for (int j = 0; j < L->m_length; j++) {
            if (L->m_data[j] % 2 == 1) { // 找到奇数
                i++;
                if (i != j) // 放置于奇数区
                    swap(L->m_data[i], L->m_data[j]);
            }
        }
        return i;
    }
    ```

    

  

  