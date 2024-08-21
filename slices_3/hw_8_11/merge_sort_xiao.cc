#include<iostream>  

#include <vector>
using namespace std; 
// 作业要求：补全下面的MergeSort函数
// 看slices的21-23页，补全mock的iterator并且体会iterator的用处
void merge_2(vector<int>::iterator left, vector<int>::iterator right,vector<int>::iterator mid)  
{   
    vector<int> temp;
    auto i = left, j = mid + 1;
    while(i <= mid && j <= right)
    {
        if( *i < *j)
        {
            temp.push_back(*i);
            i++;
        }
        else
        {
            temp.push_back(*j);
            j++;
        }

    }
    while (i <= mid) 
    {
        temp.push_back(*i);
        ++i;
    }
    
    while (j<= right) {
        temp.push_back(*j);
        ++j;
    }
    for(vector<int>::iterator it = temp.begin(); it != temp.end(); ++it) 
    {
        *left = *it;
        left++;
    }
}
void MergeSort(vector<int>::iterator left, vector<int>::iterator right)
{
    std::cout<<"MergeSort "<<*left<<"  "<<*right<<std::endl;
    if(left >= right)
    {
        return;
    }
    if(distance(left,right) <= 0){
        return;
    }
    int size = distance(left,right) + 1;
    std::cout<<"size: "<<size<<std::endl;
    vector<int>::iterator mid = left + size / 2 - 1;
    MergeSort(left, mid); 
    MergeSort(mid + 1, right); 
    merge_2(left, right,mid);
} 

int main(){
    vector<int> v = {6, 4, 11, 3,7, 31, 55, 5, 4, 77}; 

    MergeSort(v.begin(), v.end() - 1);

    for(auto &item: v){
        std::cout << item << "  ";
    }
    std::cout << std::endl;
    return 0;
}