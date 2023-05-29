#include <iostream>
using namespace std;

class Test {
public:
    // Constructors
    Test() {
        cout << "Created from constructor" << endl;
    }

    Test(const Test& t) {
        cout << "Created from copy constructor" << endl;
    }

    Test& operator = (const Test& t) {
        cout << "Created from assignment operator" << endl;
        return *this;
    }
};

int main() {
    Test t1, t2;
    t2 = t1; // = operator
    Test t3 = t1; // Copy constructor

    return 0;
}
