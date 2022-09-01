#include <iostream>
using namespace std;

class dynamicArray
{
    int *data;
    int nextIndex = 0;

public:
    int size = 5;
    dynamicArray()
    {
        data = new int[5];
    }

    void add(int n)
    {
        if (nextIndex >= size)
        {
            size *= 2;
            int *tempArr = new int[size];
            for (int i = 0; i < nextIndex; i++)
            {
                tempArr[i] = data[i];
            }
            delete[] data;
            data = tempArr;
        }
        data[nextIndex] = n;
        nextIndex++;
    }

    void print() const
    {
        for (int i = 0; i < nextIndex; i++)
        {
            cout << data[i] << " ";
        }
        cout << endl;
    }
};