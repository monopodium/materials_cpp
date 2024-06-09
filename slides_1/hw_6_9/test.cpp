#include <fstream>
#include <iostream>
#include <vector>
class Coordinate {
protected:
    int x;
    int y;
public:
//自己不去定义一个constructor,
    Coordinate(int xIn, int yIn) : x(xIn), y(yIn){};
    Coordinate(){};
};

int func(std::vector<int> a, std::vector<int> b){
    //

    //std::cout<<"i"...
    return -1;
}
int main() {
    Coordinate a(4,2);
    Coordinate b;
}
//知识点：
//1. slices里面的 jagged 2-d vector部分的代码跑通，
// 用vector的二维数组去实现矩阵的＋和×， 两个n*n的矩阵相乘，n是可变的
// 跑通slices 20页之前的所有例子，弄明白每一句英文的含义

//逻辑：
//vector实现这样的功能，抽象为一个函数
// a = [1,2,3,4,5], b = [1,2,37,8]    target = 38
// 因为 a[0] + b[2] == target, 所以返回 0，2
//如果不存在 a[i] + b[j] == target,就返回-1 
