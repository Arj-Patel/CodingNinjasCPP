#include <iostream>
#include <unordered_map>
using namespace std;

int highestFrequency(int arr[], int n)
{

    unordered_map<int, int> freq;
    int maxFreq = 0;

    for (int i = 0; i < n; i++)
    {
        freq[arr[i]]++;
        maxFreq = max(freq[arr[i]], maxFreq);
    }

    int ans;

    for (int i = 0; i < n; i++)
    {
        if (freq[arr[i]] == maxFreq)
        {
            ans = arr[i];
            break;
        }
    }

    return ans;
}
int main()
{
    int n;
    cin >> n;

    int *arr = new int[n];

    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }

    cout << highestFrequency(arr, n);

    delete[] arr;
}