#include<iostream>  
#include<string>
#include <fstream>

using namespace std; 
class Car {
protected:
    double speed;
    double range;
public:
    Car(double s, double r) : speed(s), range(r) {}
    bool operator<(const Car & other) const {
        return (speed < other.speed);
    }
    double getRange() const {
        return range;
    }
    double getSpeed() const {
        return speed;
    }
};

template<typename T, typename Comp>
const T & my_max(const T & a, const T & b, Comp comp) {
    if (comp(a,b)) {
        return b;
    } else {
        return a;
    }
}
class LTByRange {
public:
    bool operator()(const Car & a, const Car & b) const {
        return (a.getRange() < b.getRange());
    }
};
int main(){
    Car a(120,300);
    Car b(100,400);
    Car highestRange = my_max(a,b,LTByRange() );
    cout << "The car with the highest range is: " << highestRange.getRange() << endl;
    
    return 0;
}
