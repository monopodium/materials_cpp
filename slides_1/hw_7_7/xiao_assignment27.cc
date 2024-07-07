// 1. 在合适的位置加上const,明确每一个函数能够修改的范围，
// F.printMatrix ：这个函数里面不能做任何修改；
// slice: A two-part solution对于 <<的重载，都改成这个形式
// Which of these are legit 第十页： 敲一遍代码，然后再解释为什么合法或者不合法
//打印a和a的地址， 打印b和b的地址
// {}
// 验证一下：new string离开作用域里面它不会被自动销毁， string A 离开作用域里面它会被自动回收。
// 
#include<iostream>  
using namespace std; 
#include<string>
#include <fstream>
#include <vector>
using std:: vector;

class Coordinate
{
    private:
    int M_x;
    int M_Y;

    public:
    void Set_X(int x)
    {
        this ->M_x = x;
    }
    int get_x() const
    {
        return M_x;
    }
};
class Journey
{   
    private:
        Coordinate start;
    public:
        const Coordinate & getStart() const
        {
            return start;
        }
        Coordinate getStart1() const 
        {
            return start;
        }
        const Coordinate& getStart2() const 
        {
            return start;
        }

};
void printX(const Coordinate & in)     //通过在引用参数里面加入const，表示该函数保证不会修改传递的对象
{
    cout<<in.get_x()<<endl;      //因为前面声明了不会改变传递的对象，所以在前面get_X中加入了const
}

int main()
{
    Coordinate c1;
    c1.Set_X(100);

    printX(c1);

    Journey j_1;
    Coordinate a = j_1.getStart();
    const Journey const_j = j_1;
    const_j.getStart();

    Journey j_2;
    // Coordinate & b = j_2.getStart();

    Journey j_3;
    const Coordinate &c = j_3.getStart();

    Journey j_4;
    const Coordinate d = j_4.getStart();

    //slice10
    //wild pointer
    
    string * b_10 =nullptr; 
    string * b_20 = nullptr;
    //malloc //dynamic : run-time才知道我要分配什么样的空间
    vector<int>* pointer_a = NULL;
    vector<int>* pointer_b = NULL;
    //
    {
        string a_1("Hello");
        string * b_10 = &a_1;//&
        b_20 = new string("Hello");
        string c_1 = a_1;       //合法， string类有个复制构造函数
        vector<int> a(10, 0);
        std::cout << "a[3]:" << a[3] << std::endl;
        pointer_a = &a;
        pointer_b = new vector<int>(10, 0);

    }
    // b_20: dangling pointer 悬垂指针
    // cout<<"a ："<<*b_20<<endl;
    // cout<<"b ："<<*b_10<<endl;
    std::cout <<"(*pointer_a)[3]  "<< (*pointer_a)[3] << std::endl;
    std::cout << "(*pointer_b)[3]  "<<(*pointer_b)[3] << std::endl;
    delete b_20;
    //

    return 0;
}