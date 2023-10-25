#include "../source/library.cpp"

int main()
{

    Library library;
    library.addBook();
    library.addBook();
    library.addBook(); // i will make this book title = "book 3"
    library.addBook();

    library.removeBook(2); // remove the 2nd book

    cout << library.searchForBook("book 3") << endl; // should return 1

    library.borrowBook(1);
    library.borrowBook(4);

    cout << "# Borrowed:" << endl;
    library.displayBorrowedBooks();
    cout << "# Available:" << endl;
    library.displayAvailableBooks();

    library.returnBook(1);

    cout << "# Borrowed:" << endl;
    library.displayBorrowedBooks();
    cout << "# Available:" << endl;
    library.displayAvailableBooks();

    cout << "# All books:" << endl;
    library.displayAllBooks();

    return 0;
}