#include <iostream>
#include <vector>
using namespace std;
int partition(vector<int> &vec, int low, int high)
{
    vector<int> vec_2(high + 1);
    int pivot = vec[high];
    int n = (low + high + 1) / 2;
    vector<int> left(n);
    vector<int> right(high + 1 - n);
    int left_a = 0;
    int right_a = 0;
    for (int i = 0; i <= high; i++)
    {
        if (vec[i] <= pivot)
        {
            left[left_a] = vec[i];
            left_a++;
        }
        else if (vec[i] > pivot)
        {
            right[right_a] = vec[i];
            right_a++;
        }
    }
    for (int j = 0; j <= n; j++)
    {
        vec_2[j] = left[j];
    }
    for (int j = left_a; j <= high; j++)
    {
        vec_2[j] = right[n - left_a];
    }
    vec = vec_2;
    return left_a - 1;
}

void quicksort(vector<int> &vec, int low, int high)
{
    int b = partition(vec, low, high);
    quicksort(vec, low, b - 1);
    quicksort(vec, b + 1, high);
}

void printVector(const vector<int> &vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << " ";
    }
    cout << endl;
}

int main()
{
    vector<int> xxy{8, 6, 3, 10, 31, 4, 2, 1};
    printVector(xxy);
    quicksort(xxy, 0, xxy.size() - 1);
    printVector(xxy);
    return 0;
}