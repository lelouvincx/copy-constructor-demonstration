import streamlit as st
from streamlit_agraph import agraph, Node, Edge, Config
from libapp import Book, Library


# Main streamlit
st.set_page_config(
    page_title="Copy Constructor Demonstration",
    page_icon="📚",
    layout="centered",
    initial_sidebar_state="expanded",
)
st.title("Copy Constructor Demonstration")

st.sidebar.markdown("## ⚙ Settings")

# Library
st.sidebar.markdown("### 📚 Library")
# Select number of libraries
libraries = []
num_libraries = st.sidebar.slider(
    "Number of libraries", min_value=1, max_value=10, value=1, step=1
)
# Fill in name of each library
for i in range(num_libraries):
    library_name = st.sidebar.text_input(f"Fill in the name of Library {i+1}")
    libraries.append(Library(library_name))
    st.sidebar.divider()
# Get list name of libraries
name_libraries = [library.getName() for library in libraries]

# Book
st.sidebar.markdown("### 📖 Book")
# Select number of books
books = []
num_books = st.sidebar.slider(
    "Number of books", min_value=1, max_value=10, value=1, step=1
)
# Fill in information of each book
for i in range(num_books):
    book_id = st.sidebar.text_input(f"Fill in the ID of Book {i+1}")
    book_author = st.sidebar.text_input(f"Fill in the Author of Book {i+1}")
    book_title = st.sidebar.text_input(f"Fill in the Title of Book {i+1}")
    books.append(Book(book_id, book_author, book_title))
    # Select library
    book_library = None
    book_library = st.sidebar.selectbox(
        f"Select the library of Book {i+1}", name_libraries
    )
    # Add book to library
    if book_library is not None:
        for library in libraries:
            if library.getName() == book_library:
                library.addOneBook(books[i])
                break
    st.sidebar.divider()

# Select which library to copy from
library = None
name_library = st.sidebar.selectbox("Select the library to copy", name_libraries)
for lib in libraries:
    if lib.getName() == name_library:
        library = lib
        break
if st.sidebar.button(f"Copy {library.getName()}"):
    # Input new name for the copy
    new_name = None
    new_name = st.sidebar.text_input(f"Fill in the new name (must be different from the original library) of {library.getName()}", "HUST")
    if new_name is not None:
        new_library = Library(library) # Copy
        new_library.setName(new_name) # Rename
        libraries.append(new_library)
        # Add new_library's books to books
        for book in new_library.getStock():
            books.append(book)
        # Update nums
        num_books = len(books)
        num_libraries = len(libraries)
        st.sidebar.success(f"Successfully copied {library.getName()} to {new_name}")

# Display all libraries
st.markdown("## 📚 Libraries")
st.write(f"Number of libraries: {len(libraries)}")
for library in libraries:
    st.markdown(f"### 📕 {library.getName()}")
st.markdown("## 📖 Books")
st.write(f"Number of books: {len(books)}")
for book in books:
    st.markdown(f"### 📗 {book.getTitle()}")

# Visualize using agraph
st.markdown("## 📊 Visualization")

nodes = []
edges = []

# Add library nodes
for i in range(num_libraries):
    nodes.append(Node(id=libraries[i].getName(), label=libraries[i].getName(), size=30))

# Add book nodes and edge to their library
for i in range(num_books):
    nodes.append(Node(id=books[i].getNumber(), label=books[i].getTitle(), size=15))

# Add edges
for i in range(num_libraries):
    stock_vector = libraries[i].getStock()
    for book in stock_vector:
        edges.append(Edge(source=libraries[i].getName(), target=book.getNumber()))

config = Config(width=750, height=750, directed=True, physics=True, hierarchical=False)
agraph(nodes=nodes, edges=edges, config=config)
