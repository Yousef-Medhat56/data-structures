#include <iostream>
#include <string>
using namespace std;

#include "./source/hash-table.cpp"

int main()
{
    Hash<string> hashObj;
    hashObj.insert("key", "value");
    hashObj.insert("key", "value");
    hashObj.insert("key", "value");

    cout << hashObj.numberOfNodesInBucket(9) << endl;

    return 0;
}