#include <iostream>
#include <string>
using namespace std;

class IHazStringPtr {
private:
    string* str;

public:
    
    IHazStringPtr(const string& s) {
        str = new string(s);
    }

    //功能上是一模一样的
    // IHazStringPtr(const IHazStringPtr& other):str(new string(*other.str)) {

    // }
    IHazStringPtr(const IHazStringPtr& other) {
        str = new string(*other.str);
    }

    // a = b;把b的字符串的内容拷贝给a
    //左边的a已经有空间了
    IHazStringPtr &operator=(const IHazStringPtr &other){
        *str = *other.str; // 指针赋值给指针
        return *this;
    };

    //功能上是一模一样的
    // IHazStringPtr(const IHazStringPtr&other):str(other.str){

    // }
    // IHazStringPtr(const IHazStringPtr&other){
    //     str = other.str;
    // }

    ~IHazStringPtr() {
        printf("destructor : %x\n", str);
        delete str;
    }


    string getValue() const {
        return *str;
    }

    
    void setValue(const string& s) {
        *str = s;
    }
};

int main() {
    IHazStringPtr obj1("Hello");
    IHazStringPtr obj2 = obj1; //copy constructor
    IHazStringPtr obj3("World"); //constructor
    obj3 = obj1;  // operator =   deep copy
        //" avnefusenf" <-   //赋值的时候，是复制了一份string的内容，而不是指针

    obj1.setValue("New Value");

    cout << "obj1: " << obj1.getValue() << endl;
    cout << "obj2: " << obj2.getValue() << endl;
    cout << "obj3: " << obj3.getValue() << endl;

    return 0;
}
