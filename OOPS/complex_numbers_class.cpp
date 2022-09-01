#include<iostream>
using namespace std;

class ComplexNumbers
{
    int real, imag;

public:
    ComplexNumbers(int r, int i)
    {
        real = r;
        imag = i;
    }

    void print()
    {
        cout << real << " + i" << imag << endl;
    }

    void plus(ComplexNumbers const &c) // made constant reference variable to avoid invoking copy constructor and to prevent any changes
    {
        this->real = this->real + c.real;
        this->imag = this->imag + c.imag;
    }

    void multiply(ComplexNumbers const &c) // made constant reference variable to avoid invoking copy constructor and to prevent any changes
    {
        int tempReal = this->real;
        int tempImag = this->imag;
        this->real = tempReal * c.real - tempImag * c.imag;
        this->imag = tempReal * c.imag + tempImag * c.real;
    }
};