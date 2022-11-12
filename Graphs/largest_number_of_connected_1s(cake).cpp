#include <bits/stdc++.h>
using namespace std;

int biggestCake(vector<vector<int>> &cake, int n, int row, int col, vector<vector<bool>> &visited)
{

    // if(row < 0 || col < 0 || row >= n || col >= n){
    //     return 0;
    // }
    // if(cake[row][col] != 1){
    //     return 0;
    // }

    visited[row][col] = true;
    int ans = 0;

    if (row + 1 < n && cake[row + 1][col] == 1 && !visited[row + 1][col])
    {
        ans += biggestCake(cake, n, row + 1, col, visited);
    }

    if (row - 1 >= 0 && cake[row - 1][col] == 1 && !visited[row - 1][col])
    {
        ans += biggestCake(cake, n, row - 1, col, visited);
    }

    if (col + 1 < n && cake[row][col + 1] == 1 && !visited[row][col + 1])
    {
        ans += biggestCake(cake, n, row, col + 1, visited);
    }

    if (col - 1 >= 0 && cake[row][col - 1] == 1 && !visited[row][col - 1])
    {
        ans += biggestCake(cake, n, row, col - 1, visited);
    }

    return ans + 1;
}

int getBiggestPieceSize(vector<vector<int>> &cake, int n)
{

    int ans = INT_MIN;

    vector<vector<bool>> visited(n, vector<bool>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            visited[i][j] = false;
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (cake[i][j] == 1 && !visited[i][j])
            {
                ans = max(ans, biggestCake(cake, n, i, j, visited));
            }
        }
    }

    return ans;
}