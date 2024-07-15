// 作业：用c++实现stack和queue
// stack: 先进后出 push, pop, top, size
// queue: 先进先出 
// 例子：
// class stack{
// public:
//     void push(int i){

//     }
// }

// 作业 2：
#include<iostream>  
using namespace std; 
#include<string>
#include <fstream>
#include <vector>

class Stack
{   
    private:
        vector<int> v_1;

    public:
        void push(int i)
        {
            v_1.push_back(i);
        }
        void pop()
        {
            v_1.pop_back();
        }
        int size()
        {
            return v_1.size();
        }

        void print_vector()
        {   
            cout<<"vector：";
            for(vector<int>::iterator it = v_1.begin();it != v_1.end();it++)
            {
                cout<<*it<<"  ";
            }
            cout<<endl;
        }
};
class Queue
{   
    private:
        int test = 999;
        vector<int> q_1;

    public:
        Queue & operator=(const Queue& que){
            test = que.test;
            return *this;
        }
        void set_test(int in){
            test = in;
        }
        void test_this(){
            std::cout << test << std::endl;
        }
        void push(int i)
        {
            q_1.push_back(i);
        }
        void pop()
        {
            q_1.erase(q_1.begin());
        }
        int size()
        {
            return q_1.size();
        }
        void print_vector()
        {   
            cout<<"queue：";
            for(int i = 0;i<q_1.size();i++)
            {
                cout<<q_1[i]<<"  ";
            }
            cout<<endl;
        }

    
};

class IHazStringPtr {
private:
    string * str;
public:
    // slice 后面的部分，54页之后
    //copy constructor: deep copy: 不能只拷贝指针，而是要先初始化新的string的空间，再让新的指针指向新的空间
    //destructor: 及时销毁变量:出来的new string()
    //operator= ： deep copy

    //matrix: [[1,2,3],
    //         [1,2,3]] 任意类型的矩阵, 例如int, double类型
    //matrix: [[1.3,2.5,3.6],
    //         [1.6,2.8,3.9]] 任意类型的矩阵 
    
    //验证两种constructor的不同：
    //第一种：
    IHazStringPtr(const IHazStringPtr & other): str(other.str)
    { 

    }
    //第二种：
    IHazStringPtr(const IHazStringPtr & other)
    { 
        str = other.str
    }
    IHazStringPtr() : str(new string()) {}
    void addCharacter(const char c) {str->push_back(c);}
    void printIt() const { cout << *str << endl; }
};

class IHazStringPtr_v2 {
private:
    string str;
public:
    //IHazStringPtr_v2() {}
    IHazStringPtr_v2(int a) {}
    void addCharacter(const char c) {str.push_back(c);}
    void printIt() const { cout << str << endl; }
};

template<typename T>
class array {
private:
    T * elements;
    int arraySize;
public:
    array(const int s): elements(new T[s]), arraySize(s) {}
    ~array() { delete [] elements; }
    T & operator[](const int idx) { return elements[idx]; }
    int size() const { return arraySize; }
};

int main()
{
    //uint;
    
    array<int> a(10);
    a[0] = 10;
    std::cout << a[0] << std::endl;

    array<double> aa(10);
    aa[0] = 10.0;
    std::cout << aa[0] << std::endl;

    array<IHazStringPtr_v2> test(10);
    // IHazStringPtr a;
    // IHazStringPtr b = a;
    // a.addCharacter('a');
    // b.addCharacter('b');
    // a.printIt();
    // b.printIt();
    // std::cout << "================" << std::endl;
    // IHazStringPtr_v2 aa;
    // IHazStringPtr_v2 bb = aa;
    // aa.addCharacter('a');
    // bb.addCharacter('b');
    // aa.printIt();
    // bb.printIt();
    // Queue que_a;
    // que_a.set_test(1);
    // Queue que_b;
    // que_b.set_test(2);
    // Queue que_c;
    // que_c.set_test(3);

    // que_a = (que_b = que_c);

    // int a = 0;

    // int c = (a = 3);
    // std::cout <<c<<std::endl;
    // if(0==c){
    //     std::cout <<c<<std::endl;
    // }
    // que_a.test_this();
    // Stack v_1;
    // for(int i =0;i<9;i++)
    // {
    //     v_1.push(i);
    // }
    // v_1.pop();
    // v_1.print_vector();
    // cout<<"vector的size是:"<<v_1.size()<<endl;

    // Queue q1;
    // Queue *ptr;
    // for (int i = 0; i < 9; i++)
    // {
    //     q1.push(i);
    // }
    // //row
    // char c = 'A';
    // char cc = 88;
    // std::cout << cc << std::endl;
    // q1.pop();
    // q1.print_vector();
    // cout<<"Queue的size是:"<<q1.size()<<endl;
    // vector<int> *vector_ptr = nullptr;
    // {
    //     vector<int> numbers = {1,2,3};
    //     numbers[0] = 1;
    //     std::cout << "vector_ptr->at(0):" << vector_ptr->at(0) << std::endl;
    // }
    // std::cout <<"vector_ptr->at(0):"<< vector_ptr->at(0) << std::endl;

    return 0;
}