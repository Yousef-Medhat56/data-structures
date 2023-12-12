#include <iostream>
#include <string>
using namespace std;

#include "./source/hash-table.cpp"

int main()
{
    Hash<string> hashObj(4);

    hashObj.insert("Paul", "Locha");
    hashObj.insert("Kim", "Iced Mocha");
    hashObj.insert("Emma", "Strawberry Smoothie");
    hashObj.insert("Annie", "Hot Chocolate");
    hashObj.insert("Sarah", "Passion Tea");
    hashObj.insert("Pepper", "Caramel Mocha");
    hashObj.insert("Mike", "Chai Tea");
    hashObj.insert("Steve", "Apple Cider");
    hashObj.insert("Bill", "Root Beer");
    hashObj.insert("Marie", "Skinny Latte");
    hashObj.insert("Susan", "Water");
    hashObj.insert("Joe", "Green Tea");

    cout << hashObj.numberOfNodesInBucket(3) << endl;

    Node<string> *hashItem = hashObj.find("Sarah");

    if (hashItem)
        cout << hashItem->data << endl;

    bool removed_0 = hashObj.remove("Kim");
    if (removed_0)
        cout << "Removed Kim" << endl;
    else
        cout << "Not found" << endl;

    bool removed_1 = hashObj.remove("Kim");
    if (removed_1)
        cout << "Removed Kim" << endl;
    else
        cout << "Not found" << endl;
    
    bool removed_2 = hashObj.remove("Annie");
    if (removed_2)
        cout << "Removed Annie" << endl;
    else
        cout << "Not found" << endl;
   
    return 0;
}