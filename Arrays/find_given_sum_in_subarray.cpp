#include <iostream>
using namespace std;

int main()
{

    int n;
    cin >> n;

    int arr[100];

    int givenSum;
    cin >> givenSum;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int st = 0, en = 0, currentSum = 0, i = 0, j = 0;

    while ((currentSum + arr[j] <= givenSum) && j < n)
    {
        currentSum += arr[j];
        j++;
    }

    if (currentSum == givenSum)
    {
        cout << i + 1 << " " << j << endl;
        return 0;
    }

    while (j < n)
    {
        currentSum += arr[j];
        while (currentSum > givenSum)
        {
            currentSum -= arr[i];
            i++;
        }
        if (currentSum == givenSum)
        {
            st = i + 1;
            en = j + 1;
            break;
        }
        j++;
    }

    cout << st << " " << en << endl;
    return 0;
}