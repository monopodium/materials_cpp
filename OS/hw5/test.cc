#include<iostream>  
#include <vector>
#include<cstdio>
#include<map>
#include <algorithm>

void print_it(std::vector<int>xxy){
    int n=xxy.size();
    for(int i=0;i<n-1;i++){
        std::cout<<xxy[i]<<" ";
    }
    std::cout<<std::endl;
}
//从小到大排序
void bubbleSort_1(std::vector<int>&xxy){
    int n=xxy.size();
    for (int i=0;i<n-1;i++){
        for (int j=0;j<n-i-1;j++){
            if(xxy[j]>xxy[j+1]){
                std::swap(xxy[j],xxy[j+1]);
            }
        }
        print_it(xxy);
    }
}
//从大到小排序
void bubbleSort_2(std::vector<int>&xxy){
    int n=xxy.size();
    for(int i=0;i<n-1;i++){
        for(int j=n-1;j>0;j--){
            if(xxy[j]>xxy[j-1]){
                std::swap(xxy[j],xxy[j-1]);
            }
        }
    }
}

int main(){
    std::vector<int> xxy={8,3,5,4,6,9,7,2,1,0};
    bubbleSort_1(xxy);
    print_it(xxy);
    bubbleSort_2(xxy);
    print_it(xxy);
    return 0;
}