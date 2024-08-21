#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

//
int capacity = 14;
// vector 内容和time用了两个数组，不统一，尝试修改成struct
vector<int> LRC_v1;
int Time[3];

int current_time = 0;

void access(int block[],int capacity)
{       
    for(int i =0;i<capacity;i++)
    {
        current_time++;
        int key = block[i];

        for (int j = 0; j < 3; ++j) 
        {
            Time[j]++;
        }

        vector<int>::iterator it = std::find(LRC_v1.begin(), LRC_v1.end(), key);
            if (it != LRC_v1.end()) 
            {
                // 如果 key 已在缓存中，更新其时间
                int index = it - LRC_v1.begin();
                Time[index] = 0;

            }
            else
            {
                if(LRC_v1.size()<3)
                {
                    LRC_v1.push_back(key);
                    Time[LRC_v1.size() - 1] = 0;
                }
                else
                {
                    int max_number_time = 0;
                    for(int j =0;j<3;j++)
                    {
                        if(Time[j] > Time[max_number_time])
                        {
                            max_number_time = j;
                        }
                    }
                LRC_v1[max_number_time] = key;
                Time[max_number_time] = 0;

                }

            }
    cout<<"加入的元素为：："<<block[i]<<endl;
    for (size_t j = 0; j < LRC_v1.size(); ++j)
    {
        cout << LRC_v1[j] << " (time: " << Time[j] << ") ";
    }
    cout<<endl;

    }
}

int main()
{   
for(int i = 0;i<capacity;i++)
{
    Time[i] = 0;
}
    int access_sequence[] = {7,0,1,2,0,3,0,4,2,3,0,3,2,1};
    access(access_sequence,14);



    return 0;
}