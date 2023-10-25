#include "../source/dynamic-array.cpp"
#include "../source/book.cpp"

class Library
{
private:
    DynamicArray<Book *> booksList;

public:
    DynamicArray<Book *> *getBooksList();
    int assignNewBookId(); //assign the id of the new added book
    void addBook(); // push a new book object to the books list

    ~Library();
};