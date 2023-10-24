#include "../source/library.cpp"

int main()
{

    Library library;

    Book *book1 = new Book(1); // Create a Book object dynamically
    library.getBooksList()->push(book1);
    for (int i = 0; i < library.getBooksList()->getSize(); i++)
    {
        library.getBooksList()->getElmByIndex(i)->printDetails();
    }

    return 0;
}