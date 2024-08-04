#include <iostream>
#include <string>
#include<array>
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
my_list(){
    head=nullptr;
    tail=nullptr;
}

//void insert(ListNode *n0, ListNode *P) {
//    ListNode *n1 = n0->next;
//    P->next = n1;
//    n0->next = P;
//}
void push_back(T val_1){
    Node* new_node=new Node(val_1);
    if(head==nullptr){
        head=tail=new_node;
    }
    else{
        tail->next=new_node;
        tail=new_node;
    }
    
    }
    david_xxy<T> begin() {
        return david_xxy<T>(head);
    }
    
    david_xxy<T> end() {
        return david_xxy<T>(tail);
    }

    
};
template<typename T>
class david_xxy
{
private:
    Node<T>* current;
public:
    david_xxy(Node<T>* node) : current(node) {}  
     int operator*() const {
        
        return 0;
    }  
    david_xxy& operator++() {
        current = current->next;
        return *this;
    }
    bool operator!=(const david_xxy& other) const {
        
      return current!=other.current;
       
    }
};
template<typename T>
class my_vector{
    private:
    array<T,N>my_vector;
    int siz=0;
    public:
    my_vector(){
        array<T,0>my_vector;
    }
    void push_back(T val_2){
        if (siz>=N) {
            cout<<"it is wrong"<<endl;
        }
        arr[siz++] = val_2;
    }
    
};



int main(){
    my_list<int>xxy;
    xxy.push_back(17);
    xxy.push_back(4);
    xxy.push_back(2);
    xxy.push_back(18);
    xxy.push_back(4);
    for (auto it = xxy.begin(); it != xxy.end(); ++it) {
        std::cout << " " << *it;
    }
    std::cout << std::endl;


}

    
   