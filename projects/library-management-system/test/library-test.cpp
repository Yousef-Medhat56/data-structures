#include "../source/library.cpp"

int main()
{

    Library library;

   library.addBook();
   library.addBook();
   library.addBook();
   
    for (int i = 0; i < library.getBooksList()->getSize(); i++)
    {
        library.getBooksList()->getElmByIndex(i)->printDetails();
    }

    return 0;
}