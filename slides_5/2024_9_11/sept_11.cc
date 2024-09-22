#include <iostream>
#include <string>


class Person {
private:
    std::string name;
    int age;
    std::string id;

public:
    
    void set_name(const std::string&  n) { name = n; }
    void set_age(int a) { age = a; }
    void set_id( std::string  i) { id = i; }
    Person(std::string n,int a,std::string i){
        this->name=n;
        this->age=a;
        this->id=i;
    }

    
    std::string get_name()  { return name; }
    int get_age() { return age; }
    std::string get_id()  { return id; }

    
     void print_details()  {
        std::cout << "Name: " << name << std::endl;
        std::cout << "Age: " << age << std::endl;
        std::cout << "ID: " << id <<std::endl;
    }
    Person() = default;
    Person(Student& input){
        this->name = input.get_name();
        this->age = input.get_age();
        this->id = input.get_id();
    }
  
};


class Student : public Person {
private:
    std::string student_id;
    std::string major;

public:

    Student(std::string name, int age, std::string id, std::string student_id, std::string major):Person(name, age, id)
    {
        this->student_id = student_id;
        this->major = major;
    }
    Student(Person& obj,std::string student_id,std::string major):Person(obj){
        this->student_id = student_id;
        this->major = major;
    }
    void set_student_id( std::string  m) { student_id = m; }
    void set_major( std::string  j) { major = j; }

    
    std::string get_student_id()  { return student_id; }
    std::string get_major()  { return major; }


   void print_details() {
        Person::print_details(); 
        std::cout << " Student ID: " << student_id <<std::endl;
        std::cout<< " Major: " << major << std::endl;
    }

};


class Teacher : public Person {
private:
    std::string employee_id;
    std::string department;

public:
    
    void set_employee_id( std::string  i) { employee_id = i; }
    void set_department( std::string  d) { department = d; }

    
    std::string get_employee_id()  { return employee_id; }
    std::string get_department()  { return department; }

    
    void print_details()  {
        Person::print_details();  
        std::cout << "Employee ID: " << employee_id << std::endl;
        std::cout << "Department: " << department << std::endl;
    }
};

int main() {
    
    Person person;
    person.set_name("xxy");
    person.set_age(18);
    person.set_id("1234567");
    person.print_details();

    std::cout <<"-------"<<std::endl;

    
    Student student;
    student.set_name("Bob");
    student.set_age(20);
    student.set_id("1234568");
    student.set_student_id("S001");
    student.set_major("Computer Science");
    student.print_details();
    student.Person::print_details();
    
    std::cout <<"-------"<<std::endl;
    Teacher teacher;
    teacher.set_name("david");
    teacher.set_age(22);
    teacher.set_id("1234569");
    teacher.set_employee_id("S002");
    teacher.set_department("Economic");
    teacher.print_details();
    std::cout <<"-------"<<std::endl;

    Person person2(student);
    return 0;
}
