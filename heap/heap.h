#ifndef HEAP_H
#define HEAP_H

#include <vector>
using namespace std;

//Implementation for the Max Heap
template <class T>
class Heap
{
    int lastPosition;
    vector<T> data;
    //swap two elements using their index
    void swap(int from, int to);
    void trickleUp(int position);
    void trickleDown(int parent);
public:
    Heap();
    void insert(T newElm);
    void remove();
    void display();
};
#endif