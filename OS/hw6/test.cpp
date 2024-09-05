#include<iostream>
#include<unistd.h>
#include<string>
#include<vector>
#include<sys/wait.h>
using namespace std;

void func_1(string command,vector<string>& para)
{
    int flag = 0;
    for (int i = 0; i < command.size(); i++)
    {
        if (command[i]==' ')
        {
            cout<<"flag:  "<<"flag:  "<< flag<<endl;
            cout<<"substr:  "<<"i :  "<< i<<endl;
            para.push_back(command.substr(flag,i-flag));
            flag = i+1;           
        }
    
    }
    para.push_back(command.substr(flag,command.size()-flag));
}




int main()
{

    // 0 3
    // xxx
    //0 1
    
    // 0,3,6
    // 0,3
    // string command_test = "ls -a -l";
    // std::cout<<"command:"<<command_test.substr(0,3)<<std::endl;
    // std::cout<<"command:"<<command_test.substr(3,6)<<std::endl;
    // std::cout<<"command:"<<command_test.substr(6,110)<<std::endl;

    std::vector<std::string> para;

    
    string command = "ls -a -l -h saehufbyb fensfuneu";

    func_1(command,para);

    for(int i = 0; i < para.size(); i++)
    {
        cout<<para[i]<<endl; 
    }

    return 0;
}