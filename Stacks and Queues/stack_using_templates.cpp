#include <iostream>
#include <climits>
using namespace std;

template <typename T>

class templateStackArray
{

    T *data;
    int nextIndex;
    int capacity;

public:
    dynamicStackArray()
    {
        data = new T[4];
        nextIndex = 0;
        capacity = 4;
    }

    void push(T element)
    {
        if (nextIndex == capacity)
        {
            capacity *= 2;
            T *newData = new T[capacity];
            for (int i = 0; i < nextIndex; i++)
            {
                newData[i] = data[i];
            }
            delete[] data;
            data = newData;
        }

        data[nextIndex] = element;
        nextIndex++;
    }

    T pop()
    {
        if (nextIndex == 0)
        {
            cout << "Stack empty" << endl;
            return 0; //All data types accept 0
        }

        nextIndex--;
        return data[nextIndex];
    }

    bool isEmpty()
    {
        return nextIndex == 0;
    }

    T top()
    {
        if (nextIndex == 0)
        {
            cout << "Stack empty" << endl;
            return 0;
        }
        return data[nextIndex - 1];
    }

    int size()
    {
        return nextIndex;
    }
};