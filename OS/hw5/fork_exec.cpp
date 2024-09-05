#include<iostream>
#include<unistd.h>
#include<sys/wait.h>
//修改如下代码，使其能够执行用户输入的命令，例如输入ls -a，就执行ls -a命令
// LRU 的实现 : age[]   0 1 2 3 4 5 6 7 8 9
int system_test(std::string command) {
    int status;
    pid_t pid = fork();
    if (pid == 0) {
        execl("/bin/ls", "/bin/ls", "-l", NULL);
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
        std::cin >> command;
        if(command == "exit") break;
        system_test(command);
    }
    std::cout << "before..." << std::endl;
    system_test("ls -a");
    std::cout << "after...." << std::endl;
    return 0;
}