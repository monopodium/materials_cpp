#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cout << "请输入数字n: " << endl;
    cin >> n;

    vector<vector<int>> A(n, vector<int>(n));
    vector<vector<int>> B(n, vector<int>(n));
    vector<vector<int>> C(n, vector<int>(n));
    vector<vector<int>> D(n, vector<int>(n));

    cout << "输入矩阵A:" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> A[i][j];
        }
    }

    cout << "输入矩阵B:" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> B[i][j];
        }
    }

    cout << "输出矩阵A和矩阵B的和:" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            C[i][j] = A[i][j] + B[i][j];
            cout << C[i][j] << " ";
        }
        cout << endl;
    }

    cout << "输出矩阵A和矩阵B的积:" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            D[i][j] = 0; 
            for (int k = 0; k < n; ++k) {
                D[i][j] += A[i][k] * B[k][j];
            }
            cout << D[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}