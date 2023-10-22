template <class T>
class DynamicArray
{
private:
    int capacity; // the array full capacity
    int size;     // the current size of the array
    T *arr;

public:
    DynamicArray();
    ~DynamicArray();
    // get element by index
    T &getElm(int index);
    // overload the [] operator to get element by index
    T &operator[](int index);
    // push new element to the array
    void push(T val);
    // pop element from the array
    void pop();
    // remove element by index
    void remove(int index);
    // resize the array
    void resize();
    // print the array elements
    void display();
    // get the array full capacity
    int getCapaity();
    // get the array current size
    int getSize();
};