#include <pybind11/pybind11.h>
#include <pybind11/iostream.h>
#include <pybind11/stl.h>
#include <vector>
#include "libapp.cpp"
using namespace std;

namespace py = pybind11;

PYBIND11_MODULE(libapp, m) {
    // Redirect the output from std::cout to Python
    py::scoped_ostream_redirect output;

    py::class_<BorrowerRecord>(m, "BorrowerRecord")
        .def(py::init<>())
        .def(py::init<string>())
        .def("getName", &BorrowerRecord::getName)
        .def("setName", &BorrowerRecord::setName)
        .def("display", &BorrowerRecord::display);

    py::class_<Book>(m, "Book")
        .def(py::init<string, string, string>())
        .def(py::init<string>())
        .def(py::init<>())
        .def("getNumber", &Book::getNumber)
        .def("getAuthor", &Book::getAuthor)
        .def("getTitle", &Book::getTitle)
        .def("getBorrower", &Book::getBorrower)
        .def("setNumber", &Book::setNumber)
        .def("setAuthor", &Book::setAuthor)
        .def("setTitle", &Book::setTitle)
        .def("display", &Book::display)
        .def("attachBorrower", &Book::attachBorrower)
        .def("detachBorrower", &Book::detachBorrower);

    py::class_<Library>(m, "Library")
        .def(py::init<>())
        .def(py::init<string>())
        .def(py::init<const Library&>())
        .def("getName", &Library::getName)
        .def("getStock", &Library::getStock)
        .def("getBorrowers", &Library::getBorrowers)
        .def("setName", &Library::setName)
        .def("display", &Library::display)
        .def("registerOneBorrower", &Library::registerOneBorrower)
        .def("addOneBook", &Library::addOneBook)
        .def("displayBooksAvailable", &Library::displayBooksAvailable)
        .def("displayBooksBorrowed", &Library::displayBooksBorrowed)
        .def("borrowOneBook", &Library::borrowOneBook)
        .def("returnOneBook", &Library::returnOneBook)
        .def_property("_stock", &Library::getStock, &Library::setStock);
}
