#include<iostream>  
#include <vector>
#include<cstdio>
#include<map>
#include <algorithm>
using namespace std; 
//比较SLT里面的list和vector的iterator的区别：
//vector 和 list 两种数据结构的内存分配方式不同，vector内存空间是连续的，而list的内存不是连续的，
//所以这样一来vector的begin() + h 得到的迭代器是真实指向第h个元素的，而list的begin() + h 
//得到的迭代器指向的是begin()连续偏移h块内存空间（一块内存空间的大小取决于存储在list容器中类型所占大小，如类型为int，则为4个字节），
//但是因为list的内存不连续，所以begin() + h得到的不是我们想要的第h个节点的迭代器。实际上C++也没有重载list迭代器的 ‘+’ ‘-’符号，
//也不支持其迭代器的加减运算。所以为了访问list的第h个节点，只能从begin()开始一个一个往后访问，list访问节点的时间复杂度为O


class Car {
protected:
    double speed;
    double range;

public:
    Car(double spd, double rng) : speed(spd), range(rng) {}
    double getSpeed() const { return speed; }
    double getRange() const { return range; }
    bool operator<(const Car& other) const {
       return speed < other.speed;
     }
};


struct Comparator {
    bool operator()(const Car& a, const Car& b) const {
        if (a.getSpeed() < b.getSpeed()) {
            return a.getSpeed() < b.getSpeed();
        }
        else if(a.getSpeed()==b.getSpeed()){
            return 0;
        }
        
        return a.getRange() > b.getRange();
        
    }
};


int main(){
    //使用find函数
    string s1="xxyissb";
    string s2="xxy";
    int ans=s1.find(s2);
    cout<<ans<<endl;
    string s3="sb";
    int ans_1=s1.find(s3,2);//从S1第二个开始找
    
    std::vector<int> v = { 1, 2, 3, 4, 5 };
    auto it = std::find(v.begin(), v.end(), 8);
    std::cout << "================" << std::endl;
    std::cout << *it << std::endl;
    std::cout << "================" << std::endl;
    std::cout << *v.end() << std::endl;
    

    std::cout << *(v.begin()+2) << std::endl;
    std::cout << *(v.begin()+3) << std::endl;

    cout<<ans_1<<endl;
    //学map的基本操作
    map<int, string> ID_Name = {
        { 2015, "Jim" },
        { 2016, "Tom" },
        { 2017, "Bob" } };
    //单个插入，有值的话修改，没值的话插入
    ID_Name[2015] = "xxy";


    vector<Car> cars = {
        Car(150.0, 400.0),
        Car(150.0, 350.0),
        Car(200.0, 300.0),
        Car(180.0, 500.0),
        Car(150.0, 400.0)
    };
    sort(cars.begin(), cars.end(), Comparator());
    for (const auto& car : cars) {
        cout << "Speed: " << car.getSpeed() << ", Range: " << car.getRange() << endl;
    }

    return 0;


}