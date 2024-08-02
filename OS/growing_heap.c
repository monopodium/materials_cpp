#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
// #include<vector>
#define ONE_MEG 1024 * 1024
char *prev_ptr = NULL;
char *ptr = NULL;
void handler(int sig) {
    printf("Page size = %d bytes\n",(int) (ptr - prev_ptr));
    exit(0);
}
int main(void){
    char c;
    signal(SIGSEGV, handler);
    prev_ptr = ptr = sbrk(0);
    sbrk(1);
    while(1)
        c = *(++ptr);
    return 0;
}

