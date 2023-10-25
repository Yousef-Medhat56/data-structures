#include "../source/dynamic-array.cpp"
#include "../source/book.cpp"

class Library
{
private:
    DynamicArray<Book *> booksList;

public:
    DynamicArray<Book *> *getBooksList();
    int assignNewBookId();         // assign the id of the new added book
    void addBook();                // push a new book object to the books list
    void removeBook(int id);       // remove a book by its id
    int findBookById(int id);      // find a book by its id and returns its index;
    int searchForBook(string val); // search for a book by its id, title, author or genre and returns its index
    void displayAllBooks();
    void displayAvailableBooks();
    void displayBorrowedBooks();
    void borrowBook(int id); // borrow a book
    void returnBook(int id); // return a borrowed book
    ~Library();
};