#include <iostream>
#include <vector>



class Coordinate {
protected: //Access specifier sections
    int x;
    int y;
public:
    void Set(int x_in){
        x = x_in;
    }
    int getX() const{ //放在函数头和函数体之间的const意味着不允许在这个函数里修改class的成员变量
        return x;
    }
    Coordinate(int xIn, int yIn) : x(xIn), y(yIn)
    { // Initialisation syntax constructor
    }
    void operator=(Coordinate other) {
        std::cout<< "reload operator ="<<std::endl;
        x = other.x;
        y = other.y;
    }
    Coordinate(const Coordinate &coor){
        std::cout << "copy constructor!" << std::endl;
    }
};
class Journey {
protected:
    Coordinate start;
    Coordinate end;
public:

    const Coordinate& getStart(){
        return start;
    }
    void setStart(int x_in){
        start.Set(x_in);
    }
    Journey(Coordinate startIn, Coordinate endIn): start(startIn), end(endIn) {

    }
};
//static int 
//
// alias: 定义的时候一定要被初始化
// 一旦指向一个变量就不能被指向其他的
void printX(Coordinate & in) {
     //Coordinate b(4,-3);
     //in = b; // ???
     std::cout << in.getX() << std::endl;
}
int main(){
    Coordinate a(4,-3);
    printX(a);//what is passed to the function
    Coordinate b(2, 3);
    Journey journey_1(a, b);
    std::cout << "-----------" << std::endl;
    //journey_1.getStart().Set(10);

    Coordinate cc = journey_1.getStart();
    Coordinate& cc1 = journey_1.getStart();
    const Coordinate& c = journey_1.getStart();
    //c.Set(10);
    std::cout << journey_1.getStart().getX() << std::endl;
    // c.Set(10);
}