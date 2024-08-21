#include<iostream>  
#include <string>
#include <fstream>
#include <vector>
#include <list>

using namespace std; 

class Test
{
    int data;
    public:
        Test(int x):data(x){

        };
        
        int get_data(){
            return data;
        }
};