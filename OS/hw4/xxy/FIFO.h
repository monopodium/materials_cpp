#include <iostream>
#include <vector>

class Frame {
public:
    int page_number;
    int time;

    // 构造函数
    Frame(int pn = -1, int t = 0);

    // 重载运算符==
    bool operator==(const Frame& other);
};

// 声明函数，在内存中查找页面号
int find_in_mem(int page_number, const std::vector<Frame>& mem);