#include <iostream>
using namespace std;

void helper(int arr[], int n, int output[], int k, int m)
{

    if (n == 0)
    {
        if (k == 0)
        {
            for (int i = 0; i < m - 1; i++)
            {
                cout << output[i] << " ";
            }
            cout << output[m - 1] << endl;
            return;
        }
        else
        {
            return;
        }
    }

    int newOutput[m + 1];
    for (int i = 0; i < m; i++)
    {
        newOutput[i] = output[i];
    }
    newOutput[m] = arr[0];

    helper(arr + 1, n - 1, newOutput, k - arr[0], m + 1);
    helper(arr + 1, n - 1, output, k, m);
}

void printSubsetSumToK(int arr[], int n, int k)
{

    int output[0];
    helper(arr, n, output, k, 0);
}
int main()
{
    int input[1000], length, k;
    cin >> length;
    for (int i = 0; i < length; i++)
        cin >> input[i];
    cin >> k;
    printSubsetSumToK(input, length, k);
}
