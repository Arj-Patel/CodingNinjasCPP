#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> longestConsecutiveIncreasingSequence(int *arr, int n)
{

    unordered_map<int, bool> seq;
    unordered_map<int, int> indices;
    int start, maxLength = 0, startIndex;

    for (int i = 0; i < n; i++)
    {
        seq[arr[i]] = true;
        indices[arr[i]] = i;
    }

    for (int i = 0; i < n; i++)
    {
        if (seq[arr[i]] == true)
        {
            int next = arr[i] + 1, previous = arr[i] - 1;
            seq[arr[i]] = false;
            while (seq.find(next) != seq.end())
            {
                seq[next] = false;
                next++;
            }
            while (seq.find(previous) != seq.end())
            {
                seq[previous] = false;
                previous--;
            }

            startIndex = indices[previous + 1];

            if (next - previous - 1 > maxLength)
            {
                maxLength = next - previous - 1;
                start = previous + 1;
            }
            else if (next - previous - 1 == maxLength)
            {
                if (startIndex < indices[start])
                {
                    start = arr[startIndex];
                }
            }
        }
    }

    vector<int> v;

    v.push_back(start);
    v.push_back(start + maxLength - 1);

    return v;
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

    vector<int> ans = longestConsecutiveIncreasingSequence(arr, size);

    for (auto i = ans.begin(); i != ans.end(); ++i)
        cout << *i << " ";

    delete[] arr;
}
