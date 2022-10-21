#include <iostream>
using namespace std;

/*

********Brute Force Approach********
int balancedBTs(int n)
{

    if (n <= 1)
    {
        return 1;
    }

    long long ans1 = balancedBTs(n - 1);
    long long ans2 = balancedBTs(n - 2);

    return ((ans1 % (1000000007) * ans1 % (1000000007)) + (ans2 % (1000000007) * ans1 % (1000000007)) * 2) % (1000000007);
}
*/

int balancedBTs(int n)
{

    long long *arr = new long long[n + 1];

    arr[0] = 0;
    arr[1] = 1;
    arr[2] = 3;

    for (int i = 3; i <= n; i++)
    {
        arr[i] = (arr[i - 1] % 1000000007) * (arr[i - 1] % 1000000007) + 2 * (arr[i - 1] % 1000000007) * (arr[i - 2] % 1000000007);
    }

    return arr[n] % 1000000007;
}

int main()
{
    int n;
    cin >> n;
    cout << balancedBTs(n);
}