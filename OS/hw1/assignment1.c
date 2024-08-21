
#include <stdio.h>
#include <stdlib.h>

int main(void)
{ //4 bytes
char *stringaaa = "hello";
char stringbbb[] = "hello";
printf("\"hello\" = %p\n", "hello");

printf("String pointer = %p\n", stringaaa) ;       //存储的位置在只读数据区（常量区）
stringbbb[4] = "\0";

//printf("Go to %s\n", string) ;

// char string_1[] = "hello";                  //string被存储在栈区（可以安全修改）
// string_1[4] = "\0";         
// printf("Go to %s\n", string_1) ;

return 0;
}