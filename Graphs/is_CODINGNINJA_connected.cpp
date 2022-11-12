#include <bits/stdc++.h>
using namespace std;

bool checkCN(vector<vector<char>> &board, int n, int m, int row, int col, string str)
{

    if (str.length() == 0)
    {
        return true;
    }

    if (row - 1 >= 0)
    {
        if (board[row - 1][col] == str[0])
        {
            board[row - 1][col] = '1';
            bool ans = checkCN(board, n, m, row - 1, col, str.substr(1));
            board[row - 1][col] = str[0];
            if (ans)
            {
                return true;
            }
        }
    }

    if (row - 1 >= 0 && col + 1 < m)
    {
        if (board[row - 1][col + 1] == str[0])
        {
            board[row - 1][col + 1] = '1';
            bool ans = checkCN(board, n, m, row - 1, col + 1, str.substr(1));
            board[row - 1][col + 1] = str[0];
            if (ans)
            {
                return true;
            }
        }
    }

    if (col + 1 < m)
    {
        if (board[row][col + 1] == str[0])
        {
            board[row][col + 1] = '1';
            bool ans = checkCN(board, n, m, row, col + 1, str.substr(1));
            board[row][col + 1] = str[0];
            if (ans)
            {
                return true;
            }
        }
    }

    if (row + 1 < n && col + 1 < m)
    {
        if (board[row + 1][col + 1] == str[0])
        {
            board[row + 1][col + 1] = '1';
            bool ans = checkCN(board, n, m, row + 1, col + 1, str.substr(1));
            board[row + 1][col + 1] = str[0];
            if (ans)
            {
                return true;
            }
        }
    }

    if (row + 1 < n)
    {
        if (board[row + 1][col] == str[0])
        {
            board[row + 1][col] = '1';
            bool ans = checkCN(board, n, m, row + 1, col, str.substr(1));
            board[row + 1][col] = str[0];
            if (ans)
            {
                return true;
            }
        }
    }

    if (row + 1 < n && col - 1 >= 0)
    {
        if (board[row + 1][col - 1] == str[0])
        {
            board[row + 1][col - 1] = '1';
            bool ans = checkCN(board, n, m, row + 1, col - 1, str.substr(1));
            board[row + 1][col - 1] = str[0];
            if (ans)
            {
                return true;
            }
        }
    }

    if (col - 1 >= 0)
    {
        if (board[row][col - 1] == str[0])
        {
            board[row][col - 1] = '1';
            bool ans = checkCN(board, n, m, row, col - 1, str.substr(1));
            board[row][col - 1] = str[0];
            if (ans)
            {
                return true;
            }
        }
    }

    if (row - 1 >= 0 && col - 1 >= 0)
    {
        if (board[row - 1][col - 1] == str[0])
        {
            board[row - 1][col - 1] = '1';
            bool ans = checkCN(board, n, m, row - 1, col - 1, str.substr(1));
            board[row - 1][col - 1] = str[0];
            if (ans)
            {
                return true;
            }
        }
    }

    return false;
}

bool checkCN(vector<vector<char>> &board, int n, int m, string str)
{

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (board[i][j] == 'C')
            {
                board[i][j] = '1';
                int ans = checkCN(board, n, m, i, j, str.substr(1));
                board[i][j] = 'C';
                if (ans)
                {
                    return true;
                }
            }
        }
    }
    return false;
}

bool hasPath(vector<vector<char>> &board, int n, int m)
{

    string str = "CODINGNINJA";

    int i, j, chk = 0;

    // for(i = 0; i < n; i++){
    //     for(j = 0; j < m; j++){
    //         if(board[i][j] == 'C'){
    //             chk = 1;
    //             break;
    //         }
    //     }
    //     if(chk){
    //         break;
    //     }
    // }

    return checkCN(board, n, m, str);
}