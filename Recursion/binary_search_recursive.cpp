#include <iostream>
using namespace std;

int binarysearch(int arr[], int si, int ei, int x)
{

    if (si > ei)
    {
        return -1;
    }

    int mid = (si + ei) / 2;

    if (arr[mid] == x)
    {
        return mid;
    }
    else if (arr[mid] < x)
    {
        binarysearch(arr, mid + 1, ei, x);
    }
    else
    {
        binarysearch(arr, si, mid - 1, x);
    }
}

int binarySearch(int arr[], int n, int x)
{

    int ans = binarysearch(arr, 0, n - 1, x);

    return ans;
}

int main()
{
    int input[100000], length, element, ans;
    cin >> length;
    for (int i = 0; i < length; i++)
    {
        cin >> input[i];
        ;
    }

    cin >> element;
    ans = binarySearch(input, length, element);
    cout << ans << endl;
}
