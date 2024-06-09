#include <iostream>
#include <vector>

class Coordinate {
protected: //Access specifier sections
    int x;
    int y;
public:
    Coordinate(){
        std::cout << "default constructor!" << std::endl;
    }
    Coordinate(int xIn, int yIn) : x(xIn), y(yIn) { //Initialisation syntax constructor
    }
    Coordinate operator+(Coordinate other) {
        std::cout<< "reload operator +"<<std::endl;
        return Coordinate(x + other.x, y + other.y);
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
    // Journey(Coordinate startIn, Coordinate endIn) {
    //     std::cout << "in the Journey constructor!" << std::endl;
    //     start = startIn;
    //     end = endIn;
    // }
    Journey(Coordinate startIn, Coordinate endIn): start(startIn), end(endIn) {
    }
};
int main(){
    //default constructor : no parameters
    //constructor defined by ourself


    
    Coordinate a(4,-3);
    Coordinate b(2,3);
    b = a;
    // std::cout << "------" << std::endl;
    // Journey jounrney_1(a, b);
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