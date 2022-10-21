/*
    Note:
    To get all the test cases accepted, make recursive calls in following order: Top, Down, Left, Right.
    This means that if the current cell is (x, y), then order of calls should be: top cell (x-1, y),
    down cell (x+1, y), left cell (x, y-1) and right cell (x, y+1).
*/
#include <bits/stdc++.h>
using namespace std;

void ratInMaze(int **arr, int **sol, int n, int row, int col)
{

    if (row < 0 || row >= n || col >= n || col < 0)
    {
        return;
    }

    if (row == n - 1 && col == n - 1)
    {
        sol[n - 1][n - 1] = 1;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << sol[i][j] << " ";
            }
        }
        cout << endl;
        sol[n - 1][n - 1] = 0;
        return;
    }

    if (row - 1 >= 0)
    {
        if (arr[row - 1][col] == 1 && sol[row - 1][col] != 1)
        {
            sol[row][col] = 1;
            ratInMaze(arr, sol, n, row - 1, col);
            sol[row][col] = 0;
        }
    }

    if (row + 1 < n)
    {
        if (arr[row + 1][col] == 1 && sol[row + 1][col] != 1)
        {
            sol[row][col] = 1;
            ratInMaze(arr, sol, n, row + 1, col);
            sol[row][col] = 0;
        }
    }

    if (col - 1 >= 0)
    {
        if (arr[row][col - 1] == 1 && sol[row][col - 1] != 1)
        {
            sol[row][col] = 1;
            ratInMaze(arr, sol, n, row, col - 1);
            sol[row][col] = 0;
        }
    }

    if (col + 1 < n)
    {
        if (arr[row][col + 1] == 1 && sol[row][col + 1] != 1)
        {
            sol[row][col] = 1;
            ratInMaze(arr, sol, n, row, col + 1);
            sol[row][col] = 0;
        }
    }

    return;
}

int main()
{

    int n;
    cin >> n;
    int **arr = new int *[n];
    int **sol = new int *[n];

    for (int i = 0; i < n; i++)
    {
        arr[i] = new int[n];
        sol[i] = new int[n];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
            sol[i][j] = 0;
        }
    }

    ratInMaze(arr, sol, n, 0, 0);

    for (int i = 0; i < n; i++)
    {
        delete[] arr[i];
        delete[] sol[i];
    }
    delete[] arr;
    delete[] sol;

    return 0;
}
