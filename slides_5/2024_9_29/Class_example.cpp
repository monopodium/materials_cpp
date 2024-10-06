#include <iostream>
#include <memory>
#include <vector>
class Coordinate
{
public:
    int x;
    int y;
    Coordinate(int xIn, int yIn) : x(xIn), y(yIn) {}
    virtual void printDetails()
    {
        std::cout << "Coordinate: ";
        std::cout << x << "," << y << std::endl;
    }
};

class StreetAddress
{
protected:
    std::string postcode;
    int number;

public:
    StreetAddress(const std::string &pc, const int n)
        : postcode(pc), number(n) {};
};
class Bikes : public Coordinate, public StreetAddress
{
protected:
    int howMany;

public:
    Bikes(const int xIn, const int yIn,
          const std::string &pc, const int n,
          const int howManyIn)
        : Coordinate(xIn, yIn),
          StreetAddress(pc, n), howMany(howManyIn)
    {
    }
    virtual void printDetails()
    {
        std::cout << "Bikes: ";
        std::cout << x << "," << y << std::endl;
    }
};
void someFunction(StreetAddress * a) {
// b is 8 bytes before a
    // Bikes * b = static_cast<Bikes*>(a);
    Bikes * b = (Bikes*)(a);
    std::cout << b << std::endl;
    b->printDetails();
}
void someFunction(Coordinate * a) {
// b is 8 bytes before a
    // Bikes * b = static_cast<Bikes*>(a);
    Bikes * b = (Bikes*)(a);
    std::cout << b << std::endl;
     //static_cast只会在编译的时候检查，如果运行的时候发现没有对应的函数，就糟糕了
    b->printDetails();
}
int main()
{
   
    Bikes *b = new Bikes(1, 2, "12345", 3, 4);
    std::cout << b << std::endl; // prints the pointer
    Coordinate *c = b; // the start of b
    std::cout << c << std::endl;
    StreetAddress *a = b; // 8 bytes into b
    std::cout << a << std::endl;
    std::cout << "==========================" << std::endl;
    Coordinate *b1 = new Coordinate(1, 2);
    someFunction(b1);
}