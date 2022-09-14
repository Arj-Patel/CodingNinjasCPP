#include <iostream>
#include <stack>
using namespace std;

void reverseStack(stack<int> &input, stack<int> &output)
{

    if (input.empty() == 1)
    {
        return;
    }

    int size = input.size();
    int s = size - 1;

    for (int i = 0; i < size - 1; i++)
    {
        int t = input.top();
        input.pop();

        for (int j = 0; j < s; j++)
        {
            int temp = input.top();
            output.push(temp);
            input.pop();
        }

        input.push(t);

        while (output.empty() != 1)
        {
            int temp = output.top();
            input.push(temp);
            output.pop();
        }
        s--;
    }
}

int main()
{
    stack<int> input, extra;
    int size;
    cin >> size;

    for (int i = 0, val; i < size; i++)
    {
        cin >> val;
        input.push(val);
    }

    reverseStack(input, extra);

    while (!input.empty())
    {
        cout << input.top() << " ";
        input.pop();
    }
}