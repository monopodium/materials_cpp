#include<iostream>
#include<vector>
#include<deque>
#include<algorithm>
using namespace std;

// std::vector<int> access_sequence = {7,0,1,2,0,3,0,4,2,3,0,3,2,1};
// FIFO
// LRU: age[] 3   frames[] 3
// 谁最受冷落，就把谁换出去：最近最少使用

class Time
{   
    public:
    int page_number = -1;
    int time =0;
    Time(int page_number,int time)
    {
        this->page_number = page_number;
        this-> time = time;
    }
};

void LRU()
{
   //time_1,如果说当前要访问的page_Id在time_1中，就啥也不干
   //如果说当前要访问的page_Id不在time_1中，就把time_1里面第0个元素换出去,换成当前要访问的元素
    std::vector<int> access_sequence = {7,0,1,2,0,3,0,4,2,3,0,3,2,1};
    vector<Time> time_1(3,Time(-1,0));
    for(int i =0;i<access_sequence.size();i++)
    {
        int number= access_sequence[i];

        for(int i =0;i<3;i++)
        {
            time_1[i].time++;
        }

        for(int j =0;j<time_1.size();j++)
        {
            if(time_1[j].page_number ==number )
            {   
                //time_1.time = 0;               
                
            }

            
        }



    }
    
}
void FIFO(){
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
}
int main()
{
    LRU();
    return 0;
}