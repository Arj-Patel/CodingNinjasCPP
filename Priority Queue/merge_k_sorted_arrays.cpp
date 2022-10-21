#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> mergeKSortedArrays(vector<vector<int> *> arr)
{

    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < arr[i]->size(); j++)
        {
            pq.push(arr[i]->at(j));
        }
    }

    vector<int> v;
    while (!pq.empty())
    {
        v.push_back(pq.top());
        pq.pop();
    }

    return v;
}

int main()
{
    int k;
    cin >> k;

    vector<vector<int> *> input;

    for (int j = 1; j <= k; j++)
    {
        int size;
        cin >> size;
        vector<int> *current = new vector<int>;

        for (int i = 0; i < size; i++)
        {
            int a;
            cin >> a;
            current->push_back(a);
        }

        input.push_back(current);
    }

    vector<int> output = mergeKSortedArrays(input);

    for (int i = 0; i < output.size(); i++)
    {
        cout << output[i] << " ";
    }

    return 0;
}