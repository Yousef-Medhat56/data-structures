#include "../include/book.h"
#include "./utils/validator.cpp"

Book::Book(int id)
{
    this->id = id;
    inputAttrValues();
    isAvailable = true;
}

void Book::inputAttrValues()
{
    Validator::readNonEmptyStr("Title: ", this->title);
    Validator::readNonEmptyStr("Author name: ", this->author);
    Validator::readNonEmptyStr("Genre: ", this->genre);
}

void Book::printDetails()
{
    cout << "Id: " << id << endl;
    cout << "Title: " << title << endl;
    cout << "Author name: " << author << endl;
    cout << "Genre: " << genre << endl;
    cout << "Status: " << (isAvailable ? "Available" : "Not available") << endl;
}

int Book::getId()
{
    return id;
}

string Book::getTitle()
{
    return title;
}
string Book::getAuthor()
{
    return author;
}
string Book::getGenre()
{
    return genre;
}
bool Book::getStatus()
{
    return isAvailable;
}
void Book::toggleStatus()
{
    isAvailable = !isAvailable;
}