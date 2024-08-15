//4. 写代码复现 stack overflow exeception:
//（可以利用 ulimit-s 调小栈的大小限制，使得栈溢出 stackoverflow exeception 更容易发生）
#include <iostream>

int main()
{
    int largeArray[10000];

    for (int i = 0; i < 10000; ++i) {
        largeArray[i] = i;
    }

    return 0;
}
//ulimit -s 64K 将栈大小限制设置为64K：