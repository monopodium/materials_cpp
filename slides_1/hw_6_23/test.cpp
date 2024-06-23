#include<iostream>  
#include<string>
#include <fstream>
#include <vector>
using std:: vector;
using namespace std;

//constructor
// (int age)
//
class xxy{
    public:
        int A;
        int B;
        // xxy()
        // {
        //     std::cout << "default constructor!" << std::endl;
        // }
        xxy(int Age_m):age(Age_m)
        { 
        }

    
    private:
        int C;
        int D;
        int age;
};

 
int main()
{
    //vector<xxy> vector_xxy(10); 
    vector<xxy> vector_xxy;
    vector_xxy.push_back(xxy(22));
    return 0;
}
