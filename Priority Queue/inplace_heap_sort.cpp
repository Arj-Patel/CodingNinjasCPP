#include <iostream>
using namespace std;

void heapSort(int arr[], int n)
{

    int childIndex, parentIndex;
    for (int i = 1; i < n; i++)
    {
        childIndex = i;
        parentIndex = (childIndex - 1) / 2;

        while (childIndex > 0)
        {
            if (arr[childIndex] < arr[parentIndex])
            {
                std::swap(arr[childIndex], arr[parentIndex]);
            }
            childIndex = parentIndex;
            parentIndex = (childIndex - 1) / 2;
        }
    }

    int tempSize = n;
    int rightChildIndex, leftChildIndex;
    for (int i = 1; i < n; i++)
    {
        std::swap(arr[0], arr[tempSize - 1]);
        tempSize--;
        parentIndex = 0;
        rightChildIndex = 2;
        leftChildIndex = 1;
        while (rightChildIndex < tempSize)
        {

            if (arr[parentIndex] > arr[rightChildIndex] || arr[parentIndex] > arr[leftChildIndex])
            {
                if (arr[rightChildIndex] < arr[leftChildIndex])
                {
                    std::swap(arr[rightChildIndex], arr[parentIndex]);
                    parentIndex = rightChildIndex;
                }
                else
                {
                    std::swap(arr[leftChildIndex], arr[parentIndex]);
                    parentIndex = leftChildIndex;
                }
            }
            else
            {
                break;
            }
            rightChildIndex = parentIndex * 2 + 2;
            leftChildIndex = parentIndex * 2 + 1;
        }
    }

    if (arr[0] < arr[1])
    {
        std::swap(arr[0], arr[1]);
    }
}

int main()
{
    int size;
    cin >> size;

    int *input = new int[size];

    for (int i = 0; i < size; i++)
    {
        cin >> input[i];
    }

    heapSort(input, size);

    for (int i = 0; i < size; i++)
    {
        cout << input[i] << " ";
    }

    delete[] input;
}