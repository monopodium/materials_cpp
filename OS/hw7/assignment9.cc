#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

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

int find_frame(std::vector<Frame> &memory, int page_number)
{
    for (int i = 0; i < memory.size(); i++)
    {
        if (page_number == memory[i].page_number)
        {
            std::cout << "啥都不干！！" << std::endl;
            return i;
        }
    }
    return -1;
}

int main()
{
    std::vector<int> access_sequence = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2, 1};

    std::vector<Frame> memory;
    for (int i = 0;i<3;i++)
    {
        memory.push_back(Frame(-1,0));

    }
        for (int i = 0; i < access_sequence.size(); i++)
        {
            int number = access_sequence[i];

            for (int i = 0; i < memory.size(); i++)
            {
                memory[i].time++;
            }

            int result = find_frame(memory, number);

            if (result == -1) // memory里面没有找到
            {
                //一个函数判断里面有没有-1，如果有的话，就返回第一个-1的index
                //如果没有就返回 - 2
                int index_empty = find_frame(memory, -1);
                if (index_empty==-1){
                    // 如果说里面没有空位
                    // 找到最大的time对应的frame的下标

                    int max_index = find_old_frame(memory); // 找到最大的time对应的frame的下标
                    memory[max_index].page_number = number;
                    memory[max_index].time = 0;
                    // memory 里面没有空位
                }else{
                    memory[index_empty].page_number = number;
                    memory[index_empty].time = 0;
                }
            }

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
    print_frame(memory);
    std::cout << std::endl;
    // }

    return 0;
}