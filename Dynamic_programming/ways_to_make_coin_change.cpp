#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/*
// ***********MEMOIZATION APPROACH***********

int helper(int* change, int n, int value, int** arr){

    if(n == 0){
        if(value == 0){
            return 1;
        }
        else{
            return 0;
        }
    }

    if(value == 0){
        return 1;
    }
    else if(value < 0){
        return 0;
    }

    if(arr[n][value] != -1){
        return arr[n][value];
    }

    int ans = 0;

    ans += helper(change, n, value-change[0], arr);
    ans += helper(change + 1, n - 1 , value, arr);
    arr[n][value] = ans;

    return ans;

}
*/

int countWaysToMakeChange(int change[], int n, int value)
{

    /*
    int** arr = new int*[n+1];
    for(int i = 0; i <= n; i++){
        arr[i] = new int[value+1];
        for(int j = 0; j <= value; j++){
            arr[i][j] = -1;
        }
    }

    return helper(change, n, value, arr);
    */

    int *arr = new int[value + 1];
    memset(arr, 0, sizeof(arr));
    arr[0] = 1;

    for (int i = 0; i < n; i++)
    {
        for (int j = change[i]; j <= value; j++)
        {
            arr[j] += arr[j - change[i]];
        }
    }

    return arr[value];
}

int main()
{

    int numDenominations;
    cin >> numDenominations;

    int *denominations = new int[numDenominations];

    for (int i = 0; i < numDenominations; i++)
    {
        cin >> denominations[i];
    }

    int value;
    cin >> value;

    cout << countWaysToMakeChange(denominations, numDenominations, value);

    delete[] denominations;
}