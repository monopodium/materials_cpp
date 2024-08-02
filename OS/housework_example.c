#include<stdio.h>
#include<stdlib.h>
// #include<vector>
#define ONE_MEG 1024 * 1024
int globale_int = 0;
int main(void)
{
    int *malloc_ptr = malloc(4);
    char *constant_ptr = "hello";
    printf("Local variable = %15p\n", &malloc_ptr);
    printf("malloc() space = %15p\n", malloc_ptr);
    printf("Global variable = %15p\n", &globale_int);
    printf("Code &constant = %15p\n", constant_ptr);
    return 0;
}
