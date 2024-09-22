    #include<iostream>  
    using namespace std; 
    #include<string>
    #include <fstream>
    #include <vector>
    #include <list>
    #include<stdio.h>

//定义一个base class : 叫做persion,
//有成员变量：private： 姓名，年龄，身份证号，
//public:有set_name和get_name函数,set_age和get_age函数，set_id和get_id函数  
//public:有一个print_details函数，打印出姓名，年龄，身份证号

//定义一个derived class : 叫做student
//继承自base class
//有成员变量：private：学号, 专业
//override base class的print_details函数，打印出姓名，年龄，身份证号，学号，专业: 

//定义一个derived class : 叫做teacher
//继承自base class
//有成员变量：private：工号，院系
//override base class的print_details函数，打印出姓名，年龄，身份证号，工号，院系: 

//证明private和protected的区别

//在main函数里面测试所有的函数，
//定义一个persons的对象，调用所有的函数, 
//  定义一个student的对象，调用所有的函数: print_details函数要调用两个版本：基类的版本，和派生类的版本
// 对于teacher的对象，也是调用所有的函数
//证明 一个base class的对象可以通过一个devired class来构造
class Person
{   
    protected:
        string M_name;
        int M_age;
        long M_id_card;
    
    public:
        Person(string name, int age, long id)
        {
            this->M_name = name;
            this->M_age = age;
            this->M_id_card = id;

        }
        void set_name(string name)
        {
            this->M_name = name;
        }
        string get_name()
        {
            return M_name;
        }

        void set_age(int age)
        {
            this->M_age = age;
        }
        int get_age()
        {
            return M_age;
        }

        void set_id(long id)
        {
            this->M_id_card = id;
        }
        long get_id()
        {
            return M_id_card;
        }

        void print_person()
        {
            cout<<"姓名： "<<M_name<<endl;
            cout<<"年龄：  "<<M_age<<endl;
            cout<<"id_card:  "<<M_id_card<<endl;
            
        }

};
class Student:public Person
{
    private:
    int student_code;
    string M_subject;

    public:
        Student(long code,string subject,string M_name,int  M_age,int M_id_card):Person(M_name, M_age, M_id_card)
        {
            this->student_code = code;
            this->M_subject = subject;
        }

        void print_person()
        {
            cout<<"姓名： "<<M_name<<endl;
            cout<<"年龄：  "<<M_age<<endl;
            cout<<"id_card:  "<<M_id_card<<endl;
            cout<<"学生学科：  "<<M_subject<<endl;
            cout<<"code: "<<student_code<<endl;      
        }

};
class Teacher:public Person
{
    private:
    long M_code;
    string faculty;

    public:
    Teacher(long code,string faculty,string M_name,int  M_age,int M_id_card):Person(M_name, M_age, M_id_card)
    {
        this->faculty = faculty;
        this->M_code  = code;
    }
    void print_person()
    {
        cout<<"姓名： "<<M_name<<endl;
        cout<<"年龄：  "<<M_age<<endl;
        cout<<"id_card:  "<<M_id_card<<endl;
        cout<<"老师院系：  "<<faculty<<endl;
        cout<<"code: "<<M_code<<endl;      
    }

};




int main()
{
    // Person P_1 ;
    // P_1.set_name("david");
    // P_1.set_age(22);
    // P_1.set_id(32020010000);

    // P_1.print_person();
    cout<<"学生s_1:   "<<endl;
    Student s_1( 31011020030616,"数学","xxy",22,31011020);
    // s_1.set_name("xxy");
    // s_1.set_age(22);
    // s_1.set_id(31011020030616); 

    s_1.Student::print_person();
    cout<<endl;
    cout<<"父类：   "<<endl;
    s_1.Person::print_person();

    cout<<endl;

    cout<<"老师t_1:   "<<endl;
    Teacher t_1(101010,"计算机科学","mashuang",25,20030108);
    t_1.set_name("mashuang");
    t_1.set_age(25);
    t_1.set_id(20030108193); 

    t_1.print_person();

    return 0;
}