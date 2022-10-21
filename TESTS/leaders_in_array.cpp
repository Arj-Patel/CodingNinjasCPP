#include <iostream>
#include <climits>
using namespace std;

void Leaders(int *arr, int n)
{

    int output[1000000];
    int outLen = 0;

    int max = -2147483648;
    for (int i = n - 1; i >= 0; i--)
    {
        if (arr[i] >= max)
        {
            output[outLen++] = arr[i];
            max = arr[i];
        }
    }

    for (int i = outLen - 1; i >= 0; i--)
    {
        cout << output[i] << " ";
    }
    cout << endl;
}

int main()
{
    int len;
    cin >> len;
    int *arr = new int[len + 1];

    for (int i = 0; i < len; i++)
    {
        cin >> arr[i];
    }
    Leaders(arr, len);
}
