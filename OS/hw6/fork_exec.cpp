#include<iostream>
#include<unistd.h>
#include<string>
#include<vector>
#include<sys/wait.h>
using namespace std;
//修改如下代码，使其能够执行用户输入的命令，例如输入ls -a，就执行ls -a命令
// LRU 的实现 : age[]   0 1 2 3 4 5 6 7 8 9
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


int system_test(std::string command) {
    //std::string command = "ls -a -l";

    int status;
    
    std::vector<std::string> para; //ls -a
    int flag = 0;

    pid_t pid = fork();
    func_1(command,para);

    if (pid == 0) {
        int result = execl(para[0].c_str(),para[0].c_str(),para[1].c_str(), NULL);
        std::cout<<"result:"<<result<<std::endl;
        exit(127);
    } else {
        waitpid(pid, &status, 0);
    
        if (WIFEXITED(status)) {
            std::cout<<"exited, status="<<WEXITSTATUS(status)<<std::endl;
            return WEXITSTATUS(status);
        }
    }
    return -1;
}



int main() {
    //prompt 

    while(true){
        std::string command;

        std::cout << "Enter a command: ";
        getline(std::cin, command); 
        //std::cin >> command;
        if(command == "exit") break;
        system_test(command);
    }
    return 0;
}