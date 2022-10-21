#include <iostream>
#include <algorithm>
using namespace std;

int maximumProfit(int arr[], int n)
{
    sort(arr, arr + n);

    int maxProfit = -100000;
    // int ans = 0;

    for (int i = 0; i < n; i++)
    {
        int numOfBuyers = n - i;
        if (maxProfit < numOfBuyers * arr[i])
        {
            maxProfit = numOfBuyers * arr[i];
        }
    }
    return maxProfit;
}

int main()
{
    int n, *input, i, *cost;
    cin >> n;
    input = new int[n];
    for (i = 0; i < n; i++)
        cin >> input[i];

    cout << maximumProfit(input, n) << endl;
}
