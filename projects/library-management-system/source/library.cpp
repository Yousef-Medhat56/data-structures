#include "../include/library.h"

Library::~Library(){
     for (int i = 0; i < booksList.getSize(); i++) {
        delete booksList.getElmByIndex(i);
    }
}