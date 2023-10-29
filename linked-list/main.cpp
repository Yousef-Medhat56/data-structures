#include "./linked-list.cpp"

int main()
{

    DoubleLinkedList<int> list;

    list.pushBack(4);
    list.popBack();

    list.display(); // should output: {}
    list.pushFront(3);
    list.pushBack(2);
    list.pushFront(1);

    list.display(); // should output: {1,3,2}
    list.popBack();

    list.display(); // should output: {1,3}
    return 0;
}