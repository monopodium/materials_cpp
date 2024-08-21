// 作业要求：补全下面的MergeSort函数
// 看slices的21-23页，补全mock的iterator并且体会iterator的用处
 #include<iostream>  

#include <vector>
using namespace std; 

class VectorIntIterator 
{ 

public:
    int * position;
    

    VectorIntIterator(int * data) : position(data) 
    {

    }

    int & operator*() 
    { 
        return *position;
    }
    void operator++() 
    {                           // (almost right)
        ++position;
    }
    bool operator!=(const VectorIntIterator& other) const 
    {
        return position != other.position;
    }

};

class  VectorInt
{
    private:
    int data[0];
    int N = 0;


    public:
    VectorInt(int n)   
    {       
        N = n;
        for (size_t i = 0; i < n; ++i) 
        {
            data[i] = 0;
        }
    }

    int& operator[](size_t index) 
    {
    return data[index];
    }
    VectorIntIterator begin() {
        return VectorIntIterator(data);
    }

    // 返回指向尾元素的下一个位置的指针作为迭代器
    VectorIntIterator end() {
        return VectorIntIterator(data + N);
    }
};

int main()
{
    VectorInt vec(5);
    vec[0] = 10;
    vec[1] = 20;
    vec[2] = 30;
    vec[3] = 40;
    vec[4] = 50;

    for (auto item:vec) {
        std::cout << item << " ";
    }
    cout<<endl;
}