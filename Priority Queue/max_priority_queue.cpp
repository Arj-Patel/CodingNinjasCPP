#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class PriorityQueue
{
    vector<int> pq;

public:
    PriorityQueue()
    {
    }

    void insert(int element)
    {
        pq.push_back(element);
        int childIndex = pq.size() - 1;
        int parentIndex = (childIndex - 1) / 2;

        while (childIndex > 0)
        {
            if (pq[childIndex] > pq[parentIndex])
            {
                swap(pq[childIndex], pq[parentIndex]);
            }
            else
            {
                break;
            }
            childIndex = parentIndex;
            parentIndex = (childIndex - 1) / 2;
        }
    }

    int getMax()
    {
        if (pq.size() == 0)
        {
            return INT_MIN;
        }

        // for(int i = 0; i < pq.size(); i++){
        //     cout<<pq[i]<<" ";
        // }
        // cout<<endl;
        // cout<<endl;
        // cout<<endl;
        // cout<<endl;

        return pq[0];
    }

    int removeMax()
    {

        if (pq.size() == 0)
        {
            return INT_MIN;
        }

        int rValue = pq[0];
        pq[0] = pq[pq.size() - 1];
        pq.pop_back();

        int parentIndex = 0;
        int rightChildIndex = 2, leftChildIndex = 1;

        while (leftChildIndex < pq.size())
        {

            if (pq[parentIndex] < pq[rightChildIndex] || pq[parentIndex] < pq[leftChildIndex])
            {
                if (pq[rightChildIndex] > pq[leftChildIndex])
                {
                    swap(pq[rightChildIndex], pq[parentIndex]);
                    parentIndex = rightChildIndex;
                }
                else
                {
                    swap(pq[leftChildIndex], pq[parentIndex]);
                    parentIndex = leftChildIndex;
                }
            }
            else
            {
                break;
            }
            rightChildIndex = parentIndex * 2 + 2;
            leftChildIndex = parentIndex * 2 + 1;
        }

        return rValue;
    }

    int getSize()
    {
        return pq.size();
    }

    bool isEmpty()
    {

        return pq.size() == 0;
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
        case 2: // getMax
            cout << pq.getMax() << "\n";
            break;
        case 3: // removeMax
            cout << pq.removeMax() << "\n";
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