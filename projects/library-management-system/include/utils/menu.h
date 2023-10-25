#ifndef MENU_H
#define MENU_H

#include <conio.h>
#include <functional>
#include "../../source/library.cpp"
using namespace std;
class Menu
{
public:
    Menu(){};

    static void header();
    static void main(Library &library);
    static void addBook(Library &library);
    static void search(Library &library);
    static void borrow(Library &library);
    static void returnBook(Library &library);
    static void printAll(Library &library);
    static void printAvailable(Library &library);
    static void printBorrowed(Library &library);
    static void stats(Library &library);
    static void remove(Library &library);
    static void footer(Library &library, function<void(Library &library)> func);
};

#endif