#include <iostream>
#include <unistd.h>    // 包含 fork、sleep 等函数
#include <sys/wait.h>  // 包含 waitpid 函数
#include <signal.h>    // 包含信号处理函数

// 自定义的信号处理函数
void childHandler(int signum) {
    int status;
    pid_t pid;

    // 使用 waitpid 处理子进程的结束，循环以确保处理所有已终止的子进程
    while ((pid = waitpid(-1, &status, WNOHANG)) > 0) {
        std::cout << "Child process " << pid << " terminated." << std::endl;
        if (WIFEXITED(status)) {
            std::cout << "Exit status: " << WEXITSTATUS(status) << std::endl;
        } else if (WIFSIGNALED(status)) {
            std::cout << "Terminated by signal: " << WTERMSIG(status) << std::endl;
        }
        exit(0); // 退出信号处理函数
    }
}

int main() {
    // 绑定自定义的信号处理函数到 SIGCHLD 信号
    struct sigaction sa;
    sa.sa_handler = childHandler;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = SA_RESTART;
    sigaction(SIGCHLD, &sa, NULL);

    pid_t pid = fork(); // 创建子进程

    if (pid < 0) {
        // fork 失败
        std::cerr << "Fork failed!" << std::endl;
        return 1;
    } else if (pid == 0) {
        // 子进程
        std::cout << "This is the child process with PID: " << getpid() << std::endl;
        sleep(2);  // 子进程模拟处理（休眠2秒）
        std::cout << "Child process exiting." << std::endl;
        return 42;  // 子进程以状态码42退出
    } else {
        // 父进程
        std::cout << "This is the parent process with PID: " << getpid() << std::endl;
        std::cout << "Parent process waiting for child to terminate..." << std::endl;

        // 父进程继续运行，等待子进程结束信号
        while (true) {
            pause(); // 等待信号
        }
    }

    return 0;
}
