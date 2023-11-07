// Implement stack using dynamic array
#include <iostream>
#include <cassert>
using namespace std;

template <typename T>
class Stack
{
private:
    T *arr;          // Dynamic array to store stack elements
    size_t capacity; // Capacity of the stack
    int top;         // Index of the top element

public:
    Stack(size_t initialCapacity = 10) : capacity(initialCapacity), top(-1)
    {
        arr = new T[capacity];
    }

    ~Stack()
    {
        delete[] arr;
    }

    bool isEmpty()
    {
        return top == -1;
    }

    int getSize()
    {
        return top + 1;
    }

    void push(T val)
    {
        if (getSize() == capacity)
        {
            // If the array is full, resize it to accommodate more elements.
            resize(capacity * 2);
        }
        arr[++top] = val;
    }

    void pop()
    {
        assert(!isEmpty());
        --top;
    }

    T& peek()
    {
        assert(!isEmpty());
        return arr[top];
    }

private:
    void resize(int newCapacity)
    {
        T *newArr = new T[newCapacity];
        for (int i = 0; i <= top; i++)
        {
            newArr[i] = arr[i];
        }
        capacity = newCapacity;
        delete[] arr;
        arr = newArr;
    }
};

int main()
{
    Stack<int> stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);

    cout << "Stack Size: " << stack.getSize() << endl;

    cout << "Top element: " << stack.peek() << endl;

    cout << "Popping elements: ";
    while (!stack.isEmpty())
    {
        cout << stack.peek() << " ";
        stack.pop();
    }

    cout << endl;

    return 0;
}
