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
    // check if there are smaller keys
    if (node->left)
        printInOrderPrivate(node->left);

    cout << node->key << " ";

    // check if there are bigger keys
    if (node->right)
        printInOrderPrivate(node->right);
}

Node *BST::find(int key)
{
    return findPrivate(key, root);
}

Node *BST::findPrivate(int key, Node *&node)
{
    if (node)
    {
        if (key == node->key)
            return node;
        else if (key < node->key)
            return findPrivate(key, node->left);
        else if (key > node->key)
            return findPrivate(key, node->right);
    }

    return nullptr;
}

void BST::printChildren(int key)
{
    Node *node = find(key);
    if (node)
    {
        node->left ? cout << node->left->key << endl : cout << "The node has no left child\n";
        node->right ? cout << node->right->key << endl : cout << "The node has no right child\n";
    }
}

Node *BST::findSmallest()
{
    return findSmallestPrivate(root);
}

Node *BST::findSmallestPrivate(Node *&node)
{
    if (node)
    {
        if (node->left)
            return findSmallestPrivate(node->left);
        else
            return node;
    }
    return nullptr;
}

void BST::remove(int key)
{
     removePrivate(key, root);
}

Node* BST::removePrivate(int key, Node*& node)
{
    if (node == nullptr)
    {
        // Node not found
        return nullptr;
    }

    if (key < node->key)
    {
        // Key is in the left subtree
        node->left = removePrivate(key, node->left);
    }
    else if (key > node->key)
    {
        // Key is in the right subtree
        node->right = removePrivate(key, node->right);
    }
    else
    {
        // Node with the key to be deleted is found

        // Case 1: Node has no child or only one child
        if (node->left == nullptr)
        {
            Node* temp = node->right;
            delete node;
            return temp;
        }
        else if (node->right == nullptr)
        {
            Node* temp = node->left;
            delete node;
            return temp;
        }

        // Case 2: Node has two children
        Node* successor = findSmallestPrivate(node->right); // Find in-order successor
        node->key = successor->key; // Copy the value of in-order successor
        node->right = removePrivate(successor->key, node->right); // Recursively delete the in-order successor
    }

    return node;
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