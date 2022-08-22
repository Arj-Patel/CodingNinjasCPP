#include <iostream>
using namespace std;

/*
You can use minimum value of integer as -2147483647 and
maximum value of integer as 2147483647
*/
void findLargest(int **arr, int n, int m)
{
    long long max = -1247483647;

    int roc = 0, row, col; // roc is used to find whether the max sum comes from a row or a column. If roc == 0, then it is row or else column.

    for (int i = 0; i < n; i++)
    {
        long long sum = 0;
        for (int j = 0; j < m; j++)
        {
            sum += arr[i][j];
        }

        if (sum > max)
        {
            row = i;
            max = sum;
            roc = 0;
        }
    }

    for (int i = 0; i < m; i++)
    {
        long long sum = 0;
        for (int j = 0; j < n; j++)
        {
            sum += arr[j][i];
        }

        if (sum > max)
        {
            col = i;
            max = sum;
            roc = 1;
        }
    }

    if (roc)
    {
        cout << "column " << col << " " << max << endl;
    }
    else
    {
        cout << "row " << row << " " << max << endl;
    }
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

        findLargest(input, row, col);
        cout << endl;
    }
}