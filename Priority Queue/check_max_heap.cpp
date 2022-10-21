#include <iostream>
using namespace std;

bool isMaxHeap(int arr[], int n)
{

    int parentIndex = 0;
    int leftChildIndex = 1;
    int rightChildIndex = 2;
    bool ans = true;

    while (rightChildIndex < n)
    {
        if (arr[parentIndex] < arr[rightChildIndex] || arr[parentIndex] < arr[leftChildIndex])
        {
            ans = false;
            break;
        }
        parentIndex++;
        rightChildIndex = 2 * parentIndex + 1;
        leftChildIndex = 2 * parentIndex + 2;
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    int *arr = new int[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << (isMaxHeap(arr, n) ? "true\n" : "false\n");

    delete[] arr;
}