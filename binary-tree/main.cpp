#include <iostream>
#include "./source/btree.cpp"
using namespace std;

int main()
{
    BST tree;

    int TreeKeys[16] = {50, 76, 21, 4, 32, 64, 15, 52, 14, 100, 83, 2, 3, 70, 87, 80};

    cout << "Printing the tree in order\nBefore adding numbers\n";

    tree.printInOrder();

    for (int i = 0; i < 16; i++)
        tree.addLeaf(TreeKeys[i]);

    cout << "Printing the tree in order\nAfter adding numbers\n";
    tree.printInOrder();

    cout << "\nSearch for a node by its key value:\n";
    Node *node = tree.find(83);
    cout << node->key << endl;

    cout << "\nPrint node's children:\n";
    for (int i = 0; i < 16; i++)
    {
        cout << "Parent: " << TreeKeys[i] << endl;
        tree.printChildren(TreeKeys[i]);
    }

    cout << "\nFind smallest node:\n";
    cout << tree.findSmallest()->key << endl;

    tree.remove(50); // delete the root
    cout << "\nPrint node's children after deletion:\n";
    for (int i = 0; i < 16; i++)
    {
        cout << "Parent: " << TreeKeys[i] << endl;
        tree.printChildren(TreeKeys[i]);
    }
    return 0;
}