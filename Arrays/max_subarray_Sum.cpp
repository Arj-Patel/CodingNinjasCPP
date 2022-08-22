#include <iostream>
#include <climits>
using namespace std;

int main()
{

    int n;
    cin >> n;
    int arr[100];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    /*

    ************Brute Force Approach O(n^3)******************
    int max = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {

            int sum = 0;
            for (int k = i; k <= j; k++)
            {
                sum += arr[k];
            }
            if (sum > max)
            {
                max = sum;
            }
        }
    }
    cout << max << endl;

    */

    /*

    ********Cumulative Sum Approach O(n^2)*********

    int cumulativeSumArr[100];
    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        cumulativeSumArr[i] = sum;
    }

    int maxSum = INT_MIN;

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            sum = cumulativeSumArr[i] - cumulativeSumArr[j];
            maxSum = max(sum, maxSum);
        }
    }
    cout << maxSum << endl;

    */

    /***********Kadanes Approach O(n)*********/

    int currentSum = 0;
    int maxSum = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        currentSum += arr[i];
        if (currentSum < 0)
        {
            currentSum = 0;
        }
        maxSum = max(maxSum, currentSum);
    }
    cout << maxSum << endl;

    return 0;
}