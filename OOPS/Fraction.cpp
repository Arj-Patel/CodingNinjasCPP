#include <iostream>
#include "Fraction_class.cpp"
using namespace std;

int main()
{

    Fraction f1(100, 2);
    Fraction f2(20, 4);
    Fraction f3 = f1 + f2;
    f3.print();

    return 0;
}