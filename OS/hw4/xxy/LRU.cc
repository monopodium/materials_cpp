#include<iostream>
#include<vector>
#include<deque>
#include<algorithm>
using namespace std;

struct Frame
{
     int page_number =-1;
     int time =0;
     Frame(int page_number_1,int time_1)
     {
        this ->page_number = page_number_1;
        this-> time = time_1;

     }
};
// 
//架子：
int main()
{   //[0,1,2]
    //【7，0，1】
    // 0 index: 1
    // 无脑的踢掉index为0 
    vector<Frame> frame1 (3,Frame(-1,0)) ;

    std::vector<int> access_sequence = {7,0,1,2,0,3,0,4,2,3,0,3,2,1};
    for(int i =0;i<access_sequence.size();i++)
    {   
        int number = access_sequence[i];


        for(int i =0;i<3;i++)
        {
            frame1[i].time++;
        }
        int flag =0;
        for(int j =0;j<frame1.size();j++)
        {   

            if(frame1[j].page_number == number)
            {
                frame1[j].time = 0;
                flag++;
            }

            
            cout<<"frame: "<<frame1[j].page_number<<endl;
            cout<<" time:     "<<frame1[j].time<<endl;
        }
        if(flag == 0)
        {   
            int flag_1 = 0;
            for(int j =0;j<frame1.size();j++)
            {
                if(frame1[j].page_number == -1)
                {
                    frame1[j].page_number = number;
                    frame1[j].time = 0;
                    flag_1++;
                    break;

                }  
          
            }
            
            if(flag_1 ==0)
            {
                frame1[0].page_number = number;
                frame1[0].time = 0;   
            } 

        }
        cout<<" access _number:   "<< number<<endl;

    }


}