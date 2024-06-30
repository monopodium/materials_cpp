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
    vector<int> & operator[](int index)
    {
        //std::cout << "non const constrain!" << std::endl;
        return data[index];
    }
    const vector<int> operator[](int index) const 
    {
        //std::cout << "const constrain!" << std::endl;
        return data[index];
    }
    const vector<int> test(int index) const //禁止这个函数里面修改matrix类里面的成员变量
    {
        std::cout << "const constrain!" << std::endl;
        return data[index];
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
    //A *B 
    //A这个类的data B就是other

    //A = n*m  *   B = m*x
    // n *x
    //
    Matrix operator  *(Matrix &other)
    {
        cout<<"使用了乘法的符号重载！！"<<endl;


        Matrix result(M_row,other.M_column);
        for (int i = 0; i < M_row; i++)
        {
            for (int j = 0; j < other.M_column; j++)
            {    
                for(int k =0; k<M_column;k++)
                {
                    result[i][j] += data[i][k] * other[k][j];
                }
            }
        }
        return result;
    }
    friend void Print_matrix(Matrix result);        //友元函数
    ostream & operator<<(ostream & out,)
    {
        std::cout << "重载了运算符<<" << std::endl;
        for (int i = 0; i <  result.M_row; i++)
        {
        for (int j = 0; j < result.M_column; j++)
        {
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
        }
    cout<<endl;
    }
    return out;

};
//const 
void Print_matrix(const Matrix result)
{
        for (int i = 0; i <  result.M_row; i++)
        {
        for (int j = 0; j < result.M_column; j++)
        {
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
        }
    cout<<endl;
}

int main()
{
    Matrix m_1(2,2);
    m_1[0][0] = 4;
    m_1[0][1] = 3;
    m_1[1][0] = 2;
    m_1[1][1] = 1;


    Matrix m_2(2,2);
    m_2[0][0] = 4;
    m_2[0][1] = 3;
    m_2[1][0] = 2;
    m_2[1][1] = 1;

    Matrix result(2,2);
    result = m_1 + m_2;
    Print_matrix(result);

    Matrix result_2(2, 2);
    result_2 = m_1 * m_2;
    Print_matrix(result_2);

    Matrix m_3(2,1);
    Matrix m_4(1,2*2);
    m_3[0][0] = 4;
    m_3[1][0] = 3;
    m_4[0][0] = 4;
    m_4[0][1] = 3;
    Matrix result_3(2,2*2);
    result_3 = m_3 * m_4;
    Print_matrix(result_3);
    //<<重载
    //cout << m_3 << std::endl;

    return 0;
}
