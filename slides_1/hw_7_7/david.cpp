#include <iostream>
using namespace std;

// 作业：用c++实现stack和queue
// stack: 先进后出 push, pop, top, size
// queue: 先进先出 
// 例子：
// class stack{
// public:
//     void push(int i){

//     }
// }

int main(){
    //
    //在哪里定义什么样的变量？


    //定义 指向a的指针，指向a所在空间的指针，指向非new方式分配出来的指针；
    // 指向new出来的string的空间的指针。
    int a = 10;
    int b = 20;
    std::cout << &a << std::endl;
    std::cout << &b << std::endl;
    string *pointer_stack = nullptr;
    string *pointer_stack_2 = nullptr;

    int *pointer_stack_int = nullptr;
    int *pointer_stack_2_int = nullptr;
    string *pointer_heap = nullptr;
    string *pointer_heap_2 = nullptr;

    {
        int aaa;
        int bbb;
        pointer_stack_int = &aaa;
        pointer_stack_2_int = &bbb;
        string a("hello"); // stack的空间
        pointer_stack = &a;
        
        string b("hello22"); // stack的空间
        pointer_stack_2 = &b;
        pointer_heap = new string("hello");//用new分配，分配在heap的空间
        pointer_heap_2 = new string("hello111");//用new分配，分配在heap的空间s
    }
    
    cout<<"pointer_stack:"<<pointer_stack<<endl;  //大
    cout<<"pointer_stack_2:"<<pointer_stack_2<<endl;
    cout<<"pointer_heap:"<<pointer_heap<<endl;  //
    cout<<"pointer_heap_2:"<<pointer_heap_2<<endl; //大
    cout<<"pointer_stack_int:"<<pointer_stack_int<<endl;  //
    cout<<"pointer_stack_int:"<<pointer_stack_2_int<<endl; //大

//  string c=a;
 

//  string f=*b;
//  string*g=b;
//  string *h=&a;
//  cout<<a<<endl;
//  cout<<b<<endl;
//  cout<<&a<<endl;
//  cout<<&b<<endl;
    return 0;
}