#include "../include/hash-table.h"

Hash::Hash()
{
    table_size = 100;
}

Hash::Hash(size_t size) : table_size(size) {}

int Hash::hash(string key)
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