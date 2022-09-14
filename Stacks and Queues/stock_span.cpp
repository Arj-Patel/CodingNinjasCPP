#include <iostream>
using namespace std;

#include <stack>
int *stockSpan(int *price, int n)
{

    int *arr = new int[n];
    stack<int> checker;

    for (int i = 0; i < n; i++)
    {
        if (checker.empty())
        {
            arr[i] = i + 1;
        }
        else
        {
            int ind = checker.top();
            while (!checker.empty() and price[ind] < price[i])
            {
                checker.pop();
                if (!checker.empty())
                {
                    ind = checker.top();
                }
            }
            if (checker.empty())
            {
                arr[i] = i + 1;
            }
            else
            {
                arr[i] = i - ind;
            }
        }
        checker.push(i);
    }
    return arr;
}

int main()
{
    int size;
    cin >> size;

    int *input = new int[size];
    for (int i = 0; i < size; i++)
    {
        cin >> input[i];
    }

    int *output = stockSpan(input, size);
    for (int i = 0; i < size; i++)
    {
        cout << output[i] << " ";
    }

    cout << "\n";

    delete[] input;
    delete[] output;
}