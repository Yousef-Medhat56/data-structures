#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include <string>
using namespace std;

template <class T>
struct Node
{
    string key;
    T data;
    Node *next;
    Node() : next(nullptr){};
    Node(string key) : key(key), next(nullptr){};
    Node(string key, T d) : key(key), data(d), next(nullptr){};
};
template <class T>
class Hash
{
private:
    size_t table_size;
    Node<T> **table;

public:
    Hash();
    Hash(size_t size);
    ~Hash();
    int hash(string key);
    void insert(string key, T data);
    int numberOfNodesInBucket(int bucket);
};
#endif
