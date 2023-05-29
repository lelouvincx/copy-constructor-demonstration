#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

// Class BorrowerRecord definition
class BorrowerRecord {
private:
    string _name;

public:
    // Constructors
    BorrowerRecord() {
        _name = "NA";
    }

    BorrowerRecord(string name) {
        _name = name;
    }

    // Getters
    string getName() { return _name; }

    // Setters
    void setName(string name) { _name = name; }

    // Methods
    void display() {
        cout << "Borrower info: (";
        cout << "Name: " << getName() << ")";
        cout << endl;
    }
};

// Class Book definition
class Book {
private:
    string _number;
    string _author;
    string _title;
    BorrowerRecord* _borrower;

    // Private setters
    void setBorrower(BorrowerRecord* borrower) { _borrower = borrower; }

public:
    // Constructors
    Book(string number, string author, string title) {
        _number = number;
        _author = author;
        _title = title;
        _borrower = NULL;
    }

    // Chaining constructor
    Book(string number) : Book(number, "NA", "NA") {}

    // Default constructor
    Book() : Book("000") {}

    // Destructor
    // ~Book() {
    //     if (_borrower != NULL) {
    //         delete _borrower;
    //     }
    // }

    // Getters
    string getNumber() { return _number; }
    string getAuthor() { return _author; }
    string getTitle() { return _title; }
    BorrowerRecord* getBorrower() { return _borrower; }

    // Setters
    void setNumber(string number) { _number = number; }
    void setAuthor(string author) { _author = author; }
    void setTitle(string title) { _title = title; }
    // void setBorrower(BorrowerRecord* borrower) { this->_borrower = borrower; }

    // Methods
    void display() {
        cout << "Book info: (";
        cout << "Number: " << getNumber() << ", ";
        cout << "Author: " << getAuthor() << ", ";
        cout << "Title: " << getTitle() << ", ";
        cout << "Status: ";
        if (getBorrower() == NULL) {
            cout << "Available";
        } else {
            cout << "Borrowed by " << getBorrower()->getName();
        }
        cout << ")" << endl;
    }

    void attachBorrower(BorrowerRecord* borrower) {
        setBorrower(borrower);
    }

    void detachBorrower() {
        setBorrower(NULL);
    }
};

// Class Library definition
class Library {
private:
    string _name;
    vector<Book*> _stock;
    vector<BorrowerRecord*> _borrowers;

    // Private setters

public:
    // Constructors
    Library() {
        _name = "NA";
    }

    Library(string name) {
        _name = name;
    }

    // Copy constructor
    Library(const Library& other) {
        cout << "Copy constructor called" << endl;
        _name = other._name;
        // Deep copy of _stock
        for (int i = 0; i < (int)other._stock.size(); i++) {
            string tmp_number = other._stock[i]->getNumber() + "_copy";
            string tmp_author = other._stock[i]->getAuthor() + "_copy";
            string tmp_title = other._stock[i]->getTitle() + "_copy";
            cout << "Book " << i << " copied" << endl;
            Book* tmp_book = new Book(tmp_number, tmp_author, tmp_title);
            _stock.push_back(tmp_book);
        }
        // Deep copy of _borrowers
        for (int i = 0; i < (int)other._borrowers.size(); i++) {
            string tmp_name = other._borrowers[i]->getName() + "_copy";
            cout << "Borrower " << i << " copied" << endl;
            BorrowerRecord* tmp_borrower = new BorrowerRecord(tmp_name);
            _borrowers.push_back(tmp_borrower);
        }
        cout << "Copy constructor finished" << endl;
    }

    // Comment when use in python, uncomment when not
    // Destructor
    // ~Library() {
    //     cout << "Destructor called" << endl;
    //     for (vector<Book*>::iterator it = _stock.begin(); it != _stock.end(); it++) {
    //         if (*it != NULL) {
    //             delete *it;
    //         }
    //     }
    //     for (vector<BorrowerRecord*>::iterator it = _borrowers.begin(); it != _borrowers.end(); it++) {
    //         if (*it != NULL) {
    //             delete *it;
    //         }
    //     }
    //     cout << "Destructor finished" << endl;
    // }

    // Getters
    string getName() { return _name; }
    vector<Book*> getStock() { return _stock; }
    vector<BorrowerRecord*> getBorrowers() { return _borrowers; }

    // Setters
    void setName(string name) { _name = name; }
    void setStock(vector<Book*> stock) { _stock = stock; }
    void setBorrowers(vector<BorrowerRecord*> borrowers) { _borrowers = borrowers; }

    // Methods
    // 0. Display library
    void display() {
        cerr << "System: Library info: " << endl;
        cout << "\tName:\t" << getName() << endl;
        cout << "\tStock:\t" << endl;
        for (int i = 0; i < (int)_stock.size(); i++) {
            cout << "\t";
            _stock[i]->display();
        }
        cout << "\tBorrowers:\t" << endl;
        for (int i = 0; i < (int)_borrowers.size(); i++) {
            cout << "\t";
            _borrowers[i]->display();
        }
    }

    // 1. Register a new borrower
    void registerOneBorrower(string name) {
        BorrowerRecord* borrower = new BorrowerRecord(name);
        _borrowers.push_back(borrower);
        cout << "System: Borrower " << name << " registered." << endl;
    }

    // 2. Add a new book to the stock
    void addOneBook(Book* book) {
        _stock.push_back(book);
        cout << "System: Book " << book->getNumber() << " added." << endl;
    }

    // 3. Display books available for borrowing
    void displayBooksAvailable() {
        cout << "System: Books available for borrowing: " << endl;
        for (int i = 0; i < (int)_stock.size(); i++) {
            if (_stock[i]->getBorrower() == NULL) {
                _stock[i]->display();
            }
        }
    }

    // 4. Display books borrowed
    void displayBooksBorrowed() {
        cout << "System: Books borrowed: " << endl;
        for (int i = 0; i < (int)_stock.size(); i++) {
            if (_stock[i]->getBorrower() != NULL) {
                _stock[i]->display();
            }
        }
    }

    // 5. Borrow a book
    void borrowOneBook(string bookNumber, string borrowerName) {
        // Find the book
        Book* book = NULL;
        for (int i = 0; i < (int)_stock.size(); i++) {
            if (_stock[i]->getNumber() == bookNumber) {
                book = _stock[i];
                break;
            }
        }

        // Find the borrower
        BorrowerRecord* borrower = NULL;
        for (int i = 0; i < (int)_borrowers.size(); i++) {
            if (_borrowers[i]->getName() == borrowerName) {
                borrower = _borrowers[i];
                break;
            }
        }

        // Borrow the book
        if (book != NULL && borrower != NULL) {
            book->attachBorrower(borrower);
        }
        cout << "System: Book " << bookNumber << " borrowed by " << borrowerName << "." << endl;
    }

    // 6. Return a book
    void returnOneBook(string bookNumber) {
        // Find the book
        Book* book = NULL;
        for (int i = 0; i < (int)_stock.size(); i++) {
            if (_stock[i]->getNumber() == bookNumber) {
                book = _stock[i];
                break;
            }
        }

        // Return the book
        if (book != NULL) {
            book->detachBorrower();
        }
        cout << "System: Book " << bookNumber << " returned." << endl;
    }
};

int main() {
    // Create a library
    Library library = Library("HCMUS");

    // Create 3 books
    Book* c = new Book("001", "ABC", "C Programming");
    Book* java = new Book("002", "DEF", "Java Programming");
    Book* python = new Book("003", "GHI", "Python Programming");

    // Add 3 books to the library
    library.addOneBook(c);
    library.addOneBook(java);
    library.addOneBook(python);

    // Register 2 borrowers name Alice and Bob
    library.registerOneBorrower("Alice");
    library.registerOneBorrower("Bob");

    // Create library HUST copied from library HCMUS
    // Library library2 = library;
    // library2.setName("HUST");

    // Display library
    library.display();
    // cout << "----------------------------------------" << endl;
    // library2.display();

    // Alice comes and views books available for borrowing
    cout << "\n\nAlice comes and views books available for borrowing" << endl;
    library.displayBooksAvailable();

    // Alice borrows the book 'python programming'
    cout << "\n\nAlice borrows the book 'python programming'" << endl;
    library.borrowOneBook("003", "Alice");

    // Bob comes and views books available for borrowing
    cout << "\n\nBob comes and views books available for borrowing" << endl;
    library.displayBooksAvailable();

    // Bob borrows the book 'java programming'
    cout << "\n\nBob borrows the book 'java programming'" << endl;
    library.borrowOneBook("002", "Bob");

    // Alice return the book 'python programming'
    cout << "\n\nAlice return the book 'python programming'" << endl;
    library.returnOneBook("003");

    // Display library
    cout << "\n\nDisplay library" << endl;
    library.display();
    return 0;
}
