#ifndef MY_LIST_H //查资料了解这个ifndef的作用
#define MY_LIST_H

#include <iostream>
#include <string>
#include<array>
#include <vector>
using namespace std; 
// mergesort补全
// 2.实现两个类:my_list底层用linked-list存储数据，my_vec底层用array存储数据，利用template，使得两个类分别能和真正的stl中定义的vector/list一样，
template<typename T>
class my_list{
    private:
        struct Node {
            T val;         
            Node *next;  
            Node(T x) : val(x), next(nullptr) {} 
        };
        Node* head;
        Node* tail;
    public:

        template<typename T2> class iterator;

        my_list() { head = nullptr; tail = nullptr; }
        void push_back(T val_1); //declare
        iterator<T> begin(){ return iterator<T>(head); }
        iterator<T> end() { return iterator<T>(tail->next);}
};


template<typename T>
template<typename T2>
class my_list<T>::iterator{
    private:
        Node* current;
    public:
        iterator(Node* node) : current(node) {}  
        T& operator*() const {
            if(current==nullptr){
                cout<< "out of range"<<endl; //抛出异常
            }
            return current->val;
        }  
        iterator& operator++() {
            current = current->next;
            return *this;
        }
        iterator& operator+(int i){
            for(int j=0;j<i;j++){
                current=current->next;
            }
            return *this;
        }
        bool operator!=(const iterator& other) const {  
            return current!=other.current;
        }
};

template<typename T>
void my_list<T>::push_back(T val_1){
    Node* new_node=new Node(val_1);
    if(head==nullptr){
        head=tail=new_node;
    }
    else{
        tail->next=new_node;
        tail=new_node;
    }
}
#endif