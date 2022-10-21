#include <bits/stdc++.h>
using namespace std;

long long helper(long long n, long long *arr)
{

    arr[0] = 1;
    arr[1] = 1;
    arr[2] = 2;

    for (long long i = 3; i <= n; i++)
    {
        arr[i] = arr[i - 1] % (1000000007) + arr[i - 2] % (1000000007) + arr[i - 3] % (1000000007);
    }

    return arr[n] % (1000000007);
}

int main()
{

    long long t;
    cin >> t;

    while (t--)
    {
        long long n;
        cin >> n;
        long long *arr = new long long[n + 1];
        for (int i = 0; i <= n; i++)
        {
            arr[i] = 0;
        }
        cout << helper(n, arr) << endl;
        delete[] arr;
    }

    return 0;
}