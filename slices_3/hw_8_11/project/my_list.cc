#include<iostream>  
#include<string>
#include <fstream>
#include <vector>
#include <list>

using namespace std; 

template<typename T>
class my_list
{
    private:
        class Node
        {
            public:
                T data;
                Node *next;
                Node(T x) : data(x), next(nullptr) {};
        };
        Node *head;
        Node *tail;

    public:
        my_list()
        {
            head = nullptr;
            tail = nullptr;
        };
        void push_back(T val_1); 
        iterator begin() const;
        iterator end() const;

        class iterator
        {
            private:
                Node* ptr;
            public:
                iterator(Node *p):ptr(p)
                {

                }
            
                T& operator*() const
                {
                    return ptr->data;
                }
                iterator& operator++(int)
                {
                    this->ptr = ptr->next;
                    return *this;
                }
                bool operator!=(const iterator& other)
                {
                    return ptr !=  other.ptr;
                }
                iterator& operator+(int j)
                {   
                    int i =0;
                    while(i<j)
                    {
                        return ptr = ptr->next;
                        i++;
                    }
                }

            
        };
};
//生成一个编译
my_list<T>::iterator my_list<T>::begin() const
{
    cout<<"重载了begin()函数！！"<<endl;
    return iterator(head);
}
my_list<T>::iterator my_list<T>::end() const
{
    cout<<"重载了end()函数！！"<<endl;
    return iterator(tail->next);
}