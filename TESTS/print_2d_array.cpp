#include <iostream>
using namespace std;

void print2DArray(int **arr, int n, int m)
{

    int row = n;

    for (int i = 0; i < n; i++)
    {
        for (int k = 0; k < row; k++)
        {
            for (int j = 0; j < m; j++)
            {
                cout << arr[i][j] << " ";
            }
            cout << endl;
        }
        row--;
    }
}

int main()
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
    print2DArray(input, row, col);
}
