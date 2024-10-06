#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;
// 1. 用多个线程计算矩阵所有值的和，每个线程计算一行
// [1,2,3,4,5,5]  // 
// [5,2,3,4,5,5]
// [9,2,3,4,5,5]
// [7,2,3,4,5,5]

// 2. 重载operator,把find函数用到正确的位置上

// 3. find_old_frame的函数的实现：找到最旧的frame，time最大的frame的下标返回

// 2. 重载operator,把find函数用到正确的位置上
class Frame
{
public:
    int time = 0;
    int page_number = 0;

    Frame(int page_number, int time)
    {
        this->page_number = page_number;
        this->time = time;
    }
    bool operator==(const Frame & memory)
    {
        return this->page_number == memory.page_number;
    }
};
// 输出：page_number 在memory中的index  如果找不到就返回-1
void print_frame(std::vector<Frame> memory)
{
    for (int i = 0; i < memory.size(); i++)
    {
        std::cout << "page_number:  " << memory[i].page_number << std::endl;
        std::cout << "time:  " << memory[i].time << std::endl;
    }
}

// int find_frame(std::vector<Frame> &memory, int page_number)
// {
//     for (int i = 0; i < memory.size(); i++)
//     {
//         if (page_number == memory[i].page_number)
//         {
//             std::cout << "啥都不干！！" << std::endl;
//             return i;
//         }
//     }
//     return -1;
// }
int find_oldest_frame(vector<Frame> &f_1)
{
    int max_number_index = 0;
    int max_time = f_1[0].time;
    for (int i = 0; i < 3; i++)
    {
        if (f_1[i].time > max_time)
        {
            max_time = f_1[i].time;
            max_number_index = i;
        }
    }
    return max_number_index;
}

int main()
{
    std::vector<int> access_sequence = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2, 1};

    std::vector<Frame> memory;
    for (int i = 0; i < 3; i++)
    {
        memory.push_back(Frame(-1, 0));
    }

    for (int i = 0; i < access_sequence.size(); i++)
    {
        int number = access_sequence[i];

        for (int j = 0; j < memory.size(); j++)
        {
            memory[j].time++;
        }
        print_frame(memory);
        std::cout << std::endl;

        auto result = find(memory.begin(),memory.end(),Frame(number,0));
        
        if (result != memory.end()) // memory找到了
        {
            cout<<"number:"<<number<<"在memory中！！"<<endl;
        }
        else
        {
            //没找到
            auto max_number = find_oldest_frame(memory);
            memory[max_number].page_number = number;
            memory[max_number].time = 0; 
        }
        cout<<"加入的元素为：："<<number<<endl;
        for (int j = 0; j < memory.size(); ++j)
        {
            cout << memory[j].page_number << " (time: " << memory[j].time << ") ";
        }
        cout<<endl;

        // if (flag_1 == 0)
        // {
        //     int max_number_time = 0;
        //     for (int j = 0; j < 3; j++)
        //     {
        //         if (memory[j].time > memory[max_number_time].time)
        //         {
        //             max_number_time = j;
        //         }
        //     }
        //     // 替换该页面
        //     memory[max_number_time].page_number = number;
        //     memory[max_number_time].time = 0; // 更新访问时间v
        // }
    }
    

    // }

    return 0;
}