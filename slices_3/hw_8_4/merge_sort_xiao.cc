#include<iostream>  

#include <vector>
#include <list>
using namespace std; 
// 作业要求：实现merge sort算法(递归),也就是补全下面的MergeSort函数
//1. 对于vector<int>和list<int>分别实现一份sort函数
// 2.实现两个类:my_list底层用linked-list存储数据，my_vec底层用array存储数据，利用template，使得两个类分别能和真正的stl中定义的vector/list一样，存储double, int., float...的数据，并且给这两个类写begin和end函数，返回指向头和尾的iterator.   
//3.给my_list里存储的元素和my_vec里存储的元素排序 （my_list和my_vec就是为了模仿vector和list）
//
//
void MergeSort(vector<int>::iterator left,vector<int>::iterator right){
    if(left >= right){
        return;
    }
    int size = 0;
    for (vector<int>::iterator it = left; it <= right; it++)
    {
        size++;
    }
    vector<int>::iterator mid = left + size / 2;
        int *mid = (left + right) / 2;
    MergeSort(left, mid);
    MergeSort( mid + 1, right);
    vector<int> temp;

    // int i = left, j = mid + 1;
    // merge: 待补充：合并两个有序数组，两个有序数组分别是v[left, mid]和v[mid+1, right]
    //修改，用iterator去遍历
    vector<int>::iterator it_1 = v.begin() +left;
    vector<int>::iterator it_2 = v.begin()+mid +1;
    
    while (i <= mid && j <= right) {
        if (*it_1<= *it_2) // 除了用index，还可以用iterator
        {
            temp.push_back(*it_1);
            it_1++;
            // i++;
        } 
        else
        {
            temp.push_back(*it_2);
            it_2++;
            // j++;
        }
    }
    
    while (it_1 <= mid) {
        temp.push_back(*it_1);
        ++it_1 ;
    }
    
    while (it_2 <= right) {
        temp.push_back(*it_2);
        ++it_2;
    }
    for (int k = 0; k < temp.size(); k++) 
    {
        v[k+left] = temp[k];
    }
    std::cout<<"After MergeSort: ";
    for(auto &item: v){
        std::cout << item << "  ";
    }
    cout<<endl;
}

int main(){
    vector<int> v = {4,6,3,11,31,7,77,55};
    // MergeSort(0,7): MergeSort(0,3) MergeSort(4,7)

    //MergeSort(0,3): MergeSort(0,1) MergeSort(2,3)

    //
    int j = 3;
    std::vector<int>::iterator it = v.begin() + j;
    std::cout<<"it: "<<*it<<std::endl;
    std::vector<int>::iterator end = v.end()-1;
    std::cout<<"end: "<<*end<<std::endl;

    MergeSort(v.begin(), v.end() - 1);
    for (auto& item : v) {
        cout << item << "  ";
    }
    cout<<endl;
    return 0;
}