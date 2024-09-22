#include <iostream>
#include <memory>
#include <vector>
// dynamic_cast : 用于将基类的指针或引用安全地转换为派生类的指针或引用。
//  const_cast : 用于删除 const、volatile 特性。
//  static_cast: 用于基本类型之间的转换，例如 int 转换为 double，指针之间的转换，例如基类指针转换为派生类指针以及 void 指针转换为其他类型指针。
//  reinterpret_cast:  for inherently risky type casts, such as casting a pointer to an integer or vice versa.
// 记录了类型转换的原因，并让编译器有机会检查您是否按自己的想法进行了类型转换。
//

class Coordinate
{
public:
    int x;
    int y;
    int z;
    Coordinate(int xIn, int yIn) : x(xIn), y(yIn) {}
    virtual void printDetails()
    {
        std::cout << "Coordinate: ";
        std::cout << x << "," << y << std::endl;
    }
    // virtual void test() = 0;
};

class Bikes : public Coordinate
{
public:
    int howMany;
    Bikes(const int xIn, const int yIn, // member initializer list syntax
          const int howManyIn) : Coordinate(xIn, yIn), howMany(howManyIn)
    {
        std::cout << "Bikes constructor" << std::endl;
    };
    Bikes(const int howManyIn, const Coordinate &c)
        : Coordinate(c),
          howMany(howManyIn) {
          };

    virtual void test() {
        std::cout << "Bikes test" << std::endl;
    }
    virtual void printDetails() override
    { // 子类里面调用父类的函数， 通过::来调用
        std::cout << "Bikes: ";
        Coordinate::printDetails();
        std::cout << " " << howMany << std::endl;
    }
    virtual ~Bikes()
    {
        std::cout << "Bikes destructor" << std::endl;
    }
};

class ClassTest{

};

void change(const int *pt, int n)
{
    // (*pt) += n;
    int *pc;
    pc = const_cast<int *>(pt);
    *pc += n;
}
int main()
{
    Coordinate *c = new Coordinate(13, 2);
    Bikes *b = new Bikes(100, 2, 3);
    Coordinate *c1 = new Coordinate(11, 2);
    Bikes *b1 = new Bikes(133, 266, 31);
    Coordinate *c2 = new Coordinate(12, 2);
    Bikes *b2 = new Bikes(1111, 262, 3);

    std::cout<< *((int64_t *)c)<<std::endl;
    std::cout<< *((int64_t *)b)<<std::endl;
    std::cout<< *((int64_t *)c1)<<std::endl;
    std::cout<< *((int64_t *)b1)<<std::endl;
    std::cout<< *((int64_t *)c2)<<std::endl;
    std::cout<< *((int64_t *)b2)<<std::endl;
//     需要虚表（vtable）：
// Caveat: can only use it if there is a vtable：这个提醒表示，dynamic_cast只能用于包含虚函数的类，因为只有带有虚函数的类才会有虚表（vtable）。虚表是用于实现运行时多态性的，dynamic_cast依赖于它来进行类型检查。
// 至少需要一个虚函数：
// i.e. there is at least one virtual function：为了确保类有虚表，类中至少需要有一个虚函数。如果没有虚函数，编译器不会为该类生成虚表，而dynamic_cast就无法工作。
    // Bikes b(1, 2, 3);
    // Coordinate *c = &b;
    // Bikes *b2 = dynamic_cast<Bikes *>(c);
    // if (b2)
    // {
    //     std::cout << "dynamic_cast success" << std::endl;
    // }
    // else
    // {
    //     std::cout << "dynamic_cast failed" << std::endl;
    // }

    // std::cout << "=====================" << std::endl;
    // Coordinate *c2 = new Coordinate(1, 2);  //父
    // std::cout<<"请选择类型："<<std::endl;
    // std::cout<<"1. Bikes 2.Coordinate"<<std::endl;
    // int type = 0;
    // std::cin >> type;
    // if(type == 1){
    //     c2 = new Bikes(1, 2, 3); //子
    // }else{
    //     c2 = new Coordinate(1, 2); //父
    // }
    // //
    // Bikes *b3 = dynamic_cast<Bikes *>(c2); // 
    // if (b3)
    // {
    //     std::cout << "dynamic_cast success" << std::endl;
    // }
    // else
    // {
    //     std::cout << "dynamic_cast failed" << std::endl;
    // }

    // std::cout << "=====================" << std::endl;


    // volatile int a = 10; // volatile: 用于告诉编译器不要对这个变量进行优化
    // int b = a + 1;       // 

    // load a into register     
    // a = 10
    
    // load b into register
    // b = a + 1
    // store b into memory  
    // store a into memory

    // 在C++中，volatile关键字用于告诉编译器某个变量的值可能在程序的控制之外发生变化，因此编译器不应对该变量进行优化。这在某些特定场景下很重要，例如当变量的值可能由外部硬件或其他并发线程修改时
    // const Bikes *c3 = new Bikes(1, 2, 3);

    // auto b4 = const_cast<Bikes *>(c3); // 大部分不变，少部分变化的情况下使用const_cast
    // b4->x = 10;
    // auto b5 = c3;
    // // b5->x = 20;

    // int pop1 = 38383;
    // const int pop2 = 2000;
    // std::cout << "pop1, pop2: " << pop1 << ", " << pop2 << std::endl;
    // change(&pop1, -103); //david: 预测一下对pop1的修改
    // change(&pop2, -103); //xiao: 预测一下对pop2的修改
    // std::cout << "pop1, pop2: " << pop1 << ", " << pop2 << std::endl;
    
    // std::cout << "=====================" << std::endl;
    // Bikes b6(1, 2, 3);
    // int* c = (int*)(&b6);
    // Coordinate *c4 = static_cast<Coordinate*>(&b6);

    // Coordinate test(1, 2);
    // Bikes *b7 = static_cast<Bikes*>(&test);
    // b7->howMany = 10;
    // b7->printDetails();

    // b7->test();
    // std::cout << "=====================" << std::endl;
    // int test = 3;
    // struct dat {int a; short b;};
    // long value = 0xA224B118; // not be portable!!!!
    // // Big Endian: 0xA224B118
    // dat *pd = reinterpret_cast<dat *>(&value);
    // std::cout << std::hex << pd->a<<std::endl; // display first 2 bytes of value
    // std::cout << std::hex << pd->b<<std::endl; 
    return 0;
}