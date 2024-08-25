#include<iostream>
#include<vector>
using namespace std;

//c.将代码改为通过命令行参数传入mem大小的形式（之前课程上固定mem大小为3个frame)

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
class single_circle_list{
    private:
        Node *head = nullptr;
        Node *tail  = nullptr;
        int size = 0;

    public:
        Node* get_head(){
            return head;
        }
        void insert(int frame_number){
            auto new_node = new Node();
            new_node->frame_number = frame_number;
            new_node->bit = 0;
            
            if (head == nullptr)
            {
                // 往 空的一个环里插入，
                head = new_node;
                tail = new_node;
                new_node->next = new_node;
            }
            else
            {
                tail->next = new_node;
                tail = new_node;
                new_node->next = head;
            }
            size++;
        }
        single_circle_list(int mem_size)
        {
            for (int i = 0; i < mem_size;i++){
                insert(-1);
            }
        }

        //tail
        Node* find(int page_number){
            Node *ptr = head;
            while (ptr!=tail)
            {
                if(ptr->frame_number==page_number){
                    return ptr;
                }
                ptr = ptr->next;
            }
            if(ptr->frame_number == page_number){
                return ptr;
            }
            return nullptr;
        }
        
        void print(){
            Node *ptr = head;
            for (int i = 0; i < size; i++)
            {
                ptr = ptr->next;
                std::cout << " ptr frame_number: " << ptr->frame_number << " bit: " << ptr->bit ;
            }
            std::cout << std::endl;
        }
};

void access_v2(std::vector<int>& access_sequence){
    int page_fault = 0;
    single_circle_list mem(3);
    Node *ptr = mem.get_head();
    for (const auto &page_number : access_sequence)
    {
        Node *find_ptr = mem.find(page_number);
        if (find_ptr)
        {
            find_ptr->bit = 1;
        }else{
            while(ptr->bit ==1){
                ptr->bit = 0;
                ptr = ptr->next;
            }
            ptr->frame_number = page_number;
            ptr->bit = 1;
            page_fault++;
        }
        std::cout << " access: " << page_number<< std::endl;
        mem.print();
    }
}

int main(int argc,char * argv[])
{   

    cout<<"收到几个元素："<<argc<<"  "<<endl;

    for(int i = 0;i<argc ;i++)
    {
        cout<<argv[i]<<"   ";
    }
    vector<int> access_sequence ;


    for(int i = 0;i<argc ;i++)
    {
        int page_number = atoi(argv[1]);
        access_sequence.push_back(page_number);
    }

    // std::vector<int> access_sequence = {7,0,1,2,0,3,0,4,2,3,0,3,2,1};
    access_v2(access_sequence);
    std::cout<<"Hello World"<<std::endl;

    // std::vector<std::string> circular_test = {"A","B","C","D","E"};
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