/**
 * @file LinkedList.h
 * @brief: 线性表的链表声明
 * @version:  1.0
 * @author: initial271
 * @date: 2022-11-11 11:46:07
 *
 **/
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stddef.h>
#include <ostream>

template<class E>
class LinkedList; // 前置声明

template<class E>
class LinkedListNode { // the node in a linked-list
    friend LinkedList<E>;
private:
    E element_;
    LinkedListNode *next_;

    explicit LinkedListNode(const E &element) : element_(element), next_(nullptr) {}

    explicit LinkedListNode(const E &element, LinkedListNode *next) : element_(element), next_(next) {}

    ~LinkedListNode(){
        element_.~E();
    }

public:
    // disable copy c'tor and assignment operator
    LinkedListNode(const LinkedListNode &node) = delete;

    const LinkedListNode &operator=(const LinkedListNode &node) = delete;

    const E &element() const {
        return element_;
    }

    LinkedListNode *next() const {
        return next_;
    }
};

template<class E>
class LinkedList { // a simple list implemented with linked-structure
    typedef LinkedListNode<E> *PLinkedListNode;
private:
    PLinkedListNode head_, last_;
    size_t size_;

    // 2. 销毁线性表
    void destroy();

    void createListF(E *arr, int n); // 头插法建立链表
    void createListR(E *arr, int n); // 尾插法建立链表
public:
    // disable copy c'tor and assignment operator
    LinkedList(const LinkedList &) = delete;

    const LinkedList &operator=(const LinkedList &) = delete;



    // c'tor and d'tor
    // 1. 初始化链表
    LinkedList() : head_(nullptr), last_(nullptr), size_(0) {}

    // constructs a linkedList from an array, default with rear-insert.
    LinkedList(E *arr, int n, char flag = 'R'):head_(nullptr), last_(nullptr), size_(0) {
        if (flag == 'R') {
            createListR(arr, n);
        } else {
            createListF(arr, n);
        }
    };

    ~LinkedList() {
        destroy();
    }

    // 4. 链表长度
    size_t size() const {
        return size_;
    }

    PLinkedListNode head() {
        return head_;
    }

    const LinkedListNode<E> *head() const {
        return head_;
    }

    PLinkedListNode last() {
        return last_;
    }

    const LinkedListNode<E> *last() const {
        return last_;
    }

    // 3. 判断是否为空表
    bool empty() const {
        return head_ == nullptr;
    }

    // 5. 输出链表
    void output(std::ostream &out) const;

    // 6. 按元素值查找索引
    int at(const E &an_element) const;

    // 7. 向索引处插入元素
    bool insert(int index, const E &an_element);

    // 8. 删除索引处的元素
    E remove(int index);
};

// 定义部分
/**
 * 模板函数声明与定义分离文件编译的问题：若模板函数声明在.h文件，定义在.cpp文件内，进行编译时，会出现undefined reference to XXX的问题。
 * 解决方法1：在定义文件内加上所调用函数的模板特例化的声明。
 * 解决方法2：定义与声明在同一个文件内。
 */


template<class E>
void LinkedList<E>::createListF(E *arr, int n) {
    for (int i = 0; i < n; i++) {
        auto node = new LinkedListNode<E>(arr[i], head_); // next_指向head_
        head_ = node; // 更新head_
        if (!last_) last_ = node; // 尾节点
        size_++;
    }
}

template<class E>
void LinkedList<E>::createListR(E *arr, int n) {
    for (int i = 0; i < n; i++) {
        auto node = new LinkedListNode<E>(arr[i]); // next_指向last_
        if (!head_) {
            head_ = last_ = node; // 头结点
        } else {
            last_->next_ = node; // 更新last_
            last_ = node;
        }
        size_++;
    }
}

template<class E>
void LinkedList<E>::destroy() {
    PLinkedListNode currentHead = head_;
    while (currentHead) {
        PLinkedListNode oldHead = currentHead; // get current header
        currentHead = currentHead->next_; // update current header
        delete oldHead; // delete old header
    }
    head_=last_= nullptr;
    size_=0;
}

template<class E>
void LinkedList<E>::output(std::ostream &out) const {
    out << "\tlinkedlist: [ ";
    PLinkedListNode currentHead = head_;
    while (currentHead) {
        out << currentHead->element_ << " ";
        currentHead = currentHead->next_;
    }
    out << "], size = " << size_ << "\n";
}

#endif