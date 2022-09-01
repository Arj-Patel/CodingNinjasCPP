#include<iostream>
using namespace std;

class Fraction
{

    int numerator;
    int denominator;

public:
    Fraction(int n, int d)
    {
        numerator = n;
        denominator = d;
    }

    void simplify()
    {
        int gcd = 1;
        int j = min(this->numerator, this->denominator);

        for (int i = 1; i <= j; i++)
        {
            if (this->numerator % i == 0 && this->denominator % i == 0)
            {
                gcd = i;
            }
        }
        this->numerator = this->numerator / gcd;
        this->denominator = this->denominator / gcd;
    }

    Fraction operator+(Fraction const &f)
    {
        int lcm = this->denominator * f.denominator;

        int x = lcm / this->denominator;
        int y = lcm / f.denominator;

        int newNumerator = x * this->numerator + (y * f.numerator);

        Fraction fNew(newNumerator, lcm);
        fNew.simplify();

        return fNew;
    }

    void print() const
    {
        cout << this->numerator << "/" << this->denominator << endl;
    }
};
