#include "../source/dynamic-array.cpp"
#include "../source/book.cpp"

class Library
{
private:
    DynamicArray<Book *> booksList;

public:
    DynamicArray<Book *>* getBooksList();
    ~Library();
};