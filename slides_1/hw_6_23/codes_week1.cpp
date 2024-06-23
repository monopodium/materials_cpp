#include <iostream>
#include <vector>



class Coordinate {
protected: //Access specifier sections
    int x;
    int y;
public:
    // Coordinate(){
    //     std::cout << "default constructor!" << std::endl;
    // }
    Coordinate(int xIn, int yIn) : x(xIn), y(yIn) { //Initialisation syntax constructor
    }
    Coordinate operator+(Coordinate other) {
        std::cout<< "reload operator +"<<std::endl;
        return Coordinate(x + other.x, y + other.y);
    }
    // void operator=(Coordinate other) {
    //     std::cout<< "reload operator ="<<std::endl;
    //     x = other.x;
    //     y = other.y;
    // }
    Coordinate(const Coordinate &coor){
        std::cout << "copy constructor!" << std::endl;
    }
    void test1(){
        std::cout << this->x << std::endl;
    }
    void test2() const{
        std::cout << this->x << std::endl;
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
    
    //1.复制一遍我们的 startIn，endIn：调用我们的copy constructor
    //2.直接执行拷贝构造函数，start， end
    Journey(Coordinate startIn, Coordinate endIn): start(startIn), end(endIn) {

    }
};
void test(Coordinate a){

}
int main(){
    //default constructor : no parameters
    //constructor defined by ourself

    std::vector<int> coords1(2);
    std::vector<Coordinate> coords(2);
    Coordinate a(4,-3);
    Coordinate b(2,3);
    // b = a;
    // test(b);
    // b.test2();
    // if(a <b){
    //     std::cout << "????????" << std::endl;
    // }
    // std::cout << "------" << std::endl;
    Journey journey_1(a, b);
    // if(a==b){
    //     std::cout << "a==b!" << std::endl;
    // }

    // std::cout << a.getX() << std::endl;
    // std::cout << b.getX() << std::endl;

    // a.setX(8);
    // cout << a.getX() << endl;
    // cout << b.getX() << endl;
    // Coordinate a(4,-3); //Create Coordinate a; constructor gets (4,-3)
    // Coordinate b = a;
    //Create Coordinate b, using an automatically generated copy
    //constructor that copies whatever the member variable are in a
    //Can write our own too (will explain later)
    // Coordinate b; //This won’t compile, Looks for the default constructorCoordinate()
    // std::vector<Coordinate> coords(2); //Implicit default constructor calls
    // coords[0] = Coordinate(4,-2); //  Line {1}: make a vector of size 2. Use the default constructor for each Coordinate.
    //Only works if there is a defaultconstructor!
    //Line {2}, {3}: replace the coordinates in the vectors with these ones anyway

    //Alternatively:
    // std::vector<Coordinate> coords;//Line 1: make an empty vector (size0)
    // coords.push_back(Coordinate(4,-2)); //Line 2: add an extra Coordinate to the vector (size now 1)
    // coords.push_back(Coordinate(3,17));//Line 3: add another (size now 2)
}