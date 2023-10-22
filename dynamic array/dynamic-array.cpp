#include "./dynamic-array.h"
#include <cassert>
#include <algorithm>

template <class T>
DynamicArray<T>::DynamicArray()
{
    capacity = 5;
    size = 0;
    arr = new T[capacity];
}

template <class T>
DynamicArray<T>::~DynamicArray()
{
    delete[] arr;
}


template <class T>
T &DynamicArray<T>::getElm(int index)
{
    assert(("Index is invalid", index >= 0 && index < size));
    return arr[index];
}

template <class T>
T &DynamicArray<T>::operator[](int index)
{
    this->getElm[index];
}

template <class T>
void DynamicArray<T>::push(T val)
{
    if (size == capacity)
        resize();
    arr[size] = val;
    size++;
}

template <class T>
void DynamicArray<T>::pop()
{
    size--;
    if (3 * size <= capacity)
        resize();
}

template <class T>
void DynamicArray<T>::remove(int index)
{
    assert(("Index is invalid", index >= 0 && index < size));
    std::copy(arr + index + 1, arr + size, arr + index);
    size--;
    if (3 * size <= capacity)
        resize();
}

template <class T>
void DynamicArray<T>::resize()
{
    int new_capacity = std::max(2 * size, 5);

    // declare the new resized array
    T *new_arr = new T[new_capacity];

    // copy the old array to the new array
    std::copy(arr, arr + size, new_arr);

    arr = new_arr;
    capacity = new_capacity;
}

template <class T>
int DynamicArray<T>::getCapaity()
{
    return this->capacity;
}
template <class T>
int DynamicArray<T>::getSize()
{
    return this->size;
}
template <class T>
void DynamicArray<T>::display()
{
    std::cout << '{';
    for (int i = 0; i < size; i++)
    {
        std::cout << this->getElm(i);
        if(i<size-1)std::cout <<',';
    }
    std::cout << '}'<<std::endl;
}

//overload the << operator to display the array elements
template <class T>
std::ostream& operator<<(std::ostream& COUT,DynamicArray<T>& dynamicArr){
    dynamicArr.display();
    return COUT;
}
