#include "../include/library.h"


DynamicArray<Book *>* Library::getBooksList(){
return &booksList;
}

Library::~Library(){
     for (int i = 0; i < booksList.getSize(); i++) {
        delete booksList.getElmByIndex(i);
    }
}