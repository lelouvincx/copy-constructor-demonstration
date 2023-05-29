#include <iostream>
using namespace std;

class People {
private:
    string _firstName;
    string _midName;
    string _lastName;

public:
    // Constructors
    People(string firstName, string midName, string lastName) {
        _firstName = firstName;
        _midName = midName;
        _lastName = lastName;
    }

    // Methods
    void display() {
        cout << "People info: (";
        cout << "First name: " << _firstName << ", ";
        cout << "Middle name: " << _midName << ", ";
        cout << "Last name: " << _lastName << ")";
        cout << endl;
    }
};

People thisReturnsACopyOfPeople() {
    People p("John", "Smith", "Doe");
    return p;
}
