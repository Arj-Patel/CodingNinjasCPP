#include <iostream>
#include <algorithm>
using namespace std;

int tripletSum(int *arr, int n, int num)
{

    sort(arr, arr + n);
    int count = 0;

    for (int i = 0; i <= n - 2; i++)
    {
        int currentNum = num - arr[i];
        // cout<<currentNum<<endl;
        int startIndex = i + 1;
        int endIndex = n - 1;

        while (startIndex < endIndex)
        {
            int numPairs = 0;
            if (arr[startIndex] + arr[endIndex] < currentNum)
            {
                startIndex++;
            }
            else if (arr[startIndex] + arr[endIndex] > currentNum)
            {
                endIndex--;
            }
            else
            {
                int elementAtStart = arr[startIndex];
                int elementAtEnd = arr[endIndex];
                if (elementAtStart == elementAtEnd)
                {
                    int totalElementsFromStartToEnd = (endIndex - startIndex) + 1;
                    numPairs += (totalElementsFromStartToEnd * (totalElementsFromStartToEnd - 1) / 2);
                    count = count + numPairs;
                    // cout<<i<<" "<<numPairs<<endl;
                    break;
                }
                int tempStartIndex = startIndex + 1;
                int tempEndIndex = endIndex - 1;
                while (tempStartIndex <= tempEndIndex && arr[tempStartIndex] == elementAtStart)
                {
                    tempStartIndex += 1;
                }
                while (tempEndIndex >= tempStartIndex && arr[tempEndIndex] == elementAtEnd)
                {
                    tempEndIndex -= 1;
                }
                int totalElementsFromStart = (tempStartIndex - startIndex);
                int totalElementsFromEnd = (endIndex - tempEndIndex);
                numPairs = (totalElementsFromStart * totalElementsFromEnd);
                // cout<<i<<" "<<numPairs<<endl;
                count += numPairs;
                startIndex = tempStartIndex;
                endIndex = tempEndIndex;
            }
        }
    }
    return count;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;

    while (t--)
    {
        int size;
        int x;
        cin >> size;

        int *input = new int[size];

        for (int i = 0; i < size; i++)
        {
            cin >> input[i];
        }
        cin >> x;

        cout << tripletSum(input, size, x) << endl;

        delete[] input;
    }

    return 0;
}