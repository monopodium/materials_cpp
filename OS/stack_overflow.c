#include<stdio.h>
#include<stdlib.h>
#define ONE_MEG 1024*1024

int test(int n){
    if(n%100){
        printf("test invoke! %d",n);
    }
    int a = 10;
    int b = 10;
    int c = 10;
    int d = 10;
    // if (n == 0){
    //     return 0;
    // }
    return test(n-1);
}
int main(void){
    void *ptr;
    int counter;
    while (1)
    {
        ptr = malloc(ONE_MEG); // 1 MB 3GB = 3096MB
        if(!ptr)
            break;
        counter++;
        printf("Allocated %d MB\n", counter);
    }
    return 0;
}