#include <iostream>
#include <string>
#include <array>
#include <vector>
using namespace std; 

template<typename T>
class my_vector{
    private:
        T* inner_array;
        int capacity = 0; //数组容量
        int siz = 0;     // 实际大小
    public:
        my_vector(int vector_size){
            inner_array = new T[vector_size];
            capacity = vector_size;
        };
    // 如果说inner_array, size不够用，就resize
        void push_back(T val_2){
            if (siz>=capacity) {
                T* old = inner_array;
                T* inner_array = new T[2*capacity];
                for(int i=0;i<capacity;i++){
                    inner_array[i]=old[i];
                }
                capacity = 2*capacity;
                // delete[] old;
                // std::cout<<"push_back"<<std::endl;
                // std::cout<<"siz:"<<siz<<std::endl;
                // std::cout<<"capacity"<<capacity<<std::endl;
            }
            inner_array[siz++] = val_2;
        };
        T &operator[](int index)
        {
            if(index>=capacity){
                throw "out of range";
            }
            return inner_array[index];
        };
};