#include "my_vector.h"




void my_vector::push_back(const T& value)
{
    //要不满足条件了，就重新new一个数组，把旧值重新拷贝过来
    data[size] = value;
    size++;
}

my_vector my_vector::&operator+(const my_vector &other)
{
        int new_size = size +other.size;
        my_vector new_result(new_size);
        for(int i =0;i<other.size;i++)
        {
            new_result.push_back(other.data[i]);
        }
        return new_result;

}