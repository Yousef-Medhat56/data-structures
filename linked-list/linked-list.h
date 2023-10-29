template <class T>
struct Node
{
    T data;
    struct Node *prev;
    struct Node *next;

    Node(T val)
    {
        data = val;
    }
};

template <class T>
class DoubleLinkedList
{

    int size;
    struct Node<T> *head;
    struct Node<T> *tail;

public:
    DoubleLinkedList();
    ~DoubleLinkedList();
    // push new element to the front of the list
    void pushFront(T val);
    // push new element to the end of the list
    void pushBack(T val);
    //delete an element from the end of the list
    void popBack();
    // display the list elements
    void display();
};