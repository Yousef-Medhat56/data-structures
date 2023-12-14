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

void BST::printInOrder()
{
    if (root)
        printInOrderPrivate(root);
    else
        cout << "Tree is empty" << endl;
}

void BST::printInOrderPrivate(Node *&node)
{
    //check if there are smaller keys
    if (node->left)
        printInOrderPrivate(node->left);
    
    cout << node->key << " ";
    
    //check if there are bigger keys
    if (node->right)
        printInOrderPrivate(node->right);
}

BST::~BST()
{
    destroyTree(root);
}

void BST::destroyTree(Node *&node)
{
    if (node)
    {
        destroyTree(node->left);
        destroyTree(node->right);
        delete node;
    }
}