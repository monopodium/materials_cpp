#include <iostream>
#include <vector>
using namespace std;

class MinHeap {
private:
    vector<int> heap;  // 存储堆的数组

    // 返回父节点的索引
    int parent(int i) { return (i - 1) / 2; }

    // 返回左孩子的索引
    int left(int i) { return (2 * i + 1); }

    // 返回右孩子的索引
    int right(int i) { return (2 * i + 2); }

    // 将节点 i 下沉到适当位置
    void heapifyDown(int i) {
        int smallest = i;
        int l = left(i);
        int r = right(i);

        // 找出左右孩子中较小的
        if (l < heap.size() && heap[l] < heap[smallest])
            smallest = l;
        if (r < heap.size() && heap[r] < heap[smallest])
            smallest = r;

        // 如果最小值不是当前节点，交换并递归
        if (smallest != i) {
            swap(heap[i], heap[smallest]);
            heapifyDown(smallest);
        }
    }

    // 将节点 i 上浮到适当位置
    void heapifyUp(int i) {
        if (i && heap[parent(i)] > heap[i]) {
            // 如果父节点大于当前节点，交换并递归
            swap(heap[i], heap[parent(i)]);
            heapifyUp(parent(i));
        }
    }

public:
    // 插入一个新元素
    void insert(int key) {
        heap.push_back(key);
        int index = heap.size() - 1;
        heapifyUp(index);  // 上浮调整
    }

    // 获取并删除最小元素
    int extractMin() {
        if (heap.size() == 0)
            throw out_of_range("Heap is empty");

        int root = heap[0];
        heap[0] = heap.back();
        heap.pop_back();  // 删除最后一个元素

        heapifyDown(0);  // 下沉调整

        return root;
    }

    // 获取最小元素但不删除
    int getMin() {
        if (heap.size() == 0)
            throw out_of_range("Heap is empty");
        return heap[0];
    }

    // 打印堆
    void printHeap() {
        for (int i : heap) {
            cout << i << " ";
        }
        cout << endl;
    }
};

int main() {
    MinHeap h;

    h.insert(3);
    h.insert(2);
    h.insert(15);
    h.insert(5);
    h.insert(4);
    h.insert(45);

    cout << "堆内容: ";
    h.printHeap();

    cout << "最小值: " << h.getMin() << endl;

    cout << "提取最小值: " << h.extractMin() << endl;
    
    cout << "堆内容: ";
    h.printHeap();

    return 0;
}
