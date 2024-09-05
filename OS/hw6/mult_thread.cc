#include <iostream>
#include <thread>
#include <mutex>

std::mutex mtx;

// 全局变量（在不同线程之间共享）
int globalVar = 0;

void threadFunc(int threadID) {
    // 局部变量（每个线程有自己独立的栈）
    int localVar = 0;

    // 用互斥锁保证线程安全地输出信息
    mtx.lock();
    std::cout << "Thread " << threadID << " start\n";
    std::cout << "Thread " << threadID << ": Address of globalVar = " << &globalVar << "\n";
    std::cout << "Thread " << threadID << ": Address of localVar  = " << &localVar << "\n";
    std::cout << "Thread " << threadID << ": Incrementing globalVar\n";
    mtx.unlock();

    // 递增全局变量（证明全局变量在多个线程之间共享）
    globalVar++;

    mtx.lock();
    std::cout << "Thread " << threadID << ": globalVar = " << globalVar << "\n";
    std::cout << "Thread " << threadID << " end\n\n";
    mtx.unlock();
}

int main() {
    // 启动两个线程
    std::thread t1(threadFunc, 1);
    std::thread t2(threadFunc, 2);

    // 等待两个线程执行完毕
    t1.join();
    t2.join();

    return 0;
}
