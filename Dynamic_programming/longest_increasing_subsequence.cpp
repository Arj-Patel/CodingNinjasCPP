#include <bits/stdc++.h>
#include <iostream>
using namespace std;

/*
pair<int, int> helper(int* arr, int n){

    if(n == 1){
        pair<int, int> p = {arr[0],1};
        return p;
    }

    pair<int, int> p = helper(arr+1, n-1);

    if(arr[0] < p.first){
        p.first = arr[0];
        p.second++;
    }

    return p;

}

int longestIncreasingSubsequence(int* arr, int n) {

    pair<int, int> ans = helper(arr, n);

    return ans.second;
}
*/

/*
int helper(int* arr, int n, int prev, int** lisArr){

    if(n == 0){
        lisArr[0][0] = 0;
        return 0;
    }

    if(lisArr[n][prev+1] != -1){
        return lisArr[n][prev+1];
    }

    int ans1 = -1, ans2 = -1;
    if(arr[0] > prev){
        ans1 = 1 + helper(arr + 1, n - 1, arr[0], lisArr);
    }

    ans2 = helper(arr + 1, n - 1, prev, lisArr);

    lisArr[n][prev+1] = max(ans1, ans2);

    return max(ans1, ans2);

}

int longestIncreasingSubsequence(int* arr, int n) {

    int** lisArr = new int*[n+1];
    for(int i = 0; i <= n; i++){
        lisArr[i] = new int[n+1];
        for(int j = 0; j <= n; j++){
            lisArr[i][j] = -1;
        }
    }

    int ans = helper(arr, n, -1, lisArr);

    return ans;

}
*/

#include <bits/stdc++.h>
#include <iostream>
using namespace std;

/*
int f(int idx, int prev_idx, int n, int a[],
      vector<vector<int> >& dp)
{
    if (idx == n) {
        return 0;
    }

    if (dp[idx][prev_idx + 1] != -1) {
        return dp[idx][prev_idx + 1];
    }

    int notTake = 0 + f(idx + 1, prev_idx, n, a, dp);
    int take = INT_MIN;
    if (prev_idx == -1 || a[idx] > a[prev_idx]) {
        take = 1 + f(idx + 1, idx, n, a, dp);
    }

    return dp[idx][prev_idx + 1] = max(take, notTake);
}
// Function to find length of longest increasing
// subsequence.
int longestIncreasingSubsequence(int* a, int n)
{
    vector<vector<int> > dp(n + 1, vector<int>(n + 1, -1));
    return f(0, -1, n, a, dp);
}
*/

int longestIncreasingSubsequence(int *arr, int n)
{

    int *helper = new int[n];
    memset(helper, 0, sizeof(arr));
    helper[0] = 1;

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (arr[j] < arr[i])
            {
                if (helper[j] >= helper[i])
                {
                    helper[i] = helper[j] + 1;
                }
            }
        }
        if (helper[i] == 0)
        {
            helper[i] = 1;
        }
    }

    int maxEle = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        maxEle = max(maxEle, helper[i]);
        // cout<<helper[i]<<" ";
    }
    cout << endl;

    delete[] arr;
    return maxEle;
}

int main()
{
    int n;
    cin >> n;
    int *arr = new int[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << longestIncreasingSubsequence(arr, n);
}