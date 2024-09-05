#include "car.h"
#include "my_list.h"
#include "my_sort.h"
#include "my_vector.h"


void test_my_list()
{
    my_list<int> lst;
    lst.push_back(9);
    lst.push_back(5);
    lst.push_back(6);
    lst.push_back(16);
    lst.push_back(1);
    lst.push_back(3);
    lst.push_back(7);
    lst.push_back(8);
    lst.push_back(2);

    // 使用迭代器遍历my_list
    for (auto it = lst.begin(); it != lst.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    my_sort(lst);


    for (auto it = lst.begin(); it != lst.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

void test_my_vec(){
    my_vector<int> vec;

    vec.push_back(9);
    vec.push_back(5);
    vec.push_back(6);
    vec.push_back(16);
    vec.push_back(1);
    vec.push_back(3);
    vec.push_back(7);
    vec.push_back(8);
    vec.push_back(2);

    // 使用迭代器遍历my_vector
    for (auto it = vec.begin(); it != vec.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    my_sort(vec);
}

void test_my_car(){
    vector<Car> vec_car;
    //待调研：emplace_back和push_back的区别，以及如何使用emplace_back
    vec_car.push_back(Car(3, 5));

    vec_car.emplace_back(1, 7);
    vec_car.emplace_back(3, 4);
    //为什么emplace_back也会调用copy constructor?
    vec_car.emplace_back(2, 5);
    vec_car.emplace_back(5, 3);
    vec_car.emplace_back(35, 33);
    vec_car.emplace_back(25, 23);
    vec_car.emplace_back(15, 34);
    vec_car.emplace_back(5, 3);
    std::cout << "------------------" << std::endl;
    // 按照每个car的speed排序
    sort(vec_car.begin(),vec_car.end(),LTBySpeed());
    std::cout << "------------------" << std::endl;
    for(auto item:vec_car){
        item.print();
    }
    //待补充，按照每个car的weight排序
    
}


// # slice看48-最后的内容
// # 比较SLT里面的 list 和vector的iterator的区别
// # 使用find函数

// # 学map的基本操作

// # 实现一个比较器 comparator,能够比较两个类型为Car（slices里面有）的object

// # 定义一个 vector，里面存放的都是car的object，利用我们定义的comparator,对vector进行排序

// # 写两个排序的函数，给我们的 my_list， my_vector进行排序。

// https://www.bilibili.com/video/BV1Dk4y1j7oj?p=54

int main()
{
    test_my_list();
    test_my_vec();
    test_my_car();
    my_vector<int> vec;

    vec.push_back(9);
    vec.push_back(5);
    vec.push_back(6);
    vec.push_back(16);
    vec.push_back(1);
    vec.push_back(3);
    vec.push_back(7);
    vec.push_back(8);
    vec.push_back(2);
    int a,b = 0;
    int *p = &a;
    int *q = &b;
    std::cout << *p << " " << *q <<" "<<int(p-q)<< std::endl;

    return 0;
}