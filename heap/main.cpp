#include "./heap.cpp"

int main()
{
    Heap<int> heap;
    heap.insert(0);
    heap.insert(1);
    heap.insert(3);
    heap.insert(5);
    heap.insert(6);
    heap.insert(9);
    heap.insert(7);

    heap.display();
    heap.remove();
    heap.display();

    return 0;
}