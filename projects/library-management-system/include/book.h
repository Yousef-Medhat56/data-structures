#include <string>
using namespace std;

class Book
{
private:
    int id;
    string title;
    string author;
    string genre;
    bool isAvailable; // The book status (available or not)

public:
    Book(int id);
    int getId();            // get the book id
    void inputAttrValues(); // ask the user to input the attributes values
    void printDetails();    // print the book details
};