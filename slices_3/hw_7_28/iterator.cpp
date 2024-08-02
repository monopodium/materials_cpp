#include <iostream>
#include <iterator>
#include <list>
#include <vector>
#include <algorithm>
// iterator 对于指针的封装
// int * ptr ;
// ptr++;
// ++ptr

//最基本的iterator需要重载 * dereference
//++ 

// 重载了这三种操作的类就可以视为iterator
// 指针也是一种iterator
// *   ++  ++ !=
class david_xxy
{
private:
    int* ptr;
public:
    explicit david_xxy(int* p) : ptr(p) {}

    int operator*() const {
        std::cout << "operator*()" << std::endl;
        return 0;
    }
    // ++it;
    david_xxy &operator++()
    {
        std::cout << "operator++()" << std::endl;
        ++ptr;
        return *this;
    }
    //it++
    david_xxy &operator++(int) //c++
    {
        std::cout << "++operator()" << std::endl;
        ++ptr;
        return *this;
    }
    david_xxy &operator+(int i) //c++
    {
        std::cout << "++operator()" << std::endl;
        ptr+=i;
        return *this;
    }
    bool operator!=(const david_xxy& other) const {
        std::cout << "operator!=" << std::endl;
        //return ptr != other.ptr;
        return true;
    }
};


// 类似于vector, 但只能存int类型的数据
class IntegerContainer {
private:
    int* data;
    std::size_t size;

public:
    // Constructor
    IntegerContainer(std::initializer_list<int> initList) : size(initList.size()) {
        data = new int[size];
        std::copy(initList.begin(), initList.end(), data);
    }

    // Destructor
    ~IntegerContainer() {
        delete[] data;
    }

    //begin() function
    david_xxy begin() const {
        std::cout << "invoke begin!" << std::endl;
        //return david_xxy(data);
        return david_xxy(data);
    }

    // end() function
    david_xxy end() const {
        std::cout << "invoke end!" << std::endl;
        return david_xxy(data + size);
        //david_xxy(data + size);
    }
};

int main() {
    //
    int *ptr ;
    int a = 1;
    int b = a++;
    std::cout << "a:" << a << std::endl;
    std::cout << "b:" << b << std::endl;

    int another_a = 1;
    int c = ++another_a;
    std::cout << "another_a:" << another_a << std::endl;
    std::cout << "c:" << c << std::endl;
    // std::vector<int> test_vev = {4,6,9,1, 2, 3, 4, 5};
    // std::list<int> test_list = {4,6,9,1, 2, 3, 4, 5};
    // std::sort(test_vev.begin(),test_vev.end());
    // std::sort(test_list.begin(),test_list.end());
    IntegerContainer container = {1, 2, 3, 4, 5};

    // std::vector<int> vec_test = {3,4,5,6,7};
    // std::list<int> list_test = {3,4,5,6,7};

    // //太麻烦了，verbose, 冗余，
    // for (std::vector<int>::iterator it = vec_test.begin(); it != vec_test.end(); it++)
    // {
    //    std::cout<<*it<<"  ";
    // }

    // for (std::list<int>::iterator it = list_test.begin(); it != list_test.end(); it++)
    // {
    //    std::cout<<*it<<"  ";
    // }

    // for(int item:vec_test)
    // {
    //     std::cout<<item<<"  ";
    //}

    // 
    for (const int &value : container) // for(iterator<> iterator = begin;iterator++;iterator< .end())
    {
        std::cout << value << " ";
    }

    // for (auto it = container.begin();it != container.end();++it){
    //     int value = *it;
    // }
    std::cout << std::endl;

    return 0;
}
