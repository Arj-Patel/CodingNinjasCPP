#include <iostream>
#include "Stack_using_array_class.cpp"
#include "dynamic_stack_class.cpp"
using namespace std;

int main()
{

    stackArray s(4);
    dynamicStackArray sD;

    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);

    sD.push(10);
    sD.push(20);
    sD.push(30);
    sD.push(40);
    sD.push(50);

    // cout << s.top() << endl;

    // cout << s.pop() << endl;
    // cout << s.pop() << endl;
    // cout << s.pop() << endl;

    // cout << s.size() << endl;
    // cout << s.isEmpty() << endl;

    cout << sD.top() << endl;

    cout << sD.pop() << endl;
    cout << sD.pop() << endl;
    cout << sD.pop() << endl;

    cout << sD.size() << endl;
    cout << sD.isEmpty() << endl;

    return 0;
}