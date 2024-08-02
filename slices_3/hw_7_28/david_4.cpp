#include <iostream>
#include <vector>
#include <list>
#include <algorithm> 
using namespace std;


int main() {
   
    vector<int> vec = {1,2,6,8,5,7,0};
    list<int> lst = {2,1,4,6,7,8,4,4,3};
    //
    sort(vec.begin(),vec.end()); // iterator
    sort(lst.begin(),lst.end());
      
    for (auto it = vec.begin(); it != vec.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    for (auto it = lst.begin(); it != lst.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    return 0;
}
