#include "../../include/utils/menu.h"

void Menu::header()
{
    Console::clear();
    Console::divider();
    cout << "\tLibrary Management System" << endl;
    Console::divider();
    cout << endl;
}

void Menu::main(Library &library)
{
    Menu::header();
    cout << "1.Add a new book\n"
         << "2.Search for a book\n"
         << "3.Borrow a book\n"
         << "4.Return a book\n"
         << "5.Print all books\n"
         << "6.Print available books\n"
         << "7.Print borrowed books\n"
         << "8.Books statistics\n"
         << "9.Remove a book\n"
         << "0.exit\n"
         << "Enter your choice: ";

    bool exit_loop;
    do
    {
        exit_loop = true;
        switch (getch())
        {
        case '1':
            addBook(library);
            break;
        case '2':
            search(library);
            break;
        case '3':
            borrow(library);
            break;

        case '4':
            returnBook(library);
            break;

        case '5':
            printAll(library);
            break;
        case '6':
            printAvailable(library);
            break;
        case '7':
            printBorrowed(library);
            break;
        case '8':
            stats(library);
            break;
        case '9':
            remove(library);
            break;

        case '0':
            cout << 0 << endl;
            exit(1);

        default:
            exit_loop = false;
        }
    } while (!exit_loop);
}

void Menu::addBook(Library &library)
{

    Menu::header();
    cout << "Enter book info" << endl;
    Console::divider();
    library.addBook();
    // go back to the main menu
    Menu::footer(library, [](Library &library)
                 { main(library); });
}

void Menu::search(Library &library)
{
    Menu::header();
    string val;
    Validator::readNonEmptyStr("Search by Id, title, author or genre: ", val);
    int bookIndex = library.searchForBook(val);

    if (bookIndex >= 0)
    {
        library.getBooksList()->getElmByIndex(bookIndex)->printDetails();
    }
    // go back to the main menu
    Menu::footer(library, [](Library &library)
                 { main(library); });
}

void Menu::borrow(Library &library)
{
    Menu::header();
    int bookId;
    Validator::readPositiveNum("Enter book id: ", bookId);
    library.borrowBook(bookId);
    // go back to the main menu
    Menu::footer(library, [](Library &library)
                 { main(library); });
}

void Menu::returnBook(Library &library)
{
    Menu::header();
    int bookId;
    Validator::readPositiveNum("Enter book id: ", bookId);
    library.returnBook(bookId);
    // go back to the main menu
    Menu::footer(library, [](Library &library)
                 { main(library); });
}

void Menu::printAll(Library &library)
{
    Menu::header();

    library.displayAllBooks();
    // go back to the main menu
    Menu::footer(library, [](Library &library)
                 { main(library); });
}
void Menu::printAvailable(Library &library)
{
    Menu::header();

    library.displayAvailableBooks();
    // go back to the main menu
    Menu::footer(library, [](Library &library)
                 { main(library); });
}
void Menu::printBorrowed(Library &library)
{
    Menu::header();

    library.displayBorrowedBooks();
    // go back to the main menu
    Menu::footer(library, [](Library &library)
                 { main(library); });
}
void Menu::stats(Library &library)
{
    Menu::header();

    library.stats();
    // go back to the main menu
    Menu::footer(library, [](Library &library)
                 { main(library); });
}

void Menu::remove(Library &library)
{
    Menu::header();
    int bookId;
    Validator::readPositiveNum("Enter book id: ", bookId);
    library.removeBook(bookId);
    // go back to the main menu
    Menu::footer(library, [](Library &library)
                 { main(library); });
}

void Menu::footer(Library &library, function<void(Library &library)> func)
{
    cout << "Press 0 to go back\n";
    bool exit_loop;
    do
    {
        exit_loop = true;
        switch (getch())
        {
        case '0':
            func(library);
            break;
        default:
            exit_loop = false;
        }
    } while (!exit_loop);
}