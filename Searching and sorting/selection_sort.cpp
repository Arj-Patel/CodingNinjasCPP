#include <iostream>
#include <climits>
using namespace std;

void selectionSort(int arr[], int n)
{
    int j = 0;
    for (int i = 0; i < n - 1; i++)
    {
        int min = INT_MAX, midIndex;
        for (j; j < n; j++)
        {
            if (arr[j] < min)
            {
                midIndex = j;
                min = arr[j];
            }
        }
        j = i + 1;

        int temp = arr[i];
        arr[i] = min;
        arr[midIndex] = temp;
    }
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

    selectionSort(arr, n);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;

    delete arr;

    return 0;
}
