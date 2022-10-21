#include <bits/stdc++.h>
#include <iostream>
using namespace std;

/*
int helper(int* loot, int n, int* arr){

    if(n <= 0){
        arr[0] = 0;
        return 0;
    }

    if(arr[n] != -1){
        return arr[n];
    }

    int ans1 = loot[0] + helper(loot + 2, n - 2, arr);
    int ans2 = helper(loot + 1, n-1, arr);

    arr[n] = max(ans1, ans2);

    return max(ans1, ans2);

}
*/

int maxMoneyLooted(int *loot, int n)
{

    int *arr = new int[n + 1];

    // if(n <= 0){
    //     return 0;
    // }
    // for(int i = 0 ; i <= n; i++){
    //     arr[i] = -1;
    // }

    // int ans1 = arr[0] + maxMoneyLooted(arr + 2, n - 2);
    // int ans2 = maxMoneyLooted(arr+1, n-1);
    //  return helper(loot, n, arr);
    //  return max(ans1, ans2);

    arr[0] = 0;
    arr[1] = loot[0];

    for (int i = 2; i <= n; i++)
    {
        arr[i] = max(arr[i - 1], arr[i - 2] + loot[i - 1]);
    }
    int ans = arr[n];
    delete[] arr;

    return ans;
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

    cout << maxMoneyLooted(arr, n);

    delete[] arr;
}