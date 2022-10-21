#include <bits/stdc++.h>
using namespace std;

bool isPossible(int **&arr, int n, int row, int col)
{

    // for(int k = 0; k < n; k++){

    // checking for queens placed in same column
    for (int i = 0; i < row; i++)
    {
        if (arr[i][col] == 1)
        {
            // cout<<"1false"<<endl;
            return false;
        }
    }

    // checking for queens placed in right upper diagonal
    for (int j = col + 1, i = row - 1; i >= 0 && j < n; i--, j++)
    {
        if (arr[i][j] == 1)
        {
            // cout<<"2false"<<endl;
            return false;
        }
    }

    // checking for queens placed in left upper diagonal
    for (int j = col - 1, i = row - 1; i >= 0 && j >= 0; i--, j--)
    {
        if (arr[i][j] == 1)
        {
            // cout<<"3false"<<endl;
            return false;
        }
    }
    // }

    return true;
}

void nQueen(int **arr, int n, int row)
{

    if (row == n)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << arr[i][j] << " ";
            }
        }
        cout << endl;
        return;
    }

    for (int i = 0; i < n; i++)
    {
        if (isPossible(arr, n, row, i))
        {
            arr[row][i] = 1;
            nQueen(arr, n, row + 1);
            arr[row][i] = 0;
        }
    }

    return;
}

int main()
{

    int n;
    cin >> n;

    int **arr = new int *[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = new int[n];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            arr[i][j] = 0;
        }
    }

    nQueen(arr, n, 0);

    // arr[0][3] = 1;

    // cout<<isPossible(arr, 4, 2, 2)<<endl;

    for (int i = 0; i < n; i++)
    {
        delete[] arr[i];
    }
    delete[] arr;

    return 0;
}