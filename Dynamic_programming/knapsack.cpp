#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int helper(int *weights, int *values, int n, int maxWeight)
{

    if (n == 0)
    {
        return 0;
    }

    int ans1 = INT_MIN, ans2 = INT_MIN;

    if (weights[0] > maxWeight)
    {
        return helper(weights + 1, values + 1, n - 1, maxWeight);
    }

    ans1 = values[0] + helper(weights + 1, values + 1, n - 1, maxWeight - weights[0]);
    ans2 = helper(weights + 1, values + 1, n - 1, maxWeight);

    return max(ans1, ans2);
}

int knapsack(int *weights, int *values, int n, int maxWeight)
{
    return helper(weights, values, n, maxWeight);
}

int main()
{
    int n;
    cin >> n;

    int *weights = new int[n];
    int *values = new int[n];

    for (int i = 0; i < n; i++)
    {
        cin >> weights[i];
    }

    for (int i = 0; i < n; i++)
    {
        cin >> values[i];
    }

    int maxWeight;
    cin >> maxWeight;

    cout << knapsack(weights, values, n, maxWeight) << endl;

    delete[] weights;
    delete[] values;
}