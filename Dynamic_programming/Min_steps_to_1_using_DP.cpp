#include <bits/stdc++.h>
using namespace std;

/*

************MEMOISATION************

int helper(int n, int arr[]){

    if(n == 1){
        return 0;
    }

    if(arr[n] != -1){
        return arr[n];
    }

    int ans1 = INT_MAX, ans2 = INT_MAX, ans3 = INT_MAX;

    if(n % 3 == 0){
        ans1 = helper(n/3, arr);
    }

    if(n % 2 == 0){
        ans2 = helper(n/2, arr);
    }

    ans3 = helper(n - 1, arr);

    arr[n] = min({ans1, ans2, ans3}) + 1;

    return arr[n];

}
*/

/* ********DYNAMIC PROGRAMMING********** */

int countStepsToOne(int n)
{
    int arr[n + 1];

    arr[1] = 0;

    for (int i = 2; i <= n; i++)
    {

        int ans1 = INT_MAX, ans2 = INT_MAX, ans3 = INT_MAX;

        if (i % 2 == 0)
        {
            if (i / 2 >= 1)
            {
                ans1 = arr[i / 2];
            }
        }

        if (i % 3 == 0)
        {
            if (n / 3 >= 1)
            {
                ans2 = arr[i / 3];
            }
        }

        ans3 = arr[i - 1];

        arr[i] = min({ans1, ans2, ans3}) + 1;
    }

    return arr[n];
}

int main()
{
    int n;
    cin >> n;
    cout << countStepsToOne(n);
}