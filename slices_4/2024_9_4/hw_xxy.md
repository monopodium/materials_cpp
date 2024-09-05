    // #ifndef MY_LIST_H //查资料了解这个ifndef的作用
    // #define MY_LIST_H

//    if not define的简写，是宏定义的一种，ifndef是条件编译
#ifndef x   //  先检测x是否被宏定义过
    #define x//如果x没有被宏定义过，定义x，并执行程序1

    //正常的代码写在这个
        //程序段1
#endif 
    //程序段2
    //如果x已经定义过了，执行程序2