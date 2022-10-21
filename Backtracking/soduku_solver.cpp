#include <iostream>
using namespace std;

bool checkCol(int arr[][9], int col, int x)
{

    for (int i = 0; i < 9; i++)
    {
        if (arr[i][col] == x)
        {
            return false;
        }
    }

    return true;
}

bool checkRow(int arr[][9], int row, int x)
{

    for (int i = 0; i < 9; i++)
    {
        if (arr[row][i] == x)
        {
            return false;
        }
    }

    return true;
}

bool checkBox(int arr[][9], int row, int col, int x)
{

    if (row < 3)
    {
        if (col < 3)
        {
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    if (arr[i][j] == x)
                    {
                        return false;
                    }
                }
            }
        }
        else if (col >= 3 && col < 6)
        {
            for (int i = 0; i < 3; i++)
            {
                for (int j = 3; j < 6; j++)
                {
                    if (arr[i][j] == x)
                    {
                        return false;
                    }
                }
            }
        }
        else if (col >= 6)
        {
            for (int i = 0; i < 3; i++)
            {
                for (int j = 6; j < 9; j++)
                {
                    if (arr[i][j] == x)
                    {
                        return false;
                    }
                }
            }
        }
    }
    else if (row >= 3 && row < 6)
    {
        if (col < 3)
        {
            for (int i = 3; i < 6; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    if (arr[i][j] == x)
                    {
                        return false;
                    }
                }
            }
        }
        else if (col >= 3 && col < 6)
        {
            for (int i = 3; i < 6; i++)
            {
                for (int j = 3; j < 6; j++)
                {
                    if (arr[i][j] == x)
                    {
                        return false;
                    }
                }
            }
        }
        else if (col >= 6)
        {
            for (int i = 3; i < 6; i++)
            {
                for (int j = 6; j < 9; j++)
                {
                    if (arr[i][j] == x)
                    {
                        return false;
                    }
                }
            }
        }
    }
    else if (row >= 6 && row < 9)
    {
        if (col < 3)
        {
            for (int i = 6; i < 9; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    if (arr[i][j] == x)
                    {
                        return false;
                    }
                }
            }
        }
        else if (col >= 3 && col < 6)
        {
            for (int i = 6; i < 9; i++)
            {
                for (int j = 3; j < 6; j++)
                {
                    if (arr[i][j] == x)
                    {
                        return false;
                    }
                }
            }
        }
        else if (col >= 6)
        {
            for (int i = 6; i < 9; i++)
            {
                for (int j = 6; j < 9; j++)
                {
                    if (arr[i][j] == x)
                    {
                        return false;
                    }
                }
            }
        }
    }

    return true;
}

/*
bool checkBox(int arr[][9], int row, int col, int x){
    int rowFactor = row - (row%3);
    int colFactor = col - (col%3);
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(arr[i+rowFactor][j+colFactor] == x){
                return false;
            }
        }
    }
    return true;
}
*/

bool findEmpty(int arr[][9], int &row, int &col)
{

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (arr[i][j] == 0)
            {
                row = i;
                col = j;
                return true;
            }
        }
    }
    return false;
}

bool sudoku(int arr[][9])
{

    int i, j;

    if (!findEmpty(arr, i, j))
    {
        return true;
    }

    for (int k = 1; k < 10; k++)
    {

        if (checkRow(arr, i, k) && checkCol(arr, j, k) && checkBox(arr, i, j, k))
        {
            arr[i][j] = k;
            if (sudoku(arr))
            {
                return true;
            }
            arr[i][j] = 0;
        }
    }

    return false;
}

int main()
{

    int arr[9][9];
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cin >> arr[i][j];
        }
    }

    if (sudoku(arr))
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }

    // cout<<(checkRow(arr, 8, 1))<<endl;

    return 0;

    /*

    9 0 0 0 2 0 7 5 0
    6 0 0 0 5 0 0 4 0
    0 2 0 4 0 0 0 1 0
    2 0 8 0 0 0 0 0 0
    0 7 0 5 0 9 0 6 0
    0 0 0 0 0 0 4 0 1
    0 1 0 0 0 5 0 8 0
    0 9 0 0 7 0 0 0 4
    0 8 2 0 4 0 0 0 6

    */
}