#include <iostream>
#include <thread>
#include <mutex>
#include <unistd.h> // sleep
std::mutex mtx;

// 全局变量（在不同线程之间共享）
int globalVar = 0;

void threadFunc(int threadID,int* count_ptr) {
    (*count_ptr)++;
    // 局部变量（每个线程有自己独立的栈）
    int localVar = 0;

    // 用互斥锁保证线程安全地输出信息
    mtx.lock(); // 获取锁
    std::cout << "Thread " << threadID << " start\n";
    std::cout << "Thread " << threadID << ": Address of globalVar = " << &globalVar << "\n";
    std::cout << "Thread " << threadID << ": Address of localVar  = " << &localVar << "\n";
    std::cout << "Thread " << threadID << ": Incrementing globalVar\n";
    int count = 1000; 
    while (count--)
    {
        globalVar++; // ->  load add store
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
    }
    // 递增全局变量（证明全局变量在多个线程之间共享）
    
    std::cout << "Thread " << threadID << ": globalVar = " << globalVar << "\n";
    std::cout << "Thread " << threadID << " end\n\n";
    mtx.unlock(); // 释放锁
}

// vector<int> to_sum = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2, 1};
// 用一个线程把这个vector前一半儿的元素相加，用另外一个线程把另一半儿的元素相加
// 把相加的结果汇总起来，得到to_sum总体的相加结果
int main() {
    // 启动两个线程
    int count = 0; 
    std::thread t1(threadFunc, 1,&count); // create_thread
    std::thread t2(threadFunc, 2,&count); // create_thread
    
    // 等待两个线程执行完毕
    t1.join();
    t2.join();
    std::cout<<"count:\n"<<count<<std::endl;
    std::cout<<"globalVar:\n"<<globalVar<<std::endl;
    return 0;
}
