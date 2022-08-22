#include <iostream>
using namespace std;

bool checkNumber(int arr[], int n, int x)
{

    if (n == 0)
    {
        return false;
    }

    if (arr[0] == x)
    {
        return true;
    }

    checkNumber(arr + 1, n - 1, x);
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

    int x;

    cin >> x;

    if (checkNumber(input, n, x))
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }
}
