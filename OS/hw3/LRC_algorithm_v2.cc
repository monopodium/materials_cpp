#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

struct Frame{
    int page_number = -1;
    int time = 0;
    Frame(int pn,int t){
        page_number = pn;
        time = t;
    }
    bool operator==(const Frame & other){
        std::cout << "operator==!!" << std::endl;
        if (this->page_number == other.page_number)
        {
            return true;
        }
        return false;
    }
};

vector<Frame> mem(3, Frame(-1,0));

int find_in_mem(int page_number){
    for (int i = 0; i < mem.size();i++){
        if(mem[i].page_number==page_number){
            return i;
        }
    }
    return -1;
}
void access(vector<int>& block)
{
    int page_fault = 0;
    for (int i = 0; i < block.size(); i++)
    {
        int key = block[i];

        for (int j = 0; j < 3; ++j) 
        {
            mem[j].time++;
        }
        auto it = find(mem.begin(), mem.end(), Frame{key, 0});

        int index = find_in_mem(key);
        if (-1 != index)
        {
            if(it != mem.end()){
                std::cout << "    " << it - mem.begin() << "      " << index << std::endl;
            }
            else
            {
                std::cout << "有问题！" << std::endl;
            }
            // 如果 key 已在缓存中，更新其时间
            mem[index].time = 0;
        }
        else
        {
            page_fault++;
            int max_number_time = 0;
            for(int j =0;j<3;j++)
            {
                if(mem[j].time > mem[max_number_time].time)
                {
                    max_number_time = j;
                }
            }
            mem[max_number_time].page_number = key;
            mem[max_number_time].time = 0;
        }
        cout<<"加入的元素为：："<<block[i]<<endl;
        for (size_t j = 0; j < mem.size(); ++j)
        {
            cout << mem[j].page_number << " (time: " << mem[j].time << ") ";
        }
        cout<<endl;
    }
    std::cout << "page_fault:" << page_fault << std::endl;
}

int main()
{       
    vector<int> access_sequence = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2, 1};
    access(access_sequence);
    return 0;
}