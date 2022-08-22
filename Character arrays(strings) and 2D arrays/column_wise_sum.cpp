#include <iostream>
using namespace std;

int main()
{

    long long arr[1000][1000];
    int m, n;
    cin >> m >> n;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        long long sum = 0;
        for (int j = 0; j < m; j++)
        {
            sum = sum + arr[j][i];
        }
        cout << sum << " ";
    }
    cout << endl;
}
