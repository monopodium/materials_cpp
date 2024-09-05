//比较SLT里面的list和vector的iterator的区别：
//vector 和 list 两种数据结构的内存分配方式不同，vector内存空间是连续的，而list的内存不是连续的，
//所以这样一来vector的begin() + h 得到的迭代器是真实指向第h个元素的，而list的begin() + h 
//得到的迭代器指向的是begin()连续偏移h块内存空间（一块内存空间的大小取决于存储在list容器中类型所占大小，如类型为int，则为4个字节），
//但是因为list的内存不连续，所以begin() + h得到的不是我们想要的第h个节点的迭代器。实际上C++也没有重载list迭代器的 ‘+’ ‘-’符号，
//也不支持其迭代器的加减运算。所以为了访问list的第h个节点，只能从begin()开始一个一个往后访问，list访问节点的时间复杂度为O
    #include<iostream>  
    using namespace std; 
    #include<string>
    #include <fstream>
    #include <vector>
    #include <list>
    #include<algorithm>
    using std:: vector;


    int main()
    {
        vector<int> v_1 = {2,3,4,5,6,7};

        list<int> list_1 = {1,2,4,6,8};

        cout<<"vector的迭代器："<<v_1[1+3]<<endl;

        list<int> ::iterator it = list_1.begin();

        cout<<"list的迭代器"<<*(it++)<<endl;

        return 0;
    }