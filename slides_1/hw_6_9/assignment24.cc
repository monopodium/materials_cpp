    //实现一个拷贝构造函数，让student2的books_list 里面的id和student1一样，但是用的是不同的空间。
    //也就是，student2链表的修改，不能够影响student1
    //自学一下 vector，把基础的操作都学会，定义一个长为10的Student的vector的数组。
    //尝试用不同的方法操作vector,  .push_back(), reverse(), 至少学会五个不同的vector的操作方法，代码验证，并且解释他们的含义。
#include<iostream>  
using namespace std; 
#include<string>
#include <fstream>
#include <vector>

struct BookNode
{
    int id;
    BookNode* next;
};

class Person
{
    public:
    Person(string name, int age, int book_number)
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
        for(int i=0;i<index && current != nullptr;i++)
        {
            current = current->next;
        }
        current ->id = id_input;
    }

    Person(const Person &p)
    {
        cout<<"这个是拷贝函数！！"<<endl;
        // old person: 1-> 2 -> 3- 4,  
        // new person: 3-> 4
        // 
        if(p.head == nullptr)
        {
            head = nullptr;
        }
        else
        {   
            head = new BookNode;
            head->id = p.head->next->next->id;

            BookNode *first = head;
            BookNode *tail = p.head->next->next->next;

            while(tail != nullptr)
            {
                first->next = new BookNode;
                first = first->next;
                first->id = tail->id;
                tail = tail->next;
            }
        }
        
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
    private:
        static int static_int;
        BookNode *head = nullptr;
        int M_age;
        string M_name;
};

void print_vector(vector<int>v1)
{

    for(vector<int>::iterator it = v1.begin();it != v1.end();it++)
    {
        cout<<*it<<endl;
    }

}

//[1,2]
//push_back(3)
//[1,2,3,x] size = 3 capacity = 4
// class vector{
//     private:
//         int *a;
//     public:
//     // resize(){
//     //     a = (int*)malloc(30 * sizeof(int));
//     // }
//         push_back(){

//         }
// };

int main()
{
    Person p1("xxy",18,10);
    p1.borrow_book(3,1000);
    p1.print_array();

    //0， 9
    //
    Person p2(p1);
    p2.borrow_book(4,200);
    p2.borrow_book(0,250); // 0 - 7 
    p2.borrow_book(1,550); // 1 - 8 
    p2.borrow_book(7,300);
    p2.print_array();

    p1.print_array();

    vector <int> v; //创建vector 
    cout <<"创建时的容量："<<v.capacity()<<endl;//判断容器的容量
    v.push_back(10);    //  尾插入
    cout <<"push_back第一次后的size："<<v.size()<<endl;//判断容器的容量
    cout <<"push_back第一次后的容量："<<v.capacity()<<endl;//判断容器的容量
    v.push_back(20);
    cout <<"push_back第二次后的size："<<v.size()<<endl;//判断容器的容量
    cout <<"push_back第二次时的容量："<<v.capacity()<<endl;//判断容器的容量    
    v.push_back(30);
    cout <<"push_back第三次后的size："<<v.size()<<endl;//判断容器的容量
    cout <<"push_back第三次后的容量："<<v.capacity()<<endl;//判断容器的容量

    cout<<"vector__1内的元素是"<<endl;
    print_vector(v);

    v.pop_back();       //尾部删除

    cout<<"vector__1内的元素是"<<endl;
    print_vector(v);

    cout<<"vector中的元素个数："<<endl;
    cout <<v.size()<<endl;  //查看vector内元素个数   

    cout<<"判断是否为空！！！"<<endl;
    cout <<v.empty()<<endl;

    cout<<"容器的容量为："<<endl;
    cout <<v.capacity()<<endl;//判断容器的容量

    vector<int>v2;
    v2.assign(v.begin(),v.end());
    cout<<"vector__2内的元素是"<<endl;
    print_vector(v2);

    cout<<"新的 vector__2内的元素是"<<endl;
    v2.insert(v2.begin(),2,1000);
    print_vector(v2);

    cout<<"vector——2为："<<endl;
    v2.clear();             //清空
    print_vector(v2);    

    return 0;
}
