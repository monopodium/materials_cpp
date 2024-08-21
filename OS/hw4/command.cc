#include <iostream>
#include <cstdlib> // 用于std::atoi


// 
int main(int xiaoming, char* argv[]) {
    std::cout << "argc:" << xiaoming << std ::endl;
    // 检查命令行参数的数量是否正确
    if (xiaoming != 3) {
        std::cerr << "Usage: " << argv[0] << " <num1> <num2>" << std::endl;
        return 1;
    }

    // 将命令行参数转换为整数
    std::cout << "argv[0] = " << argv[0] << std::endl;
    int num1 = std::atoi(argv[1]);
    int num2 = std::atoi(argv[2]);

    // 计算并输出和
    int sum = num1 + num2;
    std::cout << "The sum of " << num1 << " and " << num2 << " is " << sum << std::endl;

    return 0;
}
