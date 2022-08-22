#include <iostream>
#include <climits>
using namespace std;

int main()
{

    int n;
    cin >> n;

    int N = 1e6 + 2;

    int arr[100];
    int *chkArr = new int[N];

    for (int i = 0; i < N; i++)
    {
        chkArr[i] = -1;
    }

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int minIndex = INT_MAX;

    for (int i = 0; i < n; i++)
    {
        if (chkArr[arr[i]] != -1)
        {
            minIndex = min(minIndex, chkArr[arr[i]]);
        }
        else
        {
            chkArr[arr[i]] = i;
        }
    }

    if (minIndex == INT_MAX)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << arr[minIndex] << endl;
    }

    delete[] chkArr;
    chkArr = NULL;
    return 0;
}