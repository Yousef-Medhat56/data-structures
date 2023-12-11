#include <iostream>
#include <string>
using namespace std;

#include "./source/hash-table.cpp"

int main()
{
    Hash<string> hashObj;
    cout<<hashObj.hash("Key");
    return 0;
}