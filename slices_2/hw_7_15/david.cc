#include <iostream>
#include <vector>
using namespace std;
class stack{
    private:
        vector<int>xxy;

    public:
        //[1,2,3]
        //[] 1. stack
        // 
        void push(int i){
            xxy.push_back(i);
        };
        void pop(){
            //
            cout<<xxy[xxy.size()-1]<<endl;
            xxy.erase(xxy.end());
        };
        void top(){
            cout<<xxy[xxy.size()-1]<<endl;
        };
        void size(){
            cout<<xxy.size()<<endl;
        };
        void print(){
            for (auto it = xxy.begin(); it != xxy.end(); ++it) {
            std::cout << *it << " ";
            }
        }

};
//
class queue{
    private:
    vector<int>xxy_1;

    public:
    void enqueue(int i){
        xxy_1.push_back(i);
    }
    void dequeue(){
        cout<<xxy_1[0]<<endl;
        xxy_1.erase(xxy_1.begin());
    }
    void front(){
        cout<<xxy_1[0]<<endl;
    }
    void size_1(){
         cout<<xxy_1.size()<<endl;
    };
    void print_1(){
        for (auto it = xxy_1.begin(); it != xxy_1.end(); ++it) {
        std::cout << *it << " ";
        }
    }
};

int main(){
    cout<<"创造一个vector(输入长度)"<<endl;
    int n;
    cin>>n;
    stack xxy;
    xxy.pop();
    for(int i=0;i<n;i++){
        int m;
        cin>>m;
        xxy.push(m);
    }
    xxy.pop();
    xxy.top();
    xxy.size();
    xxy.print();
    
    cout<<"-----------"<<endl;
    queue xxy_1;
    cout<<"创造一个vector(输入长度)"<<endl;
    int m;
    cin>>m;
    for(int j=0;j<m;j++){
        int g;
        cin>>g;
        xxy_1.enqueue(g);
    }
    xxy_1.dequeue();
    xxy_1.front();
    xxy_1.size_1();
    xxy_1.print_1();
    const vector<int> test_vector_const = {1};
    test_vector_const.at(0);
    vector<int> test_vector = {1};
    test_vector.at(0);
    test_vector[3] = 4;

    try
    {
        test_vector.at(3);
    }
    catch (std::out_of_range const& exc)
    {
        std::cout << exc.what() << '\n';
    }
    std::cout << "???????????" << std::endl;
}