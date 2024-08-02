#include <iostream>
#include <string>
using namespace std; 


class Verify{
public:
    Verify(){
        std::cout << "default constructor invoked!" << std::endl;
    }
    Verify(const Verify & other){
        std::cout << "copy constructorr invoked!" << std::endl;
    }   

    Verify& operator=(const Verify &other){
        cout << "--------" << endl;
        return *this;
    }
};
class Person
{

private:
    string M_name;
    int M_age;
    Verify v_test;

public:    
    Person(const string& name, int age) : M_name(name), M_age(age) {
        std::cout <<"初始化" << std::endl;
    }

    
   Person(const Person & other):M_name(other.M_name),M_age(other.M_age),v_test(other.v_test) // 调用了string的拷贝构造函数
    {
        std::cout << "copy construtor of Person!" << std::endl;
    }
    Person(const Person & other,int n)
    {   
       this->M_age =other.M_age; // 先调用string的构造函数，再调用赋值函数
        this->M_name =other.M_name;
        this->v_test = other.v_test;
        std::cout << "copy construtor_2 of Person!" << std::endl;
    }

    
    void print() const {
        std::cout << "Name: " << M_name << ", Age: " << M_age << std::endl;
    }
};

int main() {
    Person person1("xxy", 30);
    person1.print();
    
    // Person person2(person1);  
    // person2.print();
    
    Person person3(person1, 42);  
    person3.print();
    
    return 0;
}

    