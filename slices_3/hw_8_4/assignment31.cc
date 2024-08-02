//1. 对于vector<int>和list<int>分别实现一份sort函数
// 2.实现两个类:my_list底层用linked-list存储数据，my_vec底层用array存储数据，利用template，
//使得两个类分别能和真正的stl中定义的vector/list一样，存储double, int., float...的数据，
//并且给这两个类写begin和end函数，返回指向头和尾的iterator.   
//3.给my_list里存储的元素和my_vec里存储的元素排序
//my_list和my_vec就是为了模仿vector和list的

    #include<iostream>  
    using namespace std; 
    #include<string>
    #include <fstream>
    #include <vector>
    #include <list>
    using std:: vector;
void sort_vector(vector<int>& vec)
{
    for(int i =0;i<vec.size()-1;i++)
    {
        for(int j =i+1;j<vec.size()-1;j++)
        {
            if(vec[i] > vec[j])
            {
                int temp = vec[i];
                vec[i] = vec[j];
                vec[j] = temp;
            }
        }
    }
}
void list_sort(list<int>& lst)
{
    lst.sort();
}
//template
template<typename T>
class Node
{
    private:
    T data;
    Node *next;
};
template<typename T>
class my_list
{
    private:
    Node<T> *head;
    Node<T> *tail;

    public:
    class iterator
    {
        private:
        Node<T> *ptr;
        public:
        Iterator(Node<T> p)
        {
            Node<T> node = p;
        }
        
        T& operator*() const
        {
            return node->data;
        }
        iterator& operator++()
        {
            this->node = node->next;
            return *this;
        }
        bool operator!=(const iterator& other)
        {
            return node !=  other.node;
        }
    };
    iterator begin() const
    {
        cout<<"重载了begin()函数！！"<<endl;
        return iterator(head);
    }

    iterator end() const
    {
        cout<<"重载了end()函数！！"<<endl;
        return iterator(tail);
    }

    void sort()
    {
        
    }
};
template<class T>
class my_vector
{
    private:
        T *data; //push的时候，要去检查size的大小，
        //要是不满足条件了，就重新new一个数组
        int size = 0;
    public:
        int& operator[]{

        }
        my_vector(int max_size)
        {
            data = new T[max_size];
        }
        void push_back(T input){
            //要是不满足条件了，就重新new一个数组,把旧值拷贝过来
            data[size] = input;
            size++;
        }
        class iterator 
        {
            private:
                T* ptr;
            public:
                iterator(T* p) : ptr(p) {}

                iterator& operator++() {
                    ++ptr;
                    return *this;
                }

                bool operator!=(const iterator& other) const {
                    return ptr != other.ptr;
                }

                T& operator*() {
                    return *ptr;
                }
        };

    iterator begin() {
        return iterator(data);
    }

    iterator end() {
        return iterator(data + size);
    }


};


int main()
{
    vector<int> vec_1{11,3,44,25,19,8,10};
    sort_vector(vec_1);

    my_list<int> list_1{5,12,30,56,7,20,1};
    list_sort(list_1);



    return 0;
}