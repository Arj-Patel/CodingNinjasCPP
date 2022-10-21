#include <iostream>
#include <unordered_map>
using namespace std;

int lengthOfLongestSubsetWithZeroSum(int *arr, int n)
{

    unordered_map<int, int> checker;
    int sum = 0;
    int maxLength = 0;
    int maxStartIndex = -1;
    for (int i = 0; i < n; i++)
    {

        sum += arr[i];
        if (checker.find(sum) != checker.end())
        {
            if (i - checker[sum] + 1 > maxLength)
            {
                maxLength = i - checker[sum];
                maxStartIndex = checker[sum];
            }
        }
        if (sum == 0)
        {
            maxStartIndex = 0;
            maxLength = i + 1;
        }

        if (checker.find(sum) == checker.end())
        {
            checker[sum] = i;
        }
        maxStartIndex = i;
    }

    return maxLength;
}

int main()
{
    int size;
    cin >> size;

    int *arr = new int[size];

    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }

    cout << lengthOfLongestSubsetWithZeroSum(arr, size);

    delete[] arr;
}