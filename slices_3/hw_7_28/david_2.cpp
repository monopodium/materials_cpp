#include <iostream>
#include <string>
#include<vector>
#include<list>
#include<set>
#include <unordered_set>
using namespace std;
////template<typename T>
// void Print(T toretrievel){
//     for(auto &item: toretrievel){
//         std::cout << item << std::endl;
//     }
// }
//验证这个函数能不能打印:tuple, pair,list ,set ,unordered_set,vector里面的元素

template<typename T>
void Print(T toretrievel){
    for(auto&item:toretrievel){
        std::cout<<item<<std::endl;
    }
}
// begin() : iterator迭代器，指向这个vector/list的头
// end(): iterator迭代器，
int main(){
    tuple<int,int,string> tuple_test(1,2,"XXY");
    //Print(tuple_test);
    pair<int,char> pair_test(1,'A');
    //Print(pair_test);
    
    list<int>xxy(6, 1);
    Print(xxy);

    set<int>xxy_2;//(1,2,3,4)
    xxy_2.insert(1);
    xxy_2.insert(2);
    xxy_2.insert(3);
    xxy_2.insert(4);
    xxy_2.begin();
    Print(xxy_2);

    vector<int>xxy_3;//(1,2,3,4)
    xxy_3.push_back(1);
    xxy_3.push_back(2);
    xxy_3.push_back(3);
    xxy_3.push_back(4);
    Print(xxy_3);
    unordered_set<int> xxy_4;
	//插入元素（去重）
	xxy_4.insert(1);
	xxy_4.insert(2);
	xxy_4.insert(3);
	xxy_4.insert(3);

    Print(xxy_4);
}