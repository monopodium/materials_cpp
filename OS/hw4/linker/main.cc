#include <iostream>

#include "hello.h"

//在另外的单独的文件里面定义lru 算法（access),(.h文件里面只是声明,.cc文件里面定义)
//在main.cc里面调用lru算法
//marco 语法 ch3 17 页之前的部分 

int main() {
    say_hello();
    return 0;
}
// fc1 : * wildcard