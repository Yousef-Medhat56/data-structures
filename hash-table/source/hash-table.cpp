#include "../include/hash-table.h"

template <class T>
Hash<T>::Hash()
{
    table_size = 10;
    table = new Node<T> *[table_size];
    for (size_t i = 0; i < table_size; ++i)
    {
        table[i] = nullptr;
    }
}

template <class T>
Hash<T>::Hash(size_t size) : table_size(size)
{
    table = new Node<T> *[table_size];
    for (size_t i = 0; i < table_size; ++i)
    {
        table[i] = nullptr;
    }
}

template <class T>
Hash<T>::~Hash()
{
    for (size_t i = 0; i < table_size; ++i)
    {
        Node<T> *current = table[i];
        while (current != nullptr)
        {
            Node<T> *next = current->next;
            delete current;
            current = next;
        }
    }
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

template <class T>
void Hash<T>::insert(string key, T value)
{
    int index = hash(key);
    Node<T> *newNode = new Node<T>(key, value);

    if (table[index] == nullptr)
    {
        table[index] = newNode;
    }
    else
    {
        Node<T> *currNode = table[index];
        while (currNode->next)
            currNode = currNode->next;
        currNode->next = newNode;
    }
}

template <class T>
int Hash<T>::numberOfNodesInBucket(int bucket)
{
    int count = 0;
    if (table[bucket] != nullptr)
    {
        count = 1;
        Node<T> *currNode = table[bucket];
        while (currNode->next)
        {
            count++;
            currNode = currNode->next;
        }
    }
    return count;
}

template <class T>
Node<T> *Hash<T>::find(string key)
{
    int index = hash(key);
    Node<T> *currNode = table[index];

    while (currNode != nullptr)
    {
        if (currNode->key == key)
        {
            return currNode;
        }
        currNode = currNode->next;
    }

    return nullptr; // Key not found
}