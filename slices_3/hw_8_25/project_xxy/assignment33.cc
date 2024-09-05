
    #include<iostream>  
    using namespace std; 
    #include<string>
    #include <fstream>
    #include <vector>
    #include <list>
    #include<algorithm>
    #include<map>
    using std:: vector;

// slice看48-最后的内容
//比较SLT里面的 list 和vector的iterator的区别
// 使用find函数

// 学map的基本操作

// 实现一个比较器 comparator,能够比较两个类型为Car（slices里面有）的object

// 定义一个 vector，里面存放的都是car的object，利用我们定义的comparator,对vector进行排序

// 写两个排序的函数，给我们的 my_list， my_vector进行排序。

// https://www.bilibili.com/video/BV1Dk4y1j7oj?p=54

// class compare
// {
//     public:
//         bool operator()(const pair<int,string> &a,const pair<int,string> &b)
//         {
//             cout<<"compare:"<<endl;
//             return a.first<b.first;
//         }
// };

int main()
{
    vector<int> v = {3,3,7,6,4,2,1,21,10,89,42};

    int number = 0;

    cout<<"请输入你要查询额数字！！"<<endl;

    // cin>>number;

    auto it =  find(v.begin(),v.end(),number);      //find 函数是<algorithm>头文件下的find()函数是一个通用算法
                                                    //返回的是迭代器指向的第一个匹配的元素

    if(it != v.end())
    {
        cout<<"你要找的  "<<number<<"  "<<"在数组当中"<<endl;   //find函数返回一个迭代器，如果没有找到目标元素，则返回last，即返回结尾
        //因此it ！= v.end()表示找到了目标元素
    }
    else
    {
        cout<<" 没找到！！"<<endl;
    }   
    //需要注意的是！！！ find函数只能查找容器中第一个等于指定元素的元素。如果你想查找所有等于指定元素的元素，可以用循环结构搭配（for，while）

    //MAP的三种构造函数
    //最普通的通过传入健值来创建
    map<int,string> myMap = {{1,"apple"},{2,"banana"},{3,"orange"}};

    vector<pair<int,string>> vec = {{1,"apple"},{2,"banana"},{3,"orange"}};
   map<int,string>MyMap_2(vec.begin(),vec.end()) ;          //通过迭代器构造

    map<int,string> MAP_2 = {{1,"apple"},{2,"banana"},{3,"orange"}};
    map<int,string> copy_map(MAP_2);           //通过拷贝构造函数

    map<int,string> kNumbers;

    kNumbers[1194384] = "Andrew";  //    通过 map 的 [] 操作符可以直接插入或修改键值对。
    kNumbers[1234567] = "Someone";
    kNumbers[1000000] = "all";
    kNumbers[2000000] = "my";
    kNumbers[1500000] = "fans";

    // sort(kNumbers.begin(),kNumbers.end(),compare());

    cout<<"kNumbers中储存的是："<<"   "<<endl;
    for (const pair<int,string> & elem : kNumbers)  //遍历map并打印出健和值
    { 
        cout<<"k"<<elem.first<<"="<< elem.second << endl;   //elem.first 是 map 元素的键   //elem.second 是 map 元素的值
    }
    cout<<endl;

    auto itr = kNumbers.find(1234567);
    cout<<"找的数字为：1234567"<<endl;
    if(itr == kNumbers.end())
    {
        cout<<"没有找到你要的key"<<endl;
    }
    else
    {
        cout<<"找到的Key:  "<<(*itr).first<<"         value: "<<(*itr).second<<endl;
    }

    // sort(kNumbers.begin(),kNumbers.end(),compare());

    // for (const pair<int,string> & elem : kNumbers)  //遍历map并打印出健和值
    // { 
    //     cout<<"k"<<elem.first<<"="<< elem.second << endl;   //elem.first 是 map 元素的键   //elem.second 是 map 元素的值
    // }
    // cout<<endl;



    return 0;
}


