#include <iostream>
using namespace std;

int sum(int arr[], int n)
{

    if (n == 1)
    {
        return arr[0];
    }

    int smallOutput = sum(arr + 1, n - 1);

    return arr[0] + smallOutput;
}

int main()
{
    int n;
    cin >> n;

    int *input = new int[n];

    for (int i = 0; i < n; i++)
    {
        cin >> input[i];
    }

    cout << sum(input, n) << endl;
}
