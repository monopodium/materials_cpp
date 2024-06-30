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



class matrix
{
private:
    vector<vector<int> > a;

public:
    matrix(int n, int m);
    void Enterin(int n,int m);
    void Printout()const;
    int get_row() const {
        return a.size();
    }
    int get_column()const;
    friend matrix operator*( matrix &A,  matrix &B);
    friend matrix operator+(const matrix &D, const matrix &E);
    friend ostream &operator<<( ostream &out, matrix &D );
    vector<int> operator[](int i)
     { 
        return a[i];
     }
      
};


int matrix::get_column()const
{
    return a[0].size();
}



matrix::matrix(int n, int m)
{
    a.resize(n, vector<int>(m));
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
            C.a[i][j] = 0;
            for (int k = 0; k < A.get_column(); ++k) {
                C.a[i][j] += A.a[i][k] * B.a[k][j];
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
            F.a[i][j] = D.a[i][j] + E.a[i][j];
        }
    }

    return F;
}
//
ostream &operator<<( ostream &out, matrix &D ){
    {
        std::cout << "重载了运算符<<" << std::endl;
        for (int i = 0; i < D.get_row(); i++)
        {
            for(int j=0;j<D.get_column();j++){
                 out << D.a[i][j] << " ";
            }
            out<<endl;
        }
      }
      return out;
}



void matrix::Enterin(int n,int m)
{
    cout << "请输入矩阵" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            a[i][j] = 3;
            //cin >> a[i][j];
        }
        //cout<<"换行"<<endl;
    }
}

void matrix::Printout()const{
   for(int i=0;i<get_row();i++){
        for(int j=0;j<get_column();j++){
            cout << a[i][j] << " ";
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

    matrix A(n, m);
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


    return 0;
}

