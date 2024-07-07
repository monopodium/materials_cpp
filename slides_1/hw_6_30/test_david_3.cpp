#include <iostream>
#include <vector>
using namespace std;

int m, n;    //定义全局变量

// 1. 在合适的位置加上const,明确每一个函数能够修改的范围，
// F.printMatrix ：这个函数里面不能做任何修改；
// slice: A two-part solution对于 <<的重载，都改成这个形式
// Which of these are legit 第十页： 敲一遍代码，然后再解释为什么合法或者不合法
//打印a和a的地址， 打印b和b的地址
// {}
// 验证一下：new string离开作用域里面它不会被自动销毁， string A 离开作用域里面它会被自动回收。
// 

//
//


class matrix
{
//
private:
    vector<vector<int> > matrix_vector;

public:
    void write(){

    }
    matrix(int n, int m);
    void Enterin(int n,int m);
    void Printout() const;
    int get_row() const {
        return matrix_vector.size();
    }
    int return_a() const {
        return 0;
    }
    int get_column()const;
    friend matrix operator*( matrix &A,  matrix &B);
    friend matrix operator+(const matrix &D, const matrix &E);
    ostream &operator<<(ostream &out,const matrix &D );
    vector<int>& operator[](int i) 
    { 
        return matrix_vector[i]; 
    }
    // vector<int> operator[](int i) const
    // { 
    //     return matrix_vector[i]; 
    // }

    const vector<int>& operator[](int i) const
    { 
        return matrix_vector[i]; 
    }
     // matrix A
     //  A[0][0] = 14;
};

int matrix::get_column()const
{
    return matrix_vector[0].size();
}



matrix::matrix(int n, int m)
{
    matrix_vector.resize(n, vector<int>(m));
}

matrix operator*( matrix &A,  matrix &B)
{
    if (A.get_column() != B.get_row()) {
        throw invalid_argument("Matrices cannot be multiplied due to incompatible dimensions.");
    }
    
    // A = n*m  B = m*x C = n *x
    // n lines
    matrix C(A.get_row(), B.get_column());
    for (int i = 0; i < A.get_row(); ++i) {
        for (int j = 0; j < B.get_column(); ++j) {
            C.matrix_vector[i][j] = 0;
            for (int k = 0; k < A.get_column(); ++k) {
                C.matrix_vector[i][j] += A.matrix_vector[i][k] * B.matrix_vector[k][j];
            }
        }
    }

    return C;
}
//不希望对 operator+的函数对D和E做任何的修改，const应该加在哪里
matrix operator+( const matrix &D, const matrix &E)
{
    if (D.get_column() != E.get_column() || D.get_row() != E.get_row()) {
        throw invalid_argument("Matrices cannot be added due to incompatible dimensions.");
    }

    matrix F(D.get_row(), D.get_column());
    for (int i = 0; i < D.get_row(); ++i) {
        for (int j = 0; j < D.get_column(); ++j) {
            F.matrix_vector[i][j] = D.matrix_vector[i][j] + E.matrix_vector[i][j];
        }
    }

    return F;
}
//
ostream &operator<<(ostream &out, const  matrix &D ){
    D.write(out);// 把D的行和列都丢到out(输出流)中
    return out;
}



void matrix::Enterin(int n,int m)
{
    cout << "请输入矩阵" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            matrix_vector[i][j] = 3;
            //cin >> matrix_vector[i][j];
        }
        //cout<<"换行"<<endl;
    }
}

void matrix::Printout()const{
   for(int i=0;i<get_row();i++){
        for(int j=0;j<get_column();j++){
            cout << matrix_vector[i][j] << " ";
        }
        cout<<endl;
    }
    
}


int main()
{
    
    // cout<<"输入n和m"<<endl;
    // cin>>n;
    // cin>>m;
    n = 2;
    m = 3;
    //literally:改名字，逻辑一样，位置一样，是躲不过查重的
    //
    matrix A(n, m);
    ///？？
    //？？？
    matrix B(m, n*n);
    matrix C(n, n*n);
    A.Enterin(n,m);
    B.Enterin(m,n*n);
    C = A * B;
    cout<<C;
    
    cout << "矩阵：" << A << std::endl;

    //1*2*3 = (1*2)*3
    cout << (A[0])[0] << endl;
    A[0][0] = 14; // references
    
    cout << "尝试修改后的矩阵：" << A << std::endl;

    matrix D(n, m);
    matrix E(n, m);
    matrix F(n, m);
    D.Enterin(n,m);
    E.Enterin(n,m);
    F = D + E;
    //get_column
    //我不希望在Printout对我的class里面的变量做任何的修改 const的位置加在哪里？
    //
    F.Printout();
    const matrix matrix_const = A;
    std::cout << matrix_const[0][0] << std::endl;
    matrix_const.return_a();

    return 0;
}

