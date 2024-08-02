#include<stdio.h>
#include<stdlib.h>
// #include<vector>
#define ONE_MEG 1024 * 1024

int main(void){
    void *ptr;
    int counter = 0;
    char local[8000 * 1024];
    while(1) {
    ptr = malloc(ONE_MEG);
    if(!ptr)
        break;
        counter++;
        printf("Allocated %d MB\n", counter);
    }
    char *string = "hello";
    printf("\"hello\" = %p\n", "hello");
    printf("String pointer = %p\n", string);
    string[4] = '\0';
    printf("Go to %s\n", string);
    return 0;
}

