#include <iostream>
using namespace std;

void wavePrint(int **arr, int n, int m)
{
    int i, j, k;

    for (j = 0; j < m; j++)
    {
        if (j % 2 == 0)
        {
            for (i = 0; i < n; i++)
            {
                cout << arr[i][j] << " ";
            }
        }
        else
        {
            for (i = n - 1; i >= 0; i--)
            {
                cout << arr[i][j] << " ";
            }
        }
    }
    cout << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int row, col;
        cin >> row >> col;
        int **input = new int *[row];
        for (int i = 0; i < row; i++)
        {
            input[i] = new int[col];
            for (int j = 0; j < col; j++)
            {
                cin >> input[i][j];
            }
        }
        wavePrint(input, row, col);
        cout << endl;
    }
}