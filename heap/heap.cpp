#include "./heap.h"
#include <vector>
#include <cmath>
#include <iostream>
using namespace std;

template <class T>
Heap<T>::Heap()
{
    lastPosition = -1;
}

template <class T>
void Heap<T>::swap(int from, int to)
{
    T temp = data[from];
    data[from] = data[to];
    data[to] = temp;
}

template <class T>
void Heap<T>::trickleUp(int position)
{
    if (position == 0)
        return;

    // the index of the parent node
    int parent = floor((position - 1) / 2);

    // check if the parent node is smaller than the child
    if (data[parent] < data[position])
    {
        swap(position, parent);
        trickleUp(parent);
    }
}

template <class T>
void Heap<T>::insert(T newElm)
{
    // add the new element to the array
    data.push_back(newElm);
    // increment lastPosition and trickle Up
    trickleUp(++lastPosition);
}

template <class T>
void Heap<T>::trickleDown(int parent)
{
    int leftChild = 2 * parent + 1;
    int rightChild = 2 * parent + 2;

    //the left child is the last element and is bigger than the parent
    if (leftChild == lastPosition && data[parent] < data[leftChild])
    {
        swap(parent, leftChild);
        return;
    }

    //the right child is the last element and is bigger than the parent
    if (rightChild == lastPosition && data[parent] < data[rightChild])
    {
        swap(parent, rightChild);
        return;
    }

    // check if the parent doesn't have children
    if (leftChild >= lastPosition || rightChild >= lastPosition)
        return;

    // the left child is bigger than the right child and the parent
    if (data[leftChild] > data[rightChild] && data[parent] < data[leftChild])
    {
        swap(parent, leftChild);
        trickleDown(leftChild);
    }

    // the right child is bigger than the left child and the parent
    else if (data[rightChild] > data[leftChild] && data[parent] < data[rightChild])
    {
        swap(parent, rightChild);
        trickleDown(rightChild);
    }
}

template <class T>
void Heap<T>::remove()
{
    swap(0, lastPosition--);
    data.pop_back();
    trickleDown(0);
}

template <class T>
void Heap<T>::display()
{
    for (int i = 0; i < data.size(); i++)
    {
        cout << data[i] << " ";
    }
    cout << endl;
}