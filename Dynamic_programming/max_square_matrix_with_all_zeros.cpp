#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int findMaxSquareWithAllZeros(int **arr, int n, int m)
{

    int **tempArr = new int *[n];
    for (int i = 0; i < n; i++)
    {
        tempArr[i] = new int[m];
    }

    for (int i = 0; i < n; i++)
    {
        tempArr[i][0] = !arr[i][0];
    }
    for (int i = 0; i < m; i++)
    {
        tempArr[0][i] = !arr[0][i];
    }

    int maxSq = 0;

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            if (arr[i][j] == 1)
            {
                tempArr[i][j] = 0;
            }
            else
            {
                tempArr[i][j] = min({tempArr[i][j - 1], tempArr[i - 1][j], tempArr[i - 1][j - 1]}) + 1;
            }

            maxSq = max(maxSq, tempArr[i][j]);
        }
    }

    for (int i = 0; i < n; i++)
    {
        delete[] tempArr[i];
    }
    delete[] tempArr;
    return maxSq;
}

int main()
{
    int **arr, n, m, i, j;
    cin >> n >> m;
    arr = new int *[n];

    for (i = 0; i < n; i++)
    {
        arr[i] = new int[m];
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }

    cout << findMaxSquareWithAllZeros(arr, n, m) << endl;

    delete[] arr;

    return 0;
}