#include <iostream>
#include <string>
#include<array>
#include <vector>
using namespace std; 

void merge_2(vector<int>::iterator left, vector<int>::iterator right,vector<int>::iterator mid)  { 
    vector<int>temp(distance(left,right)+1);
    auto temp_1=temp.begin();

    //[left,mid] [mid+1,right] 
    // 
    //
    vector<int>::iterator i = left, j = mid + 1;
    
    while(i<=mid&&right>=j){
        if (*i <= *j) {
            *temp_1 = *i;
            temp_1++;
            i++;
        } else {
            *temp_1= *j;
            temp_1++;
            j++;
        }
    }
    while (i<= mid) {
        *temp_1 = *i;
        temp_1++;
        i++;
    }
    while (j <= right) {
        *temp_1 = *j;
        temp_1++;
        j++;
    }
    for (vector<int>::iterator it = temp.begin(); it!=temp.end(); it++){
        *left = *it;
        left++;
    }
    
}

void MergeSort(vector<int>::iterator left, vector<int>::iterator right){
    std::cout<<"MergeSort "<<*left<<"  "<<*right<<std::endl;
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