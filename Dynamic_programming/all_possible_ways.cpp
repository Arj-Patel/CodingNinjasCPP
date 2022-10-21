#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int helper(int a, int b, int i)
{

    if (a - pow(i, b) == 0)
    {
        return 1;
    }
    else if (a - pow(i, b) < 0)
    {
        return 0;
    }

    int ans = 0;

    ans = helper(a - pow(i, b), b, i + 1) + helper(a, b, i + 1);

    return ans;
}

int getAllWays(int a, int b)
{

    return helper(a, b, 1);
}

int main()
{
    int a, b;
    cin >> a >> b;
    cout << getAllWays(a, b);
}