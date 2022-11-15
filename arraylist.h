/**
 * @file arraylist.h
 * @brief: 线性表的顺序结构声明
 * @version:
 * @author: initial271
 * @date: 2022-11-11 11:50:42
 *
 **/
#ifndef ARRAYLIST_H
#define ARRAYLIST_H

#include <ostream>

template<class E>
class arraylist { // a simple list implemented as sequence list
private:
    E *elements_; // the elements of the arraylist
    int size_;    // the number of elements in the arraylist
    int maxSize_;
    // disable copy c'tor and assignment operator
    arraylist(const arraylist &) = delete;
    const arraylist &operator=(const arraylist &) = delete;
    // check the index whether out of the elements scope.
    bool checkIndex(int index) const {
        return index < 0 || index >= maxSize_;
    }

    // expands the space of elements
    void expand() {
        if(size_<maxSize_) return; // don't need to expand.
        E* oldElments = elements_;
        int newMaxSize = maxSize_ * 2;
        E *newElements = new E[newMaxSize];
        for (int i = 0; i < size_; i++) { // copy all elements
            newElements[i] = elements_[i];
        }
        maxSize_ = newMaxSize;
        delete[] oldElments;
    }
public:
    // default c'tor
    arraylist(): elements_(nullptr), size_(0), maxSize_(10) {
        elements_ = new E[maxSize_];
        for (int i = 0; i < maxSize_; i++) {
            elements_[i] = 0;
        }
    }
    // constructs an arraylist from an array of E that its length is n.
    arraylist(E *arr, int n) { // 1. 初始化线性表
        if (n > 0) {
            elements_ = new E[size_=maxSize_=n];
            for (int i = 0; i < n; i++) {
                elements_[i] = arr[i];
            }
        }else{
            arraylist();
        }
    }
    // d'tor
    ~arraylist() { // 2. 销毁线性表
        delete[] elements_;
        size_ = maxSize_ = 0;
    }
    bool empty()const {
        return size_ == 0;   // 3. 判断线性表是否为空
    }
    bool full()const {
        return size_ == maxSize_;
    }
    int length()const {
        return size_;   // 4. 求线性表的长度
    }
    void output(std::ostream &out)const {
        out << "arraylist[ ";
        for (int i = 0; i < size_; i++) {
            out << elements_[i] << " ";
        }
        out << "], size=" << size_<<"\n";
    } // 5. 输出线性表
    E &at(int index) {
        if (index >= size_ || index < 0) return nullptr;
        return elements_[index];
    } // 6. 求线性表某个位置元素值
    const E &at(int index)const {
        if (index >= size_ && index < 0) return nullptr;
        return elements_[index];
    }
    int indexOf(const E &element) {
        for (int i = 0; i < size_; i++) {
            if (elements_[i] == element) return i;
        }
        return -1;
    } // 7. 按元素查找索引，不存在返回-1
    void insert(const E &element, int index) {
        // verifies the index
        if (checkIndex(index)) return;
        // case 1: the arraylist is empty
        if (empty()) {
            elements_[index] = element;
            size_ = 1;
            return;
        }
        expand(); // case 3: size_ == maxsize_
        // case 3:  0 < size_ < maxsize_
        for (int i = size_; i > index; i--) { // move the elements that behind the index to its index+1.
            elements_[i] = elements_[i - 1];
        }
        elements_[index] = element;
        size_++;
    } // 8. 在索引index处插入新的元素
    E *remove(int index) {
        if (checkIndex(index)) return nullptr;
        E *oldElement = elements_[index];
        for (int i = index; i < size_ - 1; i++) {
            elements_[i] = elements_[i + 1];
        }
        return oldElement;
    } // 9. 删除索引index处的元素
};
#endif