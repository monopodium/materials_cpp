#include<iostream>
#include<memory>
#include<vector>
//Inherit
//Inheritance

// 作业：把person变成abstract class
//  teacher都继承自person
//  president继承自teacher, president去override print_details
//  teacher is a person, president is a teacher
// class-oriented
//  multimorphic : 多态
// 前序 遍历一个tree

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







// base class : 基类
class Coordinate {
// private:   // 不能被public派生类访问, 也不能被外部访问
//     int x;
//     int y;

// protected: // 可以被public派生类访问，但是不能被外部访问
//     int z;
// // constructor :自己定义的
// copy constructor : 编译器自动生成的
public:
    int x;
    int y;
    int z;
    Coordinate(int xIn, int yIn) : x(xIn), y(yIn) {}
    virtual void printDetails() {
        std::cout << "Coordinate: ";
        std::cout << x << "," << y<<std::endl;
    }
    // virtual void test() = 0;
};
//multimorphic
// derived class : 派生类 
//public 原本基类里面private的变量，派生类里面是不能直接访问的，但是可以通过基类的public function来访问
// 
class Bikes : public Coordinate {
// private:
//     int howMany;  
public:
    int howMany;  
//先去调用base class的constructor, 也就是Coordinate的constructor
//然后再调用Bikes的constructor
    Bikes(const int xIn, const int yIn, //member initializer list syntax
          const int howManyIn): Coordinate(xIn, yIn), howMany(howManyIn) 
    {
        std::cout << "Bikes constructor" << std::endl;
    };
    Bikes(const int howManyIn, const Coordinate & c)
        : Coordinate(c),
          howMany(howManyIn) {
    };

    virtual void printDetails() override { //子类里面调用父类的函数， 通过::来调用
        std::cout << "Bikes: ";
        Coordinate::printDetails();
        std::cout << " " << howMany<<std::endl;
    }
    virtual ~Bikes() {
        std::cout << "Bikes destructor" << std::endl;
    }
    // virtual void test() override {
    //     std::cout << "Bikes test" << std::endl;
    // }
};
void someFunction(Coordinate & c) {
    c.printDetails();
    std::cout << std::endl;
}
// public继承，derived class可以访问base class的public成员
// is-a relationship
// public继承，derived class要访问base class的private变量，需要通过base class的public function
//derived class在初始化的时候，会先调用base class的constructor，然后再调用derived class的constructor
//default constructor
//member initializer list syntax
// derived class有同名的函数，会override base class的函数
//如果想要调用base class的函数，可以通过::来调用
//指向base class的指针可以指向derived class的object. 但是反过来不行


//virtual function: base class中的function可以被derived class override

int main() {
    double d = 3.14;

    //普通指针：
    //Coordinate * c = new Bikes(3,4,5);
    // std::vector<Coordinate> test;
    // Coordinate c1(1, 2);
    // test.push_back(c1);
    // test.emplace_back(3, 4);

    // std::vector<std::unique_ptr<Coordinate>> v;
    // Coordinate c(1, 2);
    // v.push_back(std::make_unique<Coordinate>(&c));
    // Bikes b(1, 2, 3);
    // v.emplace_back(&b);

    // for(auto & c : v)
    // {
    //     (*c).printDetails();
    // }
    // 3*4 + 5 = 17
    // -> . & *  !
    // * / + -
    // 3*4 + 5
    Coordinate c(3,4);
    //c.printDetails();
    //
    // 32 
    //
    std::cout<<"size of Coordinate:"<< sizeof(c)<<std::endl;
    std::cout<<"address of c:    "<< &c<<std::endl;
    std::cout<<"address of c.x:  "<< &c.x<<std::endl;
    std::cout<<"address of c,y:  "<< &c.y<<std::endl;
    std::cout<<"address of c,z:  "<< &c.z<<std::endl;

    Bikes b(3,4,5);
    // std::cout << "----------------" << std::endl;
    // //b.printDetails();
    someFunction(b);
    // Coordinate* cc = new Bikes(3,4,5);
    // std::unique_ptr<Coordinate> cc(new Bikes(3,4,1));
    // c = b;
    // b = c;
    //  b.test();
    //  b.Coordinate::test(3);
    //  Coordinate * cPtr = &b;
    //  cPtr->printDetails();
    //  cPtr->test(3);
}
