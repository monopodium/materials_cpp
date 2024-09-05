#include<iostream>
#include<memory>
#include<vector>
namespace my {
template<typename T>
class unique_ptr {
private:
T * d;
public:
unique_ptr(T * dIn) : d(dIn) {}
unique_ptr() : d(nullptr) {}
~unique_ptr() { delete d; };
unique_ptr(const unique_ptr & other) = delete;
unique_ptr & operator=(const unique_ptr & other) = delete;
T & operator*() const { return *d; };
T * operator->() const { return d; };
};

};
class Coordinate {
private:
    int x;
    int y;
public:
    Coordinate(int xIn, int yIn) : x(xIn), y(yIn) {}
    int getX() const { return x; }
    int getY() const { return y; }
    operator bool() const { 
        std::cout<<"operator bool"<<std::endl;
        return x != 0 || y != 0; }
};


std::unique_ptr<Coordinate> someFunction()
{
    return std::unique_ptr<Coordinate>(new Coordinate(3, 4));
}
my::unique_ptr<Coordinate> myFunction()
{
    return my::unique_ptr<Coordinate>(new Coordinate(3, 4));
}
int main() {
    std::vector<int> numbers_test = {1, 2, 3, 4, 5};
    auto it = numbers_test.end();
    std::cout<<*it<<std::endl;

    // int a = 10;
    // double b = 10.9;
    // a = b; // okay, implicit conversion a = int(b);

    // Coordinate c(3, 4);
    // if(bool(c)){
    //     std::cout<<"c is not null"<<std::endl;
    // }
    // int lvalue_test = 5;
    // int &b = lvalue_test;
    
    // std::unique_ptr<Coordinate> a;
    // if(a){
    //     std::cout<<"a is not null"<<std::endl;
    // }
    // a = someFunction(); // surprisingly okay!
    // // my::unique_ptr<Coordinate> b;
    // // b = myFunction(); // surprisingly okay!
    // std::unique_ptr<Coordinate> a_test(new Coordinate(3, 4));

    // std::unique_ptr<Coordinate> b_test;

    // std::cout<<a_test.get()<<std::endl;
    // b_test = std::move(a_test); //move:让一个左值变成右值
    // std::cout<<a_test.get()<<std::endl;

    // // std::cout<<"b_test: "<<b_test.get()<<std::endl;
    // std::vector<int> numbers(1000000);
    // std::vector<int> a_new(std::move(numbers));
    // std::cout << numbers.size() << std::endl;
    // std::cout << a_new.size() << std::endl;

}