#include <iostream>
using namespace std;

int findSecondLargest(int *arr, int n)
{
    int max = -2147483648;
    int max2 = -2147483648;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > max)
        {
            max2 = max;
            max = arr[i];
        }
        else if (arr[i] < max && arr[i] > max2)
        {
            max2 = arr[i];
        }
    }
    return max2;
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

        cout << findSecondLargest(input, size) << endl;

        delete[] input;
    }

    return 0;
}