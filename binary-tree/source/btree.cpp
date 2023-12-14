#include <iostream>
#include "../include/btree.h"
using namespace std;

BST::BST() : root(nullptr) {}
BST::BST(int key) {
    root = new Node(key);
}
