#include<iostream>
#include<vector>
#include<queue>
#include<stack>

using namespace std;

//
    //写法不同，他们的执行区别
    // Person(const Person & other):M_name(other.M_name),M_age(other.M_age)
    // {
    //     std::cout << "copy construtor of Person!" << std::endl;
    // }
    // Person(const Person & other,int n)
    // {   
    //    this->M_age = M_age;
    //     this->M_name = M_name;  //operator=
    //     std::cout << "copy construtor_2 of Person!" << std::endl;
    // }
template<typename T>
class Matrix{
    // allocator
    // malloc :分配内存 memory allocate
    // allocator: 内存分配器
private:
    vector<vector<T>> xxy;

public:
    Matrix(unsigned int row, unsigned int col) {
        xxy.resize(row, vector<T>(col));
    }
    unsigned int getrow() const {
        return xxy.size();
    }

  
    unsigned int getcol() const {
        return xxy[0].size();
    }
    void set() {

        for(int i=0;i<getrow();i++){
            for(int j=0;j<getcol();j++){
                cin>>xxy[i][j];
            }
            cout<<"------"<<endl;
        }
    }
   

    void print() const {
        for (const auto& row : xxy) {
            for (const auto& elem : row) {
                std::cout << elem << " ";
            }
            std::cout << std::endl;
        }
    }
};
//
int main(){
    //In instantiation of
    //instantiation:实例化 
    //instrution: 告诉我们的compiler怎么生成我们需要的代码
    // 5min
    int n, m;
    std::cout << "n:" << n << std::endl;
 
    cout << "输入行" << endl;
    cin>>n;
    cout<<"输入列"<<endl;
    cin>>m;

    Matrix<int> test_a(n, m);
    Matrix<double> test_b(n,m);
    std::sort();
    test_a.set();
    test_b.set();
    test_a.print();
    test_b.print();

    
}
