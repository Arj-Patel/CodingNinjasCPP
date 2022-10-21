#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/*
int matrixMultiplication(int* arr, int n){

    if(n <= 2){
        return 0;
    }

    int minSum = INT_MAX;

    for(int i = 0; i <= n-2; i++){

        int* tempArr = new int[n-1];
        tempArr[0] = arr[0];
        for(int i = 1; i < n-1; i++){
            tempArr[i] = arr[i+1];
        }
        int currentSum = arr[0]*arr[1]*arr[2] + matrixMultiplication(tempArr, n-1);
        minSum = min(currentSum, minSum);
        delete[] tempArr;
    }

    return minSum;
}
*/

int matrixMultiplication(int *arr, int start, int end, int **matrixArr)
{

    if (end - start < 2)
    {
        return 0;
    }

    int minSum = INT_MAX;

    if (matrixArr[start][end] != -1)
    {
        return matrixArr[start][end];
    }

    for (int k = start + 1; k <= end - 1; k++)
    {

        int tempAns = (arr[start] * arr[k] * arr[end]) + matrixMultiplication(arr, start, k, matrixArr) + matrixMultiplication(arr, k, end, matrixArr);
        minSum = min(minSum, tempAns);
    }

    matrixArr[start][end] = minSum;

    return minSum;
}

int matrixChainMultiplication(int *arr, int n)
{

    int **matrixArr = new int *[n + 1];

    for (int i = 0; i <= n; i++)
    {
        matrixArr[i] = new int[n + 1];
        for (int j = 0; j <= n; j++)
        {
            matrixArr[i][j] = -1;
        }
    }

    return matrixMultiplication(arr, 0, n, matrixArr);
}

int main()
{
    int n;
    cin >> n;
    int *arr = new int[n];

    for (int i = 0; i <= n; i++)
    {
        cin >> arr[i];
    }

    cout << matrixChainMultiplication(arr, n);

    delete[] arr;
}