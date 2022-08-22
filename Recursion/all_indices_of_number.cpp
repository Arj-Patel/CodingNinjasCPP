#include <iostream>
using namespace std;

int allIndexes(int arr[], int n, int x, int output[])
{

    if (n == 0)
    {
        return 0;
    }

    int ans = allIndexes(arr, n - 1, x, output);

    if (arr[n - 1] == x)
    {
        output[ans] = n - 1;
        return ans + 1;
    }
    else
    {
        return ans;
    }
    
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

    int x;

    cin >> x;

    int *output = new int[n];

    int size = allIndexes(input, n, x, output);
    for (int i = 0; i < size; i++)
    {
        cout << output[i] << " ";
    }

    delete[] input;
    delete[] output;
}