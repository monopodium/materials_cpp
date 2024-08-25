#include "FIFO.h"
#include <vector>
using namespace std;

// LRU 页面置换算法实现
void access(const std::vector<int>& block) {
    int page_fault = 0;
    std::vector<Frame> mem(3, Frame(-1, 0));  // 3 个页面的内存

    for (int i = 0; i < block.size(); i++) {
        int key = block[i];  // 当前访问的页面号

        // 更新所有内存中的页面时间
        for (int j = 0; j < 3; ++j) {
            mem[j].time++;
        }

        // 查找页面是否在内存中
        auto it = std::find(mem.begin(), mem.end(), Frame{key, 0});
        int index = find_in_mem(key, mem);

        if (index != -1) {
            // 页面已在内存中，更新时间
            mem[index].time = 0;
        } else {
            // 页面不在内存中，发生页面错误
            page_fault++;
            int max_number_time = 0;
            for (int j = 0; j < 3; j++) {
                if (mem[j].time > mem[max_number_time].time) {
                    max_number_time = j;
                }
            }
            // 替换最久未使用的页面
            mem[max_number_time].page_number = key;
            mem[max_number_time].time = 0;
        }

        // 输出当前内存状态
        std::cout << "加入的元素为：" << block[i] << std::endl;
        for (size_t j = 0; j < mem.size(); ++j) {
            std::cout << mem[j].page_number << " (time: " << mem[j].time << ") ";
        }
        std::cout << std::endl;
    }

    std::cout << "Page faults: " << page_fault << std::endl;
}

int main() {
    std::vector<int> access_sequence = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2, 1};
    access(access_sequence);
    return 0;
}