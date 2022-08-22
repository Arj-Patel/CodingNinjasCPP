#include <iostream>
using namespace std;

int partition(int arr[], int si, int ei)
{
    int count = 0;
    for (int i = si + 1; i <= ei; i++)
    {
        if (arr[i] <= arr[si])
        {
            count++;
        }
    }

    int temp = arr[si];
    arr[si] = arr[si + count];
    arr[si + count] = temp;

    int j = ei;

    for (int i = si; i <= si + count - 1; i++)
    {
        while (arr[j] > arr[si + count] && j >= si + count + 1)
        {
            j--;
        }

        if (arr[i] > arr[si + count])
        {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    return count;
}

void quickSort(int arr[], int si, int ei)
{
    if (si >= ei)
    {
        return;
    }

    int count = partition(arr, si, ei);
    quickSort(arr, si, si + count - 1);
    quickSort(arr, si + count + 1, ei);
}

int main()
{
    int n;
    cin >> n;

    int *input = new int[n];

    for (int i = 0; i < n; i++)
    {
        cin >> input[i];
    }

    quickSort(input, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        cout << input[i] << " ";
    }

    delete[] input;
}