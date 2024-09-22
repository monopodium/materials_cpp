#include<iostream>
#include<vector>
#include<deque>
#include<algorithm>
using namespace std;

//time_1,如果说当前要访问的page_Id在time_1中，就啥也不干
//如果说当前要访问的page_Id不在time_1中，就把time_1里面第0个元素换出去,换成当前要访问的元素

// 
//LRU算法 这一周作业：应该选time最大的元素换出去
//把vector 改名为memory
// v1
// find_frame() :输入: memory, page_number, 
// 输出：page_number 在memory中的index  如果找不到就返回-1

//v2
// find(): 
// 如何 让这个find能够起作用

struct Frame
{
    int time = 0;
    int page_number= 0;

    Frame(int page_number,int time)
    {
        this->page_number = page_number;
        this->time = time;
    }
};

void print_frame(vector<Frame> frame)
{
    for(int i =0;i<frame.size();i++)
    {
        std::cout<<"page_number:  "<<frame[i].page_number<<std::endl;
        cout<<"time:  "<<frame[i].time<<endl;
    }
}




int main()
{
    vector<int> access_sequence = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2, 1};

    vector<Frame> frame(3,Frame(-1,0));
    for(int i =0;i<access_sequence.size();i++)
    {
        int number = access_sequence[i];

        for(int i =0;i<frame.size();i++)
        {
            frame[i].time++;
        }

        int flag =0;
        //find()
        for(int j =0;j<frame.size();j++)
        {
  
            if(frame[j].page_number == number)
            {
                cout<<"啥也不干！！！！"<<endl;
                flag ++;
            }

        }
        if(flag == 0)
        {
            int flag_1 = 0;
            for(int i =0;i<frame.size();i++)
            {
                if(frame[i].page_number == -1)
                {
                    frame[i].page_number = number;
                    frame[i].time = 0;
                    flag_1++;
                    break;
                }
            }
            if(flag_1== 0)
            {
                frame[0].page_number = number;
                frame[0].time = 0;   
            }
        }
        print_frame(frame);
        cout<<endl;


    }

    print_frame(frame);
    std::find(frame.begin(),frame.end(),Frame(-1,0));
    
    return 0;
}