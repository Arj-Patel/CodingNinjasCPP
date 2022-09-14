#include <iostream>
#include <climits>
using namespace std;

class dynamicStackArray
{

    int *data;
    int nextIndex;
    int capacity;

public:
    dynamicStackArray()
    {
        data = new int[4];
        nextIndex = 0;
        capacity = 4;
    }

    void push(int element)
    {
        if (nextIndex == capacity)
        {
            capacity *= 2;
            int *newData = new int[capacity];
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

    int pop()
    {
        if (nextIndex == 0)
        {
            cout << "Stack empty" << endl;
            return INT_MIN;
        }

        nextIndex--;
        return data[nextIndex];
    }

    bool isEmpty()
    {
        return nextIndex == 0;
    }

    int top()
    {
        if (nextIndex == 0)
        {
            cout << "Stack empty" << endl;
            return INT_MIN;
        }
        return data[nextIndex - 1];
    }

    int size()
    {
        return nextIndex;
    }
};