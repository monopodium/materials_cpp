#include <stdio.h>
#include <string.h>
#include <stdlib.h> 

 
 
 #define BUF_SIZE  512 * 1024
  void re() 
{
    char *buf = (char *)malloc(BUF_SIZE);


    printf("Memory allocated at: %p\n", buf);
    
    memset(buf, 0, sizeof(buf));
    for (int i = 0; i < 10; i++) 
    {
        printf("%d ", buf[i]);
    }
    free(buf);
} 

int main(void) 
{
    re();
    return 0;
}   