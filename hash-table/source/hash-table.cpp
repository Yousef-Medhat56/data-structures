#include "../include/hash-table.h"

template <class T>
Hash<T>::Hash()
{
    table_size = 10;
    table = new Node<T>[table_size];
}

template <class T>
Hash<T>::Hash(size_t size) : table_size(size) {
    table = new Node<T>[table_size];
}


template <class T>
Hash<T>::~Hash(){
    delete[] table;
}

template <class T>
int Hash<T>::hash(string key)
{
    int hash = 0;
    int index;
    for (int i = 0; i < key.length(); i++)
    {
        hash = hash + (int)key[i];
    }

    index = hash % table_size;
    return index;
}