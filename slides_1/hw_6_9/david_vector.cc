#include <vector>
#include <iostream>
using namespace std;
#include <algorithm>

int main(){
//创建一个vector
    vector<int>myVector;
// push_back添加
    myVector.push_back(1);
    myVector.push_back(2);
    myVector.push_back(3);
    myVector.push_back(4);
//输出
    cout << "Elements in the vector: ";
    for (int element : myVector) {
        cout << element << " ";
    }
    for (int i = 0;i<myVector.size();i++)
    {
        cout << myVector[i] << std::endl;
    }
    for(vector<int>::iterator it = myVector.begin();it != myVector.end();it++)
    {
        cout<<*it<<endl;
    }
    cout << endl;
    // 访问第一个
    cout<<myVector[0]<<endl;
//访问第二个
    cout<<myVector.at(1)<<endl;
//向量大小
    cout<<myVector.size()<<endl;
//删除
    myVector.erase(myVector.begin());
//输出
    cout << "Elements in the vector: ";
    for (int element : myVector) {
        cout << element << " ";
    }
    cout<<endl;
//翻转
    reverse(myVector.begin(),myVector.end());
//输出
    cout << "Elements in the vector: ";
    for (int element : myVector) {
        cout << element << " ";
    }
    cout<<endl;
//清除
    myVector.clear();
    cout<<myVector.size()<<endl;

}