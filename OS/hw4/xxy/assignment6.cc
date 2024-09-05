#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
//
//1.作业三的完善：
//a.双向循环链表（bidirectional circular linked list) insert和remove函数补全
//b.不用双向循环链表，用vector实现加index%实现一遍second chance algorithm.
//c.将代码改为通过命令行参数传入mem大小的形式（之前课程上固定mem大小为3个frame)
//d.将lru的函数/类的实现和调用分离，分别编译成.o文件再链接在一起
//2.ch3 slice 17页之前的内容，其中的macro，编程实践一下。查阅资料，首先讲明白belay's anomaly是什么样子的过程，
//再编程模拟 belay's anomaly（利用旧FIFO和命令行参数就可以实现）
 
//不用双向循环链表，用vector实现加index%实现一遍second chance algorithm.

// LRU, FIFO, SecondChance,
// 1. LRU: Least Recently Used
// 2. FIFO: First In First Out

class SecondChance {
private:
    vector<int> frames;      // 存储页面的frame
    vector<int> refBits;     // 存储页面的引用位
    queue<int> queue_page;
    // int size;            // 内存的大小
    int pointer;             // 当前指针位置，用于指向要置换的页面
    int page_faults;

public:
    SecondChance(int size)
    {       
        refBits = vector<int>(size, 0);
        frames = vector<int>(size, -1);
        

        //frames = {7, 0, 1, 2, 0};
        pointer = 0;
        page_faults = 0;

    }
    // 7在不在内存里面，
    // 
    void access(int page_number)
    {   
        // {7,0,1,2,0,3,0,4,2,3,0,3,2,1};
        // 【1，2，3】
        // -1代表没有东西，
        // [-1,-1,-1]
        // [7,0,1]
        // [2,0,1]
        // [3,0,1]
        // [4,0,1]
        // [2,0,1]
        // [3,0,1]
        int flag = 0;
        cout<<"当前访问的page_number是:  "<<page_number<<endl;
        for(int i =0;i<frames.size();i++)
        {   

            if(frames[i] == page_number)
            {   

                cout<<page_number<<"  在内存里面！！"<<endl;
                flag++;
            }
        }
        if(flag ==0)
        {
            cout << page_number << "  没在内存里面！！" << endl;
            for (int i = 0; i < frames.size(); i++)
            {
                if(frames[i] == -1)
                {
                    frames[i] = page_number;
                    return ;
                }

            }
            
            // 尝试实现FIFO算法
            int index_to_victim = 0; // FIFO算法的实现
            // frames[index_to_victim] = page_number;
            queue_page[index_to_victim]   = page_number;
            
        }
        //  
    }
    void print_memory() {
        cout << "当前的Memory frames: ";
        for (int i = 0; i <  frames.size(); i++) {
            // if (frames[i] == -1) {

            // } else {
                cout << frames[i] << " ";
            // }
        }
        cout << endl;
    }

};    

int main(int argc,char * argv[])
{   
    std::vector<int> access_sequence = {7,0,1,2,0,3,0,4,2,3,0,3,2,1};
    SecondChance sc_1(atoi(argv[1]));
    for(int i = 0;i<13;i++)
    {
        sc_1.access(access_sequence[i]);

        sc_1.print_memory();
        cout<<endl;
    }

    return 0;
}