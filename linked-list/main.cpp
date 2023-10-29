#include "./linked-list.cpp"

int main()
{

    DoubleLinkedList<int> list;

    list.pushBack(4);
    list.popFront();

    list.display(); // should output: {}
    list.pushFront(3);
    list.pushBack(2);
    list.pushFront(1);

    list.display(); // should output: {1,3,2}
    list.popBack();

    list.display(); // should output: {1,3}
    
    list.popFront();
    list.display(); // should output: {3}
   list.popBack(); 
   list.display(); // should output: {}
    list.pushBack(2);
    list.pushBack(3);
    list.pushBack(4);
    list.pushFront(1);
    list.display(); // should output: {1,2,3,4}
    cout<<list.getElmByIndex(2)<<endl; // should output: 3
    return 0;
}