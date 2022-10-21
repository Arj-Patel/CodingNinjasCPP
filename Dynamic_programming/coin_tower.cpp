#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;

int helper(int n, int x, int y, int *arr)
{

    if (n - 1 == 0 || n - x == 0 || n - y == 0)
    {
        return 1;
    }

    if (arr[n] != -1)
    {
        return arr[n];
    }

    int ans;

    if (n > x && n > y)
    {
        int a = helper(n - 1, x, y, arr);
        int b = helper(n - x, x, y, arr);
        int c = helper(n - y, x, y, arr);

        if (a == 0 || b == 0 || c == 0)
        {
            ans = 1;
        }
        else
        {
            ans = 0;
        }
    }
    else if (n < x && n > y)
    {
        int a = helper(n - 1, x, y, arr);
        int c = helper(n - y, x, y, arr);

        if (a == 0 || c == 0)
        {
            ans = 1;
        }
        else
        {
            ans = 0;
        }
    }
    else if (n > x && n < y)
    {
        int a = helper(n - 1, x, y, arr);
        int c = helper(n - x, x, y, arr);

        if (a == 0 || c == 0)
        {
            ans = 1;
        }
        else
        {
            ans = 0;
        }
    }
    else
    {
        ans = !helper(n - 1, x, y, arr);
    }

    arr[n] = ans;
    return ans;
}

string findWinner(int n, int x, int y)
{

    int *arr = new int[n + 1];
    for (int i = 0; i <= n; i++)
    {
        arr[i] = -1;
    }

    int ans = helper(n, x, y, arr);

    if (ans)
    {
        return "Beerus";
    }
    else
    {
        return "Whis";
    }
}

int main()
{
    int n, x, y;
    cin >> n >> x >> y;
    cout << findWinner(n, x, y);
}