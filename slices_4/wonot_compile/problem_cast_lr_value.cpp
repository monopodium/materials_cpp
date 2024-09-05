#include<iostream>
#include <memory>
#include <vector>

namespace xxy_david{
template<typename T>
class unique_ptr {
private:
    T * d;
public:
    unique_ptr(T * dIn) : d(dIn) {}
    T* get(){
        return d;
    }
    ~unique_ptr() {
        std::cout << "delete d" <<d<< std::endl;
        delete d;
    }
    unique_ptr(const unique_ptr<T>&) = delete; //不允许拷贝构造
    unique_ptr<T>& operator=(const unique_ptr<T>&) = delete; //不允许赋值
    T& operator*() { 
        return *d;
    };
    T *operator->() const { return d; };
};
}

void print_test(int& a) {
    std::cout << a << std::endl;
}
void increment(int& a) {
    a++;
}
// lvalue  rvalue
// 第一个个解决方案：一个指针只能被一个unique_ptr所拥有 ：不允许拷贝构造，不允许赋值 : unique_ptr
// 第二个解决方案：一个指针可以被多个shared_ptr所拥有 ：允许拷贝构造，允许赋值 : shared_ptr

//有一个计数器
int test(){
    int result = 0;
    return result;
}

int main() {
    int a = 5;
    double b = 10.9; 
    a = b;//隐式转换,先把b转换成一个int类型的变量(临时变量，rvalue)，再赋值给a
    increment(a);
    print_test(b); //修改increment函数，能正常的修改b，并且不报错
    // #ifndef MY_LIST_H //查资料了解这个ifndef的作用
    // #define MY_LIST_H
    
    // my_sort(std::unique_ptr<std::vector<int>> v_1); 

    // 比较shared_ptr和unqiue_ptr之间的区别,并且编程演示。证明区别确实存在

    // bubble sort : david
    // bubble sort : 画图 画个图，给出从左到右遍历无法讲最小值移到最左边的例子



    // lvalue reference
    // int &ref = 3;

    // &用在变量前面就是取地址
    // const reference
    // rvalue reference
    const int &ref = 3; //放在一个类型后面就是某种类型的引用
    int &&ref_3 = 4;

    //

    std::cout << a << std::endl;
    // int *p = new int(5);
    // xxy_david::unique_ptr<int> p_1(new int(5));
    // xxy_david::unique_ptr<int> p_2(new int(5));
    // std::cout << *p_1 << std::endl;
    // *p_1 = 6;
    // std::cout << *p_1 << std::endl;

    // Counter * c = new Counter(1);
    // c->count++;

    // xxy_david::unique_ptr<Counter> p_3(new Counter(1));
    // p_3->count++;
    // p_1 = p_2;
    // std::cout <<"after p_1 = p_2"<<std::endl;
    // std::cout << "p_1 " << p_1.get() << std::endl;
    // std::cout << "p_2 " << p_2.get() << std::endl;
    // std::cout << "p_1.get() " << *p_1.get() << std::endl;
    // int a = 5;
    // increment(a);

    //在变量名字或者函数名字前使用
    // std::unique_ptr<std::string> p_1 = std::make_unique<std::string>("5");
    // std::unique_ptr<int> p_2 = std::make_unique<int>(5);
    // std::cout << "p_1 " << p_1.get() << std::endl;
    // std::cout << "p_2 " << p_2.get() << std::endl;


    // std::cout << "p_1.get() " << p_1.get() << std::endl;
    // std::cout << "p_1       " << *p_1.get() << std::endl;
    // std::unique_ptr<int> p_2 = move(p_1);
    // std::cout << "p_1.get() " << p_1.get() << std::endl;

    // std::vector<int> v = {1, 2, 3, 4, 5};
    // std::vector<int> v2(v);
    // for (auto i : v) {
    //     std::cout << i << std::endl;
    // }
    // std::vector<int> v3 = std::move(v);
    // std::cout << "v.size() " << v.size() << std::endl;
    // for (auto i : v) {
    //     std::cout << i << std::endl;
    // }
    return 0;
}