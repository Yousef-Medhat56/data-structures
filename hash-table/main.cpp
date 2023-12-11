#include <iostream>
using namespace std;

#include "./source/hash-table.cpp"

int main()
{
    Hash hashObj;
    cout<<hashObj.hash("Key");
    return 0;
}