#include<iostream>
#include<unistd.h>
#include<sys/wait.h>
#include<string>
using namespace std;   
//修改如下代码，使其能够执行用户输入的命令，例如输入ls -a，就执行ls -a命令
// LRU 的实现 : age[]   0 1 2 3 4 5 6 7 8 9

int main()
{   
    int status;
    string command;
    cout<<"请输入你要执行的命令"<<endl;
    getline(std::cin, command);  

    pid_t pid = fork();
    if(pid== 0)
    {
        execl(command,command,NULL);
        exit(127);

    }
    else {
        // 父进程等待子进程完成

        waitpid(pid, &status, 0);  // 等待子进程结束

    }


    return 0;
}