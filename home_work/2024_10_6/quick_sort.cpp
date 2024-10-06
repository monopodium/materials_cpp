#include <iostream>
using namespace std;

// 快速排序的分区函数
int partition(int arr[], int low, int high) {
    int pivot = arr[high];  // 选择最后一个元素作为枢轴
    int i = low - 1;  // i 是小于枢轴的元素的最后一个索引

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            // 交换 arr[i] 和 arr[j]
            swap(arr[i], arr[j]);
        }
    }
    // 将枢轴元素放到正确的位置
    swap(arr[i + 1], arr[high]);
    return i + 1;  // 返回枢轴的位置
}

// 快速排序的递归函数
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        // 获取分区点
        int pi = partition(arr, low, high);

        // 递归排序分区的两边
        quickSort(arr, low, pi - 1);  // 排序左边
        quickSort(arr, pi + 1, high);  // 排序右边
    }
}

// 打印数组
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    cout << "排序前的数组: ";
    printArray(arr, n);

    quickSort(arr, 0, n - 1);
    
    cout << "排序后的数组: ";
    printArray(arr, n);

    return 0;
}
