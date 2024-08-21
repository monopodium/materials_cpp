#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int frame_size = 3;
vector<int> physical_memory;

queue<int> page_queue;

int page_faluts = 0;

int Access_Memory(int page_number)
{   
    if( find(physical_memory.begin(),physical_memory.end(),page_number) != physical_memory.end())   
    {
        return -1;              //检查physical memory是否有page number
    }   
    else
    {
        page_faluts++;

        if(physical_memory.size()<frame_size)
        {
            physical_memory.push_back(page_number);
            page_queue.push(page_number);   //page fault发生时往queue中放入page number
        }
        else
        {
            int page_to_remove = page_queue.front();    //最前面的那个数字被移除
            page_queue.pop();
            vector<int>::iterator it = find(physical_memory.begin(),physical_memory.end(),page_to_remove);  
                            //  find返回的值是一个iterator的指针
            *it = page_number;//把移除的数字变成page number
            page_queue.push(page_number);              
        }
        return 0;
    }



}


int main()
{   

    cout<<"FIFO的算法："<<endl;

    vector<int> access_sequence = {7,0,1,2,0,3,0,4,2,3,0,3,2,1};
    for(int i =0;i<access_sequence.size();i++)
    {
        Access_Memory(access_sequence[i]);
        cout<<"Acess_sequence  "<<access_sequence[i]<<endl;

        for(int j = 0;j<physical_memory.size();j++)
        {
            cout<<physical_memory[j]<<"  ";
        }
        cout<<endl;
    }
    cout<<"page fault:"<<page_faluts<<endl;

    return 0;
}
