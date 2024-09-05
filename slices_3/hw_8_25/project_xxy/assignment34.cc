// 定义一个 vector，里面存放的都是car的object，利用我们定义的comparator,对vector进行排序

// 写两个排序的函数，给我们的 my_list， my_vector进行排序。

    #include<iostream>  
    using namespace std; 
    #include<string>
    #include <fstream>
    #include <vector>
    #include <list>
    #include<algorithm>
    using std:: vector;

    class Car
    {
        public:
        int m_price =0;
        string m_bread ;

        public:
        Car(int price,string bread)
        {
            this->m_bread = bread;
            this->m_price = price;
        }
    };
    class compare
    {
        public:
        bool operator()(const Car &a,const Car &b)
        {
            return a.m_price <b.m_price;        //按价格从低到高排列
        }
    };
    void print_Car(vector<Car> &v_1)
    {
        for(Car & car_1 : v_1)
        {
            cout<<"牌子:   "<<car_1.m_bread<<"价格：   "<<car_1.m_price<<endl;
            
        }
    }
 // 
    void sort_vector(vector<int> & v_1)
    {
        //手画图
        for(int i =0;i<v_1.size();i++)
        {
            // j+1 <= v_1.size()-1
            // j <= v_1.size()-2
            for(int j =v_1.size()-2;j>=i;j--)
            {
                if(v_1[j]>v_1[j+1])
                {
                    int temp = v_1[j];
                    v_1[j] = v_1[j+1];
                    v_1[j+1]= temp;
                }
            }
        }
    }
    void sort_list(list<int> & list_1)

    {
        for(list<int>::iterator it_1 = list_1.begin(); it_1 != list_1.end(); it_1++)
        {
            for(list<int>::iterator it_2 = list_1.begin(); it_2 != list_1.end(); it_2++)
            {
                if (*it_2 < *next(it_2))
                {
                    auto temp = *it_2;
                    *it_2 = *next(it_2);
                    *next(it_2) = temp;
                }
            }
        }
    }




    int main()
    {
        vector<Car> v_1 = { Car(2000,"baoma"),Car(3000,"benchi"),Car(150000,"gaohe"),Car(100,"aoodi")};
        cout<<"排序之前的vector："<<endl;
        print_Car(v_1);

        sort(v_1.begin(),v_1.end(),compare());
        cout<<"sort之后的："<<endl;
        print_Car(v_1);

        cout<<endl;
        //11,2,3,13,0,20,34
        //11,2,3,    0,13,20,34
        vector<int> v_2 = {5,8,3,4,6};
        sort_vector(v_2);
        cout<<"排序的vector数字："<<endl;
        for(int element: v_2 )
        {
            cout<<element <<"   ";
        }
        cout<<endl;

        list<int> list_1 = {1,3,20,15,6,14};

        for(int element: list_1 )
        {
            cout<<"数字："<<element <<"   ";
        }
        cout<<endl;

                            

        return 0;
    }