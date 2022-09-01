#include <iostream>
using namespace std;

class Polynomial
{
    int size;

public:
    int *degCoeff;
    Polynomial()
    {
        size = 0;
        degCoeff = new int[size];
    }

    Polynomial(Polynomial const &p)
    {
        this->size = p.size;
        int *arr = new int[p.size];
        for (int i = 0; i < size; i++)
        {
            arr[i] = p.degCoeff[i];
        }
        this->degCoeff = arr;
    }

    void setCoefficient(int degree, int coeff)
    {
        if (degree >= size)
        {
            int prevSize = size;
            size = degree + 1;
            int *tempArr = new int[size];
            for (int i = 0; i < prevSize; i++)
            {
                tempArr[i] = degCoeff[i];
            }
            for (int i = prevSize; i < size; i++)
            {
                tempArr[i] = 0;
            }
            delete[] degCoeff;
            degCoeff = tempArr;
        }
        degCoeff[degree] = coeff;
    }

    Polynomial operator+(Polynomial const &f)
    {
        int s = max(this->size, f.size);
        int *newArr = new int[s];
        int minIndex = min(this->size, f.size);
        for (int i = 0; i < minIndex; i++)
        {
            newArr[i] = this->degCoeff[i] + f.degCoeff[i];
        }
        Polynomial newP;
        if (this->size > f.size)
        {
            newP.size = this->size;
            for (int i = f.size; i < this->size; i++)
            {
                newArr[i] = this->degCoeff[i];
            }
            newP.degCoeff = newArr;
        }
        else
        {
            newP.size = f.size;
            for (int i = this->size; i < f.size; i++)
            {
                newArr[i] = f.degCoeff[i];
            }
            newP.degCoeff = newArr;
        }

        return newP;
        delete[] newArr;
    }

    Polynomial operator-(Polynomial const &f)
    {
        int s = max(this->size, f.size);
        int *newArr = new int[s];
        int minIndex = min(this->size, f.size);
        for (int i = 0; i < minIndex; i++)
        {
            newArr[i] = this->degCoeff[i] - f.degCoeff[i];
        }
        Polynomial newP;
        if (this->size > f.size)
        {
            newP.size = this->size;
            for (int i = f.size; i < this->size; i++)
            {
                newArr[i] = this->degCoeff[i];
            }
            newP.degCoeff = newArr;
        }
        else
        {
            newP.size = f.size;
            for (int i = this->size; i < f.size; i++)
            {
                newArr[i] = -1 * f.degCoeff[i];
            }
            newP.degCoeff = newArr;
        }

        return newP;
        delete[] newArr;
    }

    Polynomial operator*(Polynomial const &f)
    {
        int newSize = this->size + f.size - 1;
        int *newArr = new int[newSize];
        for (int i = 0; i < newSize; i++)
        {
            newArr[i] = 0;
        }

        for (int i = 0; i < this->size; i++)
        {
            for (int j = 0; j < f.size; j++)
            {
                newArr[i + j] += this->degCoeff[i] * f.degCoeff[j];
            }
        }
        Polynomial newP;
        newP.degCoeff = newArr;
        newP.size = newSize;
        return newP;
        delete[] newArr;
    }

    Polynomial operator=(Polynomial const &f)
    {
        Polynomial pNew;
        int *newArr = new int[f.size];
        for (int i = 0; i < f.size; i++)
        {
            newArr[i] = f.degCoeff[i];
        }
        pNew.size = f.size;
        pNew.degCoeff = newArr;
    }

    void print() const
    {
        for (int i = 0; i < size; i++)
        {
            if (degCoeff[i] != 0)
            {
                cout << degCoeff[i] << "x" << i << " ";
            }
        }
        cout << endl;
    }
};