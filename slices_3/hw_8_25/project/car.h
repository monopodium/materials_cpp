#include <iostream>

class Car {
    private:
        int speed;
        int weight;
    public:
        bool operator<(const Car &car) const {
            return speed < car.speed;
        }
        Car(int speed, int weight) : speed(speed), weight(weight) {
            std::cout << "constructor" << std::endl;
        }

        Car(const Car& other){
            speed = other.speed;
            weight = other.weight;
            std::cout << "copy constructor" << std::endl;
        }
        const int get_speed() const {
            return speed;
        }
        const int get_weight() const {
            return weight;
        }

        void set_speed(int speed) {
            this->speed = speed;
        }
        void set_weight(int weight) {
            this->weight = weight;
        }
        void print(){
            std::cout << "weight: " << weight << " speed: " << speed << std::endl;
        }
};

class LTBySpeed {
public:
    bool operator()(const Car & a, const Car & b) const {
        return (a.get_speed() < b.get_speed());
    }
};


class LTByWeight{
//待补充：按照 weight比较两个car
};