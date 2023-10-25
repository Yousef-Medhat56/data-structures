#include "../source/library.cpp"

int main()
{

    Library library;
    cout << library.findBookById(1) << endl; // should return -1
    library.addBook();
    cout << library.findBookById(1) << endl; // should return 0

    library.addBook();
    library.addBook(); // i will make this book title = "book 3"

    library.removeBook(2); //remove the 2nd book
 
    cout << library.searchForBook("book 3") << endl; // should return 1

   library.displayAllBooks();

    return 0;
}