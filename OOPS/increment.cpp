#include <iostream>
#include "increment_class.cpp"
using namespace std;

int main()
{

    Increment num(100);
    Increment x;
    x = ++(++num);
    x.print();
    num.print();

    x = num++;
    x.print();
    num.print();

    Increment a1(10);
    Increment a2(3);

    a1 += a2;
    a1.print();
    a2.print();

    return 0;
}