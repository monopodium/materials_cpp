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
#include<iostream>  
using namespace std; 
#include<string>
 #include <fstream>
struct BookNode
{
    int id;
    BookNode* next;
};
class   Student
{
    public: 
    Student()
    {
        cout<<"这个是构造函数！!!"<<endl;
    }
    Student(string name, int age)
    {
        this->M_name = name;
        this->M_age = age;
    }
    Student(string name, int age, int book_number)
    {   
        BookNode *tail = head;
        for(int i =0;i<book_number;i++)
        {   
            BookNode * new_book_number = new BookNode;
            if(head == nullptr)
            {
                head = new_book_number;
                head->id = 150;
                tail = head;
            }
            else
            {  
                tail ->next = new_book_number;
                tail = tail->next;
            }

        }
    }
    void borrow_book(int index, int id_input)
    {  
        BookNode * current = head;
        for(int i=0;i<index-1&& current != nullptr;i++)
        {
            current = current->next;
        }
        current ->id = id_input;
    }

    void print_array()
    {
        BookNode *point_3 = head;
        std::cout << "======the info of student=====" << std::endl;
    while (point_3 != nullptr)
    {
        std::cout << "id:" << point_3->id << std::endl;
        point_3 = point_3->next;
    }
    }
    BookNode* check_head_1()
    {
        return head;
    }

    ~Student()
    {
        BookNode *current = head;
        while (current != nullptr)
        {
            BookNode *next = current->next;
            delete current;
            current = next;
        }
    }
    BookNode* check_head_2()
    {
        return head;
    }
    private:
    BookNode* head = nullptr;
    string M_name;
    int M_age;
    int M_score;

};

 int main()
 {
    Student student_1;
    Student student_2("xiaoxuyang",18);
    Student student_3("david",200,5);
    student_3.borrow_book(3,1000);
    student_3.print_array();
    BookNode * result = student_3.check_head_1();
    cout << "result:" << result << std::endl;
    cout << result->id << endl;
    BookNode * result_1 = student_3.check_head_2();
    cout << "result_1:" << result_1 << std::endl;
    cout<<result_1->id<<endl;
 }
