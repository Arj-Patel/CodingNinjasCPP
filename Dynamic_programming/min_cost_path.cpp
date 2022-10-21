#include <bits/stdc++.h>
using namespace std;

/*
******** BRUTE FORCE RECURSIVE APPROACH**********

int helper(int **arr, int i, int j, int m, int n){

    if(i > m || j > n){
        return INT_MAX;
    }
    if(i == m && j == n){
        return arr[i][j];
    }

    int ans1 = helper(arr, i + 1, j, m, n);

    int ans2 = helper(arr, i, j + 1, m, n);

    int ans3 = helper(arr, i + 1, j + 1, m, n);

    return arr[i][j] + min({ans1, ans2, ans3});

}
*/

/*

************ MEMONIZATION APPROACH **********

int helper(int **arr, int** temp, int i, int j, int m, int n){

    if(i > m || j > n){
        return INT_MAX;
    }
    if(i == m && j == n){
        return arr[i][j];
    }

    if(temp[i][j] != -1){
        return temp[i][j];
    }
    else{
        int ans1 = helper(arr, temp, i + 1, j, m, n);

        int ans2 = helper(arr, temp, i, j + 1, m, n);

        int ans3 = helper(arr, temp, i + 1, j + 1, m, n);

        temp[i][j] = arr[i][j] + min({ans1, ans2, ans3});

        return temp[i][j];
    }

}
*/

/******** DYNAMIC PROGRAMMING APPROACH*********/

int minCostPath(int **arr, int m, int n)
{

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (j == 0 && i == 0)
            {
                continue;
            }
            if (i == 0)
            {
                arr[i][j] += arr[i][j - 1];
            }
            else if (j == 0)
            {
                arr[i][j] += arr[i - 1][j];
            }
            else
            {
                arr[i][j] += min({arr[i - 1][j], arr[i][j - 1], arr[i - 1][j - 1]});
            }
        }
    }

    return arr[m - 1][n - 1];
}

int main()
{
    int **arr, n, m;
    cin >> n >> m;
    arr = new int *[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = new int[m];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }
    cout << minCostPath(arr, n, m) << endl;
}