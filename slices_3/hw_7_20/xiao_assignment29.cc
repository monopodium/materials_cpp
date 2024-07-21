// slice 后面的部分，54页之后
//copy constructor: deep copy: 不能只拷贝指针，而是要先初始化新的string的空间，再让新的指针指向新的空间
//destructor: 及时销毁变量:出来的new string()
//operator= ： deep copy

//matrix: [[1,2,3],
//         [1,2,3]] 任意类型的矩阵, 例如int, double类型
//matrix: [[1.3,2.5,3.6],
//         [1.6,2.8,3.9]] 任意类型的矩阵 

//验证两种constructor的不同：
//第一种：
// IHazStringPtr(const IHazStringPtr & other): str(other.str)
// { 

// }
// //第二种：
// IHazStringPtr(const IHazStringPtr & other)
// { 
//     str = other.str2
// }

// g++ -o xiao_1 xiao_assignment29.cc
#include<iostream>  
using namespace std; 
#include<string>
#include <fstream>
#include <vector>
using std:: vector;

class IHazStringPtr 
{
private:
    string * str;
public:
    IHazStringPtr() : str(new string()) 
    {

    }
    void addCharacter(const char c) {str->push_back(c);}
    IHazStringPtr(const IHazStringPtr& p)
    {
        str = new string(*p.str);           //深拷贝
    }
    void printIt() const 
    { 
        cout << *str << endl; 
    }
    ~IHazStringPtr() 
    {
        delete str;
    }
};
//template
template<class T>
class Matrix
{
    private:
    vector<vector<T>> data;
    unsigned int M_row;
    unsigned int M_column;

    public:
    Matrix(unsigned int row,unsigned int column)
    {
        M_row = row;
        M_column = column;
        data.resize(M_row,vector<int>(M_column));
    }
    vector<T> & operator[](unsigned int index)
    {
        return data[index];
    }
    void Print_matrix()
    {
            for (int i = 0; i <  M_row; i++)
            {
            for (int j = 0; j < M_column; j++)
            {
                cout<<data[i][j]<<" ";
            }
            cout<<endl;
            }
        cout<<endl;
    }  
};
    //验证两种constructor的不同：
//第一种：

class myString
{
    public:
        myString(int n){
            std::cout << " default constructor for myString!" << std::endl;
        }
        myString(){
            std::cout << " default constructor for myString!" << std::endl;
        }
        myString(const myString &test){
            std::cout << " copy constructor for myString!" << std::endl;
        }
        myString& operator = (myString &other)
        {   
            cout<<"=号函数被运用了！"<<endl;
             return *this;;
        }
};
class Person
{
private:
    int M_age;
    myString M_name;
public:
    //写一个有参数的构造函数，
    //
    Person(int age, myString name)
    {
        M_age = age;
        M_name = name;
    }
    //
    // copy construtor 

    //syntex 
    // operation

    Person(const Person & other):M_name(other.M_name),M_age(other.M_age)
    {
        std::cout << "copy construtor of Person!" << std::endl;
    }
    Person(const Person & other,int n)
    {   
       this->M_age = M_age;
        this->M_name = M_name;  //operator=
        std::cout << "copy construtor_2 of Person!" << std::endl;
    }
    // Person(myString Name,int Age)
    // {
    //     M_age = Age;
    //     M_name = Name;
    // }
    // Person(const Person & other):
    // {
    //     cout<<"拷贝函数被运用了"<<endl;
    //     M_name = other.M_name;
    //     M_age = other.M_age
        
    // }
};

int main()
{
    //construtor
    myString m_1;
    Person p_1(18,m_1);
    cout<<"----------------"<<endl;
    //copy construtor
    Person p_2(p_1);
    cout<<"---------"<<endl;
    Person p_3(p_1,18);
    // IHazStringPtr a; 
    // IHazStringPtr b=a;  copy constructor

    // IHazStringPtr b;
    // b=a; operator =  

    // a.addCharacter('a');
    // b.addCharacter('b');


    // a.printIt();
    // b.printIt();

    // cout<<"template模版函数"<<endl;
    // Matrix<int> m_1(2,2);
    // m_1[0][0] = 4;
    // m_1[0][1] = 3;
    // m_1[1][0] = 2;
    // m_1[1][1] = 1;

    // m_1.Print_matrix();

    
    return 0;
}