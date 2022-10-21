#include <bits/stdc++.h>
using namespace std;

/*
**********BRUTE FORCE***********

int minCount(int n)
{
    if(n == 1){
        return 1;
    }
    if(n < 1){
        return 0;
    }

    int x = sqrt(n);
    int finalAns = INT_MAX;

    for(int i = 1; i <= x; i++){
        int ans = minCount(n - i*i);
        finalAns = min(finalAns, ans);
    }

    return finalAns + 1;

}
*/

/*
***********MEMONIZATION METHOD**********

int helper(int n, int* arr){

    if(n == 1){
        return 1;
    }
    else if(n < 1){
        return 0;
    }

    int finalAns = INT_MAX;
    int x = sqrt(n);

    for(int i = 1; i <= x; i++){
        if(arr[n-i*i] != -1){
            finalAns = min(finalAns, arr[n-i*i]);
        }
        else{
            int ans = helper(n-i*i, arr);
            arr[n-i*i] = ans + 1;
            finalAns = min(finalAns, arr[n-i*i]);
        }
    }

    return finalAns;
}

int minCount(int n){

    if(n == 1){
        return 1;
    }
    else if(n < 1){
        return 0;
    }

    int x = sqrt(n);
    int* arr = new int[n+1];
    for(int i = 0; i <= n; i++){
        arr[i] = -1;
    }

    int ans = helper(n, arr);

    return ans;
}
*/
/* ********DYNAMIC PROGRAAMING APPROACH************* */

int minCount(int n)
{

    int *arr = new int[n + 1];

    arr[0] = 0;
    arr[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        int x = sqrt(i);
        int minVal = INT_MAX;
        for (int j = 1; j <= x; j++)
        {
            minVal = min(arr[i - j * j], minVal);
        }
        arr[i] = minVal + 1;
    }

    return arr[n];
}

int main()
{
    int n;
    cin >> n;
    cout << minCount(n);
}