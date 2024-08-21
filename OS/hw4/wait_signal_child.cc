#include <iostream>
#include <unistd.h>    // 包含 fork、sleep 等函数
#include <sys/wait.h>  // 包含 wait 函数
#include <signal.h>    // 包含信号处理函数


int main() {
    pid_t pid = fork(); // 创建子进程

    if (pid < 0) {
        // fork 失败
        std::cerr << "Fork failed!" << std::endl;
        return 1;
    } else if (pid == 0) {
        // 子进程
        std::cout << "This is the child process with PID: " << getpid() << std::endl;
        sleep(2);  // 子进程休眠2秒模拟处理
        std::cout << "Child process exiting." << std::endl;
        return 42;  // 子进程以状态码42退出
    } else {
        // 父进程
        std::cout << "This is the parent process with PID: " << getpid() << std::endl;
        std::cout << "Parent process waiting for child to terminate..." << std::endl;

        // 父进程等待子进程结束
        wait(NULL);

        std::cout << "Parent process detected child termination." << std::endl;
    }

    return 0;
}
