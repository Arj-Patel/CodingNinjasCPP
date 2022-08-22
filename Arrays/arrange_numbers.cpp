#include <iostream>
using namespace std;

void arrange(int *arr, int n)
{

    int midIndex;
    if (n % 2 == 0)
    {
        midIndex = n / 2;
    }
    else
    {
        midIndex = n / 2 + 1;
    }

    int x = 1;
    for (int i = 0; i < midIndex; i++)
    {
        arr[i] = x;
        x = x + 2;
    }

    if (n % 2 == 0)
    {
        x = x - 1;
    }
    else
    {
        x = x - 3;
    }

    for (int i = midIndex; i < n; i++)
    {
        arr[i] = x;
        x = x - 2;
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int *arr = new int[n];
        arrange(arr, n);
        for (int i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
        delete[] arr;
    }
}