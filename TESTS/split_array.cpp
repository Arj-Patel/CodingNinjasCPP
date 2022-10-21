#include <iostream>
using namespace std;

bool helper(int *arr, int n, int s, int left, int right)
{
    if (s == n)
    {
        if (right == left)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    if (arr[s] % 5 == 0)
    {
        left += arr[s];
    }
    else if (arr[s] % 3 == 0)
    {
        right += arr[s];
    }
    else
    {
        bool ans1 = helper(arr, n, s + 1, left + arr[s], right);
        bool ans2 = helper(arr, n, s + 1, left, right + arr[s]);
        if (ans1 == true || ans2 == true)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    return helper(arr, n, s + 1, left, right);
}

bool splitArray(int *arr, int n)
{

    bool ans = helper(arr, n, 0, 0, 0);
    return ans;
}

int main()
{

    int size;
    cin >> size;
    int *input = new int[1 + size];

    for (int i = 0; i < size; i++)
        cin >> input[i];

    if (splitArray(input, size))
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }

    return 0;
}
