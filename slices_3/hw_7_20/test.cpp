#include<iostream>
#include<vector>
#include<list>
#include<tuple>
#include<set>

//slices3 7页的函数补全

//template<typename T>
// void Print(T toretrievel){
//     for(auto &item: toretrievel){
//         std::cout << item << std::endl;
//     }
// }
//验证这个函数能不能打印:tuple, pair,list ,set ,unordered_set,vector里面的元素

//阅读c++ primer plus里面iterator的内容
//尝试使用iterator,调研，使用排序函数sort尝试给list和vector 
//能成功，解释原因
//不能成功，也解释原因

//阅读课件merge sort的部分，自己实现排序算法，
//输入是一个乱序的vector<int>数组

//验证两种constructor的不同：
    // Person(const Person & other):M_name(other.M_name),M_age(other.M_age)
    // {
    //     std::cout << "copy construtor of Person!" << std::endl;
    // }
    // Person(const Person & other,int n)
    // {   
    //    this->M_age = M_age;
    //     this->M_name = M_name;  //operator=
    //     std::cout << "copy construtor_2 of Person!" << std::endl;
    // }
    // P

//generic programming :泛型编程
// []
// [
//
template<typename T>
void Print(T toretrievel){
    for(auto &item: toretrievel){
        std::cout << item << std::endl;
    }
}
void printIt(const std::vector<int> &p){
    for(auto &item: p){
        std::cout << item << std::endl;
    }
}
int test(){
    return 10;
}

int main(){
    //IP port(端口)
    //
    //int *a = new int[10];
    int a;
    auto b = a + 2;

    auto result = test();
    std::list<int> list_a;
    list_a.push_back(10);
    list_a.push_back(10);
    list_a.push_back(10);
    std::cout << "list:" << std::endl;
    for (auto item : list_a)
    {
        std::cout << item << std::endl;
    }
    //auto itr = list_a.begin() + 1;
    //list的底层实现是双向的链表 linked-list 数据在内存里面不连续的存储
    //{视频1，视频2，视频1，视频1，视频1，视频1，视频1，视频1，视频1} list 
    //
    
    //{视频1，视频2}
    //binary search tree
    // 
    // hash table

    //key value
    // [(10,value1),(12,value2),(13,value3),(18,value4)]
    //从头找到尾部

    //hash(x) = x%10
    //hash(10) = 10%10 = 0
    //hash(12) = 12%10 = 2
    //hash(22)

    // [value1]
    // []
    // [value2]
    // [value4]
    // []
    // []
    // []
    // []

    std::set<int,std::greater<int>> set_a;
    set_a.insert(10);
    set_a.insert(10);
    set_a.insert(10);
    set_a.insert(8);
    set_a.insert(18);
    std::cout << "insert greater:" << std::endl;
    for (auto item : set_a)
    {
        std::cout << item << std::endl;
    }

    std::set<int,std::less<int>> set_b;
    set_b.insert(10);
    set_b.insert(10);
    set_b.insert(10);
    set_b.insert(8);
    set_b.insert(18);
    std::cout << "insert less:" << std::endl;
    for (auto item : set_b)
    {
        std::cout << item << std::endl;
    }
    

    // std::vector<int> vec(10);//数据在底层连续存储
    // vec.erase(vec.begin() + 3);
    // std::tuple<bool, int, int, int> tuple_test{false, 2, 3, 4};
    // std::pair<std::string, int> address{"127.0.0.1", 8080};
    // std::pair<int, std::string> student{202410,"david"};
    // std::cout << student.first << std::endl;
    // std::cout << student.second << std::endl;
    // std::vector<int> a(10,999);
    // auto itr = a.begin() + 2;
    // auto newItr = a.insert(itr, 10);

    // std::list<int> bb;
    // auto itr = bb.begin() + 2;
    // auto newItr = bb.insert(itr, 10);
}