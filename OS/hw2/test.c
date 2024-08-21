#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>

int main(){
    printf("Hello, I am test.c\n");
    execl("/bin/ls", "lss", "-l", NULL);
    printf("This line should not be printed\n");
    return 0;
}