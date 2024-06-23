#include <iostream>
#include <vector>
using namespace std;
vector<int> M( vector<int> A, vector<int> B, int target) {
    for (int i = 0; i < A.size(); ++i) {
        for (int j = 0; j < B.size(); ++j) {
            if (A[i] + B[j] == target) {
                return {i, j}; 
            }
        }
    }
    return {-1, -1}; 
}

int main() 
{

    vector<int> A= {1, 2, 3, 4, 5};
    vector<int> B = {1, 2, 37, 8};
    int target = 38;

    vector<int> C = M(A, B, target);

    for (int element : C ) {
        std::cout << element << " ";
    }
    return 0;
}