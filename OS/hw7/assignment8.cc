#include <iostream>
#include <thread>
#include <mutex>
#include <vector>
#include <unistd.h>
using namespace std;
// namespace name


std::mutex mtx;
// 全局变量（在不同线程之间共享）

// merge sort 

// n*n 
// [1,2,3,4,5,5]  // 
// [5,2,3,4,5,5]
// [9,2,3,4,5,5]
// [7,2,3,4,5,5]

int globalVar = 0;
int globalSum = 0;
std::vector<int> to_sum = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2, 1};

void threadFunc(int id, int start, int end,int &localSum)
{
    // 局部变量（每个线程有自己独立的栈）
    // int localVar = 0;

    // 用互斥锁保证线程安全地输出信息
    // mtx.lock();
    // std::cout << "Thread " << threadID << " start\n";
    // std::cout << "Thread " << threadID << ": Address of globalVar = " << &globalVar << "\n";
    // std::cout << "Thread " << threadID << ": Address of localVar  = " << &localVar << "\n";
    // std::cout << "Thread " << threadID << ": Incrementing globalVar\n";
    // mtx.unlock();

    // 递增全局变量（证明全局变量在多个线程之间共享）
    globalVar++;

    // int localSum = 0;
    sleep(0.0000000001);
    {
        std::lock_guard<std::mutex> xxy(mtx);
        for (int i = start; i < end; ++i)
        {
            std::cout << "Thread " << std::this_thread::get_id() << ": to_sum[" << i << "] = " << to_sum[i] << "\n";
            std::cout << "Thread " << std::this_thread::get_id() <<"localSum: "<< localSum << "\n";
            localSum += to_sum[i];
        }
    }


    // Use mutex to safely update the global su
    // 
    // 
    globalSum += localSum;
    std::cout<< "Local sum of vector: " << localSum << std::endl;
    //mtx:只能lock一次

    mtx.lock();
    mtx.unlock();
    // std::cout << "Thread " << threadID << ": globalVar = " << globalVar << "\n";
    // std::cout << "Thread " << threadID << " end\n\n";
}

int main()
{
    // 启动两个线程

    std::vector<std::vector<int>> matrix = {{1, 0, 3}, // 
                                            {4, 5, 6}, 
                                            {7, 8, 9}};
    // (0,0) (0,1) (0,2)  (0,3)
    // (1,0) (1,1) (1,2)  (1,3)
    // (2,0) (2,1) (2,2) (2,3)
    // (3,0) (3,1) (3,2) (3,3)
    int a = 1;
    int b = 2;
    swap(a,b);
    // cout<<a<<" "<<b<<endl;
    
    for (int i = 0; i < matrix.size(); i++)
    {
        for(int j =i;j<matrix[i].size();j++)
        {       
            swap(matrix[i][j],matrix[j][i]);
        }

    }
    for(int i =0;i<matrix.size();i++)
    {
        for(int j =0;j<matrix[i].size();j++)
        {   
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;

    }
    std::vector<int> local_number;

    std::vector<std::thread> threads;

    for(int i = 0; i < 2; ++i)
    {
        threads.emplace_back(threadFunc, i, i * (to_sum.size() / 2), (i + 1) * (to_sum.size() / 2),std::ref(local_number[i]));
    }

    for(int i = 0; i < 2; ++i)
    {
        threads[i].join();
    }
    int local_number_1=0;
    int local_number_2= 0;
    std::thread t1(threadFunc,0, 0, to_sum.size() / 2,std::ref(local_number_1));
    std::thread t2(threadFunc, 1,to_sum.size() / 2, to_sum.size(),std::ref(local_number_2));


    // 等待两个线程执行完毕
    t1.join();
    t2.join();
    int global_sum =  local_number_1 + local_number_2;

    cout<<"Global number:"<<global_sum<<endl;
    std::cout << "Total sum of vector: " << globalSum << std::endl;
    sleep(1);
    return 0;
}