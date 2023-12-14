#include <iostream>
#include "./source/btree.cpp"
using namespace std;

int main(){
    BST tree(10);
    tree.addLeaf(5);
    tree.addLeaf(12);
    tree.addLeaf(14);
    return 0;
}