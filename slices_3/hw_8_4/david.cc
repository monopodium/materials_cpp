#include <iostream>
#include <vector>
#include <list>
#include <algorithm> 
using namespace std;

//1. 对于vector<int>和list<int>分别实现一份sort函数
int main() {
   
    vector<int> xxy_1 = {1,2,6,8,5,7,0};
    list<int> xxy_2 = {2,1,4,6,7,8,4,4,3};
    
    sort(xxy_1.begin(),xxy_1.end());
    xxy_2.sort();
      
    for (auto it = xxy_1.begin(); it != xxy_1.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    for (auto it = xxy_2.begin(); it != xxy_2.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    return 0;
}