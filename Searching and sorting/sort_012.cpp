#include <iostream>
#include <algorithm>
using namespace std;

void sort012(int *arr, int n)
{

    int i = 0, t0 = 0, t2 = n - 1;

    while (i <= t2)
    {
        if (arr[i] == 0)
        {
            int temp = arr[i];
            arr[i] = arr[t0];
            arr[t0] = temp;
            i++;
            t0++;
        }
        else if (arr[i] == 1)
        {
            i++;
        }
        else if (arr[i] == 2)
        {
            int temp = arr[i];
            arr[i] = arr[t2];
            arr[t2] = temp;
            t2--;
        }
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int size;

        cin >> size;
        int *arr = new int[size];

        for (int i = 0; i < size; i++)
        {
            cin >> arr[i];
        }

        sort012(arr, size);

        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }

        delete[] arr;
        cout << endl;
    }

    return 0;
}