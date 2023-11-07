// Implement queue using array
#include <iostream>
#include <cassert>
using namespace std;

template <typename T>
class Queue
{
private:
    int read, write, capacity;
    T *array;

public:
    Queue(int size)
    {
        capacity = size;
        read = write = -1;
        array = new T[capacity];
    }

    ~Queue()
    {
        delete[] array;
    }

    bool isEmpty()
    {
        return read == -1;
    }

    bool isFull()
    {
        return (write + 1) % capacity == read;
    }

    void enqueue(const T &item)
    {
        assert(!isFull());

        if (isEmpty())
        {
            read = 0;
        }

        write = (write + 1) % capacity;
        array[write] = item;
        cout << item << " enqueued to the queue." << endl;
    }

    T dequeue()
    {
        assert(!isEmpty());

        T item = array[read];
        if (read == write)
        {
            read = write = -1; // Reset to empty queue
        }
        else
        {
            read = (read + 1) % capacity;
        }
        cout << item << " dequeued from the queue." << endl;
        return item;
    }
};

int main()
{
    Queue<int> intQueue(5);
    intQueue.enqueue(1);
    intQueue.enqueue(2);
    intQueue.enqueue(3);
    intQueue.enqueue(4);
    intQueue.enqueue(5);
    intQueue.dequeue();
    intQueue.dequeue();
    intQueue.enqueue(6);
    intQueue.enqueue(7);

    Queue<string> stringQueue(3);
    stringQueue.enqueue("Alice");
    stringQueue.enqueue("Bob");
    stringQueue.dequeue();
    stringQueue.enqueue("Charlie");

    return 0;
}
