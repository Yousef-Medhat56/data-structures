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
    void removeBook(int id); //remove a book by its id
    int findBookById(int id); //find a book by its id and returns its index;
    ~Library();
};