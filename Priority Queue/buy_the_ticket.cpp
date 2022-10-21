#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int buyTicket(int *arr, int n, int k)
{

    priority_queue<int> pq;
    queue<int> q;

    for (int i = 0; i < n; i++)
    {
        q.push(arr[i]);
        pq.push(arr[i]);
    }

    int currentIndex = k;
    int count = 0;

    for (int i = 0; i < n; i++)
    {

        if (q.front() == pq.top() && currentIndex == 0)
        {
            count++;
            break;
        }
        else if (currentIndex == 0)
        {
            currentIndex = q.size();
        }

        if (q.front() == pq.top())
        {
            q.pop();
            pq.pop();
            currentIndex--;
            count++;
        }
        else
        {
            int temp = q.front();
            q.pop();
            q.push(temp);
            currentIndex--;
            i--;
        }
    }
    return count;
}

int main()
{
    int n;
    cin >> n;

    int *arr = new int[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int k;
    cin >> k;

    cout << buyTicket(arr, n, k);

    delete[] arr;
}