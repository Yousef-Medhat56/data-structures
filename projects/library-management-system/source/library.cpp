#include "../include/library.h"

DynamicArray<Book *> *Library::getBooksList()
{
    return &booksList;
}

void Library::addBook()
{
    // the id of the new book
    int newBookId = assignNewBookId();
    Book *newBook = new Book(newBookId);
    getBooksList()->push(newBook);
    Console::success("Book added successfully!");
}

int Library::assignNewBookId()
{
    int booksListSize = booksList.getSize();

    // check if the books list is not empty
    if (booksListSize > 0)
    {
        // get the id of the last book
        int lastBookId = booksList[--booksListSize]->getId();
        return ++lastBookId;
    }
    else
    {
        return 1;
    }
}

int Library::findBookById(int id)
{
    int booksListSize = booksList.getSize();
    for (int i = 0; i < booksListSize; i++)
    {
        if (id == booksList[i]->getId())
        {
            return i;
        }
    }
    Console::error("Book doesn't exist");
    return -1;
}

void Library::removeBook(int id)
{
    int bookIndex = findBookById(id);
    if (bookIndex >= 0)
    {
        booksList.remove(bookIndex);
        Console::success("Book removed successfully!");
    }
}

int Library::searchForBook(string val)
{
    int booksListSize = booksList.getSize();
    for (int i = 0; i < booksListSize; i++)
    {
        // try to convert val to int and check if it is for a book id
        try
        {
            if (stoi(val) == booksList[i]->getId())
            {
                return i;
            }
        }
        // else, search for the book by its title, author or genre
        catch (...)
        {
            if (
                val == booksList[i]->getTitle() || val == booksList[i]->getAuthor() || val == booksList[i]->getGenre())
            {
                return i;
            }
        }
    }
    Console::error("Book doesn't exist");
    return -1;
}

void Library::displayAllBooks()
{
    int displayedBooks = 0;
    for (int i = 0; i < booksList.getSize(); i++)
    {
        booksList[i]->printDetails();
        Console::divider_v2();
        displayedBooks++;
    }
    if (displayedBooks == 0)
        cout << "There are no  books" << endl;
}

void Library::displayAvailableBooks()
{
    int displayedBooks = 0;
    for (int i = 0; i < booksList.getSize(); i++)
    {

        if (booksList[i]->getStatus())
        {
            booksList[i]->printDetails();
            Console::divider_v2();
            displayedBooks++;
        }
    }
    if (displayedBooks == 0)
        cout << "There are no available books" << endl;
}

void Library::displayBorrowedBooks()
{
    int displayedBooks = 0;
    for (int i = 0; i < booksList.getSize(); i++)
    {
        if (!booksList[i]->getStatus())
        {
            booksList[i]->printDetails();
            Console::divider_v2();
            displayedBooks++;
        }
    }
    if (displayedBooks == 0)
        cout << "There are no borrowed books" << endl;
}

void Library::borrowBook(int id)
{
    int bookIndex = findBookById(id);
    if (bookIndex >= 0)
    {
        bool isAvailable = booksList[bookIndex]->getStatus();
        if (isAvailable)
        {
            booksList[bookIndex]->toggleStatus();
            Console::success("The book is borrowed successfully");
        }
        else
            Console::error("The book is not available");
    }
}

void Library::returnBook(int id)
{
    int bookIndex = findBookById(id);
    if (bookIndex >= 0)
    {
        bool isAvailable = booksList[bookIndex]->getStatus();
        if (!isAvailable)
        {
            booksList[bookIndex]->toggleStatus();
            Console::success("The book is returned successfully");
        }
        else
            Console::error("The book is not borrowed");
    }
}

void Library::stats()
{
    int availableBooks = 0;
    int borrowedBooks = 0;
    for (int i = 0; i < booksList.getSize(); i++)
    {
        if (booksList[i]->getStatus())
            availableBooks++;
        else
            borrowedBooks++;
    }

    cout << "Total books: " << booksList.getSize() << endl;
    cout << "Available books: " << availableBooks << endl;
    cout << "Borrowed books: " << borrowedBooks << endl;
}

Library::~Library()
{
    for (int i = 0; i < booksList.getSize(); i++)
    {
        delete booksList.getElmByIndex(i);
    }
}