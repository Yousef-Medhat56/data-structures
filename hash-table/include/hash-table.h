#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include <string>
using namespace std;
class Hash
{
private:
    size_t table_size;

public:
    Hash();
    Hash(size_t size);
    int hash(string key);
};
#endif
