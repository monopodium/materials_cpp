#include<iostream>  
using namespace std; 
#include<string>
#include <fstream>
#include <vector>
using std:: vector;
// 加法 乘法
//   n*n
// class matrix {
//  matrix(n*m)

//  重载运算符进行加法和乘法操作
// 重载<<的运算符
// }
//
//  matrix a;
// a[1][2] = 1;
// matrix b;
// 
// matrix c = a*b;
// cout<<c
class Matrix 
{   
    private:
    vector<vector<int>> data;
    int M_row;
    int M_column;

    public:
    Matrix(int row,int column)
    {
        M_row = row;
        M_column = column;
        data.resize(M_row,vector<int>(M_column));

    }
    vector<int>& operator[](int i){
        return data[i];
    }
    Matrix operator +(Matrix &other)
    {
        cout<<"使用了加号的符号重载！！"<<endl;
            
        Matrix result(M_row,M_column);
        for (int i = 0; i < M_row; i++)
        {
       for (int j = 0; j < M_column; j++)
       {
            result[i][j]= data[i][j] + other[i][j];
        }
        }
        return result;
    }


};

int main()
{
    Matrix a(2,2);
    a[0][0] = 4;
    Matrix b(2, 2);
    b[0][0] = 4;
    Matrix c = a + b;
    std::cout << c[0][0] << " " << c[0][1] << " " << c[0][2] << std::endl;
    
    return 0;
}
