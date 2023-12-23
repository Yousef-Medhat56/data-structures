#include "./heap.h"
#include <vector>
using namespace std;

template <class T>
Heap<T>::Heap()
{
    lastPosition = -1;
    data<T> = {};
}


template <class T>
void Heap<T>::swap(int from, int to){
    T temp = data[from];
    data[from] = data[to];
    data[to] = temp;
}