// 定义一个 vector，里面存放的都是car的object，利用我们定义的comparator,对vector进行排序

// 写两个排序的函数，给我们的 my_list， my_vector进行排序。

    #include<iostream>  
    using namespace std; 
    #include<string>
    #include <fstream>
    #include <vector>
    #include <list>
    using std:: vector;


    void print_vector(vector<int> &v_1)
    {
        for(int i =0;i<v_1.size();i++)
        {
            cout<<v_1[i]<<  "   ";
        }
        cout<<endl;
    }


    void sort_vector(vector<int> & v_1)
    {
        for(int i =0;i<v_1.size();i++)
        {

            for(int j = i;j<v_1.size()-1;j++)
            {
                cout<<" ["<<i<<"]"<<"  ";   
                print_vector(v_1);
                if(v_1[j]>v_1[j+1])
                {
                    int temp = v_1[j];
                    v_1[j] = v_1[j+1];
                    v_1[j+1 ]= temp;
                }
                
            }
        }
    }
    //
    void sort_vector_2(vector<int> & v_1)
    {
        // 5   8   3   4   6
        // 8   5   3   4   6
        // 8   3   4   3   6
        for(int i =0;i<v_1.size();i++)
        {
            // j从前往后遍历，每次将最小的数字放到最后面
            for(int j = 0;j<v_1.size()-1-i;j++)
            {
  
                print_vector(v_1);
                if(v_1[j+1]<v_1[j])
                {
                    int temp = v_1[j];
                    v_1[j] = v_1[j+1];
                    v_1[j+1 ]= temp;
                }
                cout<<" ["<<i<<"]"<<"  "; 
                
            }
        }
    }
    void sort_list(list<int> & list_1)

    {
        for(list<int>::iterator it_1 = list_1.begin(); it_1 != list_1.end(); it_1++)
        {
            for(list<int>::iterator it_2 = list_1.begin(); it_2 != list_1.end(); it_2++)
            {
                if (*it_2 > *next(it_2))
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

        cout<<endl;
        vector<int> v_2 = {5,8,3,4,6,1,100,3};
        // sort_vector(v_2);

        // cout<<"排序的vector数字："<<endl;
        // for(int element: v_2 )
        // {
        //     cout<<element <<"   ";
        // }
        // cout<<endl;

        cout<<"vector(2)："<<endl;
        sort_vector_2(v_2);




        // list<int> list_1 = {100,32,20,15,6,14};

        // sort_list(list_1);
        // for(int element: list_1 )
        // {
        //     // cout<<"数字："<<element <<"   ";
        // }
        // cout<<endl;

                            

        return 0;
    }