#include <iostream>
#include "Dynamic_array_class.cpp"
using namespace std;

int main()
{

    dynamicArray a;
    a.add(10);
    a.add(20);
    a.add(30);
    a.add(40);
    a.add(50);
    cout << a.size << endl;
    a.add(60);
    cout << a.size << endl;

    a.print();

    return 0;
}