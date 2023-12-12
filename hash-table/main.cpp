#include <iostream>
#include <string>
using namespace std;

#include "./source/hash-table.cpp"

int main()
{
    Hash<string> hashObj;
    hashObj.insert("key_1", "value_1");
    hashObj.insert("key_2", "value_2");
    hashObj.insert("key_3", "value_3");

    cout << hashObj.numberOfNodesInBucket(3) << endl;

    Node<string> *hashItem = hashObj.find("key_1");
    if (hashItem)
        cout << hashItem->data << endl;
        
    return 0;
}