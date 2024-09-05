#include<iostream>
#include<vector>
#include<deque>
#include<algorithm>
using namespace std;

// std::vector<int> access_sequence = {7,0,1,2,0,3,0,4,2,3,0,3,2,1};
//FIFO
// LRU
// 谁最受冷落，就把谁换出去：最近最少使用

int main()
{
    std::vector<int> access_sequence = {7,0,1,2,0,3,0,4,2,3,0,3,2,1};
    deque<int> queue_page; //构造函数
    std::cout<<"deque_size:"<<queue_page.size()<<std::endl;


    for(int i =0;i<14;i++)
    {
        cout<<"access_sequence: "<<access_sequence[i]<<endl;

        if(find(queue_page.begin(),queue_page.end(),access_sequence[i])==queue_page.end())//如果说我找不到
        {
            if(queue_page.size()<3)
            {
                queue_page.push_back(access_sequence[i]);
            }
            else
            {
                queue_page.pop_front();
                queue_page.push_back(access_sequence[i]);
            }        
        }

        for(int i =0;i<queue_page.size();i++)
        {
            cout<<"deque:"<<queue_page[i]<<endl;
        }
    }
    return 0;
}