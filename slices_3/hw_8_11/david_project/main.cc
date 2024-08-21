#include "my_list.h"
#include "my_compare.h"
#include "my_sort.h"
#include <algorithm>

//
class campare{
    public:
        bool operator()(int a,int b){
            std::cout<<"compare: "<<std::endl;
            return a>b;
        }
};

int main()
{   

    vector<int> x{17,4,2,18,4};
    std::sort(x.begin(),x.end(),campare());

    for(auto it=x.begin();it!=x.end();it++){
        std::cout<<*it<<" ";
    }
    std::cout<<std::endl;

    // my_list<int> xxy;
    // xxy.push_back(17);
    // xxy.push_back(4);
    // xxy.push_back(2);
    // xxy.push_back(18);
    // xxy.push_back(4);
    // for (auto it = xxy.begin(); it != xxy.end(); ++it)
    // {
    //     std::cout << " " << *it;
    // }
    // std::cout << std::endl;
    // auto it = xxy.begin() + 3;
    // std::cout << " " << *it;
    // std::cout << std::endl;
}
   