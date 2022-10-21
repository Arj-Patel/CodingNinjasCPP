#include <bits/stdc++.h>
using namespace std;

void findMedian(int *arr, int n)
{

    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;

    for (int i = 0; i < n; i++)
    {

        if (minHeap.size() == 0 && maxHeap.size() == 0)
        {
            maxHeap.push(arr[i]);
        }
        else if (arr[i] > maxHeap.top())
        {
            minHeap.push(arr[i]);
        }
        else
        {
            maxHeap.push(arr[i]);
        }

        if (abs(maxHeap.size() - minHeap.size()) > 1)
        {
            if (maxHeap.size() > minHeap.size())
            {
                int temp = maxHeap.top();
                maxHeap.pop();
                minHeap.push(temp);
            }
            else
            {
                int temp = minHeap.top();
                minHeap.pop();
                maxHeap.push(temp);
            }
        }

        /*
        if (maxHeap.size() > minHeap.size())
        {
            int temp = maxHeap.top();
            maxHeap.pop();
            minHeap.push(temp);
        }
        else if (minHeap.size() > maxHeap.size())
        {
            int temp = minHeap.top();
            minHeap.pop();
            maxHeap.push(temp);
        }
        */

        if ((maxHeap.size() + minHeap.size()) % 2 == 0)
        {
            cout << (maxHeap.top() + minHeap.top()) / 2 << " ";
        }
        else
        {
            if (maxHeap.size() > minHeap.size())
            {
                cout << maxHeap.top() << " ";
            }
            else
            {
                cout << minHeap.top() << " ";
            }
        }
    }
}

/*
#include<bits/stdc++.h>
#include<queue>
void findMedian(int *arr, int n)
{
    // Write your code here
    if(n==0)
        return;
    priority_queue<int, vector<int>, greater<int>> minpq;  // Minheap for 2nd half array.
    priority_queue<int> maxpq; maxpq.push(arr[0]); // Max heap for 1st half array.
    cout<<arr[0]<<" "; // only one element so itself is median
    int median;
    for(int i=1;i<n;i++){
        //Insert accordingly
        if(arr[i] <= maxpq.top())
            maxpq.push(arr[i]);
        else
            minpq.push(arr[i]);
        //Balance the height of both the heap
        if(abs(maxpq.size() - minpq.size()) > 1){
            if(maxpq.size() > minpq.size()){
                int temp=maxpq.top();
                maxpq.pop();
                minpq.push(temp);
            }
            else{
                int temp=minpq.top();
                minpq.pop();
                maxpq.push(temp);
            }
        }
        //Get the median
        if(maxpq.size() > minpq.size())
            median=maxpq.top();
        else if(maxpq.size() < minpq.size())
            median=minpq.top();
        else
            median=(maxpq.top() + minpq.top())/2;   // no. of element is even.

        cout<<median<<" ";
    }
}*/

int main()
{
    int n;
    cin >> n;

    int *arr = new int[n];

    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }

    findMedian(arr, n);

    delete[] arr;
}
