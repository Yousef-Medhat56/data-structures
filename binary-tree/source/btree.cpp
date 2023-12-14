#include <iostream>
#include "../include/btree.h"
using namespace std;

BST::BST() : root(nullptr) {}
BST::BST(int key)
{
    root = new Node(key);
}

void BST::addLeaf(int key)
{
    addLeafPrivate(key, root);
}

void BST::addLeafPrivate(int key, Node *&node)
{
    if (node == nullptr)
        node = new Node(key);
    else if (key < node->key)
        // add node to the left child
        addLeafPrivate(key, node->left);
    else if (key > node->key)
        // add node to the right child
        addLeafPrivate(key, node->right);
}
