#include <bits/stdc++.h>
using namespace std;

void help(int input[], int size, int k, int i, int output[], int &count)
{
    if (size == 0)
    {
        if (k == 0)
        {
            count++;
            return;
        }
        else
        {
            return;
        }
    }
    int newoutput[i + 1];
    int m;
    for (m = 0; m < i; m++)
    {
        newoutput[m] = output[m];
    }
    newoutput[m] = input[0];
    help(input + 1, size - 1, k - input[0], i + 1, newoutput, count);
    help(input + 1, size - 1, k, i, output, count);
}

void subsetSumToK(int input[], int size, int k, int &count)
{
    int output[0];
    help(input, size, k, 0, output, count);
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, k;
        cin >> n >> k;

        int *arr = new int[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        int count = 0;
        subsetSumToK(arr, n, k, count);
        cout << count << endl;

        delete[] arr;
    }

    return 0;
}