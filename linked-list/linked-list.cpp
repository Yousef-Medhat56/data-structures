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

