#include<iostream>  
#include <vector>
#include<cstdio>
#include<map>
#include <algorithm>
#include <memory>

//从小到大排序
void bubbleSort_1(std::unique_ptr<std::vector<int>> xxy){
    int n=(*xxy).size();
    for (int i=1;i<n;i++){
        for (int j=n-1;j>=i;j--){
            if((*xxy)[j]<(*xxy)[j-1]){
                std::swap((*xxy)[j],(*xxy)[j-1]);
            }
        }
    }
}
//从大到小排序
void bubbleSort_2(std::unique_ptr<std::vector<int>>& xxy){
    int n=(*xxy).size();
    for(int i=0;i<n-1;i++){
        for(int j=n-1;j>0;j--){
            if((*xxy)[j]>(*xxy)[j-1]){
                std::swap((*xxy)[j],(*xxy)[j-1]);
            }
        }
    }
}
void print_it(std::vector<int>xxy){
    int n=xxy.size();
    for(int i=0;i<n;i++){
        std::cout<<xxy[i]<<" ";
    }
    std::cout<<std::endl;
}
int main(){
    std::vector<int> xxy={8,3,5,4,6};
    std::unique_ptr<std::vector<int>> xxy_2(&xxy);
    bubbleSort_1(move(xxy_2)); //
    print_it(xxy);
    bubbleSort_2(xxy_2);
    print_it(xxy);
    return 0;
}