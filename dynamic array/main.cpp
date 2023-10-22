#include <iostream>
#include "./dynamic-array.cpp"
using namespace std;

int main()
{
    DynamicArray<int> dynamicArr;
    for (int i = 0; i < 10; i++)
        dynamicArr.push(i);

    dynamicArr.display();

    dynamicArr.pop();
    cout << "After Pop" << endl;
    dynamicArr.display();

    cout << "Remove 2nd element" << endl;
    dynamicArr.remove(1);
    cout<<dynamicArr;

    cout << "Get capacity" << endl;
    cout << dynamicArr.getCapaity() << endl;

    cout << "Get size" << endl;
    cout << dynamicArr.getSize() << endl;
    return 0;
}