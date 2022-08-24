#include <iostream>
using namespace std;

int findDuplicate(int *arr, int n)
{

    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }

    int sumOfElements = ((n - 1) * (n - 2)) / 2;

    return sum - sumOfElements;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int size;
        cin >> size;
        int *input = new int[size];

        for (int i = 0; i < size; i++)
        {
            cin >> input[i];
        }

        cout << findDuplicate(input, size) << endl;
    }

    return 0;
}