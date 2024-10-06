#include <iostream>
#include <vector>
#include <cmath>
#include <string>
using namespace std;

// 运算符枚举
enum Operator { ADD, SUBTRACT, MULTIPLY, DIVIDE };

// 将运算符转换为字符
char operatorToChar(Operator op) {
    switch (op) {
        case ADD: return '+';
        case SUBTRACT: return '-';
        case MULTIPLY: return '*';
        case DIVIDE: return '/';
    }
    return ' ';
}

// 计算两个数的结果
double applyOperator(double a, double b, Operator op) {
    switch (op) {
        case ADD: return a + b;
        case SUBTRACT: return a - b;
        case MULTIPLY: return a * b;
        case DIVIDE: 
            if (b != 0) return a / b;
            else return NAN;  // 防止除以0
    }
    return NAN;
}

// 递归函数，使用回溯法解决Countdown问题
void countdownHelper(vector<double>& numbers, double target, vector<string>& expression, vector<string>& bestExpression, double& closestResult, double currentResult) {
    if (numbers.size() == 1) {
        // 如果只剩一个数字，检查它是否等于目标值
        if (abs(numbers[0] - target) < 1e-6) {
            bestExpression = expression;
            closestResult = numbers[0];
        }

        // 更新最接近的结果
        if (abs(numbers[0] - target) < abs(closestResult - target)) {
            bestExpression = expression;
            closestResult = numbers[0];
        }
        return;
    }

    // 遍历每一对数字
    for (int i = 0; i < numbers.size(); ++i) {
        for (int j = i + 1; j < numbers.size(); ++j) {
            vector<double> remainingNumbers;
            for (int k = 0; k < numbers.size(); ++k) {
                if (k != i && k != j) {
                    remainingNumbers.push_back(numbers[k]);
                }
            }

            // 尝试每种运算符
            vector<Operator> ops = {ADD, SUBTRACT, MULTIPLY, DIVIDE};
            for (auto op : ops) {
                double result = applyOperator(numbers[i], numbers[j], op);

                // 忽略非法的运算（如除以0）
                if (isnan(result)) {
                    continue;
                }

                // 构造逆波兰表达式
                string rpnExpr = to_string(numbers[i]) + " " + to_string(numbers[j]) + " " + operatorToChar(op);
                expression.push_back(rpnExpr);

                // 递归调用
                remainingNumbers.push_back(result);
                countdownHelper(remainingNumbers, target, expression, bestExpression, closestResult, result);
                remainingNumbers.pop_back();
                expression.pop_back();
            }
        }
    }
}

// 解决Countdown问题的函数
void countdown(vector<double> numbers, double target) {
    vector<string> expression;
    vector<string> bestExpression;
    double closestResult = 1e9;  // 初始为一个很大的值

    countdownHelper(numbers, target, expression, bestExpression, closestResult, 0);

    if (abs(closestResult - target) < 1e-6) {
        cout << "找到准确解法 (逆波兰表达式): ";
        for (const string& expr : bestExpression) {
            cout << expr << " ";
        }
        cout << "= " << target << endl;
    } else {
        cout << "没有找到准确解，最接近的解法 (逆波兰表达式): ";
        for (const string& expr : bestExpression) {
            cout << expr << " ";
        }
        cout << "= " << closestResult << " (目标值: " << target << ")" << endl;
    }
}

int main() {
    vector<double> numbers = {25, 50, 75, 100, 3, 6};  // 给定数字
    double target = 952;  // 目标值

    countdown(numbers, target);

    return 0;
}
