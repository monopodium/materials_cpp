#include "my_list.h"

void sort_vector(vector<int>& vec)
{
    for(int i =0;i<vec.size()-1;i++)
    {
        for(int j =i+1;j<vec.size()-1;j++)
        {
            if(vec[i] > vec[j])
            {
                int temp = vec[i];
                vec[i] = vec[j];
                vec[j] = temp;
            }
        }
    }
}




int main()
{
    // my_vector<int> vec_1(10);

    // int value = 0;
    // for (int i = 0; i < 10; ++i) {
    //     vec_1.push_back(i);
    // }

    // for (auto it = vec_1.begin(); it != vec_1.end(); it++) {
    //     std::cout << *it << " ";
    // }
    // cout<<endl;
    my_list <int> list_1;
    list_1.push_back(10);
    list_1.push_back(20);    
    list_1.push_back(30);

for (auto it = list_1.begin(); it != list_1.end(); it++) {
    std::cout << *it << " ";
    }

    cout<<endl;  
    iterator it = list_1.begin()+4;
    cout<<*it<<endl;


    // my_list<int> list_1{5,12,30,56,7,20,1};
    // list_sort(list_1);



    return 0;
}