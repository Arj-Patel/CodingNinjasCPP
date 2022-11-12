#include <bits/stdc++.h>
using namespace std;

bool chkCycle(vector<vector<char>> &board, int n, int m, int row, int col, int sr, int sc, bool visited, int count, char ch)
{

    if (visited && count >= 4 && row == sr && col == sc)
    {
        return true;
    }

    if (row - 1 >= 0)
    {
        if (board[row - 1][col] == ch)
        {
            // cout<<1<<endl;
            board[row - 1][col] = '1';
            bool ans = chkCycle(board, n, m, row - 1, col, sr, sc, true, count + 1, ch);
            board[row - 1][col] = ch;
            if (ans)
            {
                return true;
            }
        }
    }

    // if(row - 1 >= 0 && col + 1 < m){
    //     if(board[row-1][col+1] == ch){
    //         cout<<2<<endl;
    //         board[row-1][col+1] = '1';
    //         bool ans = chkCycle(board, n, m, row-1, col+1, sr, sc, true, count+1, ch);
    //         board[row-1][col+1] = ch;
    //         if(ans){
    //             return true;
    //         }
    //     }
    // }

    if (col + 1 < m)
    {
        if (board[row][col + 1] == ch)
        {
            // cout<<3<<endl;
            board[row][col + 1] = '1';
            bool ans = chkCycle(board, n, m, row, col + 1, sr, sc, true, count + 1, ch);
            board[row][col + 1] = ch;
            if (ans)
            {
                return true;
            }
        }
    }

    // if(row + 1 < n && col + 1 < m){
    //     if(board[row+1][col+1] == ch){
    //         cout<<4<<endl;
    //         board[row+1][col+1] = '1';
    //         bool ans = chkCycle(board, n, m, row+1, col+1, sr, sc, true, count+1, ch);
    //         board[row+1][col+1] = ch;
    //         if(ans){
    //             return true;
    //         }
    //     }
    // }

    if (row + 1 < n)
    {
        if (board[row + 1][col] == ch)
        {
            // cout<<5<<endl;
            board[row + 1][col] = '1';
            bool ans = chkCycle(board, n, m, row + 1, col, sr, sc, true, count + 1, ch);
            board[row + 1][col] = ch;
            if (ans)
            {
                return true;
            }
        }
    }

    // if(row + 1 < n && col - 1 >= 0){
    //     if(board[row+1][col-1] == ch){
    //         cout<<6<<endl;
    //         board[row+1][col-1] = '1';
    //         bool ans = chkCycle(board, n, m, row+1, col-1, sr, sc, true, count+1, ch);
    //         board[row+1][col-1] = ch;
    //         if(ans){
    //             return true;
    //         }
    //     }
    // }

    if (col - 1 >= 0)
    {
        if (board[row][col - 1] == ch)
        {
            // cout<<7<<endl;
            board[row][col - 1] = '1';
            bool ans = chkCycle(board, n, m, row, col - 1, sr, sc, true, count + 1, ch);
            board[row][col - 1] = ch;
            if (ans)
            {
                return true;
            }
        }
    }

    // if(row - 1 >= 0 && col - 1 >= 0){
    //     if(board[row-1][col-1] == ch){
    //         cout<<8<<endl;
    //         board[row-1][col-1] = '1';
    //         bool ans = chkCycle(board, n, m, row-1, col-1, sr, sc, true, count+1, ch);
    //         board[row-1][col-1] = ch;
    //         if(ans){
    //             return true;
    //         }
    //     }
    // }

    return false;
}

bool hasCycle(vector<vector<char>> &board, int n, int m)
{

    for (int i = 0; i < 26; i++)
    {

        char ch = 'A' + i;
        // char ch = 'C';
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < m; k++)
            {
                if (board[j][k] == ch)
                {
                    // board[j][k] = '1';
                    // cout<<ch<<endl;
                    bool ans = chkCycle(board, n, m, j, k, j, k, false, 0, ch);
                    if (ans)
                    {
                        return true;
                    }
                    // board[j][k] = ch;
                }
            }
        }
    }

    return false;
}