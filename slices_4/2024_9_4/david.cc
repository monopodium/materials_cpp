#include<iostream>  
#include <vector>
#include<map>
#include <algorithm>
#include <iostream>
#include <memory>

//
void increment( int &&d) {
    // d += 1; 
}
// int & :普通类型的引用，只能接受左值

// int && : 右值引用，只能接受右值
// const int & : 常量引用，可以接受左值和右值

int main() {
    int x = 7;
    double y = 10.9;
    increment(y); 
    std::cout << y << std::endl; 
  
    // std::unique_ptr<int> xxy(new int(16));
    // std::cout << *xxy << std::endl;
    // std::unique_ptr<int> xxy_2(xxy);   
    // std::cout << *xxy2 << std::endl;  

    // std::shared_ptr<int> xxy_3(new int(16));
    // std::cout << *xxy_3 << std::endl;
    // std::shared_ptr<int> xxy_4(xxy_3);
    // std::cout << *xxy_4 << std::endl;

    return 0;
}

//#ifndef MY_LIST_H 是一个常见的预处理器指令，它的作用是确保头文件 my_list.h 中的内容只在第一次包含时被编译。
//这是通过在文件中定义一个宏（在这个例子中是 MY_LIST_H），然后检查这个宏是否已经被定义来实现的。
//如果 MY_LIST_H 还没有被定义，那么 #define MY_LIST_H 将会定义它，并且接下来的代码会被编译。如果 MY_LIST_H 已经被定义（比如因为这个头文件已经被包含过），
//那么预处理器将跳过这段代码，从而避免重复包含。


//关于 std::unique_ptr 和 std::shared_ptr 的区别，主要在于它们对资源的所有权管理方式不同：
//std::unique_ptr 是一种智能指针，它采用独占所有权管理方式。这意味着同一时间只能有一个 unique_ptr 指向一个给定的资源。
//当 unique_ptr 被销毁时，它自动释放所拥有的资源，防止内存泄漏。
//std::shared_ptr 也是智能指针，但它采用共享所有权管理方式。多个 shared_ptr 可以指向同一个资源，
//每个 shared_ptr 都有一个引用计数，用来跟踪有多少个 shared_ptr 共享这个资源。当最后一个 shared_ptr 被销毁时，资源才会被释放。
