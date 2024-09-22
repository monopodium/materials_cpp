#include <iostream>
using namespace std;
#include <string>
#include <fstream>
#include <vector>
#include <list>
#include <stdio.h>
// 作业：把person变成abstract class
//  teacher都继承自person
//  president继承自teacher, president去override print_details
//  teacher is a person, president is a teacher
// class-oriented
//  multimorphic : 多态
// 前序+中序+后序 遍历一个tree

class Person
{
protected:
    string M_name;
    int M_age;
    long M_id_card;

public:

    Person(string name,int age,const long& id)
    {
        M_name = name;
        M_age = age;
        M_id_card = id;
    }
    Person()
    {

    }
    virtual void set_name(string name) = 0;

    virtual string get_name() = 0;

    virtual void set_age(int age) = 0;

    virtual int get_age() = 0;

    virtual void set_id(long id) = 0;

    virtual long get_id() = 0;

    virtual void print_person() = 0;
};

class Teacher : public Person
{
private:
    long M_code;
    string faculty;

public:
    Teacher(string name,int age,long id,long code, string faculty):Person(name,age,id)
    {
        this->faculty = faculty;
        this->M_code = code;
    }
    Teacher()
    {
    }

    void set_name(string name) override
    {
        this->M_name = name;
    }
    string get_name() override
    {
        return M_name;
    }

    void set_age(int age) override
    {
        this->M_age = age;
    }
    int get_age() override
    {
        return M_age;
    }

    void set_id(long id) override
    {
        this->M_id_card = id;
    }
    long get_id() override
    {
        return M_id_card;
    }

    void print_person() override
    {
        cout << "姓名： " << M_name << endl;
        cout << "年龄：  " << M_age << endl;
        cout << "id_card:  " << M_id_card << endl;
        cout << "faculty: 学科" << faculty << endl;
        cout << "code: " << M_code << endl;
    }
};
class president : public Teacher
{
private:
    string president_name;

public:
    president(string name)
    {
        president_name = name;
    }
    void print_person() override
    {
        cout << "总统的姓名是：" << president_name << endl;
    }
};

int main()
{
    // & 
    // name, age, id, student_id, major
    Teacher t_1("mashuang",18,20021301841,101010, "数学"); // 

    t_1.print_person();

    president p_1("川普");
    p_1.print_person();

    return 0;
}