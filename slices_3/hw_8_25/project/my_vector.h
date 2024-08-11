#ifndef MY_VECTOR_H
#define MY_VECTOR_H
#include <iostream>

template <typename T>
class my_vector {
public:
    my_vector() : data_(nullptr), size_(0), capacity_(0) {}// 构造函数
    ~my_vector() {delete[] data_;}// 析构函数
    void push_back(T value); // 向vector中添加元素
    std::size_t size() const { return size_;} // 获取元素数量
    std::size_t capacity() const { return capacity_; } // 获取容量
    T &operator[](std::size_t index);                  // 重载下标操作符
    const T &operator[](std::size_t index) const;

    // 嵌套迭代器类
    class iterator;

    // 返回迭代器开始
    iterator begin() {
        return iterator(data_);
    }

    // 返回迭代器结束
    iterator end() {
        return iterator(data_ + size_);
    }

private:
    T* data_;
    std::size_t size_;
    std::size_t capacity_;

    // 重新分配内存并扩大容量
    void resize() {
        if (capacity_ == 0) {
            capacity_ = 1;
        } else {
            capacity_ *= 2;
        }

        T* new_data = new T[capacity_];
        // 拷贝旧数据到新数据
        for (std::size_t i = 0; i < size_; ++i) {
            new_data[i] = data_[i];
        }

        // 删除旧数据
        delete[] data_;

        // 更新指针
        data_ = new_data;
    }
};

template <typename T>
void my_vector<T>::push_back(T value) {
    if (size_ == capacity_) {
        // 如果容量不够，则扩展容量为两倍
        resize();
    }
    data_[size_++] = value;
}

template <typename T>
T& my_vector<T>::operator[](std::size_t index) { // 重载下标操作符
    if (index >= size_) {
        throw std::out_of_range("Index out of range");
    }
    return data_[index];
}

template <typename T>
const T& my_vector<T>::operator[](std::size_t index) const {
    if (index >= size_) {
        throw std::out_of_range("Index out of range");
    }
    return data_[index];
}

template <typename T>
class my_vector<T>::iterator {
    public:
        iterator(T* ptr) : ptr_(ptr) {}

    // 重载解引用操作符
    T& operator*() const { return *ptr_; }

    // 重载前置增量操作符
    iterator& operator++() {
        ++ptr_;
        return *this;
    }

    // 重载后置增量操作符
    iterator operator++(T) {
        iterator tmp = *this;
        ++(*this);
        return tmp;
    }

    // 比较操作符
    bool operator==(const iterator& other) const { return ptr_ == other.ptr_; }
    bool operator!=(const iterator& other) const { return !(*this == other); }

private:
    int* ptr_;
};

#endif