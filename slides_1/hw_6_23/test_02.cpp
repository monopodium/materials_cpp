#include <iostream>
#include <vector>
using namespace std; 

class Coordinate 
{
    public:
    Coordinate()
    {
    std::cout << "调用了一遍构造函数!" << std::endl;
    }

};

class Journey {
protected:
    Coordinate start;
    Coordinate end;
public:
    // 1.复制一遍我们的 startIn，endIn：调用我们的copy constructor
    Journey(Coordinate startIn, Coordinate endIn) {
    //2. 初始化我们的 start，end：调用我们的默认构造函数 ：default constructor
        std::cout << "in the Journey constructor!" << std::endl;
    //3. 调用 = 将 start和end赋值
        start = startIn;
        end = endIn;
    }
    
    Journey(Coordinate startIn, Coordinate endIn,int n): start(startIn), end(endIn) {

    }

};

int main()
{   
    
    Coordinate x1;
    std::cout << "运行到 flag 1" << std::endl;
    Coordinate x2;
    std::cout << "运行到 flag 2" << std::endl;
    int n =0;
    
    
    Journey j1(x1,x2);
    std::cout << "运行到 flag 3" << std::endl;
    Journey j2(x1,x2,n);


}