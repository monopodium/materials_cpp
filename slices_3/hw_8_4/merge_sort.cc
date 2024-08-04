#include<iostream>  

#include <vector>
using namespace std; 
// 作业要求：实现merge sort算法(递归),也就是补全下面的MergeSort函数
//1. 对于vector<int>和list<int>分别实现一份sort函数
// 2.实现两个类:my_list底层用linked-list存储数据，my_vec底层用array存储数据，利用template，使得两个类分别能和真正的stl中定义的vector/list一样，存储double, int., float...的数据，并且给这两个类写begin和end函数，返回指向头和尾的iterator.   
//3.给my_list里存储的元素和my_vec里存储的元素排序 （my_list和my_vec就是为了模仿vector和list）
// 

//让这个函数能对vector进行排序
void merge_2(vector<int>::iterator left, vector<int>::iterator right,vector<int>::iterator mid)  { 
 // 只用一个temp的形式   

    vector<int> temp;  
    vector<int>::iterator i = left;
    vector<int>::iterator j = mid + 1;
    while (i<=mid && j<=right) {
        if(*i<=*j){ // v[i]
            temp.push_back(*i);
            i++;   
        }else{
            temp.push_back(*j);
            j++;
        }
        
    }
    while(i<=mid){
        temp.push_back(*i);
        i++;
    }
    while(j<=right){
        temp.push_back(*j);
        j++;
    }
    for (int k = 0; k < temp.size();k++){
        *(left + k) = temp[k];
    }
    //     for (int i = 0; i < n1; i++)
    //     { // v [left,mid]
    //         temp[i] = v[i + left];
    //         for (int j = mid + 1; j < n2; j++)
    //         { // v [mid+1,right]
    //             temp[j] = v[mid + j];
    //         }
    //     }
    // int i = 0, j = mid, k = left;
    // while (i < n1 && j < n2) {
    //     if (temp[i] <= temp[j]) {
    //         v[k] = temp[i];
    //         k++;
    //         i++;
    //     } else {
    //         v[k] = temp[j];
    //         k++;
    //         j++;
    //     }
    // }
    // while(i<n1){
    //     v[k] = temp[i];
    //         k++;
    //         i++;
    // }
    // while(j<n2){
    //      v[k] = temp[j];
    //         k++;
    //         j++;
    // }
}
void MergeSort(vector<int>::iterator left, vector<int>::iterator right){
    std::cout<<"MergeSort "<<*left<<"  "<<*right<<std::endl;
    // std::cout<<"MergeSort v "<<v[left]<<"  "<<v[right]<<std::endl;
    if(left >= right){
        return;
    }
    int size = 0;
    for (vector<int>::iterator it = left; it <= right; it++)
    {
        size++;
    }
    std::cout<<"size: "<<size<<std::endl;
    vector<int>::iterator mid = left + size / 2 - 1;
    MergeSort(left, mid); // v这个数组的[left,mid]之间的数应该是有序的
    MergeSort(mid + 1, right); 
    merge_2(left, right,mid);// v这个数组的[mid+1, right]之间的数应该是有序的   
} 
// merge: 待补充：合并两个有序数组，两个有序数组分别是v[left, mid]和v[mid+1, right]

int main(){
    vector<int> v = {6, 4, 11, 3}; //, 3, 11};//, 7, 31, 55, 5, 4, 77
    //MergeSort(v,0,3): MergeSort(0,1) MergeSort(2,3)
    //MergeSort(0,1): MergeSort(0,0) MergeSort(1,1) [6] [4]
    MergeSort(v.begin(), v.end() - 1);

    for(auto &item: v){
        std::cout << item << "  ";
    }
    std::cout << std::endl;
    vector<int>::iterator itr = v.begin();

    std::cout<<"*itr: "<<*itr<<std::endl;
    int i = 3;
    std::cout << "*itr: " << *(itr + i) << std::endl;

    vector<int>::iterator end = v.end();

    std::cout<<"*(end): "<<*end<<std::endl;
    std::cout<<"*(end-1): "<<*(end-1)<<std::endl;
    std::cout<<"*(end-2): "<<*(end-2)<<std::endl;
    std::cout<<"*(end-3): "<<*(end-3)<<std::endl;
    cout<<endl;
    return 0;
}
