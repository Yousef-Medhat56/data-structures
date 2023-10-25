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
    return -1;
}

void Library::removeBook(int id)
{
    int bookIndex = findBookById(id);
    if (bookIndex >= 0)
    {
        booksList.remove(bookIndex);
    }
}

Library::~Library()
{
    for (int i = 0; i < booksList.getSize(); i++)
    {
        delete booksList.getElmByIndex(i);
    }
}