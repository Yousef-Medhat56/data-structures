// Implement queue using doubly linked list
#include <iostream>
#include <cassert>
using namespace std;

template <class T>
struct Node
{
    T data;
    struct Node *prev;
    struct Node *next;

    Node(T val) : data(val), prev(nullptr), next(nullptr){};
};


template <typename T>
class Queue {
private:
    Node<T>* read;
    Node<T>* write;

public:
    Queue() : read(nullptr), write(nullptr) {}

    ~Queue() {
        while (!isEmpty()) {
            dequeue();
        }
    }

    bool isEmpty() const {
        return read == nullptr;
    }

    void enqueue(const T& item) {
        Node<T>* newNode = new Node<T>(item);
        if (isEmpty()) {
            read = write = newNode;
        } else {
            write->next = newNode;
            newNode->prev = write;
            write = newNode;
        }
        cout << item << " enqueued to the queue." << endl;
    }

    T dequeue() {
        assert(!isEmpty());
        T item = read->data;
       

        if (read == write) {
            delete read;
            read = write = nullptr;
        } else {
            read = read->next;
            delete read->prev;
            read->prev = nullptr;
        }

        
        cout << item << " dequeued from the queue." << endl;

        return item;
    }
};

int main() {
    Queue<int> intQueue;
    intQueue.enqueue(1);
    intQueue.enqueue(2);
    intQueue.enqueue(3);
    intQueue.enqueue(4);
    intQueue.enqueue(5);
    intQueue.dequeue();
    intQueue.dequeue();
    intQueue.enqueue(6);
    intQueue.enqueue(7);

    Queue<string> stringQueue;
    stringQueue.enqueue("Alice");
    stringQueue.enqueue("Bob");
    stringQueue.dequeue();
    stringQueue.enqueue("Charlie");

    return 0;
}
