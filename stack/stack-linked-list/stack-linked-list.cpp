// Implement stack using doubly linked list
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
class Stack
{
private:
    Node<T> *top;
    size_t size;

public:
    Stack() : top(nullptr), size(0) {}

    ~Stack()
    {
        while (!isEmpty())
        {
            pop();
        }
    }

    bool isEmpty()
    {
        return size == 0;
    }

    size_t getSize()
    {
        return size;
    }

    void push(T val)
    {
        Node<T> *newNode = new Node<T>(val);
        if (isEmpty())
        {
            top = newNode;
        }
        else
        {
            newNode->prev = top;
            top->next = newNode;
            top = newNode;
        }
        size++;
    }

    void pop()
    {
        if (!isEmpty())
        {
            if (size == 1)
                delete top;
            else
            {
                top = top->prev;
                delete top->next;
            }
            size--;
        }
    }

    T &peek()
    {
        assert(!isEmpty());

        return top->data;
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