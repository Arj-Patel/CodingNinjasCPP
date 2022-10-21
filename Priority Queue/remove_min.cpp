#include <iostream>
#include <climits>
#include <vector>
using namespace std;

class PriorityQueue
{
    vector<int> pq;

public:
    bool isEmpty()
    {
        return pq.size() == 0;
    }

    int getSize()
    {
        return pq.size();
    }

    int getMin()
    {
        if (isEmpty())
        {
            return 0;
        }

        return pq[0];
    }

    void insert(int element)
    {
        pq.push_back(element);

        int childIndex = pq.size() - 1;

        while (childIndex > 0)
        {
            int parentIndex = (childIndex - 1) / 2;

            if (pq[childIndex] < pq[parentIndex])
            {
                int temp = pq[childIndex];
                pq[childIndex] = pq[parentIndex];
                pq[parentIndex] = temp;
            }
            else
            {
                break;
            }

            childIndex = parentIndex;
        }
    }

    int removeMin()
    {
        if (isEmpty())
        {
            return 0;
        }
        int rValue = pq[0];

        swap(pq[0], pq[pq.size() - 1]);

        pq.pop_back();
        int temp = 0;
        int lChild = 1, rChild = 2;

        while ((lChild < pq.size() && rChild < pq.size()) && (pq[temp] > pq[rChild] || pq[temp] > pq[lChild]))
        {
            if (pq[rChild] < pq[lChild])
            {
                swap(pq[rChild], pq[temp]);
                temp = rChild;
                rChild = 2 * temp + 2;
                lChild = 2 * temp + 1;
            }
            else
            {
                swap(pq[lChild], pq[temp]);
                temp = lChild;
                rChild = 2 * temp + 2;
                lChild = 2 * temp + 1;
            }
        }

        return rValue;
    }
};

int main()
{
    PriorityQueue pq;

    int choice;
    cin >> choice;

    while (choice != -1)
    {
        switch (choice)
        {
        case 1: // insert
            int element;
            cin >> element;
            pq.insert(element);
            break;
        case 2: // getMin
            cout << pq.getMin() << "\n";
            break;
        case 3: // removeMax
            cout << pq.removeMin() << "\n";
            break;
        case 4: // size
            cout << pq.getSize() << "\n";
            break;
        case 5: // isEmpty
            cout << (pq.isEmpty() ? "true\n" : "false\n");
        default:
            return 0;
        }

        cin >> choice;
    }
}