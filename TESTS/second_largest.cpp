#include <iostream>
using namespace std;
#include <climits>

int main()
{

    long long n;
    cin >> n;

    if (n == 1 || n == 0)
    {
        cout << INT_MIN << endl;
        return 0;
    }

    int i = 1;

    int max1 = INT_MIN;
    int max2 = INT_MIN;

    int *arr = new int[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int chk = arr[0];
    bool good = false;

    for (int i = 1; i < n; i++)
    {
        if (arr[i] != chk)
        {
            good = true;
        }
    }

    if (!good)
    {
        cout << INT_MIN << endl;
        return 0;
    }

    if (good)
    {
        for (int i = 0; i < n; i++)
        {
            if (arr[i] > max1)
            {
                max2 = max1;
                max1 = arr[i];
            }
            else if (arr[i] < max1 && arr[i] > max2)
            {
                max2 = arr[i];
            }
        }

        cout << max2 << endl;
    }

    // cout<<min2<<endl;

    return 0;
}
