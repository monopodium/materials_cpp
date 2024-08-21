#include<iostream>  
using namespace std; 
#include<string>
#include <fstream>
#include <list>

template<class T>
class my_vector
{   
    private:
        T *data; 
                    //要是不满足条件，就重新new一个
        int size = 0;
    public:

        T& operator[](int index) { return data[index]; }
        my_vector(int max_size) { data = new T[max_size]; }

        void push_back(const T &value);
        my_vector &operator+(const my_vector &other);
        iterator begin() { return iterator(data); }

        iterator end() { return iterator(data + size); }
        
        class iterator 
        {
            private:
                T* ptr;
            public:
                iterator(T* p) : ptr(p) {}

                // iterator& operator ++() {
                //     ++ptr;
                //     return *this;
                // }
                iterator& operator ++(int) { //it++
                    auto old = this;
                    ++ptr;
                    return *old;
                }
                iterator& operator ++() {//++it
                    ++ptr;
                    return *this;
                }
                bool operator!=(const iterator& other) const {
                    return ptr != other.ptr;
                }

                T& operator*() {
                    return *ptr;
                }
        };
};