#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

struct Node{
    int frame_number; // frame number
    int bit = 0; // time
    Node* next;
    Node* prev;//
};
// A->B->C

// A->B->C
// 双向： A有一个指向b的指针，A.next 是B， B也要有一个指向A的指针，B.prev是A


// frame 定义这样一个环状的链表，并且，让这个链表大小是内存能容纳的frame的数量
//只要有一个指针，不停后移
// class single_circle_list{
//     private:
//         Node *head = nullptr;       //链表的头指针
//         Node *tail  = nullptr;      //链表的尾指针
//         int size = 0;               //链表的大小

//     public:
//         Node* get_head(){
//             return head;
//         }   

//         //frame_number是page的数量，表示内存里面能容纳的空间
//         void insert(int frame_number){
//             auto new_node = new Node();
//             new_node->frame_number = frame_number;
//             new_node->bit = 0;
            
//             if (head == nullptr)
//             {
//                 // 往 空的一个环里插入，
//                 head = new_node;
//                 tail = new_node;
//                 new_node->next = new_node;
//             }
//             else
//             {
//                 tail->next = new_node;
//                 tail = new_node;
//                 new_node->next = head;
//             }
//             size++;
//         }
//         single_circle_list(int mem_size)
//         {
//             for (int i = 0; i < mem_size;i++){
//                 insert(-1);
//             }
//         }

//         //tail
//         Node* find(int page_number){
//             Node *ptr = head;
//             while (ptr!=tail)
//             {
//                 if(ptr->frame_number==page_number){
//                     return ptr;
//                 }
//                 ptr = ptr->next;
//             }
//             if(ptr->frame_number == page_number){
//                 return ptr;
//             }
//             return nullptr;
//         }
        
//         void print(){
//             Node *ptr = head;
//             for (int i = 0; i < size; i++)
//             {
//                 ptr = ptr->next;
//                 std::cout << " ptr frame_number: " << ptr->frame_number << " bit: " << ptr->bit ;
//             }
//             std::cout << std::endl;
//         }
// };

// void access_v2(std::vector<int>& access_sequence){
//     int page_fault = 0;
//     single_circle_list mem(3);
//     Node *ptr = mem.get_head();
//     for (const auto &page_number : access_sequence)
//     {
//         Node *find_ptr = mem.find(page_number);
//         if (find_ptr)
//         {
//             find_ptr->bit = 1;
//         }else{
//             while(ptr->bit ==1){
//                 ptr->bit = 0;
//                 ptr = ptr->next;
//             }
//             ptr->frame_number = page_number;
//             ptr->bit = 1;
//             page_fault++;
//         }
//         std::cout << " access: " << page_number<< std::endl;
//         mem.print();
//     }
// }

// 
class circular_list{
    private:
        Node* head;
        Node* tail;
        int size = 0;

    public:
        Node* get_head(){
            return head;
        }
        Node* get_tail(){
            return tail;
        }
        int get_size(){
            return size;
        }
        circular_list(int mem_size){
            head = nullptr;
            tail = nullptr;

                for(int i = 0; i < mem_size; i++){
                    insert(-1);
                }
        }
        // todo: 补充insert
        void insert(int frame_number)
        {   
            //创造新节点并初始化
            auto new_node_1 = new Node();
            new_node_1->frame_number = frame_number;
            new_node_1->bit = 0;    
            new_node_1->next = nullptr;
            new_node_1->prev = nullptr;

            if(head == nullptr)
            {
                head = new_node_1;
                tail = new_node_1;
                new_node_1->next = head;        //当只有一个节点的时候，指向自己
                new_node_1 ->prev = head;
            }
            else
            {   
                new_node_1->next = head;    // 新节点的next指向头部，形成环
                new_node_1->prev = tail;     // 新节点的prev指向尾部           
                tail->next = new_node_1;     // 尾部的next指向新节点
                head->prev = new_node_1;     // 头部的prev指向新节点
                tail = new_node_1;              // 更新尾指针
            }
            size++;
        }
        // todo: remove实现双向链表的remove: 1. 找到要删除的第index个node 2. 删除node 3. 重新连接node
        // todo2: 不用双向链表，用vector再实现一遍
        void remove(int index)
        {       
            Node* temp = head;
            
            if(index == 0)
            {
                // 删除头节点
                delete head;
                head = nullptr;
                tail = nullptr;

            }
            else
            {   
                // 遍历到要删除的第index个节点
                for(int i = 0; i<size;i++)
                {
                    temp = temp->next;
                }
                temp->prev ->next = temp->next;
                temp ->next->prev = temp->prev;
            }

            if(temp == tail)
            {
                tail = temp->prev;  // 如果删除的是尾节点，更新尾节点
            }
            size --;

        }
        bool access(int frame_number){
            Node* temp = head;
            for(int i = 0; i < size; i++)
            {
                if(temp->frame_number == frame_number)      //遍历整个链表，如果页面已经在内存中，该函数会返回 true
                {
                    temp->bit = 1;          //并更新该页面的 bit 位为 1
                    return true;
                }
                temp = temp->next;
            }
            return false;   //如果不在内存中（即返回 false），将进行页面置换。
        }
        void print(){
            Node* temp = head;
            for(int i = 0; i < size; i++){
                std::cout<<" frame_number: "<<temp->frame_number<<" bit: "<<temp->bit<<" ";
                temp = temp->next;
            }
            std::cout<<std::endl;
        }
};

void access(std::vector<int>& access_sequence){
    int page_faults = 0;        //用于记录发生了多少次页面置换（即缺页次数）
    if(access_sequence.size() == 0){
        return;
    }

    int mem_size = 3;
    circular_list mem(mem_size);        //创建了一个大小为三的循环链表

    auto ptr = mem.get_head();
    for(int i = 0; i < access_sequence.size(); i++)
    {
        if(!mem.access(access_sequence[i]))     //检查页面是否在内存中！！
                                //当 mem.access(access_sequence[i]) == false（页面不在内存中），需要找一个页面进行置换。
        {
            int page_number = access_sequence[i];
            while(ptr->bit == 1)    
            {
                ptr->bit = 0;       //如果当前 ptr 指向的页面的 bit == 1，则表示该页面最近使用过，不能被替换。
                ptr = ptr->next;        //因此将它的 bit 置为 0 并继续检查下一个页面。
            }
            ptr->frame_number = page_number;    //跳出循环一定找到 bit == 0 的页面，就将它替换为新页面 page_number
            ptr->bit = 1;                   //并将该页面的 bit 设为 1
            ptr = ptr->next;
            page_faults++;           //页面置换发生时，page_faults++，即记录一次缺页。
        }
        std::cout<<"Access_sequence: "<<access_sequence[i]<<std::endl;
        mem.print();
    }
    std::cout<<"Page faults: "<<page_faults<<std::endl;
}

int main(int )
{
    std::vector<int> access_sequence = {7,0,1,2,0,3,0,4,2,3,0,3,2,1};
    access(access_sequence);
    std::cout<<"Hello World"<<std::endl;

    std::vector<std::string> circular_test = {"A","B","C","D","E"};
    // 0, 1, 2, 3, 4, 5,6,7,8
    // 
    // int ptr_num = 0;
    // while (true)
    // {
    //     std::cout << circular_test[ptr_num % circular_test.size()] << std::endl;
    //     ptr_num++;
    // }
    return 0;
}