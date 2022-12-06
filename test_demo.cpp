/**
 * @file test_demo.cpp
 * @brief: 
 * @version: 1.0
 * @author: inith271
 * @email: oy.zf@qq.com
 * @date: 22/12/03 15:15
 *
 **/

#include <cstdio>
#include <cstring>
#include <cstdlib>

//动态数组结构体
struct dynamicArray
{
    //真实在堆区开辟的数组的指针
    void** pAddr;
    //数组容量
    int m_Capacity;
    //数组大小
    int m_Size;

};

//初始化数组的功能     参数  初始数组的容量  返回值是数组指针
struct dynamicArray* init_dynamicArray(int capacity)
{
    if (capacity <= 0)
    {
        return NULL;
    }
    //给数组分配内存
    struct dynamicArray* arr = malloc(sizeof(struct dynamicArray));
    if (arr == NULL)
    {
        return NULL;
    }

    //给数组属性分配内容
    arr->pAddr = malloc(sizeof(void*)* capacity);
    //容量的初始化
    arr->m_Capacity = capacity;
    //大小的初始化
    arr->m_Size = 0;

    return arr;

}

//插入数组
void insert_dynamicArray(struct dynamicArray* arr, void *data, int pos)
{

    if (arr == NULL)
    {

        return;
    }
    if (data == NULL)
    {

        return;
    }
    if (pos < 0 || pos > arr->m_Size)
    {

        //尾插
        pos = arr->m_Size;
    }

    //判断数组是否满了
    if (arr->m_Size == arr->m_Capacity)
    {
        //1、计算新的内存空间大小
        int newCapacity = arr->m_Capacity * 2;

        //2、开辟新空间
        void** newSpace = malloc(sizeof(void*) * newCapacity);
        //3、将原空间下的数据拷贝到新空间下
        memcpy(newSpace, arr->pAddr, sizeof(void*)* arr->m_Capacity);
        //4、释放原空间
        free(arr->pAddr);
        //5、更改指针指向
        arr->pAddr = newSpace;

        //6、更新新空间的容量
        arr->m_Capacity = newCapacity;
    }

    //将新元素插入到数组中的指定位

    for (size_t i = arr->m_Size - 1; i >= pos; i--)
    {
        arr->pAddr[i + 1] = arr->pAddr[i];

    }
    //将数据插入到指定位置
    arr->pAddr[pos] = data;

    //更新数组大小
    arr->m_Size++;
}

//遍历
void foreach_dynamicArray(struct dynamicArray* arr,void (*myPrint)(void*))
{
    if (arr == NULL)
    {
        return;
    }
    for (size_t i = 0; i < arr->m_Size; i++)
    {
        myPrint(arr->pAddr[i]);
    }
}




struct Person
{
    char name[64];
    int age;
};

//回调函数打印数据
void printPerson(void *data)
{
    struct Person* person = data;
    printf("姓名:%s  年龄: %d\n",person->name,person->age);

}


//测试动态数组
void test01()
{
    //初始化动态数组
    struct dynamicArray* arr = init_dynamicArray(5);

    struct Person p1 = { "赵云", 18 };
    struct Person p2 = { "张飞", 19 };
    struct Person p3 = { "关羽", 20 };
    struct Person p4 = { "刘备", 19 };
    struct Person p5 = { "诸葛亮", 22 };
    struct Person p6 = { "黄忠", 17 };

    printf("插入数据前---数组的容量：%d\n", arr->m_Capacity);
    printf("插入数据前---数组的大小：%d\n", arr->m_Size);
    //插入数据
    insert_dynamicArray(arr, &p1, 0);
    insert_dynamicArray(arr, &p2, 0);
    insert_dynamicArray(arr, &p3, 1);
    insert_dynamicArray(arr, &p4, -1);
    insert_dynamicArray(arr, &p5, 1);
    insert_dynamicArray(arr, &p6, 0);

    //黄忠  张飞  诸葛亮  关羽   赵云  刘备
    foreach_dynamicArray(arr, printPerson);

    printf("插入数据后---前数组的容量：%d\n", arr->m_Capacity);
    printf("插入数据后---数组的大小：%d\n", arr->m_Size);
}


int main()
{
    test01();


    system("pause");
    return EXIT_SUCCESS;
}
