#include <iostream>
using namespace std;

// 快速排序的分区函数
int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // 选择最后一个元素作为基准
    int i = low - 1; // i是小于基准的元素的最后位置

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]); // 把小于基准的元素移到前面
        }
    }
    swap(arr[i + 1], arr[high]); // 将基准放到正确位置
    return i + 1; // 返回基准的位置
}

// 快速排序的递归函数
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high); // 找到分区点
        quickSort(arr, low, pi - 1); // 对分区点左边进行递归排序
        quickSort(arr, pi + 1, high); // 对分区点右边进行递归排序
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
    cout << "原数组: ";
    printArray(arr, n);

    quickSort(arr, 0, n - 1);

    cout << "排序后数组: ";
    printArray(arr, n);
    return 0;
}
