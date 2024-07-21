#include <iostream>
#include <iterator>

class IntegerContainer {
private:
    int* data;
    std::size_t size;

public:
    // Constructor
    IntegerContainer(std::initializer_list<int> initList) : size(initList.size()) {
        data = new int[size];
        std::copy(initList.begin(), initList.end(), data);
    }

    // Destructor
    ~IntegerContainer() {
        delete[] data;
    }

    // Iterator definition
    class Iterator1 {
    private:
        int* ptr;
    public:
        explicit Iterator1(int* p) : ptr(p) {}

        int& operator*() const {
            return *ptr;
        }

        Iterator1& operator++() {
            ++ptr;
            return *this;
        }

        bool operator!=(const Iterator1& other) const {
            return ptr != other.ptr;
        }
    };

    // begin() function
    Iterator1 begin() const {
        return Iterator1(data);
    }

    // end() function
    Iterator1 end() const {
        return Iterator1(data + size);
    }
};

int main() {
    IntegerContainer container = {1, 2, 3, 4, 5};

    for (const auto& value : container) {
        std::cout << value << " ";
    }
    std::cout << std::endl;

    return 0;
}
