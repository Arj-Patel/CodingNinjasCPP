#include <iostream>
using namespace std;

#include <queue>
void reverseQueue(queue<int> &input)
{

    if (input.empty() == 1)
    {
        return;
    }

    int temp = input.front();
    input.pop();

    reverseQueue(input);

    input.push(temp);
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        queue<int> q;
        int size;
        cin >> size;

        for (int i = 0, val; i < size; i++)
        {
            cin >> val;
            q.push(val);
        }

        reverseQueue(q);
        while (!q.empty())
        {
            cout << q.front() << " ";
            q.pop();
        }

        cout << "\n";
    }
}