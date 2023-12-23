#include "./heap.h"
#include <vector>
#include <cmath>
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
        
    //the index of the parent node
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
    //add the new element to the array
    data.push_back(newElm);
    //increment lastPosition and trickle Up
    trickleUp(++lastPosition);
}