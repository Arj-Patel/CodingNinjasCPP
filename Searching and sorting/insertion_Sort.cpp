#include <iostream>
using namespace std;

/*
void insertionSort(int arr[], int n)
{

    for (int i = 1; i < n; i++)
    {
        int flag = 1;
        int start;
        int j = i - 1;
        while (j > -1)
        {
            if (arr[i] <= arr[j])
            {
                start = j;
                flag = 0;
            }
            j--;
        }

        if (flag)
        {
            continue;
        }

        int temp = arr[i];
        for (int k = i - 1; k >= start; k--)
        {
            arr[k + 1] = arr[k];
        }

        arr[start] = temp;
    }
}
*/

void insertionSort(int arr[], int n)
{
    int current;
    for (int i = 1; i < n; i++)
    {
        current = arr[i];
        for (int j = i - 1; j > -1; j--)
        {
            if (current <= arr[j])
            {
                arr[j + 1] = arr[j];
                arr[j] = current;
            }
            else
            {
                break;
            }
        }
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

    insertionSort(arr, n);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;

    delete arr;

    return 0;
}