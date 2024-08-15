
#include <stdio.h>
#include <stdlib.h>

int global_int = 10; // 全局变量

int main(void) {
    int *malloc_ptr = (int*)malloc(sizeof(int)); // 动态分配内存
    const char *constant_ptr = "hello"; // 字符串常量
    
    printf("Local variable = %15p\n", (void*)&malloc_ptr);

    // 打印动态分配的内存空间的地址
    printf("Malloc'd space = %15p\n", (void*)malloc_ptr);

    // 打印全局变量的地址
    printf("Global variable = %15p\n", (void*)&global_int);

    // 打印字符串常量的地址
    printf("Code & constant = %15p\n", (void*)constant_ptr);

    free(malloc_ptr);
return 0;
}