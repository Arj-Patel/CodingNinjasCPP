#include <cstring>
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

/*
int helper(int* weights, int* values, int n, int maxWeight, int** arr){
    if(n == 0 || maxWeight == 0){
        return 0;
    }

    int ans1 = INT_MIN, ans2 = INT_MIN;
    if(arr[n][maxWeight] != -1){
        return arr[n][maxWeight];
    }

    if(weights[0] > maxWeight){
        arr[n][maxWeight] = helper(weights+1, values+1, n-1, maxWeight, arr);
        return arr[n][maxWeight];
    }

    ans1 = values[0] + helper(weights+1, values+1, n-1, maxWeight-weights[0], arr);
    ans2 = helper(weights+1, values+1, n-1, maxWeight, arr);

    arr[n][maxWeight] = max(ans1, ans2);
    return max(ans1, ans2);

}
*/

int knapsack(int *weight, int *value, int n, int maxWeight)
{

    int **arr = new int *[n + 1];
    for (int i = 0; i <= n; i++)
    {
        arr[i] = new int[maxWeight + 1];
    }

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= maxWeight; j++)
        {
            if (i == 0 || j == 0)
            {
                arr[i][j] = 0;
            }
            else if (weight[i - 1] <= j)
            {
                arr[i][j] = max(value[i - 1] + arr[i - 1][j - weight[i - 1]], arr[i - 1][j]);
            }
            else
            {
                arr[i][j] = arr[i - 1][j];
            }
        }
    }
    return arr[n][maxWeight];
}

int main()
{
    int n;
    cin >> n;
    int *wt = new int[n];
    int *val = new int[n];

    for (int i = 0; i < n; i++)
    {
        cin >> wt[i];
    }

    for (int j = 0; j < n; j++)
    {
        cin >> val[j];
    }

    int w;
    cin >> w;

    cout << knapsack(wt, val, n, w) << "\n";

    delete[] wt;
    delete[] val;
}