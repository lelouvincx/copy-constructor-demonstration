#include <iostream>
using namespace std;


class MyClass {
private:
    int data;

public:
    MyClass(int value) {
        data = value;
    }

    // Copy constructor
    MyClass(const MyClass& other) {
        data = other.data;
    }

    int getData() {
        return data;
    }
};

int main() {
    MyClass obj1(10); // Creating an object and initializing it with a value

    MyClass obj2 = obj1; // Using the copy constructor to create a copy of obj1

    std::cout << "obj1 data: " << obj1.getData() << std::endl; // Output: obj1 data: 10
    cout << "Id of obj1: " << &obj1 << endl; // Output: Id of obj1: 0x7fffbf7c6b90
    std::cout << "obj2 data: " << obj2.getData() << std::endl; // Output: obj2 data: 10
    cout << "Id of obj2: " << &obj2 << endl; // Output: Id of obj2: 0x7fffbf7c6b80

    return 0;
}
