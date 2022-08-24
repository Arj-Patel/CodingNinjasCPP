#include <iostream>
using namespace std;

int main()
{

    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        long long n;
        cin >> n;
        long long *arr = new long long[n];
        long long posCount = 0;
        long long negCount = 0;

        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            if (arr[i] < 0)
            {
                negCount++;
            }
            else if (arr[i] > 0)
            {
                posCount++;
            }
        }

        posCount = (posCount - 1) * posCount / 2;
        negCount = (negCount - 1) * negCount / 2;
        long long count = negCount + posCount;

        cout << count << endl;
        delete[] arr;
    }

    return 0;
}