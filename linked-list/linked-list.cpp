#include <iostream>
#include <cassert>
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

template <class T>
void DoubleLinkedList<T>::pushBack(T val)
{

    Node<T> *newNode = new Node<T>(val);
    newNode->prev = tail;
    newNode->next = nullptr;

    if (tail)
        tail->next = newNode;

    tail = newNode;

    if (!head)
        head = tail;
    size++;
}

template <class T>
void DoubleLinkedList<T>::popBack()
{
    if (tail)
    {
        if (size == 1)
        {
            delete tail;
            tail = nullptr;
            head = nullptr;
        }
        else
        {
            tail = tail->prev;
            delete tail->next;
            tail->next = nullptr;
        }
        size--;
    }
}

template <class T>
void DoubleLinkedList<T>::popFront()
{
    if (head)
    {
        if (size == 1)
        {
            delete head;
            head = nullptr;
            tail = nullptr;
        }
        else
        {
            head = head->next;
            delete head->prev;
            head->prev = nullptr;
        }
        size--;
    }
}

template <class T>
T &DoubleLinkedList<T>::getElmByIndex(int index)
{
    assert(index < size && index >= 0);

    Node<T> *currNode = head;
    for (int i = 0; i < index; i++)
    {
        currNode = currNode->next;
    }

    return currNode->data;
}
template <class T>
void DoubleLinkedList<T>::display()
{
    Node<T> *currNode = head;
    if (currNode)
    {
        cout << "{";
        while (currNode->next)
        {
            cout << currNode->data << " <=> ";
            currNode = currNode->next;
        }

        cout << currNode->data << "}" << endl;
    }
    else
        cout << "{}" << endl;
}