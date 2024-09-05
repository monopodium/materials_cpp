#include<iostream>  
using namespace std; 
#include<string>
#include <fstream>
#include <vector>
#include <list>
#include<stdio.h>
#include <memory>
#include <memory>


//修改increment函数，能正常的修改b，并且不报错
// my_sort(std::unique_ptr<std::vector<int>> v_1); 

// 比较shared_ptr和unqiue_ptr之间的区别,并且编程演示。证明区别确实存在

void my_sort(std::unique_ptr<std::vector<int>>& v_1)
{
    for(int i =0;i< 6;i++)
    {
        for(int j = 4;j>=0;j--)
        {
            if((*v_1)[j] >(*v_1)[j+1])
            {
                swap((*v_1)[j],(*v_1)[j+1]);
            }
        }
    }
}

void print_test(int & a)
{
    cout<<a<<endl;
}
void increment(int &a)
{
    a++;
}

int main()
{
    int a =5;
    //a是左值，  5是右值

    int &c = a;
    //变量的引用也可以作为左值
    double b = 10.9;
    a = b;
    increment(a);
    print_test(a);      //把print_test中参数b改成a;

    int * p_1 = new int(5);
    std::unique_ptr<int> ptr_1 (p_1);
    cout<<"ptr_1 :  "<< *p_1<<endl;

    //vector<int> v_1 = {11,3,5,7,9,10};
    std::unique_ptr<vector<int>> v_1 = std::make_unique<vector<int>>(6);
    (*v_1)[0] = 11;
    (*v_1)[1] = 3;
    (*v_1)[2] = 5;
    (*v_1)[3] = 7;
    (*v_1)[4] = 9;
    (*v_1)[5] = 10;

    std::unique_ptr<std::vector<int>> uptr;

    std::unique_ptr<int> u_1(new int (5) );
    cout<<"u_1"<<(*u_1)<<endl;
    std::unique_ptr<int> u_2(u_1 );
    cout<<"u_1"<<(*u_1)<<endl;

    std::shared_ptr<int> u_3(new int (15) );
    cout<<"u_3"<<(*u_3)<<endl;
    std::shared_ptr<int> u_4(u_3 );
    cout<<"u_4"<<(*u_4)<<endl;

    cout<<"u_1"<<(*u_1)<<endl;
    std::unique_ptr<int> u_1(new int (5));   // for(int i =0;i<6;i++)
    // {
    //     (*uptr)[i] = v_1[i];
    // }
    my_sort(v_1);

}