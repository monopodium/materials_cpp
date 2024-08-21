#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

//
int main(void) {
    int pid;
pid = fork();       //fork() 函数用于创建一个新的进程（子进程）。
                    //这个函数被调用一次，但返回两次：在父进程中返回子进程的 PID，在子进程中返回 0。
printf("PID %d: %p.\n", getpid(), &pid);
    if(pid)
        wait(NULL);
return 0; }