//知识点：
//1. slices里面的 jagged 2-d vector部分的代码跑通，
// 用vector的二维数组去实现矩阵的＋和×， 两个n*n的矩阵相乘，n是可变的
// 跑通slices 20页之前的所有例子，弄明白每一句英文的含义

//逻辑：
//vector实现这样的功能，抽象为一个函数
// a = [1,2,3,4,5], b = [1,2,37,8]    target = 38
// 因为 a[0] + b[2] == target, 所以返回 0，2
//如果不存在 a[i] + b[j] == target,就返回-1 
#include<iostream>  
using namespace std; 
#include<string>
#include <fstream>
#include <vector>
using std:: vector;

void printVector(vector<int> v1)
{
    for(vector<int>::iterator it = v1.begin();it != v1.end();it++)
    {
        cout<<*it<<" ";
    }
    cout<<endl;
}
void two_dimensional_array(vector<vector<int>> v2)
{
    for (int i = 0; i < v2.size(); i++)
   {
       for (int j = 0; j <v2[i].size(); j++)
       {
            cout << v2[i][j] << " ";
        }
        cout << endl;
    }
}
class Coordinate
{
    protected:
    int x;
    int y;
    public:
    Coordinate(int X,int Y)
    {
        this->x = X;
        this->y = Y;
    }
    void set_x(int X)
    {
        this->x = X;        
    }
    int get_x()
    {
        return x;
    }    

};
vector<vector<int>> Add_vector(vector<vector<int>> v1,vector<vector<int>> v2)
{
    int n = v1.size();
    vector<vector<int>> result(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++)
   {
       for (int j = 0; j < n ; j++)
       {
            result[i][j]= v1[i][j] + v2[i][j];
        }

    }
    return result;
}
vector<vector<int>> multiply_vector(vector<vector<int>> v1,vector<vector<int>> v2)
{
    // [1,2] * [5,6]  = [1*5 + 2*7,  ]   
    // [3,4]   [7,8]    [         ,  ]
    int n = v1.size();
    vector<vector<int>> result(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++)
   {
       for (int j = 0; j < n ; j++)
       {    
            for(int k =0;k<n;k++)
            {
                result[i][j] += v1[i][k] * v2[k][j];
            }
        }

    }
    return result;
}

void check_target(vector<int> v1,vector<int> v2)
{       
    cout<<"作业二："<<endl;
    int target = 38;
    bool flag = false;
    for(int i =0;i<v1.size();i++)
    {
        for(int j=0;j<v2.size();j++)
        {
            if(v1[i] + v2[j] == target)
            {
                cout<<"vector_1 "<<"["<<i<<"]"<<" + "<<"vector2 "<<"["<<j<<"]"<<" = "<<target<<endl;
                flag = true;
            }
        }
    }
    if(!flag)
    {
        cout<<"没找到！！！"<<endl;
    }
}



int main()
{   
    //slice 7
    vector<int> number1(10);
    
    for(int i = 0;i<10;i++)
    {
        number1[i] = i;
    }
    cout<<"第一个vector数组：";
    printVector(number1);

    //slice 9
    string a = "XIAO";
    cout<<"string A:"<<a<<endl;
    string b = "David";
    cout<<"string B:"<<b<<endl;
    string c = b+'s'+'b';
    cout<<"string C:"<<c<<endl;
    c[0] = 'd';
    cout<<"string C:"<<c<<endl;

    cout<<endl;

    //slice 2d
    cout<<"jagged 2D vector:"<<endl;
    vector<vector<int>> vector_1
        {
        {1, 2},
        {4, 5, 6},
        {7, 8, 9, 10} };
    for (int i = 0; i < vector_1.size(); i++)
    {
       for (int j = 0; j <vector_1[i].size(); j++)
       {
            cout << vector_1[i][j] << " ";
        }
        cout << endl;
    }
    cout<<endl;

    cout<<"Coordinate class函数:"<<endl;

    Coordinate test_1(4,3);
    Coordinate test_2 =test_1;
    cout<<"a的 x 值为:"<<test_1.get_x()<<endl;
    cout<<"b的 x 值为:"<<test_2.get_x()<<endl;

    cout<<endl;

    vector<vector<int>> num2 =  
    {
        
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };
    cout<<"第一个数组"<<endl;
    two_dimensional_array(num2);
    vector<vector<int>> num3 =
    {
        
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };
    vector<vector<int>> result;

    result = Add_vector( num2 , num3);

    cout<<"两个数组相加："<<endl;
    two_dimensional_array(result);

    vector<vector<int>> result_2;

    result_2 = multiply_vector( num2 , num3);

    cout<<"两个数组相乘："<<endl;
    two_dimensional_array(result_2);

//vector实现这样的功能，抽象为一个函数
// a = [1,2,3,4,5], b = [1,2,37,8]    target = 38
// 因为 a[0] + b[2] == target, 所以返回 0，2
//如果不存在 a[i] + b[j] == target,就返回-1
    vector<int> num_5;
    for(int i = 0;i<5;i++)
    {
        num_5.push_back(i);
    }
    vector<int> num_6(4);
    num_6[0] = 1;
    num_6[1] = 2;
    num_6[2] = 37;
    num_6[3] = 8;

    check_target(num_5,num_6);

    return 0;
}
