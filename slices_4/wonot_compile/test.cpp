#include<iostream>
#include <memory>
#include <vector>

template<typename T>
class LinkedList{

public:

    bool insert(const T& value){
        return true;
    };
};
int main()
{
    LinkedList<int> t;
    t.insert(42);
    return 0;
}