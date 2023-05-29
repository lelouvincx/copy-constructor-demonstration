from libapp import Book, Library

def demo():
    # Create a library
    library = Library("HCMUS")

    # Create 2 books
    c = Book("000", "ABC", "C Programming")
    java = Book("001", "XYZ", "Java Programming")
    python = Book("002", "XYZ", "Python Programming")

    # Add books to the library
    library.addOneBook(c)
    library.addOneBook(java)
    library.addOneBook(python)

    # Register 1 borrowers name Alice and Bob
    library.registerOneBorrower("Alice")
    library.registerOneBorrower("Bob")

    # Create library1 HUST copied from library
    library1 = Library(library)
    library1.setName("HUST")

    # Display all libraries
    library.display()
    print("----")
    library1.display()


demo()
