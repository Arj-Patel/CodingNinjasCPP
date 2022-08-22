#include <iostream>
using namespace std;

void merge(int arr[], int si, int mid, int ei)
{
    int i = si, j = mid + 1, k = si;
    int n = 1e6;
    int *tempArr = new int[n];

    while (i <= mid && j <= ei)
    {
        if (arr[i] < arr[j])
        {
            tempArr[k++] = arr[i++];
        }
        else
        {
            tempArr[k++] = arr[j++];
        }
    }
    while (i <= mid)
    {
        tempArr[k++] = arr[i++];
    }
    while (j <= ei)
    {
        tempArr[k++] = arr[j++];
    }

    for (i = si; i < k; i++)
    {
        arr[i] = tempArr[i];
    }

    delete[] tempArr;
}

void mergeSort(int arr[], int si, int ei)
{
    if (si >= ei)
    {
        return;
    }

    int mid = si + (ei - si) / 2;

    mergeSort(arr, si, mid);
    mergeSort(arr, mid + 1, ei);
    merge(arr, si, mid, ei);
}

int main()
{
    int length;
    cin >> length;

    int *input = new int[length];

    for (int i = 0; i < length; i++)
    {
        cin >> input[i];
    }

    mergeSort(input, 0, length - 1);

    for (int i = 0; i < length; i++)
    {
        cout << input[i] << " ";
    }

    delete[] input;
}