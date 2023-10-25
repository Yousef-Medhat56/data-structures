#include "../source/library.cpp"

int main()
{

    Library library;
    cout << library.findBookById(1) << endl; // should return -1
    library.addBook();
    cout << library.findBookById(1) << endl; // should return 0

    library.addBook();
    library.addBook();

    for (int i = 0; i < library.getBooksList()->getSize(); i++)
    {
        library.getBooksList()->getElmByIndex(i)->printDetails();
    }

    return 0;
}