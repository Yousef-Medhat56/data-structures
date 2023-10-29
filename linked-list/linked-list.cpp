#include <iostream>
#include "./linked-list.h"
using namespace std;

template <class T>
DoubleLinkedList<T>::DoubleLinkedList()
{
    size = 0;
    head = nullptr;
    tail = nullptr;
}

template <class T>
DoubleLinkedList<T>::~DoubleLinkedList()
{

    Node<T> *currNode = head;
    while (currNode->next)
    {
        currNode = currNode->next;
        delete currNode->prev;
    }

    delete currNode;
}

template <class T>
void DoubleLinkedList<T>::pushFront(T val)
{
    Node<T> *newNode = new Node<T>(val);
    newNode->prev = nullptr;
    newNode->next = head;

    if (head)
        head->prev = newNode;

    head = newNode;

    if (!tail)
        tail = head;
    size++;
}
