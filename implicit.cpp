#include <iostream>
using namespace std;

class Sample1 {
    int id;
};

class Sample2 {
private:
    int id;

public:
    Sample2(int value=0) {
        cout << "Created from constructor" << endl;
        id = value;
    }

    Sample2(Sample2& sp) {
        cout << "Created from copy constructor" << endl;
        id = sp.id;
    }
};

int main() {
    Sample2 a(10); // Created from constructor
    Sample2 b = a; // Created from copy constructor

    cout << "Id of a: " << &a << endl;
    cout << "Id of b: " << &b << endl;
    return 0;
}
