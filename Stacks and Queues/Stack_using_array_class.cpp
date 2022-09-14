#include <iostream>
#include <climits>
using namespace std;

class stackArray
{

    int *data;
    int nextIndex;
    int capacity;

public:
    stackArray(int totalSize)
    {
        data = new int[totalSize];
        nextIndex = 0;
        capacity = totalSize;
    }

    void push(int element)
    {
        if (nextIndex == capacity)
        {
            cout << "Stack full" << endl;
            return;
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