#include <iostream>
#include <vector>
using namespace std;
// 加法 乘法
//   n*n
// class matrix {
//  matrix(n*m)
//   重载运算符进行赋值操作[][]
//  重载运算符进行加法和乘法操作
// 重载<<的运算符
// }
//
//  matrix a;
// a[1][2] = 1;
// matrix b;
// 
// matrix c = a*b;
// cout<<c

class Coordinate {
public: //Access specifier sections
    std::string name;
    int x;
    int y;
public:
    Coordinate(){
        std::cout << "coordinate default constructor!" << std::endl;
    }
    Coordinate(std::string nameIn, int xIn, int yIn) : name(nameIn),x(xIn), y(yIn) { //Initialisation syntax constructor
        cout<<"---------"<<endl;
    }
   
    Coordinate(const Coordinate &coor){
        std::cout << "copy constructor!" << std::endl;
    }
    // a > b
    bool operator >(Coordinate &other){
        std::cout << "name: " <<name<< std::endl;
        std::cout << "other.name: " <<other.name<< std::endl;
        std::cout << "x: " <<x<< std::endl;
        std::cout << "other.x: " <<other.x<< std::endl;
        std::cout << "y: " <<y<< std::endl;
        std::cout << "other.y: " <<other.y<< std::endl;
        std::cout << " reload of operator >" << std::endl;
        bool result = x > other.x;
        return result;
    }
    bool operator ==(Coordinate &other){
        return (x == other.x && y == other.y);
    }
    // void operator =(Coordinate other){
    //     std::cout << "reload of =" << std::endl;
    //     x = other.x;
    //     y = other.y;
    // }
};
class Journey {
public:
    Coordinate start;
    Coordinate end;
public:
//overload: 可以声明两个函数，名字一样，参数列表不一样
//但是不能声明两个函数，函数名字和参数列表都一样


    // 1.复制一遍我们的 startIn，endIn：调用我们的copy constructor
    //2. 初始化我们的 start，end：调用我们的默认构造函数 ：default constructor
    //3. 调用 = 将 start和end赋值

    Journey(Coordinate &startIn, Coordinate &endIn) {
        std::cout << "in the Journey constructor!" << std::endl;
        start = startIn;
        end = endIn;
    }
    
    //1.复制一遍我们的 startIn，endIn：调用我们的copy constructor
    //2.直接执行拷贝构造函数，start， end
    Journey(Coordinate startIn, Coordinate endIn, int n): start(startIn), end(endIn) {
    }
    void Print(){
        std::cout << start.x << std::endl;
    }
    Coordinate& getStart(){
        return start;
    }

};
std::ostream & operator<<(ostream& o1, const Journey &Journey1)
{
    o1 << "start x: " << Journey1.start.x << "start y: "<< Journey1.start.x << "";
    return o1;
}
int main(){
    
    Coordinate a("a",1,2);
    Coordinate b("b",3, 4);
     
    // > 
    //bool operator >(Coordinate &other)
    // if(a>b){
    //     std::cout << "a>b" << endl;
    // }{
    //     std::cout << "a<=b" << endl;
    // }
    
    Journey j_1(a, b);
    std::cout <<"It is:"<< j_1<<" "<< j_1  << std::endl;
    
    std::cout << "flag!" << std::endl;
    b = j_1.getStart();
    // std::cout << a << std::endl;
    //  string a;

    //把a,b复制一份作为参数传递进去，copy constructor
    //
}