//slices3 7页的函数补全

//template<typename T>
// void Print(T toretrievel){
//     for(auto &item: toretrievel){
//         std::cout << item << std::endl;
//     }
// }
//验证这个函数能不能打印:tuple, pair,list ,set ,unordered_set,vector里面的元素

//阅读c++ primer plus里面iterator的内容
//尝试使用iterator,调研，使用排序函数sort尝试给list和vector 
//能成功，解释原因
//不能成功，也解释原因

//阅读课件merge sort的部分，自己实现排序算法，
//输入是一个乱序的vector<int>数组

//验证两种constructor的不同：
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
    // P
    #include<iostream>  
    using namespace std; 
    #include<string>
    #include <fstream>
    #include <vector>
    #include<list>
    #include<set>
    #include<deque>
    #include<algorithm>


    //作业一：补全代码
    pair<double,double> getMinAndMax(const vector<double> & n) 
    {
        double min = n[0];
        double max = n[0];
        for (int i = 0; i < n.size(); ++i) {
            if(min>n[i])
            {
                min = n[i];
            }
            if(max<n[i])
            {
                max = n[i];
            }
        }
        return pair<double,double>(min,max);
    }
    //打印函数  
    template<typename T>
    void Print(T toretrievel){
        for(auto &item: toretrievel){
            std::cout << item << "  ";
        }
        cout<<endl;
    }
    int main()
    {   
        //pair
        // pair<int,string> student_1(18,"david");
        // cout<<student_1.first<<endl;
        // cout<<student_1.second<<endl;
        //作业一：
        vector<double> v_1{20,10,3,6,7,11,12};
        pair<double,double> p_1= getMinAndMax(v_1);
        cout<<"min"<<p_1.first<<endl;
        cout<<"max"<<p_1.second<<endl;

        //list底层是双向链表（数据不支持连续存储）
        list<int> list_a(10);
        list_a.push_back(6);
        list_a.push_back(6);
        list_a.push_back(6);
        cout<<"list:"<<endl;
        Print(list_a);

        set<int,less<int>> set_a;
        set_a.insert(5);
        set_a.insert(5);
        set_a.insert(20);
        set_a.insert(18);
        set_a.insert(9);
        cout<<"set less:"<<endl;
        Print(set_a);

        // tuple<int,double,float,string> t_1{20,6.66,2.1,"xiao"};
        // cout<<"tuple:"<<endl;
        // Print(t_1);
        
        deque<int> d_2(10);
        d_2.push_back(10);
        d_2.push_front(10);
        cout<<"deque:"<<endl;
        Print(d_2);

        //iterator
        vector<int> v_8;
        for(int i =0;i<10;i++)
        {
            v_8.push_back(i);
        }
        cout<<"vector:排序";
        for(vector<int>::iterator it = v_8.begin();it!= v_8.end();it++)
        {
            cout<<*it<<"  ";
        }

        vector<int>v1{4,6,9,11},v2{8,5,12,10,3};
        vector<int>v3;
        v3.resize(v1.size()+v2.size());
        merge(v1.begin(),v1.end(),v2.begin(),v2.end(),v3.begin());
        sort(v3.begin(),v3.end());
        cout<<"merge排序："<<endl;
        Print(v3);

        return 0;
    }
