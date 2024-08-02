#include<iostream>  

#include <vector>
using namespace std; 
// 作业要求：实现merge sort算法(递归),也就是补全下面的MergeSort函数
//1. 对于vector<int>和list<int>分别实现一份sort函数
// 2.实现两个类:my_list底层用linked-list存储数据，my_vec底层用array存储数据，利用template，使得两个类分别能和真正的stl中定义的vector/list一样，存储double, int., float...的数据，并且给这两个类写begin和end函数，返回指向头和尾的iterator.   
//3.给my_list里存储的元素和my_vec里存储的元素排序 （my_list和my_vec就是为了模仿vector和list）
//

void MergeSort(vector<int> &v, int left, int right){
    if(left >= right){
        return;
    }
    int mid = (left + right) / 2;
    MergeSort(v, left, mid);
    MergeSort(v, mid + 1, right);
    vector<int> temp;
    int i = left, j = mid + 1;
    // merge: 待补充：合并两个有序数组，两个有序数组分别是v[left, mid]和v[mid+1, right]

    for(int i = left; i <= right; i++){
        v[i] = temp[i - left];
    }
}
int main(){
    vector<int> v = {4,6,3,11,7,31,55, 5, 4,77};
    MergeSort(v, 0, v.size() - 1);
    for(auto &item: v){
        std::cout << item << "  ";
    }
    cout<<endl;
    return 0;
}
