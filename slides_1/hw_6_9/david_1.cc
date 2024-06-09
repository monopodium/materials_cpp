#include <iostream>
using namespace std;

//单独写代码，不复杂
//封装 encapsulation
//安全性
//给上层只暴漏一个接口
//函数重载：reload

//1. 功能实现
// 给我们的student增加构造和析构函数，
//  3 different constructor: default, 2 parameters, 3 parameters
//  1. Student() 2. Student(string name, int age) 3. Student(string name, int age, int book_number)，10
//  3.在第三个析构函数里面，创建一个长为book_number的链表。
// 用第三个构造函数去初始化3个学生。
// 实现一个成员函数：borrow_book(int i, int id_input);这个函数实现的功能：将head指向的链表的第i个BookNode的id设为id_input
// 再实现一个成员函数：print_books():把学生的book链表打印出来。
// 验证这些函数功能是正确的。
// 实现一个析构函数，在这这个析构函数里面，把链表分配的空间释放掉

// 2.验证
// 实现一个函数，把student里面的head指针返回回来， return_head;
// 在main函数里面，BookNode* main_head = ...;
// main_head在析构前后会不会有变化
struct BookNode
{
    int id;
    BookNode* next = nullptr;
};

class Student
{
    public:

       
        void set(string nam,int age,double sco);
        void print_age();
        void borrow_book(int i,int id_input);
        void print_books();
        Student(){
            std::cout << "default constructor!" << std::endl;
        }; // default constructor
        Student(string name, int age)
        {
            name = name;
            age = age;
            std::cout << "在这里执行了构造函数 2:constructor!" << std::endl;
            head = new BookNode;
            //
            // for(){

            // }
        };
        Student(string name_1,int age_1,int book_number): name(name_1), age(age_1){
            //name = name_1;
            //age = age_1;
            std::cout << "在这里执行了构造函数 3:constructor!" << std::endl;
            head=new BookNode;
            BookNode* tail=head;
            for(int i=1;i<book_number;i++){
                tail->next=new BookNode;
                tail=tail->next;
            }
        }
        ~Student(){
            BookNode* tail= head;
            while(tail!=nullptr){
                BookNode* temp;
                temp=tail;
                tail=tail->next;
                delete temp;
            }
            std::cout << "这里调用了析构函数！！！" << std::endl;
           
        };
        // 引用
        Student(const Student &obj) //copy constructor 
        // booklist 仅复制book_list的id，但是要存到新被构造的学生自己的空间里
        {
            age = obj.age;
            name = obj.name;
            //新的student分配一个linked_list
            // 10
            head; //= new BookNode;
            BookNode *tail= head;

            BookNode *old_tail = obj.head;
            while(old_tail!=nullptr){
                //判断tail是不是等于空，分别去处理
                if(tail!=nullptr){
                    tail->next=new BookNode;
                    tail->id=old_tail->id;
                    tail=tail->next;
                }
                else{
                    tail = new BookNode;
                    tail->id = old_tail->id;
                    head = tail;
                }
                old_tail = old_tail->next;
            }
            
            
                        // head = obj.head;
            // if(obj.head==nullptr){
            //     cout<<"there is no list"<<endl;
            //     return;
            // }else{
            //     head=new BookNode;
            //     BookNode *tail=head;
            //     for(int i=1;i<book_number;i++){
            //     tail->next=new BookNode;
            //     tail=tail->next;
            // }
            // }
        }
             

     
        

    BookNode* return_head(){
        return head;
    }

    private:
    //member variables
        BookNode* head = nullptr;
        string name;
        int age;
        double score;
};


void Student::print_age(){
    std::cout<<"print age: " << age << std::endl;
}
void Student::set(string nam,int ge,double sco)
{
    name="family"+nam;
    age=ge;
    score=sco;

};
void Student::borrow_book(int i,int id_input){
    
    BookNode *tail=head;
    for(int j=0;j<i;j++){
        tail=tail->next;
    }
    tail->id=id_input;
    
}
void Student::print_books(){
     BookNode* current =head;
        while (current != nullptr) {
            
            cout << current->id << endl;
            current= current->next;
            
            
        }
        cout<<endl;
}

int main(){
    
  
    Student student1("xxy", 24, 3);
    student1.borrow_book(0, 101);
    student1.borrow_book(1, 102);
    student1.borrow_book(2, 103);
    student1.print_age();
    Student student2(student1);
    Student student3 = student1;
    student2.print_age();
    student2.borrow_book(0, 333333301);
    student1.print_books();
    return 0;
}
