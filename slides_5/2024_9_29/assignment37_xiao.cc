// 前序+中序+后序 遍历一个tree

#include <iostream>
using namespace std;
#include<vector>
#include<algorithm>

//快速排序
void Quick_sort(int array[],int start,int end)
{

    int pivot = array[start];
    int left = start;
    int right = end-1;
    while(left<right)
    {

        while(left < right &&array[right] >= pivot)
        {
            right--;
        }
        while(left < right &&array[left] <=pivot)
        {
            left++;
        }
        if (left < right)
        {
            std::swap(array[left], array[right]);
        }
    }
    swap(array[start],array[left]);

    Quick_sort(array,start,left-1);
    Quick_sort(array,left+1,end);
    
}

int main()
{
    int array[] = {2,11,30,29,40,5,11,78,9,100};
    int size = sizeof(array) / sizeof(array[0]);
    Quick_sort(array,0,size-1);
        for (int i = 0; i < size; i++)
    {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}