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
        Student(string name_1,int age_1,int book_number){
            name = name_1;
            age = age_1;
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
        Student(const Student &obj)
        {
            age = obj.age;
            name = obj.name;
            score = obj.score;
            //head怎么去拷贝？？
            head = obj.head;
            std::cout << "自己定义的拷贝构造函数" << std::endl;
        }

    BookNode* return_head(){
        return head;
    }

    private:
       
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
    //实现一个拷贝构造函数，让student2的books_list 里面的id和student1一样，但是用的是不同的空间。
    //也就是，student2链表的修改，不能够影响student1
    //自学一下 vector，把基础的操作都学会，定义一个长为10的Student的vector的数组。
    //尝试用不同的方法操作vector,  .push_back(), reverse(), 至少学会五个不同的vector的操作方法，代码验证，并且解释他们的含义。 
    int a = 10;
    int b;
    b = a;//赋值
    a = 100;
    std::cout << "b" << b << std::endl;
    Student student1("xxy", 24, 3);
    student1.borrow_book(0, 101);
    student1.borrow_book(1, 102);
    student1.borrow_book(2, 103);
    student1.print_age();
    Student student2(student1); //1. 默认构造函数 2. 调用有参数的 3. 拷贝构造的方式构造
    student2.print_age();

    //1. 我是做了一个叫做拷贝构造的操作
    //2.如果说，我不自己写拷贝构造函数，编译器会给你一个默认的拷贝构造函数：无脑复制一份


  //  = student1; // 用拷贝的方式去构造一个student2
    // student2 = student1; //单纯的拷贝（赋值)
    student2.borrow_book(0, 333333301);
    std::cout << "============print_books================" << std::endl;
    student1.print_books();

    // insertValue("david",23,100,&head);
    // insertValue("xxy",24,70,&head);
    // insertValue("xiaoming",25,80,&head);
    // insertValue("xiaohong",26,90,&head);
    // 1.如果说我自己不写构造函数，那编译器会给你生成一个默认的构造函数，这个默认的构造函数，它是没有参数的
    // 2.如果说我自己写了一个构造函数，那编译器就不会给你默认的构造函数, 如果你自己写的这个构造函数是有参数的，
    // 那你新定义一个Student变量的时候，一定要输入参数
    //
    // scope:作用域
    // BookNode *head_out;
    // {
    //     Student array[4];
    //     Student student_default;
    //     Student xxy("xxy",24);
    //     Student student1("xxy", 24, 3);
    //     Student student2("xiaoming",25,2);
    //     Student student3("xiaohong",26,4);
    //     student1.borrow_book(0, 101);
    //     student1.borrow_book(1, 102);
    //     student1.borrow_book(2, 103);
    //     student1.print_books();
    //     head_out = student1.return_head();
    //     std::cout << "head_out: " << head_out << std::endl;
    //     std::cout << "head_out->id: " << head_out->id << std::endl; // xiao: 101， //david: 101
    // }
    // std::cout << "head_out: " << head_out << std::endl;
    // std::cout << "head_out->id: " << head_out->id << std::endl;

    // std::cout << "??????????????????????????" << std::endl;


    return 0;
}
